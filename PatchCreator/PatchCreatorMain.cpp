// PatchCreatorDll.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "connectFunc.h"
#include <StormLib.h>
#include "common.hpp"
#include "dbc.hpp"
#include <iostream>
#include <fstream>

DBCFileLoader DBCSpell;
DBCFileLoader DBCItemDisplayInfo;
DBCFileLoader DBCSpellItemEnchantment;
DBCFileLoader DBCSpellVisualKit;

std::map<uint32, uint32> SpellsMap{};
std::map<uint32, uint32> ItemDisplayInfoMap{};
std::map<uint32, uint32> SpellItemEnchantmentMap{};
std::map<uint32, uint32> SpellVisualKitMap{};

bool ChangeSpellDBC();
bool ChangeItemDisplayInfoDBC();
bool ChangeSpellItemEnchantmentDBC();
bool ChangeSpellVisualKitDBC();

bool CreateMPQ(std::string);
bool ParseJsons(SpellMap*,int, SpellMap*,int);
bool ExtractMPQ(std::string);
bool MainFunction(SpellMap*,int, SpellMap*,int , std::string);

bool PatchCreate(SpellMap* SpellDBC, int SpellDBCCount, SpellMap* SpellVisualKitDBC, int SpellVisualKitDBCCount, const char* a)
{
	return MainFunction(SpellDBC, SpellDBCCount, SpellVisualKitDBC, SpellVisualKitDBCCount, std::string(a));
}

bool MainFunction(SpellMap* SpellDBC, int SpellDBCCount, SpellMap* SpellVisualKitDBC, int SpellVisualKitDBCCount, std::string path) {

	ParseJsons(SpellDBC, SpellDBCCount, SpellVisualKitDBC, SpellVisualKitDBCCount);
	bool isSuccess =  ExtractMPQ(path);
	if (!isSuccess) return false;
	ChangeSpellDBC();
	ChangeItemDisplayInfoDBC();
	ChangeSpellItemEnchantmentDBC();
	ChangeSpellVisualKitDBC();

	return CreateMPQ(path);
}

bool ParseJsons(SpellMap* SpellDBC, int SpellDBCCount, SpellMap* SpellVisualKitDBC, int SpellVisualKitDBCCount) {
	
	for (int i = 0; i < SpellDBCCount; i++) {
		SpellsMap[SpellDBC[i].Key] =SpellDBC[i].Value;
	}
	for (int i = 0; i < SpellVisualKitDBCCount; i++) {
		SpellVisualKitMap[SpellVisualKitDBC[i].Key] = SpellVisualKitDBC[i].Value;
	}
	return true;
};

TCHAR* ConverterToTCHAR(const char* orig) {
	TCHAR* tchar = 0;
	std::string str = std::string(orig);
	tchar = new TCHAR[str.size() + 1];
	copy(str.begin(), str.end(), tchar);
	tchar[str.size()] = 0;
	return tchar;
};


bool ExtractMPQ(std::string path = "error") {

	HANDLE mpq;
	bool isSuccess = SFileOpenArchive(ConverterToTCHAR((path + std::string("/Data/ruRU/patch-ruRU-4.mpq")).c_str()), 0, STREAM_FLAG_WRITE_SHARE, &mpq);
	if (!isSuccess) return false;
	if (mpq) {
		SFileExtractFile(mpq, "DBFilesClient\\Spell.dbc", ConverterToTCHAR("./Spell.dbc"), SFILE_OPEN_FROM_MPQ);
		SFileExtractFile(mpq, "DBFilesClient\\ItemDisplayInfo.dbc", ConverterToTCHAR("./ItemDisplayInfo.dbc"), SFILE_OPEN_FROM_MPQ);
		SFileExtractFile(mpq, "DBFilesClient\\SpellItemEnchantment.dbc", ConverterToTCHAR("./SpellItemEnchantment.dbc"), SFILE_OPEN_FROM_MPQ);
		SFileExtractFile(mpq, "DBFilesClient\\SpellVisualKit.dbc", ConverterToTCHAR("./SpellVisualKit.dbc"), SFILE_OPEN_FROM_MPQ);

		SFileCloseArchive(mpq);
		return true;
	}
	return false;
};

bool ChangeSpellDBC() {
	DBCSpell.Load("./Spell.dbc");
	if (!DBCSpell.getNumFields()) {
		return false;
	}
	
	FILE* npf;
	errno_t err = fopen_s(&npf, "./Spell.dbc", "wb");
	if (err == 0) {
		
		fwrite(&DBCSpell.header, 4, 1, npf);
		fwrite(&DBCSpell.recordCount, 4, 1, npf);
		fwrite(&DBCSpell.fieldCount, 4, 1, npf);
		fwrite(&DBCSpell.recordSize, 4, 1, npf);
		fwrite(&DBCSpell.stringSize, 4, 1, npf);

		for (uint32 i = 0; i < DBCSpell.recordCount; i++) {
			auto record = DBCSpell.getRecord(i);
			int spellid = record.getInt32(0);
	
			if (SpellsMap.count(spellid)) {
				record.setUInt32(131, SpellsMap[spellid]);
			}
		}

		fwrite(DBCSpell.data, DBCSpell.recordSize * DBCSpell.recordCount + DBCSpell.stringSize, 1, npf);
		fwrite(DBCSpell.stringTable, DBCSpell.stringSize, 0, npf);

		fclose(npf);
		return true;
	}
	else
	{
		return false;
	}

}

bool ChangeItemDisplayInfoDBC() {
	DBCItemDisplayInfo.Load("./ItemDisplayInfo.dbc");
	if (!DBCItemDisplayInfo.getNumFields()) {
		return false;
	}
	
	for (uint32 i = 0; i < DBCItemDisplayInfo.recordCount; i++) {
		auto record = DBCItemDisplayInfo.getRecord(i);

		record.setUInt32(23, 0);
		record.setUInt32(11, 0);

	}
	FILE* npf;
	errno_t err = fopen_s(&npf, "./ItemDisplayInfo.dbc", "wb");
	if (err == 0) {
		fwrite(&DBCItemDisplayInfo.header, 4, 1, npf);
		fwrite(&DBCItemDisplayInfo.recordCount, 4, 1, npf);
		fwrite(&DBCItemDisplayInfo.fieldCount, 4, 1, npf);
		fwrite(&DBCItemDisplayInfo.recordSize, 4, 1, npf);
		fwrite(&DBCItemDisplayInfo.stringSize, 4, 1, npf);
		fwrite(DBCItemDisplayInfo.data, DBCItemDisplayInfo.recordSize * DBCItemDisplayInfo.recordCount + DBCItemDisplayInfo.stringSize, 1, npf);
		fwrite(DBCItemDisplayInfo.stringTable, DBCItemDisplayInfo.stringSize, 0, npf);
		fclose(npf);
		return true;
	}
	else
	{
		return false;
	}
}

bool ChangeSpellItemEnchantmentDBC() {
	DBCSpellItemEnchantment.Load("./SpellItemEnchantment.dbc");
	if (!DBCSpellItemEnchantment.getNumFields()) {
		return false;
	}
	
	for (uint32 i = 0; i < DBCSpellItemEnchantment.recordCount; i++) {
		auto record = DBCSpellItemEnchantment.getRecord(i);
		record.setUInt32(31, 0);
	}

	FILE* npf;
	errno_t err = fopen_s(&npf, "./SpellItemEnchantment.dbc", "wb");
	if (err == 0) {
		fwrite(&DBCSpellItemEnchantment.header, 4, 1, npf);
		fwrite(&DBCSpellItemEnchantment.recordCount, 4, 1, npf);
		fwrite(&DBCSpellItemEnchantment.fieldCount, 4, 1, npf);
		fwrite(&DBCSpellItemEnchantment.recordSize, 4, 1, npf);
		fwrite(&DBCSpellItemEnchantment.stringSize, 4, 1, npf);
		fwrite(DBCSpellItemEnchantment.data, DBCSpellItemEnchantment.recordSize * DBCSpellItemEnchantment.recordCount + DBCSpellItemEnchantment.stringSize, 1, npf);
		fwrite(DBCSpellItemEnchantment.stringTable, DBCSpellItemEnchantment.stringSize, 0, npf);
		fclose(npf);
		return true;
	}
	else
	{
		return false;
	}
}

bool ChangeSpellVisualKitDBC() {
	DBCSpellVisualKit.Load("./SpellVisualKit.dbc");
	if (!DBCSpellVisualKit.getNumFields()) { return false; };
	for (uint32 i = 0; i < DBCSpellVisualKit.recordCount; i++) {

		auto record = DBCSpellVisualKit.getRecord(i);
		int spellid = record.getInt32(0);

		if (SpellVisualKitMap.count(spellid)) {
			
			record.setInt32(6, 0);
			record.setInt32(7, 0);
		}
	}
	FILE* npf;
	errno_t err = fopen_s(&npf, "./SpellVisualKit.dbc", "wb");
	if (err == 0) {
		fwrite(&DBCSpellVisualKit.header, 4, 1, npf);
		fwrite(&DBCSpellVisualKit.recordCount, 4, 1, npf);
		fwrite(&DBCSpellVisualKit.fieldCount, 4, 1, npf);
		fwrite(&DBCSpellVisualKit.recordSize, 4, 1, npf);
		fwrite(&DBCSpellVisualKit.stringSize, 4, 1, npf);
		fwrite(DBCSpellVisualKit.data, DBCSpellVisualKit.recordSize * DBCSpellVisualKit.recordCount + DBCSpellVisualKit.stringSize, 1, npf);
		fwrite(DBCSpellVisualKit.stringTable, DBCSpellVisualKit.stringSize, 0, npf);
		fclose(npf);
		return true;
	}
	else {
		return false;
	}
	return true;
}

bool CreateMPQ(std::string path = "error") {
	try {
		HANDLE mpq;
		remove((path + std::string("/Data/ruRU/patch-ruRU-[.mpq")).c_str());
		bool isSucsess = SFileCreateArchive(ConverterToTCHAR((path + std::string("/Data/ruRU/patch-ruRU-[.mpq")).c_str()), MPQ_CREATE_ATTRIBUTES + MPQ_CREATE_ARCHIVE_V2, 0x000000010, &mpq);
		if (!isSucsess)
		{
			remove("./Spell.dbc");
			remove("./ItemDisplayInfo.dbc");
			remove("./SpellItemEnchantment.dbc");
			remove("./SpellVisualKit.dbc");
			return false;
		}
			
		SFileAddFileEx(mpq, ConverterToTCHAR("./Spell.dbc"), "DBFilesClient\\Spell.dbc", MPQ_FILE_COMPRESS + MPQ_FILE_REPLACEEXISTING, MPQ_COMPRESSION_ZLIB, MPQ_COMPRESSION_NEXT_SAME);
		remove("./Spell.dbc");
		SFileAddFileEx(mpq, ConverterToTCHAR("./ItemDisplayInfo.dbc"), "DBFilesClient\\ItemDisplayInfo.dbc", MPQ_FILE_COMPRESS + MPQ_FILE_REPLACEEXISTING, MPQ_COMPRESSION_ZLIB, MPQ_COMPRESSION_NEXT_SAME);
		remove("./ItemDisplayInfo.dbc");
		SFileAddFileEx(mpq, ConverterToTCHAR("./SpellItemEnchantment.dbc"), "DBFilesClient\\SpellItemEnchantment.dbc", MPQ_FILE_COMPRESS + MPQ_FILE_REPLACEEXISTING, MPQ_COMPRESSION_ZLIB, MPQ_COMPRESSION_NEXT_SAME);
		remove("./SpellItemEnchantment.dbc");
		SFileAddFileEx(mpq, ConverterToTCHAR("./SpellVisualKit.dbc"), "DBFilesClient\\SpellVisualKit.dbc", MPQ_FILE_COMPRESS + MPQ_FILE_REPLACEEXISTING, MPQ_COMPRESSION_ZLIB, MPQ_COMPRESSION_NEXT_SAME);
		remove("./SpellVisualKit.dbc");
		return SFileCloseArchive(mpq);
	}
	catch (...) {
		return false;
	}
};

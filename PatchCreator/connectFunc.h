#pragma once
#ifdef PATCHCREATOR_EXPORTS
#define PATCHCREATOR_API __declspec(dllexport)
#else
#define PATCHCREATOR_API __declspec(dllimport)
#endif
#include <string>
#include <map>


struct SpellMap
{
    int Key;
    int Value;
};


/*struct SpellMaps
{
    SpellMap* SpellDBC;
   // int SpellDBCCount;
    SpellMap* SpellVisualKitDBC;
   // int SpellVisualKitDBCCount;
};*/

extern "C" PATCHCREATOR_API bool PatchCreate(SpellMap* SpellDBC, int SpellDBCCount, SpellMap* SpellVisualKitDBC, int SpellVisualKitDBCCount,const char* a);

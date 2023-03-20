/*
 * DBC to SQL Converter
 * Copyright (C) 2009 David Vas, Anubisss
 * <http://code.google.com/p/dbctosql/>

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __SPEL_H__
#define __SPEL_H__

char const *SPELL_DBC = "Spell.dbc";
char const *SPELL_SQL = "Spell_dbc.sql";
char const *SPELL_TABLE = "dbc_spell";

#define SPELL_DBC_CLIENT_BUILD 12340 // 3.3.5a

#define SPELL_DBC_COLUMN_NUMS 234
// #define SPELL_DBC_ROWS_NUMS 49839

// Spell.dbc struct: TrinityCore2 r4907

// {
//{"uint32","0_Entry"},
//{"uint32","1_Category"},
//{"uint32","2_Dispel"},
//{"uint32","3_Mechanic"},
//{"uint32","4_Attributes"},
//{"uint32","5_AttributesEx"},
//{"uint32","6_AttributesEx2"},
//{"uint32","7_AttributesEx3"},
//{"uint32","8_AttributesEx4"},
//{"uint32","9_AttributesEx5"},
//{"uint32","10_AttributesEx6"},
//{"uint32","11_AttributesEx7"},
//{"uint32","12_Stances"},
//{"uint32","13_unk320_2"},
//{"uint32","14_StancesNot"},
//{"uint32","15_unk320_3"},
//{"uint32","16_Targets"},
//{"uint32","17_TargetCreatureType"},
//{"uint32","18_RequiresSpellFocus"},
//{"uint32","19_FacingCasterFlags"},
//{"uint32","20_CasterAuraState"},
//{"uint32","21_TargetAuraState"},
//{"uint32","22_CasterAuraStateNot"},
//{"uint32","23_TargetAuraStateNot"},
//{"uint32","24_casterAuraSpell"},
//{"uint32","25_targetAuraSpell"},
//{"uint32","26_excludeCasterAuraSpell"},
//{"uint32","27_excludeTargetAuraSpell"},
//{"uint32","28_CastingTimeIndex",},
//{"uint32","29_RecoveryTime"},
//{"uint32","30_CategoryRecoveryTime"},
//{"uint32","31_InterruptFlags"},
//{"uint32","32_AuraInterruptFlags"},
//{"uint32","33_ChannelInterruptFlags"},
//{"uint32","34_procFlags"},
//{"uint32","35_procChance"},
//{"uint32","36_procCharges"},
//{"uint32","37_maxLevel"},
//{"uint32","38_baseLevel"},
//{"uint32","39_spellLevel"},
//{"uint32","40_DurationIndex"},
//{"uint32","41_powerType"},
//{"uint32","42_manaCost"},
//{"uint32","43_manaCostPerlevel"},
//{"uint32","44_manaPerSecond"},
//{"uint32","45_manaPerSecondPerLevel"},
//{"uint32","46_rangeIndex"},
//{"float","47_speed"},
//{"uint32","48_modalNextSpell"},
//{"uint32","49_StackAmount"},
//{"uint32","50_Totem1"},
//{"uint32","51_Totem2"},
//{"int32","52_Reagent1"},
//{"int32","53_Reagent2"},
//{"int32","54_Reagent3"},
//{"int32","55_Reagent4"},
//{"int32","56_Reagent5"},
//{"int32","57_Reagent6"},
//{"int32","58_Reagent7"},
//{"int32","59_Reagent8"},
//{"uint32","60_ReagentCount1"},
//{"uint32","61_ReagentCount2"},
//{"uint32","62_ReagentCount3"},
//{"uint32","63_ReagentCount4"},
//{"uint32","64_ReagentCount5"},
//{"uint32","65_ReagentCount6"},
//{"uint32","66_ReagentCount7"},
//{"uint32","67_ReagentCount8"},
//{"int32","68_EquippedItemClass"},
//{"int32","69_EquippedItemSubClassMask"},
//{"int32","70_EquippedItemInventoryTypeMask"},
//{"uint32","71_Effect1"},
//{"uint32","72_Effect2"},
//{"uint32","73_Effect3"},
//{"int32","74_EffectDieSides1"},
//{"int32","75_EffectDieSides2"},
//{"int32","76_EffectDieSides3"},
//{"float","77_EffectRealPointsPerLevel1"},
//{"float","78_EffectRealPointsPerLevel2"},
//{"float","79_EffectRealPointsPerLevel3"},
//{"int32","80_EffectBasePoints1"},
//{"int32","81_EffectBasePoints2"},
//{"int32","82_EffectBasePoints3"},
//{"uint32","83_EffectMechanic1"},
//{"uint32","84_EffectMechanic2"},
//{"uint32","85_EffectMechanic3"},
//{"uint32","86_EffectImplicitTargetA1"},
//{"uint32","87_EffectImplicitTargetA2"},
//{"uint32","88_EffectImplicitTargetA3"},
//{"uint32","89_EffectImplicitTargetB1"},
//{"uint32","90_EffectImplicitTargetB2"},
//{"uint32","91_EffectImplicitTargetB3"},
//{"uint32","92_EffectRadiusIndex1"},
//{"uint32","93_EffectRadiusIndex2"},
//{"uint32","94_EffectRadiusIndex3"},
//{"uint32","95_EffectApplyAuraName1"},
//{"uint32","96_EffectApplyAuraName2"},
//{"uint32","97_EffectApplyAuraName3"},
//{"uint32","98_EffectAmplitude1"},
//{"uint32","99_EffectAmplitude2"},
//{"uint32","100_EffectAmplitude3"},
//{"float","101_EffectValueMultiplier1"},
//{"float","102_EffectValueMultiplier2"},
//{"float","103_EffectValueMultiplier3"},
//{"uint32","104_EffectChainTarget1"},
//{"uint32","105_EffectChainTarget2"},
//{"uint32","106_EffectChainTarget3"},
//{"uint32","107_EffectItemType1"},
//{"uint32","108_EffectItemType2"},
//{"uint32","109_EffectItemType3"},
//{"int32","110_EffectMiscValue1"},
//{"int32","111_EffectMiscValue2"},
//{"int32","112_EffectMiscValue3"},
//{"int32","113_EffectMiscValueB1"},
//{"int32","114_EffectMiscValueB2"},
//{"int32","115_EffectMiscValueB3"},
//{"uint32","116_EffectTriggerSpell1"},
//{"uint32","117_EffectTriggerSpell2"},
//{"uint32","118_EffectTriggerSpell3"},
//{"float","119_EffectPointsPerComboPoint1"},
//{"float","120_EffectPointsPerComboPoint2"},
//{"float","121_EffectPointsPerComboPoint3"},
//{"flag96","122_EffectSpellClassMask1"},
//{"flag96","123_EffectSpellClassMask2"},
//{"flag96","124_EffectSpellClassMask3"},
//{"flag96","125_EffectSpellClassMask4"},
//{"flag96","126_EffectSpellClassMask5"},
//{"flag96","127_EffectSpellClassMask6"},
//{"flag96","128_EffectSpellClassMask7"},
//{"flag96","129_EffectSpellClassMask8"},
//{"flag96","130_EffectSpellClassMask9"},
//{"uint32","131_SpellVisual1"},
//{"uint32","132_SpellVisual2"},
//{"uint32","133_SpellIconID"},
//{"uint32","134_activeIconID"},
//{"uint32","135_spellPriority"},
//{"char*","136_SpellName_0"},
//{"char*","137_SpellName_1"},
//{"char*","138_SpellName_2"},
//{"char*","139_SpellName_3"},
//{"char*","140_SpellName_4"},
//{"char*","141_SpellName_5"},
//{"char*","142_SpellName_6"},
//{"char*","143_SpellName_7"},
//{"char*","144_SpellName_8"},
//{"char*","145_SpellName_9"},
//{"char*","146_SpellName_10"},
//{"char*","147_SpellName_11"},
//{"char*","148_SpellName_12"},
//{"char*","149_SpellName_13"},
//{"char*","150_SpellName_14"},
//{"char*","151_SpellName_15"},
//{"uint32","152_SpellNameFlag"},
//{"char*","153_Rank_0"},
//{"char*","154_Rank_1"},
//{"char*","155_Rank_2"},
//{"char*","156_Rank_3"},
//{"char*","157_Rank_4"},
//{"char*","158_Rank_5"},
//{"char*","159_Rank_6"},
//{"char*","160_Rank_7"},
//{"char*","161_Rank_8"},
//{"char*","162_Rank_9"},
//{"char*","163_Rank_10"},
//{"char*","164_Rank_11"},
//{"char*","165_Rank_12"},
//{"char*","166_Rank_13"},
//{"char*","167_Rank_14"},
//{"char*","168_Rank_15"},
//{"uint32","169_RankFlags"},
//{"char*","170_Description_0"},
//{"char*","171_Description_1"},
//{"char*","172_Description_2"},
//{"char*","173_Description_3"},
//{"char*","174_Description_4"},
//{"char*","175_Description_5"},
//{"char*","176_Description_6"},
//{"char*","177_Description_7"},
//{"char*","178_Description_8"},
//{"char*","179_Description_9"},
//{"char*","180_Description_10"},
//{"char*","181_Description_11"},
//{"char*","182_Description_12"},
//{"char*","183_Description_13"},
//{"char*","184_Description_14"},
//{"char*","185_Description_15"},
//{"uint32","186_DescriptionFlags"},
//{"char*","187_ToolTip_0"},
//{"char*","188_ToolTip_1"},
//{"char*","189_ToolTip_2"},
//{"char*","190_ToolTip_3"},
//{"char*","191_ToolTip_4"},
//{"char*","192_ToolTip_5"},
//{"char*","193_ToolTip_6"},
//{"char*","194_ToolTip_7"},
//{"char*","195_ToolTip_8"},
//{"char*","196_ToolTip_9"},
//{"char*","197_ToolTip_10"},
//{"char*","198_ToolTip_11"},
//{"char*","199_ToolTip_12"},
//{"char*","200_ToolTip_13"},
//{"char*","201_ToolTip_14"},
//{"char*","202_ToolTip_15"},
//{"uint32","203_ToolTipFlags"},
//{"uint32","204_ManaCostPercentage"},
//{"uint32","205_StartRecoveryCategory"},
//{"uint32","206_StartRecoveryTime"},
//{"uint32","207_MaxTargetLevel"},
//{"uint32","208_SpellFamilyName"},
//{"flag96","209_SpellFamilyFlagsLow"},
//{"flag96","210_SpellFamilyFlagsHigh"},
//{"flag96","211_SpellFamilyFlags2"},
//{"uint32","212_MaxAffectedTargets"},
//{"uint32","213_DmgClass"},
//{"uint32","214_PreventionType"},
//{"uint32","215_StanceBarOrder"},
//{"float","216_EffectDamageMultiplier1"},
//{"float","217_EffectDamageMultiplier2"},
//{"float","218_EffectDamageMultiplier3"},
//{"uint32","219_MinFactionId"},
//{"uint32","220_MinReputation"},
//{"uint32","221_RequiredAuraVision"},
//{"uint32","222_TotemCategory1"},
//{"uint32","223_TotemCategory2"},
//{"int32","224_AreaGroupId"},
//{"uint32","225_SchoolMask"},
//{"uint32","226_runeCostID"},
//{"uint32","227_spellMissileID"},
//{"uint32","228_PowerDisplayId"},
//{"float","229_EffectBonusMultiplier1"},
//{"float","230_EffectBonusMultiplier2"},
//{"float","231_EffectBonusMultiplier3"},
//{"uint32","232_spellDescriptionVariableID"},
//{"uint32","233_SpellDifficultyId"},
// };
//wow 335 sirus parser to sql
char const *spell_translation[SPELL_DBC_COLUMN_NUMS][2] =
{
 {"int32" , "ID"},
 {"uint32" , "Category"},
 {"uint32" , "DispelType"},
 {"uint32" , "Mechanic"},
 {"uint32" , "Attributes"},
 {"uint32" , "AttributesEx"},
 {"uint32" , "AttributesExB"},
 {"uint32" , "AttributesExC"},
 {"uint32" , "AttributesExD"},
 {"uint32" , "AttributesExE"},
 {"uint32" , "AttributesExF"},
 {"uint32" , "AttributesExG"},
 {"uint32" , "ShapeshiftMask"},
 {"uint32" , "ShapeshiftExclude"},
 {"uint32" , "Targets" },
 {"uint32" , "TargetCreatureType"},
 {"uint32" , "RequiresSpellFocus"},
 {"uint32" , "FacingCasterFlags"},
 {"uint32" , "CasterAuraState"},
 {"uint32" ,"TargetAuraState"},
 {"uint32" , "ExcludeCasterAuraState"},
 {"uint32" , "ExcludeTargetAuraState"},
 {"uint32" , "CasterAuraSpell"},
 {"uint32" , "TargetAuraSpell"},
 {"uint32" , "ExcludeCasterAuraSpell"},
 {"uint32" , "ExcludeTargetAuraSpell"},
 {"uint32" , "CastingTimeIndex" },
 {"uint32" , "RecoveryTime"},
 {"uint32" , "CategoryRecoveryTime"},
 {"uint32" , "InterruptFlags"},
 {"uint32" , "AuraInterruptFlags"},
 {"uint32" , "ChannelInterruptFlags"},
 {"uint32" , "ProcTypeMask"},
 {"uint32" , "ProcChance"},
 {"uint32" , "ProcCharges" },
 {"uint32" , "MaxLevel"},
 {"uint32" , "BaseLevel" },
 {"uint32" , "SpellLevel"},
 {"uint32" , "DurationIndex"},
 {"int32" , "PowerType" },
 {"uint32" , "ManaCost"},
 {"uint32" , "ManaCostPerLevel" },
 {"uint32" , "ManaPerSecond"},
 {"uint32" , "ManaPerSecondPerLevel"},
 {"uint32" , "RangeIndex"},
 {"float" , "Speed"},
 {"uint32" , "ModalNextSpell"},
 {"uint32" , "CumulativeAura"},
 {"uint32" , "Totem_1" },
 {"uint32" , "Totem_2" },
 {"int32" , "Reagent_1" },
 {"int32" , "Reagent_2" },
 {"int32" , "Reagent_3" },
 {"int32" , "Reagent_4" },
 {"int32" , "Reagent_5" },
 {"int32" , "Reagent_6" },
 {"int32" , "Reagent_7" },
 {"int32" ,"Reagent_8" },
 {"int32" , "ReagentCount_1"},
 {"int32" , "ReagentCount_2"},
 {"int32" , "ReagentCount_3"},
 {"int32" , "ReagentCount_4"},
 {"int32" , "ReagentCount_5"},
 {"int32" , "ReagentCount_6"},
 {"int32" , "ReagentCount_7"},
 {"int32" , "ReagentCount_8"},
 {"int32" , "EquippedItemClass"},
 {"int32" , "EquippedItemSubclass"},
 {"int32" , "EquippedItemInvTypes"},
 {"uint32" , "Effect_1"},
 {"uint32" , "Effect_2"},
 {"uint32" , "Effect_3"},
 {"int32" , "EffectDieSides_1" },
 {"int32" , "EffectDieSides_2" },
 {"int32" , "EffectDieSides_3" },
 {"float" , "EffectRealPointsPerLevel_1" },
 {"float" , "EffectRealPointsPerLevel_2" },
 {"float" , "EffectRealPointsPerLevel_3" },
 {"int32" , "EffectBasePoints_1"},
 {"int32" , "EffectBasePoints_2"},
 {"int32" , "EffectBasePoints_3"},
 {"uint32" , "EffectMechanic_1" },
 {"uint32" , "EffectMechanic_2" },
 {"uint32" , "EffectMechanic_3" },
 {"uint32" , "ImplicitTargetA_1"},
 {"uint32" , "ImplicitTargetA_2"},
 {"uint32" , "ImplicitTargetA_3"},
 {"uint32" , "ImplicitTargetB_1"},
 {"uint32" , "ImplicitTargetB_2"},
 {"uint32" , "ImplicitTargetB_3"},
 {"uint32" , "EffectRadiusIndex_1" },
 {"uint32" , "EffectRadiusIndex_2" },
 {"uint32" , "EffectRadiusIndex_3" },
 {"uint32" , "EffectAura_1"},
 {"uint32" ,"EffectAura_2"},
 {"uint32" , "EffectAura_3"},
 {"uint32" , "EffectAuraPeriod_1"},
 {"uint32" , "EffectAuraPeriod_2"},
 {"uint32" , "EffectAuraPeriod_3"},
 {"float" , "EffectMultipleValue_1"},
 {"float" , "EffectMultipleValue_2"},
 {"float" , "EffectMultipleValue_3"},
 {"uint32" , "EffectChainTargets_1"},
 {"uint32" , "EffectChainTargets_2"},
 {"uint32" , "EffectChainTargets_3"},
 {"uint32" , "EffectItemType_1" },
 {"uint32" , "EffectItemType_2" },
 {"uint32" , "EffectItemType_3" },
 {"int32" , "EffectMiscValue_1"},
 {"int32" , "EffectMiscValue_2"},
 {"int32" , "EffectMiscValue_3"},
 {"int32" , "EffectMiscValueB_1"},
 {"int32" , "EffectMiscValueB_2"},
 {"int32" , "EffectMiscValueB_3"},
 {"uint32" , "EffectTriggerSpell_1"},
 {"uint32" , "EffectTriggerSpell_2"},
 {"uint32" , "EffectTriggerSpell_3"},
 {"float" , "EffectPointsPerCombo_1"},
 {"float" , "EffectPointsPerCombo_2"},
 {"float" , "EffectPointsPerCombo_3"},
 {"uint32" , "EffectSpellClassMaskA_1" },
 {"uint32" , "EffectSpellClassMaskA_2" },
 {"uint32" , "EffectSpellClassMaskA_3" },
 {"uint32" , "EffectSpellClassMaskB_1" },
 {"uint32" , "EffectSpellClassMaskB_2" },
 {"uint32" , "EffectSpellClassMaskB_3" },
 {"uint32" , "EffectSpellClassMaskC_1" },
 {"uint32" , "EffectSpellClassMaskC_2" },
 {"uint32" , "EffectSpellClassMaskC_3" },
 {"uint32" , "SpellVisualID_1"},
 {"uint32" , "SpellVisualID_2"},
 {"uint32" ,"SpellIconID"},
 {"uint32" , "ActiveIconID"},
 {"uint32" , "SpellPriority"},
 {"char*" , "Name_Lang_enUS"},
 {"char*" , "Name_Lang_enGB"},
 {"char*" , "Name_Lang_koKR"},
 {"char*" , "Name_Lang_frFR"},
 {"char*" , "Name_Lang_deDE"},
 {"char*" , "Name_Lang_enCN"},
 {"char*" , "Name_Lang_zhCN"},
 {"char*" , "Name_Lang_enTW"},
 {"char*" , "Name_Lang_zhTW"},
 {"char*" , "Name_Lang_esES"},
 {"char*" , "Name_Lang_esMX"},
 {"char*" , "Name_Lang_ruRU"},
 {"char*" , "Name_Lang_ptPT"},
 {"char*" , "Name_Lang_ptBR"},
 {"char*" , "Name_Lang_itIT"},
 {"char*" , "Name_Lang_Unk"},
 {"uint32" , "Name_Lang_Mask"},
 {"char*" ,"NameSubtext_Lang_enUS"},
 {"char*" , "NameSubtext_Lang_enGB"},
 {"char*" , "NameSubtext_Lang_koKR"},
 {"char*" , "NameSubtext_Lang_frFR"},
 {"char*" , "NameSubtext_Lang_deDE"},
 {"char*" , "NameSubtext_Lang_enCN"},
 {"char*" , "NameSubtext_Lang_zhCN"},
 {"char*" , "NameSubtext_Lang_enTW"},
 {"char*" , "NameSubtext_Lang_zhTW"},
 {"char*" , "NameSubtext_Lang_esES"},
 {"char*" ,"NameSubtext_Lang_esMX"},
 {"char*" ,"NameSubtext_Lang_ruRU"},
 {"char*" ,"NameSubtext_Lang_ptPT"},
 {"char*" ,"NameSubtext_Lang_ptBR"},
 {"char*" ,"NameSubtext_Lang_itIT"},
 {"char*" ,"NameSubtext_Lang_Unk"},
 {"uint32" , "NameSubtext_Lang_Mask"},
 {"char*" , "Description_Lang_enUS"},
 {"char*" , "Description_Lang_enGB"},
 {"char*" , "Description_Lang_koKR"},
 {"char*" , "Description_Lang_frFR"},
 {"char*" , "Description_Lang_deDE"},
 {"char*" , "Description_Lang_enCN"},
 {"char*" , "Description_Lang_zhCN"},
 {"char*" , "Description_Lang_enTW"},
 {"char*" ,"Description_Lang_zhTW"},
 {"char*" , "Description_Lang_esES"},
 {"char*" , "Description_Lang_esMX"},
 {"char*" , "Description_Lang_ruRU"},
 {"char*" , "Description_Lang_ptPT"},
 {"char*" , "Description_Lang_ptBR"},
 {"char*" , "Description_Lang_itIT"},
 {"char*" , "Description_Lang_Unk"},
 {"uint32" , "Description_Lang_Mask"},
 {"char*" , "AuraDescription_Lang_enUS"},
 {"char*" , "AuraDescription_Lang_enGB"},
 {"char*" , "AuraDescription_Lang_koKR"},
 {"char*" , "AuraDescription_Lang_frFR"},
 {"char*" , "AuraDescription_Lang_deDE"},
 {"char*" , "AuraDescription_Lang_enCN"},
 {"char*" , "AuraDescription_Lang_zhCN"},
 {"char*" , "AuraDescription_Lang_enTW"},
 {"char*" , "AuraDescription_Lang_zhTW"},
 {"char*" , "AuraDescription_Lang_esES"},
 {"char*" , "AuraDescription_Lang_esMX"},
 {"char*" , "AuraDescription_Lang_ruRU"},
 {"char*" , "AuraDescription_Lang_ptPT"},
 {"char*" , "AuraDescription_Lang_ptBR"},
 {"char*" , "AuraDescription_Lang_itIT"},
 {"char*" , "AuraDescription_Lang_Unk"},
 {"uint32" , "AuraDescription_Lang_Mask"},
 {"uint32" , "ManaCostPct" },
 {"uint32" , "StartRecoveryCategory"},
 {"uint32" , "StartRecoveryTime"},
 {"uint32" , "MaxTargetLevel"},
 {"uint32" , "SpellClassSet"},
 {"uint32" , "SpellClassMask_1" },
 {"uint32" , "SpellClassMask_2" },
 {"uint32" , "SpellClassMask_3" },
 {"uint32" , "MaxTargets"},
 {"uint32" , "DefenseType" },
 {"uint32" , "PreventionType"},
 {"uint32" , "StanceBarOrder"},
 {"float" , "EffectChainAmplitude_1"},
 {"float" , "EffectChainAmplitude_2"},
 {"float" , "EffectChainAmplitude_3"},
 {"uint32" , "MinFactionID"},
 {"uint32" , "MinReputation"},
 {"uint32" , "RequiredAuraVision"},
 {"uint32" , "RequiredTotemCategoryID_1"},
 {"uint32" , "RequiredTotemCategoryID_2"},
 {"int32" , "RequiredAreasID"},
 {"uint32" , "SchoolMask"},
 {"uint32" , "RuneCostID"},
 {"uint32" , "SpellMissileID"},
 {"int32" , "PowerDisplayID"},
 {"float" , "Field227"},
 {"float" , "Field228"},
 {"float" , "Field229"},
 {"uint32" , "SpellDescriptionVariableID" },
 {"uint32" , "SpellDifficultyID"},
};

char const *SPELL_TABLE_INDEX = spell_translation[0][1];

#endif

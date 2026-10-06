#include "addrs.h"

size_t g_baseAddress;
size_t dwGameSignature;
GameVersion dwGameVersion;

//Gloval variables=================================================================
int* __dwCurrentEpisode;
int* pDword_F0EBC4;
char* pByte_109B225;
CText* g_text;
CGameConfigReader** g_pGameConfigReader;
int* pDword_109823C;
int* pDword_1098240;
int* pDword_1098244;
int* pDword_1098248;
int* pDword_1098238;
int* pDword_109824C;
int* pDword_1098494;
int* pDword_1098498;
int* pDword_109849C;
int* pDword_10984A0;
int* pDword_1098490;
int* pDword_10984A4;
char* pByte_10984A8;
int* pDword_F0EC4C;
_RTL_CRITICAL_SECTION* pStru_10A1320;
CRenderer* g_pRenderer;
char* pByte_109A158;
char* pByte_109A958;
int* pDword_109B21C;
int* pDword_109B220;
void* off_109B2CC;
int* pDword_10986E8;
pgDictionary<grcTexture>** CTxdStore::ms_Current;
int* pDword_1098940;
char* pByte_1098700;
int* dwCurrentLanguage;
int* dwGameLanguage;
int* filterSaveSettings;
char* pByte_104D7C8;
char* pByte_F07ED4;
__int64* pQword_104DE2C;
char* pByte_F07EA4;
int* grcTexturePC__ms_dwTextureQuality;
int* pDword_104DDE0;
int* pDword_104DDE4;
int* pDword_104DDE8;
int* pDword_104DDEC;
int* pDword_104DDF0;
int* pDword_104DDF4;
int* pDword_104DDF8;
int* pDword_104DDFC;
int* pDword_104DE00;
int* pDword_104DE04;
int* pDword_104DB98;
const char* pszPath;
char* pByte_104DE83;

size_t sub_7C5D70_lea;
size_t sub_7C5D70_mov;
size_t _loadSettings_dwCurrentLanguage_1;
size_t _loadSettings_dwCurrentLanguage_2;
size_t cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_1;
size_t cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_2;
size_t cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_1;
size_t cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_2;
size_t cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_3;

size_t cRadar_writeBlipSaveData_jp_condition;
size_t cRadar_readBlipSaveData_jp_condition;

size_t cVehicleModelInfo_initVehData_nulltex;


//Functions=================================================================
size_t cText_isJapaneseLang;

size_t cGameConfigReader__FileType_getPrevFile;
size_t cGameConfigReader__FileType_getFileByType;

size_t t_gpDict_Lookup;

size_t cSprite2d_setTexture;
size_t cSprite2d_Delete;

size_t cFontDesc_LoadFontTex;

size_t cTxdStore_loadFile;
size_t cTxdStore_getIndexByName;
size_t cTxdStore_findSlotFromHashKey;
size_t cTxdStore_release;
size_t cTxdStore_releaseEntry;
size_t cTxdStore_pushCurrentTxd;
size_t cTxdStore_addEntry;
size_t cTxdStore_addRef;
size_t cTxdStore_popCurrentTxd;
size_t cTxdStore_atStringHash;
size_t cTxdStore_at;

size_t cAutoLock_constructor;
size_t cAutoLock_destructor;

size_t cRenderer_removeAllTexturesFromDictionary;

size_t f_hashStringLowercaseFromSeed;
size_t f__readFontsDat;
size_t cFont_InitPerFrame;

size_t fiDevice_getDevice;
size_t cPlayer_isSignedLocally;
size_t f_sub_7CAC70;
size_t f_gta_fopen;
size_t f_gta_fread;
size_t f_gta_fclose;
size_t f_sub_4E3150;
size_t f_sub_49C4D0;
size_t f_sub_7C20C0;
size_t f_loadSettings;

size_t cFrontEnd_GetLanguageFromSystemLanguage;
size_t cText_GetLanguageFile;
size_t f_loadFontTextures;

GameVersion getGameVersion()
{
    if (dwGameSignature == FIX_ADDR(0x019AEF44)) dwGameVersion = GameVersion::GTAIV_1070;
    else if (dwGameSignature == FIX_ADDR(0x019D1B04)) dwGameVersion = GameVersion::GTAIV_1080;
    else if (dwGameSignature == FIX_ADDR(0x01928410)) dwGameVersion = GameVersion::EFLC_1120;
    else if (dwGameSignature == FIX_ADDR(0x0194C0EC)) dwGameVersion = GameVersion::EFLC_1130;
    else dwGameVersion = GameVersion::Unknown;
    return dwGameVersion;
}

void initAddrsDynamic()
{
    //Global Variables=================
    __dwCurrentEpisode = *(int**)findPattern("8B 1D ? ? ? ? 83 C4 10 8D 4C 24 10 51 8B 0D ? ? ? ? ", 2);
    pDword_F0EBC4 = *(int**)findPattern("A1 ? ? ? ? 83 F8 FF 75 03 B0 01 C3 ", 1);
    pByte_109B225 = *(char**)findPattern("C6 05 ? ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? E8 ? ? ? ? 8B F8 A0 ? ? ? ? 83 C4 04 3C 72 74 60 3C 6A ", 2);
    g_text = *(CText**)findPattern("B9 ? ? ? ? 89 1D ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? ", 1);
    g_pGameConfigReader = *(CGameConfigReader***)findPattern("8B 35 ? ? ? ? 3B F3 89 1D ? ? ? ? 74 05 E8 ? ? ? ? ", 2);
    pDword_109823C = *(int**)findPattern("D8 B0 ? ? ? ? 59 C3 0F B6 05 ? ? ? ? 69 C0 ? ? ? ? D9 80 ? ? ? ? D8 B0 ? ? ? ? 59 ", 2);
    pDword_1098240 = *(int**)findPattern("F3 0F 5E 98 ? ? ? ? F3 0F 59 CB F3 0F 59 D3 F3 0F 58 CA F3 0F 5C 0D ? ? ? ? F3 0F 58 C8 F3 0F 10 80 ? ? ? ? F3 0F 59 C3 ", 4);
    pDword_1098244 = *(int**)findPattern("F3 0F 59 90 ? ? ? ? 0F 28 DD F3 0F 5E 98 ? ? ? ? F3 0F 59 CB F3 0F 59 D3 F3 0F 58 CA F3 0F 5C 0D ? ? ? ? F3 0F 58 C8 ", 4);
    pDword_1098248 = *(int**)findPattern("F3 0F 10 80 ? ? ? ? F3 0F 59 C3 F3 0F 58 C2 0F 2F E8 77 03 0F 28 C5 ", 4);
    pDword_1098238 = *(int**)findPattern("8B 88 ? ? ? ? 6A 01 51 E8 ? ? ? ? 8B 04 B5 ? ? ? ? 8B D6 69 D2 ? ? ? ? 8D BA ? ? ? ? 50 57 E8 ? ? ? ? ", 2);
    pDword_109824C = *(int**)findPattern("F3 0F 10 88 ? ? ? ? 66 C1 EB 04 0F B7 D3 F3 0F 2A D2 F3 0F 5C 15 ? ? ? ? F3 0F 59 90 ? ? ? ? 0F 28 DD F3 0F 5E 98 ? ? ? ? F3 0F 59 CB ", 4);

    pDword_1098494 = *(int**)findPattern("8B 0D ? ? ? ? 6A 33 E8 ? ? ? ? 8B F0 39 AE ? ? ? ? 74 2D 8D A4 24 ? ? ? ? 56 57 E8 ? ? ? ? 8B 0D ? ? ? ? 83 C4 08 56 8A D8 E8 ? ? ? ? 8B F0 39 AE ? ? ? ? 75 DE 84 DB 75 0E 68 ? ? ? ? 57 E8 ? ? ? ? 83", 248);

    pDword_1098498 = *(int**)findPattern("8B 0D ? ? ? ? 6A 33 E8 ? ? ? ? 8B F0 39 AE ? ? ? ? 74 2D 8D A4 24 ? ? ? ? 56 57 E8 ? ? ? ? 8B 0D ? ? ? ? 83 C4 08 56 8A D8 E8 ? ? ? ? 8B F0 39 AE ? ? ? ? 75 DE 84 DB 75 0E 68 ? ? ? ? 57 E8 ? ? ? ? 83", 256);
    pDword_109849C = *(int**)findPattern("8B 0D ? ? ? ? 6A 33 E8 ? ? ? ? 8B F0 39 AE ? ? ? ? 74 2D 8D A4 24 ? ? ? ? 56 57 E8 ? ? ? ? 8B 0D ? ? ? ? 83 C4 08 56 8A D8 E8 ? ? ? ? 8B F0 39 AE ? ? ? ? 75 DE 84 DB 75 0E 68 ? ? ? ? 57 E8 ? ? ? ? 83", 272);
    pDword_10984A0 = *(int**)findPattern("8B 0D ? ? ? ? 6A 33 E8 ? ? ? ? 8B F0 39 AE ? ? ? ? 74 2D 8D A4 24 ? ? ? ? 56 57 E8 ? ? ? ? 8B 0D ? ? ? ? 83 C4 08 56 8A D8 E8 ? ? ? ? 8B F0 39 AE ? ? ? ? 75 DE 84 DB 75 0E 68 ? ? ? ? 57 E8 ? ? ? ? 83", 288);
    pDword_1098490 = *(int**)findPattern("8B 0D ? ? ? ? 6A 33 E8 ? ? ? ? 8B F0 39 AE ? ? ? ? 74 2D 8D A4 24 ? ? ? ? 56 57 E8 ? ? ? ? 8B 0D ? ? ? ? 83 C4 08 56 8A D8 E8 ? ? ? ? 8B F0 39 AE ? ? ? ? 75 DE 84 DB 75 0E 68 ? ? ? ? 57 E8 ? ? ? ? 83", 301);
    pDword_10984A4 = *(int**)findPattern("8B 0D ? ? ? ? 6A 33 E8 ? ? ? ? 8B F0 39 AE ? ? ? ? 74 2D 8D A4 24 ? ? ? ? 56 57 E8 ? ? ? ? 8B 0D ? ? ? ? 83 C4 08 56 8A D8 E8 ? ? ? ? 8B F0 39 AE ? ? ? ? 75 DE 84 DB 75 0E 68 ? ? ? ? 57 E8 ? ? ? ? 83", 309);
    pByte_10984A8 = *(char**)findPattern("8B 0D ? ? ? ? 6A 33 E8 ? ? ? ? 8B F0 39 AE ? ? ? ? 74 2D 8D A4 24 ? ? ? ? 56 57 E8 ? ? ? ? 8B 0D ? ? ? ? 83 C4 08 56 8A D8 E8 ? ? ? ? 8B F0 39 AE ? ? ? ? 75 DE 84 DB 75 0E 68 ? ? ? ? 57 E8 ? ? ? ? 83", 330);
    pDword_F0EC4C = *(int**)findPattern("8B 35 ? ? ? ? 56 E8 ? ? ? ? 83 C4 08 85 C0 74 09 56 E8 ? ? ? ? 83 C4 04 ", 2);
    pStru_10A1320 = *(_RTL_CRITICAL_SECTION**)findPattern("68 ? ? ? ? 8D 4C 24 3C E8 ? ? ? ? 39 5D 0C 0F 84 ? ? ? ? 8B 0D ? ? ? ? E8 ? ? ? ? 8B F0 ", 1);
    g_pRenderer = *(CRenderer**)findPattern("B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 85 C0 74 0B 8B 10 8B C8 8B 42 08 6A 01 FF D0 ", 1);
    pByte_109A158 = *(char**)findPattern("8D B8 ? ? ? ? 8B 04 B5 ? ? ? ? 3B C7 0F 84 ? ? ? ? 80 3D ? ? ? ? ? 0F 85 ? ? ? ? 8B 0D ? ? ? ? ", 2);
    pByte_109A958 = *(char**)findPattern("C7 05 ? ? ? ? ? ? ? ? EB B6 ", 6);
    pDword_109B21C = *(int**)findPattern("89 34 85 ? ? ? ? A1 ? ? ? ? 8B 14 81 8B 82 ? ? ? ? D1 E8 A8 01 5E ", 3);
    pDword_109B220 = *(int**)findPattern("C7 05 ? ? ? ? ? ? ? ? 75 0A B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? E8 ? ? ? ? 83 CD FF 55 8B F0 89 3D ? ? ? ? ", 2);
    off_109B2CC = *(void**)findPattern("B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? E8 ? ? ? ? 83 CD FF 55 8B F0 ", 1);
    pDword_10986E8 = *(int**)findPattern("89 3D ? ? ? ? E8 ? ? ? ? 56 E8 ? ? ? ? 56 E8 ? ? ? ? 68 ? ? ? ? E8 ? ? ? ? 8B F8 ", 2);
    CTxdStore::ms_Current = *(pgDictionary<grcTexture>***)findPattern("8B 3D ? ? ? ? 6A 00 50 8B F1 E8 ? ? ? ? 83 C4 08 50 8B CF ", 2);
    pDword_1098940 = *(int**)findPattern("C7 05 ? ? ? ? ? ? ? ? E8 ? ? ? ? 83 C4 04 85 C0 74 0F 56 E8 ? ? ? ? 8B 35 ? ? ? ? 83 C4 04 ", 2);
    pByte_1098700 = *(char**)findPattern("B9 ? ? ? ? E8 ? ? ? ? 6A 03 E8 ? ? ? ? 83 C4 04 89 35 ? ? ? ? E8 ? ? ? ? 8B 8C 24 ? ? ? ? 5E 5B 5F 5D 33 CC ", 1);
    dwCurrentLanguage = *(int**)findPattern("8B 0D ? ? ? ? 33 C0 3B 0D ? ? ? ? 0F 95 C0 C3 ", 2);
    dwGameLanguage = *(int**)findPattern("89 0D ? ? ? ? A3 ? ? ? ? A3 ? ? ? ? 75 5D 84 1D ? ? ? ? ", 2);
    filterSaveSettings = *(int**)findPattern("BF ? ? ? ? BB ? ? ? ? F3 AB 89 1D ? ? ? ? 0F 85 ? ? ? ? E8 ? ? ? ? ", 1);
    pByte_104D7C8 = *(char**)findPattern("80 3D ? ? ? ? ? 74 3A 0F BF 46 2E ", 2);
    pByte_F07ED4 = *(char**)findPattern("68 ? ? ? ? 8B CF E8 ? ? ? ? 8B 04 9D ? ? ? ? 85 C0 ", 1);
    pQword_104DE2C = *(__int64**)findPattern("66 0F D6 05 ? ? ? ? F3 0F 7E 84 24 ? ? ? ? 50 ", 4);
    pByte_F07EA4 = *(char**)findPattern("A0 ? ? ? ? 68 ? ? ? ? 51 ", 1);
    grcTexturePC__ms_dwTextureQuality = *(int**)findPattern("8B 15 ? ? ? ? A1 ? ? ? ? 8B 0D ? ? ? ? 89 54 24 3C 8B 15 ? ? ? ? ", 2);
    pDword_104DDE0 = *(int**)findPattern("A1 ? ? ? ? 8B 0D ? ? ? ? 89 54 24 3C 8B 15 ? ? ? ? ", 1);
    pDword_104DDE4 = *(int**)findPattern("8B 0D ? ? ? ? 89 54 24 3C 8B 15 ? ? ? ? ", 2);
    pDword_104DDE8 = *(int**)findPattern("8B 15 ? ? ? ? 89 44 24 48 A1 ? ? ? ? 83 C4 0C ", 2);
    pDword_104DDEC = *(int**)findPattern("C7 05 ? ? ? ? ? ? ? ? 89 1D ? ? ? ? 89 35 ? ? ? ? 89 35 ? ? ? ? ", 2);
    pDword_104DDF0 = *(int**)findPattern("89 35 ? ? ? ? 89 35 ? ? ? ? 89 5C 24 14 8B 08 ", 2);
    pDword_104DDF4 = *(int**)findPattern("89 35 ? ? ? ? 89 5C 24 14 8B 08 52 50 8B 41 18 ", 2);
    pDword_104DDF8 = *(int**)findPattern("8B 15 ? ? ? ? 8D 44 24 40 50 B9 ? ? ? ? ", 2);
    pDword_104DDFC = *(int**)findPattern("A1 ? ? ? ? 83 C4 0C 89 4C 24 34 89 54 24 38 89 44 24 18 ", 1);
    pDword_104DE00 = *(int**)findPattern("A1 ? ? ? ? 83 C0 FF 33 C9 85 C0 0F 9C C1 ", 1);
    pDword_104DE04 = *(int**)findPattern("89 0D ? ? ? ? C7 05 ? ? ? ? ? ? ? ? 89 35 ? ? ? ? C7 05 ? ? ? ? ? ? ? ? ", 2);
    pDword_104DB98 = *(int**)findPattern("89 3C 85 ? ? ? ? 83 C0 01 3D ? ? ? ? 76 E8 ", 3);
    pszPath = *(const char**)findPattern("C6 05 ? ? ? ? ? E8 ? ? ? ? 83 C4 04 84 C0 74 19 ", 2);

    cVehicleModelInfo_initVehData_nulltex = findPattern("E8 ? ? ? ? 8B 4C 24 ? 8B 01 8B 50 10 FF D2", 5);


    switch (dwGameVersion)//Назначение адреса переменным в зависимости от патчей
    {
    case GameVersion::GTAIV_1070:
        pByte_104DE83 = (char*)FIX_ADDR(0x010C7CD3);
        break;
    case GameVersion::GTAIV_1080:
        pByte_104DE83 = (char*)FIX_ADDR(0x010FC3A3);
        break;
    case GameVersion::EFLC_1120:
        pByte_104DE83 = (char*)FIX_ADDR(0x0104DE83);
        break;
    case GameVersion::EFLC_1130:
        pByte_104DE83 = (char*)FIX_ADDR(0x0106A393);
        break;
    }

    sub_7C5D70_lea = findPattern("8D 6F 01 74 05 BD ? ? ? ? 03 5C 24 10 3B DD 7C 63 83 FF 65 74 59 33 DB ", 2);
    sub_7C5D70_mov = findPattern("BD ? ? ? ? 03 5C 24 10 3B DD 7C 63 83 FF 65 74 59 33 DB ", 1);

    cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_1 = findPattern("C7 05 ? ? ? ? ? ? ? ? 80 3D ? ? ? ? ? 74 0F B8 ? ? ? ? A3 ? ? ? ? A3 ? ? ? ? ", 0);
    cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_2 = findPattern("B8 ? ? ? ? A3 ? ? ? ? A3 ? ? ? ? 68 ? ? ? ? 8B CE E8 ? ? ? ? 84 C0 74 11 68 ? ? ? ? 8B CE E8 ? ? ? ? A3 ? ? ? ? ", 0);
    cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_1 = findPattern("89 2D ? ? ? ? EB 16 3B C5 EB 0A ", 0);
    cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_2 = findPattern("89 1D ? ? ? ? 55 E8 ? ? ? ? 83 C4 04 80 3D ? ? ? ? ? 74 0F 55 89 3D ? ? ? ? E8 ? ? ? ? 83 C4 04 ", 0);
    cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_3 = findPattern("89 3D ? ? ? ? E8 ? ? ? ? 83 C4 04 8B 15 ? ? ? ? 3B 15 ? ? ? ? 0F 84 ? ? ? ? 80 3D ? ? ? ? ? 0F 84 ? ? ? ? 55 B9 ? ? ? ? ", 0);

    cRadar_writeBlipSaveData_jp_condition = findPattern("74 37 80 3D ? ? ? ? ? 75 2E 8D 8C 24 ? ? ? ? 51 8D 56 60 52 66 C7 86 ? ? ? ? ? ? ", 0);// old 83 C4 30 80 3D ? ? ? ? 6A 74 37 80 3D ? ? ? ? 00 75 2E 8D 8C 24 BC
    cRadar_readBlipSaveData_jp_condition = findPattern("74 37 80 3D ? ? ? ? ? 75 2E 8D 84 24 ? ? ? ? 6A 1E 50 E8 ? ? ? ? ", 0);//old 83 C4 30 80 3D ? ? ? ? 6A 74 37 80 3D ? ? ? ? 00 75 2E 8D 84 24 BC|

    //Functions=================
    cText_isJapaneseLang = findPattern("E8 ? ? ? ? 84 C0 75 04 6A 07 ", 0);
    cText_isJapaneseLang = getFnAddrInCallOpcode(cText_isJapaneseLang);

    cGameConfigReader__FileType_getPrevFile = findPattern("E8 ? ? ? ? 83 B8 ? ? ? ? ? B9 ? ? ? ? 0F 45 C8 ", 0);
    cGameConfigReader__FileType_getPrevFile = getFnAddrInCallOpcode(cGameConfigReader__FileType_getPrevFile);

    cGameConfigReader__FileType_getFileByType = findPattern("E8 ? ? ? ? 8B F0 39 BE ? ? ? ? 74 31 8D 49 00 ", 0);
    cGameConfigReader__FileType_getFileByType = getFnAddrInCallOpcode(cGameConfigReader__FileType_getFileByType);

    t_gpDict_Lookup = findPattern("E8 ? ? ? ? F3 0F 10 94 37 ? ? ? ? F3 0F 10 35 ? ? ? ? F3 0F 2A A4 37 ? ? ? ? ", 0);
    t_gpDict_Lookup = getFnAddrInCallOpcode(t_gpDict_Lookup);

    cSprite2d_setTexture = findPattern("E8 ? ? ? ? 66 A1 ? ? ? ? 8B 15 ? ? ? ? 0F B7 C8 66 05 01 00 66 A3 ? ? ? ? 8B 44 24 0C ", 0);
    cSprite2d_setTexture = getFnAddrInCallOpcode(cSprite2d_setTexture);

    cSprite2d_Delete = findPattern("E8 ? ? ? ? 83 C6 04 81 FE ? ? ? ? 7C BA ", 0);
    cSprite2d_Delete = getFnAddrInCallOpcode(cSprite2d_Delete);

    cFontDesc_LoadFontTex = findPattern("E8 ? ? ? ? 6A 03 E8 ? ? ? ? 83 C4 04 89 35 ? ? ? ? E8 ? ? ? ? 8B 8C 24 ? ? ? ? 5E 5B 5F 5D 33 CC ", 0);
    cFontDesc_LoadFontTex = getFnAddrInCallOpcode(cFontDesc_LoadFontTex);

    cTxdStore_loadFile = findPattern("E8 ? ? ? ? A1 ? ? ? ? 50 E8 ? ? ? ? 0F 57 C0 F3 0F 10 0D ? ? ? ? F3 0F 10 54 24 ? ", 0);
    cTxdStore_loadFile = getFnAddrInCallOpcode(cTxdStore_loadFile);

    cTxdStore_getIndexByName = findPattern("E8 ? ? ? ? 83 C4 08 6A 00 56 8B F8 E8 ? ? ? ? ", 0);
    cTxdStore_getIndexByName = getFnAddrInCallOpcode(cTxdStore_getIndexByName);

    cTxdStore_findSlotFromHashKey = findPattern("E8 ? ? ? ? 8B 4C 24 14 6A 00 6A 70 68 ? ? ? ? ", 0);
    cTxdStore_findSlotFromHashKey = getFnAddrInCallOpcode(cTxdStore_findSlotFromHashKey);

    cTxdStore_release = findPattern("E8 ? ? ? ? 56 E8 ? ? ? ? 68 ? ? ? ? E8 ? ? ? ? 8B F8 A0 ? ? ? ? 83 C4 14 ", 0);
    cTxdStore_release = getFnAddrInCallOpcode(cTxdStore_release);

    cTxdStore_releaseEntry = findPattern("E8 ? ? ? ? 83 C4 08 5F C6 05 ? ? ? ? ? 5E ", 0);
    cTxdStore_releaseEntry = getFnAddrInCallOpcode(cTxdStore_releaseEntry);

    cTxdStore_pushCurrentTxd = findPattern("E8 ? ? ? ? 57 E8 ? ? ? ? 83 C4 04 BE ? ? ? ? 8D 9B ? ? ? ? ", 0);
    cTxdStore_pushCurrentTxd = getFnAddrInCallOpcode(cTxdStore_pushCurrentTxd);

    cTxdStore_addEntry = findPattern("E8 ? ? ? ? 83 C4 04 8B F8 56 57 ", 0);
    cTxdStore_addEntry = getFnAddrInCallOpcode(cTxdStore_addEntry);

    cTxdStore_addRef = findPattern("E8 ? ? ? ? 83 C4 0C E8 ? ? ? ? 57 E8 ? ? ? ? 83 C4 04 BE ? ? ? ? 8D 9B ? ? ? ? ", 0);
    cTxdStore_addRef = getFnAddrInCallOpcode(cTxdStore_addRef);

    cTxdStore_popCurrentTxd = findPattern("E8 ? ? ? ? E8 ? ? ? ? 84 C0 75 15 53 ", 0);
    cTxdStore_popCurrentTxd = getFnAddrInCallOpcode(cTxdStore_popCurrentTxd);

    cTxdStore_atStringHash = findPattern("E8 ? ? ? ? 0F B7 77 0C 83 C4 08 33 C9 ", 0);
    cTxdStore_atStringHash = getFnAddrInCallOpcode(cTxdStore_atStringHash);

    cTxdStore_at = findPattern("E8 ? ? ? ? 8B F8 8B 44 24 18 6A 00 50 E8 ? ? ? ? 83 C4 14 ", 0);
    cTxdStore_at = getFnAddrInCallOpcode(cTxdStore_at);

    cAutoLock_constructor = findPattern("E8 ? ? ? ? 8B 8F ? ? ? ? 8B 97 ? ? ? ? 8B 87 ? ? ? ? 51 ", 0);
    cAutoLock_constructor = getFnAddrInCallOpcode(cAutoLock_constructor);

    cAutoLock_destructor = findPattern("E8 ? ? ? ? 8B 16 8B 02 8B 3D ? ? ? ? 6A 00 8B CE FF D0 ", 0);
    cAutoLock_destructor = getFnAddrInCallOpcode(cAutoLock_destructor);

    cRenderer_removeAllTexturesFromDictionary = findPattern("E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 85 C0 ", 0);
    cRenderer_removeAllTexturesFromDictionary = getFnAddrInCallOpcode(cRenderer_removeAllTexturesFromDictionary);

    f__readFontsDat = findPattern("E8 ? ? ? ? 83 C4 04 89 35 ? ? ? ? E8 ? ? ? ? 8B 8C 24 ? ? ? ? 5E 5B 5F 5D 33 CC ", 0);
    f__readFontsDat = getFnAddrInCallOpcode(f__readFontsDat);

    cFont_InitPerFrame = findPattern("E8 ? ? ? ? 8B 35 ? ? ? ? F3 0F 2A 86 ? ? ? ? F3 0F 59 86 ? ? ? ? A1 ? ? ? ? 3B C5 F3 0F 2C C8 F3 0F 2A C1 ", 0);
    cFont_InitPerFrame = getFnAddrInCallOpcode(cFont_InitPerFrame);


    //_loadSettings
    fiDevice_getDevice = findPattern("83 EC 08 53 8B 5C 24 10 6A 07 68 ? ? ? ? ", 0);

    cPlayer_isSignedLocally = findPattern("E8 ? ? ? ? 84 C0 0F 84 ? ? ? ? 8B 94 24 ? ? ? ? 8B 84 24 ? ? ? ? 8B 8C 24 ? ? ? ? ", 0);
    cPlayer_isSignedLocally = getFnAddrInCallOpcode(cPlayer_isSignedLocally);

    f_sub_7CAC70 = findPattern("E8 ? ? ? ? 68 ? ? ? ? 68 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? 8B F8 E8 ? ? ? ? 83 C4 14 ", 0);
    f_sub_7CAC70 = getFnAddrInCallOpcode(f_sub_7CAC70);

    f_gta_fopen = findPattern("E8 ? ? ? ? 83 C4 10 3B C3 75 7A 68 ? ? ? ? ", 0);
    f_gta_fopen = getFnAddrInCallOpcode(f_gta_fopen);

    f_gta_fread = findPattern("E8 ? ? ? ? 8B 0D ? ? ? ? 8B 15 ? ? ? ? 83 C4 0C ", 0);
    f_gta_fread = getFnAddrInCallOpcode(f_gta_fread);

    f_gta_fclose = findPattern("E8 ? ? ? ? 83 C4 1C 56 FF 15 ? ? ? ? EB 09 ", 0);
    f_gta_fclose = getFnAddrInCallOpcode(f_gta_fclose);

    f_sub_4E3150 = findPattern("E8 ? ? ? ? 85 C0 74 13 80 3D ? ? ? ? ? ", 0);
    f_sub_4E3150 = getFnAddrInCallOpcode(f_sub_4E3150);

    f_sub_49C4D0 = findPattern("E8 ? ? ? ? 83 C4 04 68 ? ? ? ? 8B CE E8 ? ? ? ? 85 C0 0F 95 C0 50 E8 ? ? ? ? ", 0);
    f_sub_49C4D0 = getFnAddrInCallOpcode(f_sub_49C4D0);

    f_sub_7C20C0 = findPattern("E8 ? ? ? ? 83 C4 04 80 3D ? ? ? ? ? 74 0F 55 89 3D ? ? ? ? ", 0);
    f_sub_7C20C0 = getFnAddrInCallOpcode(f_sub_7C20C0);

    f_loadSettings = findPattern("E8 ? ? ? ? 84 C0 74 16 A1 ? ? ? ? 83 E8 01 ", 0);
    f_loadSettings = getFnAddrInCallOpcode(f_loadSettings);
    //==============


    cFrontEnd_GetLanguageFromSystemLanguage = findPattern("E8 ? ? ? ? 39 35 ? ? ? ? 8B 0D ? ? ? ? 89 0D ? ? ? ? A3 ? ? ? ? A3 ? ? ? ? ", 0);
    cFrontEnd_GetLanguageFromSystemLanguage = getFnAddrInCallOpcode(cFrontEnd_GetLanguageFromSystemLanguage);

    cText_GetLanguageFile = findPattern("E8 ? ? ? ? 8B C8 8D 9B ? ? ? ? 8A 10 83 C0 01 ", 0);

    f_loadFontTextures = findPattern("E8 ? ? ? ? 8B 0D ? ? ? ? C6 05 ? ? ? ? ? 89 0D ? ? ? ? ", 0);
    f_loadFontTextures = getFnAddrInCallOpcode(f_loadFontTextures);
}
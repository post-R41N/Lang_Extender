#include "addrs.h"

size_t g_baseAddress;

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
int* __dwCurrentLanguage;

size_t sub_7C5D70_lea;
size_t sub_7C5D70_mov;
size_t _loadSettings_dwCurrentLanguage_1;
size_t _loadSettings_dwCurrentLanguage_2;
size_t cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_1;
size_t cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_2;
size_t cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_1;
size_t cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_2;
size_t cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_3;

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
size_t f_sub_814AA0;

size_t cFrontEnd_GetLanguageFromSystemLanguage;
size_t cText_GetLanguageFile;
size_t f_loadFontTextures;

void initAddrsDynamic()
{
    //Global Variables=================
    __dwCurrentEpisode = *(int**)findPattern("8B 1D ? ? ? ? 83 C4 10 8D 4C 24 10 ", 2);
    pDword_F0EBC4 = *(int**)findPattern("A1 ? ? ? ? 83 F8 FF 75 03 B0 01 ", 1);
    pByte_109B225 = *(char**)findPattern("C6 05 ? ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? E8 ? ? ? ? 8B F8 ", 2);
    g_text = *(CText**)findPattern("B9 ? ? ? ? 89 1D ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? ", 1);
    g_pGameConfigReader = *(CGameConfigReader***)findPattern("8B 35 ? ? ? ? 3B F3 89 1D ? ? ? ? 74 05 ", 2);
    pDword_109823C = *(int**)findPattern("D8 B0 ? ? ? ? 59 C3 0F B6 05 ? ? ? ? ", 2);
    pDword_1098240 = *(int**)findPattern("F3 0F 5E 98 ? ? ? ? F3 0F 59 CB F3 0F 59 D3 ", 4);
    pDword_1098244 = *(int**)findPattern("F3 0F 59 90 ? ? ? ? 0F 28 DD F3 0F 5E 98 ? ? ? ? ", 4);
    pDword_1098248 = *(int**)findPattern("F3 0F 10 80 ? ? ? ? F3 0F 59 C3 F3 0F 58 C2 ", 4);
    pDword_1098238 = *(int**)findPattern("8B 88 ? ? ? ? 6A 01 51 E8 ? ? ? ? ", 2);
    pDword_109824C = *(int**)findPattern("F3 0F 10 88 ? ? ? ? 66 C1 EB 04 0F B7 D3 ", 4);
    pDword_1098494 = *(int**)findPattern("F3 0F 11 05 ? ? ? ? F3 0F 11 05 ? ? ? ? F3 0F 10 05 ? ? ? ? F3 0F 11 05 ? ? ? ? F3 0F 10 05 ? ? ? ? F3 0F 11 05 ? ? ? ? F3 0F 10 05 ? ? ? ? A3 ? ? ? ? ", 4);
    pDword_1098498 = *(int**)findPattern("F3 0F 11 05 ? ? ? ? F3 0F 10 05 ? ? ? ? F3 0F 11 05 ? ? ? ? F3 0F 10 05 ? ? ? ? F3 0F 11 05 ? ? ? ? F3 0F 10 05 ? ? ? ? A3 ? ? ? ? ", 4);
    pDword_109849C = *(int**)findPattern("F3 0F 11 05 ? ? ? ? F3 0F 10 05 ? ? ? ? F3 0F 11 05 ? ? ? ? F3 0F 10 05 ? ? ? ? A3 ? ? ? ? ", 4);
    pDword_10984A0 = *(int**)findPattern("F3 0F 11 05 ? ? ? ? F3 0F 10 05 ? ? ? ? A3 ? ? ? ? F3 0F 11 05 ? ? ? ? 74 09 ", 4);
    pDword_1098490 = *(int**)findPattern("89 3D ? ? ? ? 89 3D ? ? ? ? E8 ? ? ? ? 56 ", 2);
    pDword_10984A4 = *(int**)findPattern("F3 0F 11 05 ? ? ? ? 74 09 80 3D ? ? ? ? ? 74 0F ", 4);
    pByte_10984A8 = *(char**)findPattern("B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? E8 ? ? ? ? 8B F0 ", 1);
    pDword_F0EC4C = *(int**)findPattern("8B 35 ? ? ? ? 56 E8 ? ? ? ? 83 C4 08 ", 2);
    pStru_10A1320 = *(_RTL_CRITICAL_SECTION**)findPattern("68 ? ? ? ? 8D 4C 24 3C E8 ? ? ? ? 39 5D 0C ", 1);
    g_pRenderer = *(CRenderer**)findPattern("B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 85 C0 ", 1);
    pByte_109A158 = *(char**)findPattern("8D B8 ? ? ? ? 8B 04 B5 ? ? ? ? 3B C7 ", 2);
    pByte_109A958 = *(char**)findPattern("C7 05 ? ? ? ? ? ? ? ? EB B6 ", 6);
    pDword_109B21C = *(int**)findPattern("89 34 85 ? ? ? ? A1 ? ? ? ? 8B 14 81 8B 82 ? ? ? ? ", 3);
    pDword_109B220 = *(int**)findPattern("C7 05 ? ? ? ? ? ? ? ? 75 0A B9 ? ? ? ? ", 2);
    off_109B2CC = *(void**)findPattern("B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? E8 ? ? ? ? 83 CD FF 55 8B F0 ", 1);
    pDword_10986E8 = *(int**)findPattern("89 3D ? ? ? ? E8 ? ? ? ? 56 ", 2);
    CTxdStore::ms_Current = *(pgDictionary<grcTexture>***)findPattern("8B 3D ? ? ? ? 6A 00 50 8B F1 E8 ? ? ? ? 83 C4 08 ", 2);
    pDword_1098940 = *(int**)findPattern("C7 05 ? ? ? ? ? ? ? ? E8 ? ? ? ? 83 C4 04 85 C0 ", 2);
    pByte_1098700 = *(char**)findPattern("B9 ? ? ? ? E8 ? ? ? ? 6A 03 E8 ? ? ? ? 83 C4 04 ", 1);
    __dwCurrentLanguage = *(int**)findPattern("8B 0D ? ? ? ? 33 C0 3B 0D ? ? ? ? 0F 95 C0 ", 2);

    sub_7C5D70_lea = findPattern("8D 6F 01 74 05 BD ? ? ? ? 03 5C 24 10 3B DD 7C 63 83 FF 65 74 59 33 DB ", 2);
    sub_7C5D70_mov = findPattern("BD ? ? ? ? 03 5C 24 10 3B DD 7C 63 83 FF 65 74 59 33 DB 83 FF 67 74 10 83 FF 68 74 0B ", 1);
    _loadSettings_dwCurrentLanguage_1 = findPattern("89 1D ? ? ? ? E8 ? ? ? ? 83 C4 04 38 1D ? ? ? ? C6 05 ? ? ? ? ? 74 1B 38 1D ? ? ? ? C7 05 ? ? ? ? ? ? ? ? ", 0);
    _loadSettings_dwCurrentLanguage_2 = findPattern("C7 05 ? ? ? ? ? ? ? ? 74 09 53 E8 ? ? ? ? 83 C4 04 ", 0);
    cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_1 = findPattern("C7 05 ? ? ? ? ? ? ? ? 80 3D ? ? ? ? ? 74 0F B8 ? ? ? ? A3 ? ? ? ? A3 ? ? ? ? ", 0);
    cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_2 = findPattern("B8 ? ? ? ? A3 ? ? ? ? A3 ? ? ? ? 68 ? ? ? ? 8B CE E8 ? ? ? ? 84 C0 74 11 68 ? ? ? ? 8B CE E8 ? ? ? ? A3 ? ? ? ? ", 0);
    cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_1 = findPattern("89 2D ? ? ? ? EB 16 3B C5 EB 0A ", 0);
    cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_2 = findPattern("89 1D ? ? ? ? 55 E8 ? ? ? ? 83 C4 04 80 3D ? ? ? ? ? 74 0F 55 89 3D ? ? ? ? E8 ? ? ? ? 83 C4 04 ", 0);
    cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_3 = findPattern("89 3D ? ? ? ? E8 ? ? ? ? 83 C4 04 8B 15 ? ? ? ? 3B 15 ? ? ? ? 0F 84 ? ? ? ? 80 3D ? ? ? ? ? 0F 84 ? ? ? ? 55 B9 ? ? ? ? ", 0);

    //Functions=================
    cText_isJapaneseLang = findPattern("80 B9 ? ? ? ? ? 74 0C 80 B9 ? ? ? ? ? 75 03 32 C0 C3 ", 0);

    cGameConfigReader__FileType_getPrevFile = findPattern("0F B7 51 04 56 8B 74 24 08 8B 86 ? ? ? ? 85 C0 57 7D 04 33 C0 EB 06 ", 0);
    cGameConfigReader__FileType_getFileByType = findPattern("55 8B EC 83 E4 F8 81 EC ? ? ? ? A1 ? ? ? ? 33 C4 89 84 24 ? ? ? ? 0F B7 41 04 8B 55 08 ", 0);

    t_gpDict_Lookup = findPattern("53 55 8B 6C 24 0C 56 57 EB 06 8D 9B 00 00 00 00 0F B7 51 14 33 FF 83 EA 01 78 26 8B 59 10 8B FF ", 0);

    cSprite2d_setTexture = findPattern("83 EC 08 57 8B F9 68 ? ? ? ? 8D 4C 24 08 E8 ? ? ? ? 8B 0F 85 C9 74 38 0F B7 41 0A 66 85 C0 ", 0);
    cSprite2d_Delete = findPattern("83 EC 08 56 8B F1 68 ? ? ? ? 8D 4C 24 08 E8 ? ? ? ? 8B 0E 85 C9 74 38 0F B7 41 0A 66 85 C0 ", 0);

    cFontDesc_LoadFontTex = findPattern("8B 44 24 04 56 57 8B 3D ? ? ? ? 6A 00 50 8B F1 ", 0);

    cTxdStore_loadFile = findPattern("A1 ? ? ? ? 8B 48 04 53 8B 5C 24 08 F6 04 0B 80 ", 0);
    cTxdStore_getIndexByName = findPattern("8B 44 24 04 50 E8 ? ? ? ? 83 C4 04 89 44 24 04 E9 ? ? ? ? ", 0);
    cTxdStore_findSlotFromHashKey = findPattern("8B 54 24 04 83 FA FF 74 32 8B 0D ? ? ? ? 8B 41 04 ", 0);
    cTxdStore_release = findPattern("8B 0D ? ? ? ? 8B 41 04 56 8B 74 24 08 F6 04 06 80 74 04 33 C0 EB 08 8B 41 0C 0F AF C6 03 01 83 40 04 FF 83 78 04 00 7F 1D 8B 0D ? ? ? ? 51 ", 0);
    cTxdStore_releaseEntry = findPattern("8B 0D ? ? ? ? 8B 41 04 56 57 8B 7C 24 0C F6 04 07 80 74 04 33 C0 EB 08 ", 0);
    cTxdStore_pushCurrentTxd = findPattern("A1 ? ? ? ? B9 ? ? ? ? 01 0D ? ? ? ? 85 C0 A3 ? ? ? ? 74 03 01 48 0C C3 ", 0);
    cTxdStore_addEntry = findPattern("8B 0D ? ? ? ? 56 E8 ? ? ? ? 8B F0 8B 44 24 08 50 C7 06 ? ? ? ? C7 46 ? ? ? ? ? E8 ? ? ? ? 8B 0D ? ? ? ? 89 46 08 C7 46 ? ? ? ? ? 8B C6 2B 01 83 C4 04 ", 0);
    cTxdStore_addRef = findPattern("8B 0D ? ? ? ? 8B 41 04 8B 54 24 04 F6 04 02 80 74 07 33 C0 83 40 04 01 C3 8B 41 0C 0F AF C2 03 01 83 40 04 01 C3 ", 0);
    cTxdStore_popCurrentTxd = findPattern("A1 ? ? ? ? 83 2D ? ? ? ? ? 85 C0 8B 0D ? ? ? ? A3 ? ? ? ? 74 09 83 40 0C 01 A1 ? ? ? ? ", 0);
    cTxdStore_atStringHash = findPattern("8B 4C 24 08 56 8B 74 24 08 80 3E 22 0F 94 C2 84 D2 74 03 83 C6 01 ", 0);
    cTxdStore_at = findPattern("8B 0D ? ? ? ? 8B 41 04 8B 54 24 04 F6 04 02 80 74 05 33 C0 8B 00 C3 8B 41 0C 0F AF C2 03 01 8B 00 C3 ", 0);

    cAutoLock_constructor = findPattern("8B 44 24 04 56 8B F1 89 46 04 C7 06 ? ? ? ? 83 38 00 74 07 50 FF 15 ? ? ? ? ", 0);
    cAutoLock_destructor = findPattern("8B 01 85 C0 74 16 83 C0 FF 89 01 75 0F 8B 49 04 83 39 00 74 07 51 FF 15 ? ? ? ? ", 0);

    cRenderer_removeAllTexturesFromDictionary = findPattern("56 8B F1 B9 ? ? ? ? 39 4C 24 08 75 2C 80 3D ? ? ? ? ? 74 23 A1 ? ? ? ? 66 39 48 0A 76 04 66 89 48 0A ", 0);

    f_hashStringLowercaseFromSeed = findPattern("8B 4C 24 08 56 8B 74 24 08 80 3E 22 0F 94 C2 84 D2 74 03 83 C6 01 ", 0);
    f__readFontsDat = findPattern("81 EC ? ? ? ? A1 ? ? ? ? 33 C4 89 84 24 ? ? ? ? A0 ? ? ? ? 53 55 56 57 33 ED 33 DB 83 CF FF 3C 72 89 6C 24 14 C6 44 24 ? ? 74 76 3C 6A 0F 84 ? ? ? ? ", 0);
    f_sub_814AA0 = findPattern("D9 E8 83 EC 08 D9 54 24 04 D9 1C 24 E8 ? ? ? ? B8 ? ? ? ? 50 E8 ? ? ? ? 6A 01 E8 ? ? ? ? 6A 00 E8 ? ? ? ? ", 0);

    cFrontEnd_GetLanguageFromSystemLanguage = findPattern("56 33 F6 FF 15 ? ? ? ? 25 ? ? ? ? 83 C0 F9 83 F8 12 77 2C ", 0);
    cText_GetLanguageFile = findPattern("E8 ? ? ? ? 8B C8 8D 9B ? ? ? ? ", 0);
    f_loadFontTextures = findPattern("81 EC ? ? ? ? A1 ? ? ? ? 33 C4 89 84 24 ? ? ? ? 53 55 56 57 68 ? ? ? ? 8D 4C 24 14 E8 ? ? ? ? 33 FF 57 B9 ? ? ? ? C6 05 ? ? ? ? ? ", 0);
}

void initAddrs()
{
    //__dwCurrentEpisode = (int*)FIX_ADDR(0x10619D8);
    //pDword_F0EBC4 = (int*)FIX_ADDR(0x00F0EBC4);
    //pByte_109B225 = (char*)FIX_ADDR(0x0109B225);
    //g_text = (CText*)FIX_ADDR(0x01058D00);
    //g_pGameConfigReader = (CGameConfigReader**)FIX_ADDR(0x01924E6C);
    //pDword_109823C = (int*)FIX_ADDR(0x0109823C);
    //pDword_1098240 = (int*)FIX_ADDR(0x01098240);
    //pDword_1098244 = (int*)FIX_ADDR(0x01098244);
    //pDword_1098248 = (int*)FIX_ADDR(0x01098248);
    //pDword_1098238 = (int*)FIX_ADDR(0x01098238);
    //pDword_109824C = (int*)FIX_ADDR(0x0109824C);
    //pDword_1098494 = (int*)FIX_ADDR(0x01098494);
    //pDword_1098498 = (int*)FIX_ADDR(0x01098498);
    //pDword_109849C = (int*)FIX_ADDR(0x0109849C);
    //pDword_10984A0 = (int*)FIX_ADDR(0x010984A0);
    //pDword_1098490 = (int*)FIX_ADDR(0x01098490);
    //pDword_10984A4 = (int*)FIX_ADDR(0x010984A4);
    //pByte_10984A8 = (char*)FIX_ADDR(0x010984A8);
    //pDword_F0EC4C = (int*)FIX_ADDR(0x00F0EC4C);
    //pStru_10A1320 = (_RTL_CRITICAL_SECTION*)FIX_ADDR(0x010A1320);
    //g_pRenderer = (CRenderer*)FIX_ADDR(0x01064980);
    //pByte_109A158 = (char*)FIX_ADDR(0x0109A158);
    //pByte_109A958 = (char*)FIX_ADDR(0x0109A958);
    //pDword_109B21C = (int*)FIX_ADDR(0x0109B21C);
    //pDword_109B220 = (int*)FIX_ADDR(0x0109B220);
    //off_109B2CC = (void*)FIX_ADDR(0x0109B2CC);
    //pDword_10986E8 = (int*)FIX_ADDR(0x010986E8);
    //CTxdStore::ms_Current = (pgDictionary<grcTexture>**)FIX_ADDR(0x01924E30);
    //pDword_1098940 = (int*)FIX_ADDR(0x01098940);
    //pByte_1098700 = (char*)FIX_ADDR(0x01098700);
    //__dwCurrentLanguage = (int*)FIX_ADDR(0x0104DC18);
}
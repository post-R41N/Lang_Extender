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
size_t cFont_InitPerFrame;

size_t cFrontEnd_GetLanguageFromSystemLanguage;
size_t cText_GetLanguageFile;
size_t f_loadFontTextures;

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
    pByte_109A958 = *(char**)findPattern("C6 05 ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? EB B6 ", 12);
    pDword_109B21C = *(int**)findPattern("89 34 85 ? ? ? ? A1 ? ? ? ? 8B 14 81 8B 82 ? ? ? ? D1 E8 A8 01 5E ", 3);
    pDword_109B220 = *(int**)findPattern("C7 05 ? ? ? ? ? ? ? ? 75 0A B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? E8 ? ? ? ? 83 CD FF 55 8B F0 89 3D ? ? ? ? ", 2);
    off_109B2CC = *(void**)findPattern("B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? E8 ? ? ? ? 83 CD FF 55 8B F0 ", 1);
    pDword_10986E8 = *(int**)findPattern("89 3D ? ? ? ? E8 ? ? ? ? 56 E8 ? ? ? ? 56 E8 ? ? ? ? 68 ? ? ? ? E8 ? ? ? ? 8B F8 ", 2);
    CTxdStore::ms_Current = *(pgDictionary<grcTexture>***)findPattern("8B 3D ? ? ? ? 6A 00 50 8B F1 E8 ? ? ? ? 83 C4 08 50 8B CF ", 2);
    pDword_1098940 = *(int**)findPattern("C7 05 ? ? ? ? ? ? ? ? E8 ? ? ? ? 83 C4 04 85 C0 74 0F 56 E8 ? ? ? ? 8B 35 ? ? ? ? 83 C4 04 ", 2);
    pByte_1098700 = *(char**)findPattern("B9 ? ? ? ? E8 ? ? ? ? 6A 03 E8 ? ? ? ? 83 C4 04 89 35 ? ? ? ? E8 ? ? ? ? 8B 8C 24 ? ? ? ? 5E 5B 5F 5D 33 CC ", 1);
    __dwCurrentLanguage = *(int**)findPattern("8B 0D ? ? ? ? 33 C0 3B 0D ? ? ? ? 0F 95 C0 C3 ", 2);


    sub_7C5D70_lea = findPattern("8D 6F 01 74 05 BD ? ? ? ? 03 5C 24 10 3B DD 7C 63 83 FF 65 74 59 33 DB ", 2);
    sub_7C5D70_mov = findPattern("BD ? ? ? ? 03 5C 24 10 3B DD 7C 63 83 FF 65 74 59 33 DB ", 1);
    _loadSettings_dwCurrentLanguage_1 = findPattern("89 1D ? ? ? ? E8 ? ? ? ? 83 C4 04 38 1D ? ? ? ? C6 05 ? ? ? ? ? 74 1B 38 1D ? ? ? ? C7 05 ? ? ? ? ? ? ? ? ", 0);
    _loadSettings_dwCurrentLanguage_2 = findPattern("C7 05 ? ? ? ? ? ? ? ? 74 09 53 E8 ? ? ? ? 83 C4 04 5D B0 01 5B 8B 8C 24 ? ? ? ? 33 CC E8 ? ? ? ? 81 C4 ? ? ? ? ", 0);
    cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_1 = findPattern("C7 05 ? ? ? ? ? ? ? ? 80 3D ? ? ? ? ? 74 0F B8 ? ? ? ? A3 ? ? ? ? A3 ? ? ? ? ", 0);
    cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_2 = findPattern("B8 ? ? ? ? A3 ? ? ? ? A3 ? ? ? ? 68 ? ? ? ? 8B CE E8 ? ? ? ? 84 C0 74 11 68 ? ? ? ? 8B CE E8 ? ? ? ? A3 ? ? ? ? ", 0);
    cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_1 = findPattern("89 2D ? ? ? ? EB 16 3B C5 EB 0A ", 0);
    cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_2 = findPattern("89 1D ? ? ? ? 55 E8 ? ? ? ? 83 C4 04 80 3D ? ? ? ? ? 74 0F 55 89 3D ? ? ? ? E8 ? ? ? ? 83 C4 04 ", 0);
    cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_3 = findPattern("89 3D ? ? ? ? E8 ? ? ? ? 83 C4 04 8B 15 ? ? ? ? 3B 15 ? ? ? ? 0F 84 ? ? ? ? 80 3D ? ? ? ? ? 0F 84 ? ? ? ? 55 B9 ? ? ? ? ", 0);

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

    cFrontEnd_GetLanguageFromSystemLanguage = findPattern("E8 ? ? ? ? 39 35 ? ? ? ? 8B 0D ? ? ? ? 89 0D ? ? ? ? A3 ? ? ? ? A3 ? ? ? ? ", 0);
    cFrontEnd_GetLanguageFromSystemLanguage = getFnAddrInCallOpcode(cFrontEnd_GetLanguageFromSystemLanguage);

    cText_GetLanguageFile = findPattern("E8 ? ? ? ? 8B C8 8D 9B ? ? ? ? 8A 10 83 C0 01 ", 0);

    f_loadFontTextures = findPattern("E8 ? ? ? ? 8B 0D ? ? ? ? C6 05 ? ? ? ? ? 89 0D ? ? ? ? ", 0);
    f_loadFontTextures = getFnAddrInCallOpcode(f_loadFontTextures);
}
// dllmain.cpp : Defines the entry point for the DLL application.
#include <windows.h>
#include <stdio.h>
#include "addrs.h"

static void enableConsole()
{
    FILE* pFile = NULL;
    AllocConsole();
    SetConsoleTitleA("DEBUILDER CONSOLE");
    freopen_s(&pFile, "CONOUT$", "w", stdout);
    freopen_s(&pFile, "CONOUT$", "w", stderr);
    freopen_s(&pFile, "CONIN$", "r", stdin);
}

void print_addrs()
{
    printf_s("g_baseAddress: %u\n", g_baseAddress);
    printf_s("dwGameSignature Addr: %p\n", IDA_ADDR(dwGameSignature));

    //printf_s("Patch: %c\n", (const char)dwGameVersionName);
    printf_s("Patch: ");
    switch (dwGameVersion)
    {
    case GameVersion::GTAIV_1070:
        printf_s("GTA IV 1.0.7.0");
        break;
    case GameVersion::GTAIV_1080:
        printf_s("GTA IV 1.0.8.0");
        break;
    case GameVersion::EFLC_1120:
        printf_s("EFLC 1.1.2.0");
        break;
    case GameVersion::EFLC_1130:
        printf_s("EFLC 1.1.3.0");
        break;
    case GameVersion::Unknown:
        printf_s("Unknown");
        break;
    }
    printf_s("\n");

    printf_s("\nGlobal Variables=====================================\n");
    printf_s("__dwCurrentEpisode: 0x%p\n", IDA_ADDR(__dwCurrentEpisode));
    printf_s("pDword_F0EBC4: 0x%p\n", IDA_ADDR(pDword_F0EBC4));
    printf_s("pByte_109B225: 0x%p\n", IDA_ADDR(pByte_109B225));
    printf_s("g_text: 0x%p\n", IDA_ADDR(g_text));
    printf_s("g_pGameConfigReader: 0x%p\n", IDA_ADDR(g_pGameConfigReader));
    printf_s("pDword_109823C: 0x%p\n", IDA_ADDR(pDword_109823C));
    printf_s("pDword_1098240: 0x%p\n", IDA_ADDR(pDword_1098240));
    printf_s("pDword_1098244: 0x%p\n", IDA_ADDR(pDword_1098244));
    printf_s("pDword_1098494: 0x%p\n", IDA_ADDR(pDword_1098494));
    printf_s("pDword_1098498: 0x%p\n", IDA_ADDR(pDword_1098498));
    printf_s("pByte_109A958: 0x%p\n", IDA_ADDR(pByte_109A958));
    printf_s("pDword_109849C: 0x%p\n", IDA_ADDR(pDword_109849C));
    printf_s("pDword_10984A0: 0x%p\n", IDA_ADDR(pDword_10984A0));
    printf_s("pDword_1098490: 0x%p\n", IDA_ADDR(pDword_1098490));
    printf_s("pDword_10984A4: 0x%p\n", IDA_ADDR(pDword_10984A4));
    printf_s("pByte_10984A8: 0x%p\n", IDA_ADDR(pByte_10984A8));
    printf_s("pDword_F0EC4C: 0x%p\n", IDA_ADDR(pDword_F0EC4C));
    printf_s("pStru_10A1320: 0x%p\n", IDA_ADDR(pStru_10A1320));
    printf_s("g_pRenderer: 0x%p\n", IDA_ADDR(g_pRenderer));
    printf_s("pByte_109A158: 0x%p\n", IDA_ADDR(pByte_109A158));
    printf_s("pByte_109A958: 0x%p\n", IDA_ADDR(pByte_109A958));
    printf_s("pDword_109B21C: 0x%p\n", IDA_ADDR(pDword_109B21C));
    printf_s("pDword_109B220: 0x%p\n", IDA_ADDR(pDword_109B220));
    printf_s("off_109B2CC: 0x%p\n", IDA_ADDR(off_109B2CC));
    printf_s("pDword_10986E8: 0x%p\n", IDA_ADDR(pDword_10986E8));
    printf_s("CTxdStore::ms_Current: 0x%p\n", IDA_ADDR(CTxdStore::ms_Current));
    printf_s("pDword_1098940: 0x%p\n", IDA_ADDR(pDword_1098940));
    printf_s("pByte_1098700: 0x%p\n", IDA_ADDR(pByte_1098700));
    printf_s("dwCurrentLanguage: 0x%p\n", IDA_ADDR(dwCurrentLanguage));
    printf_s("dwGameLanguage: 0x%p\n", IDA_ADDR(dwGameLanguage));

    printf_s("filterSaveSettings: 0x%p\n", IDA_ADDR(filterSaveSettings));
    printf_s("pByte_104D7C8: 0x%p\n", IDA_ADDR(pByte_104D7C8));
    printf_s("pByte_F07ED4: 0x%p\n", IDA_ADDR(pByte_F07ED4));
    printf_s("pQword_104DE2C: 0x%p\n", IDA_ADDR(pQword_104DE2C));
    printf_s("pByte_F07EA4: 0x%p\n", IDA_ADDR(pByte_F07EA4));
    printf_s("grcTexturePC__ms_dwTextureQuality: 0x%p\n", IDA_ADDR(grcTexturePC__ms_dwTextureQuality));
    printf_s("pDword_104DDE0: 0x%p\n", IDA_ADDR(pDword_104DDE0));
    printf_s("pDword_104DDE4: 0x%p\n", IDA_ADDR(pDword_104DDE4));
    printf_s("pDword_104DDE8: 0x%p\n", IDA_ADDR(pDword_104DDE8));
    printf_s("pDword_104DDEC: 0x%p\n", IDA_ADDR(pDword_104DDEC));
    printf_s("pDword_104DDF0: 0x%p\n", IDA_ADDR(pDword_104DDF0));
    printf_s("pDword_104DDF4: 0x%p\n", IDA_ADDR(pDword_104DDF4));
    printf_s("pDword_104DDF8: 0x%p\n", IDA_ADDR(pDword_104DDF8));
    printf_s("pDword_104DDFC: 0x%p\n", IDA_ADDR(pDword_104DDFC));
    printf_s("pDword_104DE00: 0x%p\n", IDA_ADDR(pDword_104DE00));
    printf_s("pDword_104DE04: 0x%p\n", IDA_ADDR(pDword_104DE04));
    printf_s("pDword_104DB98: 0x%p\n", IDA_ADDR(pDword_104DB98));
    printf_s("pszPath: 0x%p\n", IDA_ADDR(pszPath));
    printf_s("pByte_104DE83: 0x%p\n", IDA_ADDR(pByte_104DE83));

    printf_s("sub_7C5D70_lea: 0x%zX\n", IDA_ADDR(sub_7C5D70_lea));
    printf_s("sub_7C5D70_mov: 0x%zX\n", IDA_ADDR(sub_7C5D70_mov));

    printf_s("_loadSettings_dwCurrentLanguage_1: 0x%zX\n", IDA_ADDR(_loadSettings_dwCurrentLanguage_1));
    printf_s("_loadSettings_dwCurrentLanguage_2: 0x%zX\n", IDA_ADDR(_loadSettings_dwCurrentLanguage_2));

    printf_s("cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_1: 0x%zX\n", IDA_ADDR(cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_1));
    printf_s("cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_2: 0x%zX\n", IDA_ADDR(cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_2));

    printf_s("cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_1: 0x%zX\n", IDA_ADDR(cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_1));
    printf_s("cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_2: 0x%zX\n", IDA_ADDR(cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_2));
    printf_s("cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_3: 0x%zX\n", IDA_ADDR(cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_3));

    //printf_s("cVehicleModelInfo_initVehData_nulltex: 0x%zX\n", IDA_ADDR(cVehicleModelInfo_initVehData_nulltex));

    printf_s("\nFunctions============================================\n");
    printf_s("CText::isJapaneseLang: 0x%p\n", IDA_ADDR(cText_isJapaneseLang));

    printf_s("cGameConfigReader__FileType_getPrevFile: 0x%zX\n", IDA_ADDR(cGameConfigReader__FileType_getPrevFile));
    printf_s("cGameConfigReader__FileType_getFileByType: 0x%zX\n", IDA_ADDR(cGameConfigReader__FileType_getFileByType));

    printf_s("t_gpDict_Lookup: 0x%zX\n", IDA_ADDR(t_gpDict_Lookup));

    printf_s("cSprite2d_setTexture: 0x%zX\n", IDA_ADDR(cSprite2d_setTexture));
    printf_s("cSprite2d_Delete: 0x%zX\n", IDA_ADDR(cSprite2d_Delete));

    printf_s("cFontDesc_LoadFontTex: 0x%zX\n", IDA_ADDR(cFontDesc_LoadFontTex));

    printf_s("cTxdStore_loadFile: 0x%zX\n", IDA_ADDR(cTxdStore_loadFile));
    printf_s("cTxdStore_getIndexByName: 0x%zX\n", IDA_ADDR(cTxdStore_getIndexByName));
    printf_s("cTxdStore_findSlotFromHashKey: 0x%zX\n", IDA_ADDR(cTxdStore_findSlotFromHashKey));
    printf_s("cTxdStore_release: 0x%zX\n", IDA_ADDR(cTxdStore_release));
    printf_s("cTxdStore_releaseEntry: 0x%zX\n", IDA_ADDR(cTxdStore_releaseEntry));
    printf_s("cTxdStore_pushCurrentTxd: 0x%zX\n", IDA_ADDR(cTxdStore_pushCurrentTxd));
    printf_s("cTxdStore_addEntry: 0x%zX\n", IDA_ADDR(cTxdStore_addEntry));
    printf_s("cTxdStore_addRef: 0x%zX\n", IDA_ADDR(cTxdStore_addRef));
    printf_s("cTxdStore_popCurrentTxd: 0x%zX\n", IDA_ADDR(cTxdStore_popCurrentTxd));
    printf_s("cTxdStore_atStringHash: 0x%zX\n", IDA_ADDR(cTxdStore_atStringHash));
    printf_s("cTxdStore_at: 0x%zX\n", IDA_ADDR(cTxdStore_at));

    printf_s("cAutoLock_constructor: 0x%zX\n", IDA_ADDR(cAutoLock_constructor));
    printf_s("cAutoLock_destructor: 0x%zX\n", IDA_ADDR(cAutoLock_destructor));

    printf_s("cRenderer_removeAllTexturesFromDictionary: 0x%zX\n", IDA_ADDR(cRenderer_removeAllTexturesFromDictionary));

    printf_s("f__readFontsDat: 0x%zX\n", IDA_ADDR(f__readFontsDat));
    printf_s("CFont::InitPerFrame: 0x%zX\n", IDA_ADDR(cFont_InitPerFrame));

    printf_s("fiDevice_getDevice: 0x%zX\n", IDA_ADDR(fiDevice_getDevice));
    printf_s("cPlayer_isSignedLocally: 0x%zX\n", IDA_ADDR(cPlayer_isSignedLocally));
    printf_s("f_sub_7CAC70: 0x%zX\n", IDA_ADDR(f_sub_7CAC70));
    printf_s("f_gta_fopen: 0x%zX\n", IDA_ADDR(f_gta_fopen));
    printf_s("f_gta_fread: 0x%zX\n", IDA_ADDR(f_gta_fread));
    printf_s("f_gta_fclose: 0x%zX\n", IDA_ADDR(f_gta_fclose));
    printf_s("f_sub_4E3150: 0x%zX\n", IDA_ADDR(f_sub_4E3150));
    printf_s("f_sub_49C4D0: 0x%zX\n", IDA_ADDR(f_sub_49C4D0));
    printf_s("f_sub_7C20C0: 0x%zX\n", IDA_ADDR(f_sub_7C20C0));
    printf_s("f_loadSettings: 0x%zX\n", IDA_ADDR(f_loadSettings));

    printf_s("cFrontEnd_GetLanguageFromSystemLanguage: 0x%zX\n", IDA_ADDR(cFrontEnd_GetLanguageFromSystemLanguage));
    printf_s("cText_GetLanguageFile: 0x%zX\n", IDA_ADDR(cText_GetLanguageFile));
    printf_s("f_loadFontTextures: 0x%zX\n", IDA_ADDR(f_loadFontTextures));
}

void init()
{
    g_baseAddress = (size_t)GetModuleHandleA(nullptr);
    dwGameSignature = *(size_t*)FIX_ADDR_OFFSET(0x00401067, 2);
    enableConsole();
    system("pause");

    getGameVersion();
    initAddrsDynamic();
    //patchInitVehData_SignLiveries_FFAware();

    print_addrs();
    system("pause");

    breakLimits();
    injectFunc(f_loadSettings, (size_t)(_loadSettings));

    injectFunc(cFrontEnd_GetLanguageFromSystemLanguage, (size_t)(CFrontEnd::GetLanguageFromSystemLanguage));
    setFnAddrInCallOpcode(cText_GetLanguageFile, getThisCallAddr(&CText::GetLanguageFile));
    injectFunc(f_loadFontTextures, (size_t)(_loadFontTextures));
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        init();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


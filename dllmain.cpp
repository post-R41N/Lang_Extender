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

void init()
{
    g_baseAddress = (size_t)GetModuleHandleA(nullptr);

    initAddrsDynamic();
    breakLimits();

    enableConsole();
    printf_s("%u\n", g_baseAddress);
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
    printf_s("__dwCurrentLanguage: 0x%p\n", IDA_ADDR(__dwCurrentLanguage));

    printf_s("sub_7C5D70_lea: 0x%zX\n", IDA_ADDR(sub_7C5D70_lea));
    printf_s("sub_7C5D70_mov: 0x%zX\n", IDA_ADDR(sub_7C5D70_mov));

    printf_s("_loadSettings_dwCurrentLanguage_1: 0x%zX\n", IDA_ADDR(_loadSettings_dwCurrentLanguage_1));
    printf_s("_loadSettings_dwCurrentLanguage_2: 0x%zX\n", IDA_ADDR(_loadSettings_dwCurrentLanguage_2));

    printf_s("cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_1: 0x%zX\n", IDA_ADDR(cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_1));
    printf_s("cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_2: 0x%zX\n", IDA_ADDR(cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_2));

    printf_s("cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_1: 0x%zX\n", IDA_ADDR(cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_1));
    printf_s("cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_2: 0x%zX\n", IDA_ADDR(cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_2));
    printf_s("cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_3: 0x%zX\n", IDA_ADDR(cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_3));

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

    printf_s("cFrontEnd_GetLanguageFromSystemLanguage: 0x%zX\n", IDA_ADDR(cFrontEnd_GetLanguageFromSystemLanguage));
    printf_s("cText_GetLanguageFile: 0x%zX\n", IDA_ADDR(cText_GetLanguageFile));
    printf_s("f_loadFontTextures: 0x%zX\n", IDA_ADDR(f_loadFontTextures));

    system("pause");

    injectFunc(cFrontEnd_GetLanguageFromSystemLanguage, (size_t)(CFrontEnd::GetLanguageFromSystemLanguage));
    setFnAddrInCallOpcode(cText_GetLanguageFile, getThisCallAddr(&CText::GetLanguageFile));
    //injectFunc(f_loadFontTextures, (size_t)(_loadFontTextures));
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


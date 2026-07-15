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
    initAddrs();
    breakLimits();

    enableConsole();
    printf_s("%u\n", g_baseAddress);
    printf_s("\n");
    printf_s("__dwCurrentEpisode: 0x%p\n", IDA_ADDR(__dwCurrentEpisode));
    printf_s("pDword_F0EBC4: 0x%p\n", IDA_ADDR(pDword_F0EBC4));
    printf_s("pByte_109B225: 0x%p\n", IDA_ADDR(pByte_109B225));
    system("pause");

    injectFunc(FIX_ADDR(0x007BB3B0), (size_t)(CFrontEnd::GetLanguageFromSystemLanguage));
    setFnAddrInCallOpcode(FIX_ADDR(0x007D00D3), getThisCallAddr(&CText::GetLanguageFile));
    injectFunc(FIX_ADDR(0x00815AD0), (size_t)(_loadFontTextures));
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


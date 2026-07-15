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

void initAddrsDynamic()
{
    __dwCurrentEpisode = *(int**)findPattern("8B 1D ? ? ? ? 83 C4 10 8D 4C 24 10 ", 2);
    pDword_F0EBC4 = *(int**)findPattern("A1 ? ? ? ? 83 F8 FF 75 03 B0 01 ", 1);
    pByte_109B225 = *(char**)findPattern("C6 05 ? ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? E8 ? ? ? ? 8B F8 ", 2);
    /*
    g_text = *(CText**)findPattern("A1 ? ? ? ? 83 F8 FF 75 03 B0 01 ", 1);
    g_pGameConfigReader = *(CGameConfigReader***)findPattern("A1 ? ? ? ? 83 F8 FF 75 03 B0 01 ", 1);
    pDword_109823C = *(int**)findPattern("A1 ? ? ? ? 83 F8 FF 75 03 B0 01 ", 1);
    pDword_1098240 = *(int**)findPattern("A1 ? ? ? ? 83 F8 FF 75 03 B0 01 ", 1);
    pDword_1098244 = *(int**)findPattern("A1 ? ? ? ? 83 F8 FF 75 03 B0 01 ", 1);
    pDword_1098248 = *(int**)findPattern("A1 ? ? ? ? 83 F8 FF 75 03 B0 01 ", 1);
    pDword_1098238 = *(int**)findPattern("A1 ? ? ? ? 83 F8 FF 75 03 B0 01 ", 1);
    pDword_109824C = *(int**)findPattern("A1 ? ? ? ? 83 F8 FF 75 03 B0 01 ", 1);
    pDword_1098494 = (int*)
    pDword_1098498 = (int*)
    pDword_109849C = (int*)
    pDword_10984A0 = (int*)
    pDword_1098490 = (int*)
    pDword_10984A4 = (int*)
    pByte_10984A8 = (char*)
    pDword_F0EC4C = (int*)
    pStru_10A1320 = (_RTL_CRITICAL_SECTION*)
    g_pRenderer = (CRenderer*)
    pByte_109A158 = (char*)
    pByte_109A958 = (char*)
    pDword_109B21C = (int*)
    pDword_109B220 = (int*)
    off_109B2CC = (void*)
    pDword_10986E8 = (int*)
    CTxdStore::ms_Current = (pgDictionary<grcTexture>**)
    pDword_1098940 = (int*)
    pByte_1098700 = (char*)
    __dwCurrentLanguage = (int*)
    */
}

void initAddrs()
{
    //__dwCurrentEpisode = (int*)FIX_ADDR(0x10619D8);
    //pDword_F0EBC4 = (int*)FIX_ADDR(0x00F0EBC4);
    //pByte_109B225 = (char*)FIX_ADDR(0x0109B225);
    g_text = (CText*)FIX_ADDR(0x01058D00);
    g_pGameConfigReader = (CGameConfigReader**)FIX_ADDR(0x01924E6C);
    pDword_109823C = (int*)FIX_ADDR(0x0109823C);
    pDword_1098240 = (int*)FIX_ADDR(0x01098240);
    pDword_1098244 = (int*)FIX_ADDR(0x01098244);
    pDword_1098248 = (int*)FIX_ADDR(0x01098248);
    pDword_1098238 = (int*)FIX_ADDR(0x01098238);
    pDword_109824C = (int*)FIX_ADDR(0x0109824C);
    pDword_1098494 = (int*)FIX_ADDR(0x01098494);
    pDword_1098498 = (int*)FIX_ADDR(0x01098498);
    pDword_109849C = (int*)FIX_ADDR(0x0109849C);
    pDword_10984A0 = (int*)FIX_ADDR(0x010984A0);
    pDword_1098490 = (int*)FIX_ADDR(0x01098490);
    pDword_10984A4 = (int*)FIX_ADDR(0x010984A4);
    pByte_10984A8 = (char*)FIX_ADDR(0x010984A8);
    pDword_F0EC4C = (int*)FIX_ADDR(0x00F0EC4C);
    pStru_10A1320 = (_RTL_CRITICAL_SECTION*)FIX_ADDR(0x010A1320);
    g_pRenderer = (CRenderer*)FIX_ADDR(0x01064980);
    pByte_109A158 = (char*)FIX_ADDR(0x0109A158);
    pByte_109A958 = (char*)FIX_ADDR(0x0109A958);
    pDword_109B21C = (int*)FIX_ADDR(0x0109B21C);
    pDword_109B220 = (int*)FIX_ADDR(0x0109B220);
    off_109B2CC = (void*)FIX_ADDR(0x0109B2CC);
    pDword_10986E8 = (int*)FIX_ADDR(0x010986E8);
    CTxdStore::ms_Current = (pgDictionary<grcTexture>**)FIX_ADDR(0x01924E30);
    pDword_1098940 = (int*)FIX_ADDR(0x01098940);
    pByte_1098700 = (char*)FIX_ADDR(0x01098700);
    __dwCurrentLanguage = (int*)FIX_ADDR(0x0104DC18);
}
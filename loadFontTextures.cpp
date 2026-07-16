#include <Windows.h>
#include "addrs.h"
#include <stdio.h>

unsigned int __cdecl hashStringLowercaseFromSeed(const char* a1, unsigned int a2)
{
    return ((unsigned int(__cdecl*)(const char* a1, unsigned int a2))(f_hashStringLowercaseFromSeed))(a1, a2);
}

int __cdecl _readFontsDat(int a1)
{
    return ((int(__cdecl*)(int a1))(f__readFontsDat))(a1);
}

int sub_814AA0()
{
    return ((int(*)())(f_sub_814AA0))();
}

void _loadFontTextures()
{
    int IndexByName; // esi
    int v1; // edi
    CGameConfigReader__FileType* v2; // esi
    bool v3; // bl
    CGameConfigReader__FileType* PrevFile; // esi
    bool File; // bl
    CGameConfigReader__FileType* FileByType; // esi
    bool v7; // bl
    pgDictionary<grcTexture>* v8; // esi
    unsigned int v9; // eax
    DWORD v10; // eax
    pgDictionary<grcTexture>* v11; // esi
    unsigned int v12; // eax
    DWORD v13; // eax
    int v14; // esi
    int v15; // esi
    bool v16; // bl
    int v17; // esi
    CGameConfigReader__FileType v19; // [esp+18h] [ebp-8Ch] BYREF


    //TEST#####################################
    bool isRU = false;
    bool isJP = false;
    bool isInt = false;
    int TextType = 0;
    TextType = (int)g_text->m_cTextType;
    //#########################################


    CAutoLock v18((LPCRITICAL_SECTION)pStru_10A1320);
    *pByte_109B225 = 1;
    g_pRenderer->removeAllTexturesFromDictionary(0);
    pDword_109B21C[0] = (int)pByte_109A158;
    *pDword_109B220 = (int)pByte_109A958;
    if (*__dwCurrentEpisode == 2) ((CSprite2d*)off_109B2CC)->Delete();
    IndexByName = CTxdStore::getIndexByName("fonts");
    pDword_1098238[0] = 0;
    *pDword_1098490 = 0;
    *pDword_10986E8 = 0;
    CTxdStore::findSlotFromHashKey(-1);
    CTxdStore::release(IndexByName);
    CTxdStore::releaseEntry(IndexByName);
    v1 = CTxdStore::addEntry("fonts");
    if (g_text->m_cTextType == 114)
    {
        isRU = true;
        v19.nNext = *(unsigned __int16*)(g_pGameConfigReader + 4);
        v19.nType = ConfigFontTxdR;
        PrevFile = (CGameConfigReader__FileType*)(*g_pGameConfigReader)->getPrevFile((CGameConfigReader*)&v19);
        if (PrevFile->nNext == -1) goto LABEL_13;
        do
        {
            File = CTxdStore::loadFile(v1, (const char*)PrevFile);
            PrevFile = (CGameConfigReader__FileType*)(*g_pGameConfigReader)->getPrevFile((CGameConfigReader*)PrevFile);
        } 
        while (PrevFile->nNext != -1);
        if (!File)
        {
            LABEL_13:
            CTxdStore::loadFile(v1, "platform:/textures/fonts_r");
        }
    }
    else if (g_text->m_cTextType == 106 || g_text->m_bJapanese)
    {
        isJP = true;
        FileByType = (CGameConfigReader__FileType*)(*g_pGameConfigReader)->getFileByType(ConfigFontTxdJ);
        if (FileByType->nNext == -1) goto LABEL_17;
        do
        {
            v7 = CTxdStore::loadFile(v1, (const char*)FileByType);
            FileByType = (CGameConfigReader__FileType*)(*g_pGameConfigReader)->getPrevFile((CGameConfigReader*)FileByType);
        } 
        while (FileByType->nNext != -1);
        if (!v7)
        {
            LABEL_17:
            CTxdStore::loadFile(v1, "platform:/textures/fonts_j");
        }
    }
    else
    {
        isInt = true;
        v2 = (CGameConfigReader__FileType*)(*g_pGameConfigReader)->getFileByType(ConfigFontTxd);
        if (v2->nNext == -1) goto LABEL_9;
        do
        {
            v3 = CTxdStore::loadFile(v1, (const char*)v2);
            v2 = (CGameConfigReader__FileType*)(*g_pGameConfigReader)->getPrevFile((CGameConfigReader*)v2);
        } 
        while (v2->nNext != -1);
        if (!v3)
        {
            LABEL_9:
            CTxdStore::loadFile(v1, "platform:/textures/fonts");
        }
    }

    //TEST#####################################
    printf_s("\n");
    printf_s("Is Russian %d\n", isRU);
    printf_s("Is Japanese %d\n", isJP);
    printf_s("Is International %d\n", isInt);
    printf_s("Text Type is %d\n", TextType);

    //UITexture* test = (UITexture*)FIX_ADDR(0x007C4889);
    //printf_s("%p\n", test);
    //#########################################

    CTxdStore::addRef(v1);
    CTxdStore::findSlotFromHashKey(v1);
    v8 = *CTxdStore::ms_Current;
    v9 = CTxdStore::atStringHash("font1", 0);
    v10 = v8->Lookup(v8, v9);
    v11 = *CTxdStore::ms_Current;
    *pDword_109823C = 0x44000000;
    *pDword_1098240 = 0x44000000;
    *pDword_1098244 = 0x42200000;
    *pDword_1098248 = 0x40800000;
    pDword_1098238[0] = v10;
    pDword_109824C[0] = 1109262336;
    v12 = CTxdStore::atStringHash("font3", 0);
    v13 = v11->Lookup(v11, v12);
    *pDword_1098494 = 1140850688;
    *pDword_1098498 = 1140850688;
    *pDword_109849C = 1109393408;
    *pDword_10984A0 = 1082130432;
    *pDword_1098490 = v13;
    *pDword_10984A4 = 1109262336;

    if (g_text->m_cTextType == 106 || g_text->m_bJapanese) ((CFontDesc*)pByte_10984A8)->LoadFontTex("font4");
    if (*__dwCurrentEpisode == 2) ((CSprite2d*)off_109B2CC)->setTexture("RSTICK_ROTATE");
    _readFontsDat(-1);

    if (*pDword_F0EBC4 != -1)
    {
        v14 = *pDword_F0EC4C;
        pDword_1098940[0] = 0;
        if (CTxdStore::at(*pDword_F0EC4C))
        {
            CTxdStore::release(v14);
            v14 = *pDword_F0EC4C;
        }
        CTxdStore::releaseEntry(v14);
        *pDword_F0EC4C = CTxdStore::addEntry("streamedfont");
        v19.nNext = *(unsigned __int16*)(g_pGameConfigReader + 4);
        v19.nType = 43;
        v15 = (int)(*g_pGameConfigReader)->getPrevFile((CGameConfigReader*)&v19);
        if (((CGameConfigReader__FileType*)v15)->nNext == -1)
            goto LABEL_29;
        do
        {
            v16 = CTxdStore::loadFile(*pDword_F0EC4C, (const char*)v15);
            v15 = (int)(*g_pGameConfigReader)->getPrevFile((CGameConfigReader*)v15);
        } while (((CGameConfigReader__FileType*)v15)->nNext != -1);
        if (!v16)
            LABEL_29:
        if (g_text->m_cTextType == 114) CTxdStore::loadFile(*pDword_F0EC4C, "platform:/textures/fonts_r_streamed_1");
        else CTxdStore::loadFile(*pDword_F0EC4C, "platform:/textures/fonts_streamed_1");
        v17 = *pDword_F0EC4C;
        CTxdStore::addRef(*pDword_F0EC4C);
        CTxdStore::findSlotFromHashKey(v17);
        if ((unsigned int)(*pDword_F0EBC4 - 7) <= 1) ((CFontDesc*)pByte_1098700)->LoadFontTex("font2");
        _readFontsDat(3);
    }
    *pByte_109B225 = 0;
}
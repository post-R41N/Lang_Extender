#pragma once
#include <windows.h>
#include <stdint.h>
#include "defs.h"
#include "hookFuncs.h"

#define FIX_ADDR(addr) (addr - 0x400000 + g_baseAddress)
#define IDA_ADDR(addr) ((size_t)addr - (size_t)g_baseAddress + 0x400000)
#define VALIDATE_SIZE(struc, size)				static_assert(sizeof(struc) == size, "Invalid structure size of " #struc)
#define VALIDATE_OFFSET(struc, member, offset)	static_assert(offsetof(struc, member) == offset, "The offset of " #member " in " #struc " is not " #offset "...")

extern size_t g_baseAddress;

//Functions==============================================
extern size_t cText_isJapaneseLang;

extern size_t cGameConfigReader__FileType_getPrevFile;
extern size_t cGameConfigReader__FileType_getFileByType;

extern size_t t_gpDict_Lookup;

extern size_t cSprite2d_setTexture;
extern size_t cSprite2d_Delete;

extern size_t cFontDesc_LoadFontTex;

extern size_t cTxdStore_loadFile;
extern size_t cTxdStore_getIndexByName;
extern size_t cTxdStore_findSlotFromHashKey;
extern size_t cTxdStore_release;
extern size_t cTxdStore_releaseEntry;
extern size_t cTxdStore_pushCurrentTxd;
extern size_t cTxdStore_addEntry;
extern size_t cTxdStore_addRef;
extern size_t cTxdStore_popCurrentTxd;
extern size_t cTxdStore_atStringHash;
extern size_t cTxdStore_at;

extern size_t cAutoLock_constructor;
extern size_t cAutoLock_destructor;

extern size_t cRenderer_removeAllTexturesFromDictionary;

extern size_t f_hashStringLowercaseFromSeed;
extern size_t f__readFontsDat;
extern size_t f_sub_814AA0;

extern size_t cFrontEnd_GetLanguageFromSystemLanguage;
extern size_t cText_GetLanguageFile;
extern size_t f_loadFontTextures;

namespace rage 
{
    // rage
} 

enum ConfigFiles
{
    ConfigDelayedIde = 0,
    ConfigDelayedIpl = 1,
    ConfigIpl = 2,
    ConfigAnimGrp = 3,
    ConfigHandling = 4,
    ConfigVehicleExtras = 5,
    ConfigGxt = 6,
    ConfigPlayer = 7,
    ConfigCarcols = 8,
    CongigPedGrp = 9,
    ConfigCarGrp = 10,
    ConfigRadio = 11,
    ConfigRadioLogos = 12,
    ConfigRadarBlips = 13,
    ConfigWeaponInfo = 14,
    ConfigThrowWeaponInfo = 15,
    ConfigHtml = 16,
    ConfigRmptfx = 17,
    ConfigPedPersonality = 18,
    ConfigMeleeeAnims = 19,
    ConfigActionTable = 20,
    ConfigExplosionFx = 21,
    ConfigVehOff = 22,
    ConfigFDatFile = 23,
    ConfigFTxdFile = 24,
    ConfigFMenuFile = 25,
    ConfigLBDataFile = 26,
    ConfigLBIconsFile = 27,
    ConfigPedvars = 28,
    ConfigPopCycle = 29,
    ConfigTimeCycle = 30,
    ConfigDisableFile = 31,
    ConfigPLSettingsMale = 32,
    ConfigPLSettingsFemale = 33,
    ConfigCredits = 34,
    ConfigHudColor = 35,
    ConfigHudTxd = 36,
    ConfigFontDat = 37,
    ConfigFontTxd = 38,
    ConfigPLSettingsLight = 39,
    ConfigSaveIcon = 40,
    ConfigWeaponFx = 41,
    ConfigHudDat = 42,
    ConfigFontsTrTxd = 43,
    ConfigScrollBar = 44,
    ConfigVisualSettings = 45,
    ConfigTickboxFile = 46,
    ConfigFontDatR = 47,
    ConfigFontTxdR = 48,
    ConfigFontsTrTxdR = 49,
    ConfigFontDatJ = 50,
    ConfigFontTxdJ = 51,
    ConfigLast = 52,
};

struct alignas(0x10) Vector4
{
    float x, y, z, w;
};

struct Vector3
{
    float x, y, z;
};

struct CText__data
{
    int pData;
    int nCount;
};

struct CText__data2
{
    int field_0;
    int field_4;
    int field_8;
    char field_C;
    char field_D[3];
};

struct CText
{
    CText__data field_0;
    CText__data field_8;
    CText__data field_10[14];
    CText__data field_80[14];
    char m_abAdditionalTextLoaded[14];
    char m_abStreamingAdditionalText[14];
    CText__data2 field_10C[14];
    char m_szAdditionalTextNames[112];
    int field_25C;
    unsigned char m_cTextType;
    char field_261;
    char field_262;
    char m_bJapanese;
    CText__data field_264;
    static size_t GetLanguageFile_origcall;
    const char* GetLanguageFile(char a2);
    bool isJapaneseLang()
    {
        return ((bool(__thiscall*)(CText*))(cText_isJapaneseLang))(this);
    }
};

template <typename T> struct sysArray 
{
    T* pElements;
    WORD wCount;
    WORD capacity;
};

struct CGameConfigReader__FileType
{
    char field_0[128];
    int nType;
    int nNext;
};

struct CGameConfigReader
{
    sysArray<int> m_files;
    sysArray<int> m_disabledFiles;
    char m_fileTypeNames[1664];
    CGameConfigReader__FileType m_lastType;
    CGameConfigReader__FileType* getPrevFile(CGameConfigReader* a2)
    {
        return ((CGameConfigReader__FileType*(__thiscall*)(CGameConfigReader*, CGameConfigReader * a2))(cGameConfigReader__FileType_getPrevFile))(this, a2);
    }
    CGameConfigReader__FileType* getFileByType(int a2)
    {
        return ((CGameConfigReader__FileType*(__thiscall*)(CGameConfigReader*, int a2))(cGameConfigReader__FileType_getFileByType))(this, a2);
    }
    //CGameConfigReader__FileType* sub_4774A0();
};

struct datBase
{
    int __vmt;
};

struct pgBase : datBase
{
    int m_pBlockMap;
};

struct grcTexture : pgBase
{
    char resourceType;
    char m_nbDepth;
    __int16 m_wUsageCount;
    int field_C;
    int field_10;
    int m_pszTextureName;
    int m_pITexture;
    __int16 m_wWidth;
    __int16 m_wHeight;
    int m_pixelFormat;
    __int16 m_wStride;
    char m_eTextureType;
    char m_nbLevels;
};

template <typename T> struct pgDictionary : pgBase
{
    int m_pParentDictionary;
    int m_dwUsageCount;
    sysArray<int> m_nameHashes;
    sysArray<T*> m_data;
    DWORD Lookup(pgDictionary*, DWORD a2)
    {
        return ((DWORD(__thiscall*)(pgDictionary*, DWORD a2))(t_gpDict_Lookup))(this, a2);
    }
};

struct CSprite2d
{
    grcTexture* m_pTxd;
    void setTexture(const char* a2)
    {
        return ((void(__thiscall*)(CSprite2d*, const char* a2))(cSprite2d_setTexture))(this, a2);
    }
    void Delete()
    {
        return ((void(__thiscall*)(CSprite2d*))(cSprite2d_Delete))(this);
    }
};

struct CFontDesc
{
    int LoadFontTex(const char* a2)
    {
        return ((int(__thiscall*)(CFontDesc*, const char* a2))(cFontDesc_LoadFontTex))(this, a2);
    }
};

struct CTxdStore
{
    static bool __cdecl loadFile(int dwIndex, const char* pszFileName)
    {
        return ((bool(__cdecl*)(int dwIndex, const char* pszFileName))(cTxdStore_loadFile))(dwIndex, pszFileName);
    }
    static int getIndexByName(const char* a1)
    {
        return ((int(__cdecl*)(const char* a1))(cTxdStore_getIndexByName))(a1);
    }
    static void __cdecl findSlotFromHashKey(int a1)
    {
        return ((void(__cdecl*)(int a1))(cTxdStore_findSlotFromHashKey))(a1);
    }
    static char __cdecl release(int a1)
    {
        return ((char(__cdecl*)(int a1))(cTxdStore_release))(a1);
    }
    static int __cdecl releaseEntry(int a1)
    {
        return ((int(__cdecl*)(int a1))(cTxdStore_releaseEntry))(a1);
    }
    static pgDictionary<grcTexture>* pushCurrentTxd()
    {
        return ((pgDictionary<grcTexture>*(*)())(cTxdStore_pushCurrentTxd))();
    }
    static int __cdecl addEntry(const char* a1)
    {
        return ((int(__cdecl*)(const char* a1))(cTxdStore_addEntry))(a1);
    }
    static int __cdecl addRef(int a1)
    {
        return ((int(__cdecl*)(int a1))(cTxdStore_addRef))(a1);
    }
    static DWORD* popCurrentTxd()
    {
        return ((DWORD*(*)())(cTxdStore_popCurrentTxd))();
    }
    static pgDictionary<grcTexture>** ms_Current;
    static unsigned int __cdecl atStringHash(const char* a1, unsigned int a2)
    {
        return ((unsigned int(__cdecl*)(const char* a1, unsigned int a2))(cTxdStore_atStringHash))(a1, a2);
    }
    static size_t __cdecl at(int a1)
    {
        return ((size_t(__cdecl*)(int a1))(cTxdStore_at))(a1);
    }
};

struct CAutoLock
{
    int m_nLockCount;
    int m_pCriticalSection;
    CAutoLock(LPCRITICAL_SECTION lpCriticalSection)
    {
        ((CAutoLock*(__thiscall*)(CAutoLock*, LPCRITICAL_SECTION lpCriticalSection))(cAutoLock_constructor))(this, lpCriticalSection);
    }
    ~CAutoLock()
    {
        ((void(__thiscall*)(CAutoLock*))(cAutoLock_destructor))(this);
    }
};

struct CRenderer 
{
    int removeAllTexturesFromDictionary(int a2) 
    {
        return ((int(__thiscall*)(CRenderer*, int a2))(cRenderer_removeAllTexturesFromDictionary))(this, a2);
    }
};

struct CFrontEnd
{
    static int GetLanguageFromSystemLanguage();
};

//Global Variables==============================================
extern int* __dwCurrentEpisode;
extern int* pDword_F0EBC4;
extern char* pByte_109B225;
extern CGameConfigReader** g_pGameConfigReader;
extern CText* g_text;
extern int* pDword_109823C;
extern int* pDword_1098240;
extern int* pDword_1098244;
extern int* pDword_1098248;
extern int* pDword_1098238;
extern int* pDword_109824C;
extern int* pDword_1098494;
extern int* pDword_1098498;
extern int* pDword_109849C;
extern int* pDword_10984A0;
extern int* pDword_1098490;
extern int* pDword_10984A4;
extern char* pByte_10984A8;
extern int* pDword_F0EC4C;
extern _RTL_CRITICAL_SECTION* pStru_10A1320;
extern CRenderer* g_pRenderer;
extern char* pByte_109A158;
extern char* pByte_109A958;
extern int* pDword_109B21C;
extern int* pDword_109B220;
extern void* off_109B2CC;
extern int* pDword_10986E8;
extern char* pByte_10984A8;
extern int* pDword_1098940;
extern char* pByte_1098700;
extern int* __dwCurrentLanguage;

extern size_t sub_7C5D70_lea;
extern size_t sub_7C5D70_mov;
extern size_t _loadSettings_dwCurrentLanguage_1;
extern size_t _loadSettings_dwCurrentLanguage_2;
extern size_t cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_1;
extern size_t cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_2;
extern size_t cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_1;
extern size_t cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_2;
extern size_t cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_3;

void initAddrsDynamic();
void initAddrs();
int GetLanguageFromSystemLanguage();
void breakLimits();
void _loadFontTextures();
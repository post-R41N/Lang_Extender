#include <Windows.h>
#include "addrs.h"
#include <stdio.h>

void sub_7CAC70(const char* a1, char a2)
{
    return ((void(*)(const char* a1, char a2))(f_sub_7CAC70))(a1, a2);
}

int __cdecl gta_fopen(const char* a1, const char* a2)
{
    return ((int(__cdecl*)(const char* a1, const char* a2))(f_gta_fopen))(a1, a2);
}
int __cdecl gta_fread(fiFile* a1, char* a2, int a3)
{
    return ((int(__cdecl*)(fiFile * a1, char* a2, int a3))(f_gta_fread))(a1, a2, a3);
}
int __cdecl gta_fclose(fiFile* a1)
{
    return ((int(__cdecl*)(fiFile * a1))(f_gta_fclose))(a1);
}

void** sub_4E3150()
{
    return ((void** (*)())(f_sub_4E3150))();
}

void __cdecl sub_49C4D0(char a1)
{
    return ((void(__cdecl*)(char a1))(f_sub_49C4D0))(a1);
}

int __cdecl sub_7C20C0(int a1)//CFrontEnd::FillMenuItemFromScreen
{
    return ((int(__cdecl*)(int a1))(f_sub_7C20C0))(a1);
}

int CFrontEnd::GetLanguageFromSystemLanguage()
{
    int langID; // esi

    langID = 0;
    switch (GetUserDefaultUILanguage() & 0x3FF)
    {
    case 9://English
        langID = 0;
        break;
    case 0xC://French
        langID = 1;
        break;
    case 7://German
        langID = 2;
        break;
    case 0x10://Italian
        langID = 3;
        break;
    case 0xA://Spanish
        langID = 4;
        break;
    case 0x19://Russian
        langID = 5;
        break;
    case 0x11://Japanese
        langID = 6;
        break;
    default:
        break;
    }
    return langID;
}

const char* CText::GetLanguageFile(char a2)
{
    int UserLanguage; // eax
    bool isJapanese; // zf
    const char* result; // eax

    if (a2) UserLanguage = CFrontEnd::GetLanguageFromSystemLanguage();
    else UserLanguage = dwCurrentLanguage[0];
    isJapanese = this->m_bJapanese == 1;
    this->m_cTextType = 101;

    //UserLanguage = 6;
    //*dwGameLanguage = UserLanguage;
    //*dwCurrentLanguage = UserLanguage;

    switch (UserLanguage)
    {
    case 0:
        result = "AMERICAN.GXT";
        break;
    case 1:
        result = "FRENCH.GXT";
        break;
    case 2:
        result = "GERMAN.GXT";
        break;
    case 3:
        result = "ITALIAN.GXT";
        break;
    case 4:
        result = "SPANISH.GXT";
        break;
    case 5:
        this->m_cTextType = 114;
        result = "RUSSIAN.GXT";
        break;
    case 6:
        this->m_cTextType = 106;
        result = "JAPANESE.GXT";
        break;
    default:
        return "AMERICAN.GXT";
    }
    return result;
}

char _loadSettings()
{
    fiFile* v0; // ebp
    fiDevice* Device;
    CPlayer* v2; // eax
    int v4; // [esp+8h] [ebp-49Ch] BYREF
    char v5[660]; // [esp+Ch] [ebp-498h] BYREF
    char pszPath[512]; // [esp+2A0h] [ebp-204h] BYREF
    const char* settingsName = "SETTINGS.CFG";

    v4 = 0;
    sub_7CAC70("Settings", 1);
    //if (dwGameVersion == GameVersion::GTAIV_1070 || dwGameVersion == GameVersion::GTAIV_1080) settingsName = "SETTINGS.CFG";
    if (dwGameVersion == GameVersion::EFLC_1120 || dwGameVersion == GameVersion::EFLC_1130) settingsName = "SETTINGS_EFLC.CFG";
    v0 = (fiFile*)gta_fopen(settingsName, "r");
    if (!v0) return 0;
    gta_fread(v0, (char*)&v4, 4);
    if (v4 == 271062290)
    {
        gta_fread(v0, v5, 308);
        gta_fread(v0, &v5[308], 352);
        gta_fread(v0, (char*)filterSaveSettings, 260);
        gta_fread(v0, pByte_104D7C8, 512);
        gta_fread(v0, pByte_F07ED4, 16);
        gta_fread(v0, (char*)pQword_104DE2C, 16);
        gta_fread(v0, pByte_F07EA4, 1);
        v2 = (CPlayer*)sub_4E3150();
        if (v2 && v2->isSignedLocally())
        {
            *grcTexturePC__ms_dwTextureQuality = *(DWORD*)&v5[580];
            *pDword_104DDE0 = *(DWORD*)&v5[584];
            *pDword_104DDE4 = *(DWORD*)&v5[588];
            *pDword_104DDE8 = *(DWORD*)&v5[592];
            *pDword_104DDEC = *(DWORD*)&v5[596];
            *pDword_104DDF0 = *(DWORD*)&v5[600];
            *pDword_104DDF4 = *(DWORD*)&v5[604];
            *pDword_104DDF8 = *(DWORD*)&v5[608];
            *pDword_104DDFC = *(DWORD*)&v5[612];
            *pDword_104DE00 = *(DWORD*)&v5[616];
            *pDword_104DE04 = *(DWORD*)&v5[620];
        }
        else memcpy(pDword_104DB98, v5, 0x294u);
        if (*pDword_104DDF8 > 3) *pDword_104DDF8 = 0;
        gta_fclose(v0);
        sub_49C4D0(1);
    }
    else
    {
        memset(pszPath, 0, sizeof(pszPath));
        memset(v5, 0, 0x200u);
        gta_fclose(v0);
        sprintf_s(pszPath, "%s", &::pszPath);
        Device = fiDevice::getDevice(pszPath, 1);
        if (dwGameVersion == GameVersion::GTAIV_1070 || dwGameVersion == GameVersion::GTAIV_1080) sprintf_s(v5, "%s\\Settings.cfg", pszPath);
        else if (dwGameVersion == GameVersion::EFLC_1120 || dwGameVersion == GameVersion::EFLC_1130) sprintf_s(v5, "%s\\Settings_eflc.cfg", pszPath);
        (*((void(__thiscall**)(fiDevice*, char*))Device->__vmt + 14))(Device, v5);
    }
    *pByte_104DE83 = 1;
    sub_7C20C0(0);
    return 1;
}

void breakLimits()
{
    //Extending Language options from 6 to 7 in sub_7C5D70 function
    if (sub_7C5D70_lea != 0) writeBYTE(sub_7C5D70_lea, 2); // lea ebp,[edi+1] -> [edi+2]: v16 = 7 вместо 6
    if (sub_7C5D70_mov != 0) writeBYTE(sub_7C5D70_mov, 7); // mov ebp,1 -> mov ebp,7 (branch m_bJapanese)

    //Breaking resets of dwCurrentLanguage/dwGameLanguage in CFrontEnd::UpdateMenuOptionsFromProfile function
    if (cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_1 != 0) makeNop(cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_1, 10);//NOPing the __dwCurrentLanugage = 0
    if (cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_2 != 0) makeNop(cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_2, 15);//NOPing operation for giving language value = 6

    //Breaking resets of dwCurrentLanguage in CFrontEnd::SetValuesBasedOnPreference function
    if (cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_1 != 0) makeNop(cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_1, 6);//NOPing the mov __dwCurrentLanguage, ebp(0)
    if (cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_2 != 0) makeNop(cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_2, 6);//NOPing the mov __dwCurrentLanguage, ebx(4)
    if (cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_3 != 0) makeNop(cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_3, 6);//NOPing the mov __dwCurrentLanguage, edi(6)

    //Breaking conditions for Japanese lang in CRadar_writeBlipSaveData
    if (cRadar_writeBlipSaveData_jp_condition != 0) makeNop(cRadar_writeBlipSaveData_jp_condition, 11);//NOPing the jz+cmp g_text.m_bJapanese, 0
    //Breaking conditions for Japanese lang in CRadar_readBlipSaveData
    if (cRadar_readBlipSaveData_jp_condition != 0) makeNop(cRadar_readBlipSaveData_jp_condition, 11);//NOPing the jz+cmp g_text.m_bJapanese, 0
}

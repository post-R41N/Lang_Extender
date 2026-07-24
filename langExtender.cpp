#include <Windows.h>
#include "addrs.h"
#include <stdio.h>

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
    else UserLanguage = __dwCurrentLanguage[0];
    isJapanese = this->m_bJapanese == 1;
    this->m_cTextType = 101;
    //if (!isJapanese) return "AMERICAN.GXT";

    //Test Langs
    //UserLanguage = 5;
    //__dwCurrentLanguage[0] = UserLanguage;
    //__dwGameLanguage[0] = UserLanguage;
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

void breakLimits()
{
    //Extending Language options from 6 to 7 in sub_7C5D70 function
    if (sub_7C5D70_lea != 0) writeBYTE(sub_7C5D70_lea, 2); // lea ebp,[edi+1] -> [edi+2]: v16 = 7 вместо 6
    if (sub_7C5D70_mov != 0) writeBYTE(sub_7C5D70_mov, 7); // mov ebp,1 -> mov ebp,7 (branch m_bJapanese)

    
    //Breaking resets of dwCurrentLanguage in _loadSettings function
    if (_loadSettings_dwCurrentLanguage_1 != 0) makeNop(_loadSettings_dwCurrentLanguage_1, 6);//NOPing the __dwCurrentLanugage = 0
    if (_loadSettings_dwCurrentLanguage_2 != 0) makeNop(_loadSettings_dwCurrentLanguage_2, 10);//NOPing the __dwCurrentLanugage = 6

    //Breaking resets of dwCurrentLanguage/dwGameLanguage in CFrontEnd::UpdateMenuOptionsFromProfile function
    if (cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_1 != 0) makeNop(cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_1, 10);//NOPing the __dwCurrentLanugage = 0
    if (cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_2 != 0) makeNop(cFrontEnd_UpdateMenuOptionsFromProfile_dwCurrentLanguage_2, 15);//NOPing operation for giving language value = 6
    

    //Breaking resets of dwCurrentLanguage in CFrontEnd::SetValuesBasedOnPreference function
    if (cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_1 != 0) makeNop(cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_1, 6);//NOPing the mov __dwCurrentLanguage, ebp(0)
    if (cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_2 != 0) makeNop(cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_2, 6);//NOPing the mov __dwCurrentLanguage, ebx(4)
    if (cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_3 != 0) makeNop(cFrontEnd_SetValuesBasedOnPreference_dwCurrentLanguage_3, 6);//NOPing the mov __dwCurrentLanguage, edi(6)
}
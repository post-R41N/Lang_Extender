#include "hookFuncs.h"

size_t findPattern(const char* pszPattern, ptrdiff_t offset = 0) 
{
    size_t found_address = 0;
    //#ifdef _DEBUG
    //	hook::pattern g = hook::pattern(pszPattern); // .count(1);
    //#else
    hook::pattern g = hook::pattern(pszPattern).count(1);
    //#endif
    if (!g.empty()) found_address = reinterpret_cast<size_t>(g.get(0).get<void>(offset));
    return found_address;
}

DWORD g_dwOldProtect;
bool setProtect(size_t addr, size_t size, DWORD newProtect)
{
    size = (size + 0xfff) & ~0xfff;
    return VirtualProtect((void*)addr, size, newProtect, &g_dwOldProtect);
}

uint8_t writeBYTE(size_t addr, uint8_t val)
{
    setProtect(addr, sizeof val, PAGE_EXECUTE_READWRITE);

    uint8_t oldVal = *(uint8_t*)addr;
    *(uint8_t*)addr = val;

    setProtect(addr, sizeof val, g_dwOldProtect);

    return oldVal;
}

void makeNop(size_t addr, size_t size)
{
    setProtect(addr, size, PAGE_EXECUTE_READWRITE);
    memset((void*)addr, 0x90, size);
    setProtect(addr, size, g_dwOldProtect);
}

size_t setFnAddrInCallOpcode(size_t callPos, size_t pfn)
{
    BYTE* patch = (BYTE*)callPos + 1;

    auto retVal = (*(DWORD*)patch + (callPos + 5));
    setProtect(callPos, 5, PAGE_EXECUTE_READWRITE);
    *(DWORD*)patch = (pfn - (callPos + 5));
    setProtect(callPos, 5, g_dwOldProtect);

    return retVal;
}


uint32_t writeDWORD(size_t addr, uint32_t val)
{
    setProtect(addr, sizeof val, PAGE_EXECUTE_READWRITE);

    uint32_t oldVal = *(uint32_t*)addr;
    *(uint32_t*)addr = val;
    setProtect(addr, sizeof val, g_dwOldProtect);

    return oldVal;
}

void injectFunc(size_t addr, size_t pfn)
{
    DWORD oldProtect;
    if (VirtualProtect(reinterpret_cast<void*>(addr), 5, PAGE_EXECUTE_READWRITE, &oldProtect))
    {
        uint8_t* patch = reinterpret_cast<uint8_t*>(addr);
        *patch = 0xE9;
        *reinterpret_cast<uint32_t*>(patch + 1) = static_cast<uint32_t>(pfn - (addr + 5));
        VirtualProtect(reinterpret_cast<void*>(addr), 5, oldProtect, &oldProtect);
        FlushInstructionCache(GetCurrentProcess(), reinterpret_cast<void*>(addr), 5);
    }
}
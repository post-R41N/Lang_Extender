#pragma once
#include <windows.h>
#include <stdint.h>
#include "defs.h"
#include "3rd-party/Hooking.Patterns.h"

template<typename T> size_t getThisCallAddr(T func)
{
    return (size_t)(void*&)func;
}

size_t findPattern(const char* pszPattern, ptrdiff_t offset);
uint8_t writeBYTE(size_t addr, uint8_t val);
void makeNop(size_t addr, size_t size);
size_t setFnAddrInCallOpcode(size_t callPos, size_t pfn);
DWORD writeDWORD(size_t addr, DWORD value);

void injectFunc(size_t addr, size_t pfn);
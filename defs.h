#pragma once
#include <windows.h>
#include <stdint.h>

// Базовые типы, используемые декомпилятором
//typedef uint8_t  BYTE;
//typedef uint16_t WORD;
//typedef uint32_t DWORD;
typedef uint64_t QWORD;

// Универсальный макрос для обращения к произвольному байту по его индексу в памяти
#define BYTEn(x, n)   (*((BYTE*)&(x)+(n)))
#define WORDn(x, n)   (*((WORD*)&(x)+(n)))

// Макросы извлечения конкретных байт (считая от младшего к старшему для Little-Endian)
#define BYTE0(x)      BYTEn(x,  0)
#define BYTE1(x)      BYTEn(x,  1)
#define BYTE2(x)      BYTEn(x,  2)
#define BYTE3(x)      BYTEn(x,  3)
#define BYTE4(x)      BYTEn(x,  4)
#define BYTE5(x)      BYTEn(x,  5)
#define BYTE6(x)      BYTEn(x,  6)
#define BYTE7(x)      BYTEn(x,  7)

// Реализация LOBYTE и HIBYTE в стиле IDA Pro
#define LOBYTE(x)     BYTEn(x, 0)

// Внимание: В IDA Pro макрос HIBYTE всегда возвращает САМЫЙ СТАРШИЙ байт переменной 
// в зависимости от её реального размера (например, BYTE1 для 16-бит, BYTE3 для 32-бит или BYTE7 для 64-бит)
#define HIBYTE(x)     (*((BYTE*)&(x)+sizeof(x)-1)) 

// Дополнительные полезные макросы Hex-Rays для работы со словами
#define LOWORD(x)     (*((WORD*)&(x)))
#define HIWORD(x)     (*((WORD*)&(x)+sizeof(x)/2-1))

// Универсальный макрос для обращения к произвольному двойному слову (4 байта) по индексу
#define DWORDn(x, n)  (*((DWORD*)&(x)+(n)))

// Младшие 32 бита (Double Word) из 64-битного числа
#define LODWORD(x)    DWORDn(x, 0)

// Старшие 32 бита (Double Word) из 64-битного числа
#define HIDWORD(x)    DWORDn(x, 1)
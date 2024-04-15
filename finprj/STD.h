/*
definitions for the ANSI linux terminal coloring set
to activate terminal coloring in ypur terminal, open CMD
as admin and type:
reg add HKEY_CURRENT_USER\Console /v VirtualTerminalLevel /t REG_DWORD /d 0x00000001 /f
and to deactivate, type:
reg add HKEY_CURRENT_USER\Console /v VirtualTerminalLevel /t REG_DWORD /d 0x00000000 /f
*/

#define TerminalColorsOff
#define dbsize 5

#if  defined(TerminalColorsOn)
#define R   "\x1b[31m"  //RED
#define G   "\x1b[32m"  //GREEN
#define Y   "\x1b[33m"  //YELLOW
#define B   "\x1b[34m"  //BLUE
#define M   "\x1b[35m"  //MEGENTA
#define C   "\x1b[36m"  //CYAN
#define RST "\x1b[0m"   //Color reset

#elif defined(TerminalColorsOff)
#define R   ""
#define G   ""
#define Y   ""
#define B   ""
#define M   ""
#define C   ""
#define RST ""
#endif


#define NULL ((void*)0)   // definition for the NULL as a void pointer pointing at 0 to be used instead of 0 as a NULL
#define u32 0xffffffff    // definition for a 32 bit max size of a unsigned int

typedef unsigned char  uint8;      // unsigned 8 bit var
typedef char           Int8;       // signed 8 bit var
typedef unsigned short uint16;     // unsigned 16 bit var
typedef short          int16;      // signed 16 bit var
typedef unsigned int   uint32;     // unsigned 32 bit var
typedef int            int32;      // signed 32 bit var
typedef enum{false,true}bool;      // logic var

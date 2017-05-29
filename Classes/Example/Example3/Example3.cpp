#include "Example3.h"

Example3::Example3()
: _answer("")
{
}

Example3::~Example3()
{
}

std::string Example3::calcAnswer()
{
    uint32_t src = 0x1234ABCD;
    uint32_t dst = *swapByteAsm(&src);

    printf("src: %08x\ndst: %08x\n", src, dst);

    return _answer;
}

uint32_t* Example3::swapByte(uint32_t* src)
{
    char dst[4];
    char *p = (char*)src;

    // byte swap
    dst[3] = *p++;
    dst[2] = *p++;
    dst[1] = *p++;
    dst[0] = *p;

    return (uint32_t*)dst;
}

uint32_t* Example3::swapByteAsm(uint32_t* src)
{
    uint32_t *dst;

    asm volatile (
                  "LDR r4, [%[src]] \t\n"
                  "LDR r6, [%[dst]] \t\n"

                  "AND r5, r4, 0xff \t\n"
                  "ORR r6, r5, r6 \t\n"
                  "LSL r6, r6, #8 \t\n"
                  "LSR r4, r4, #8 \t\n"

                  "AND r5, r4, 0xff \t\n"
                  "ORR r6, r5, r6 \t\n"
                  "LSL r6, r6, #8 \t\n"
                  "LSR r4, r4, #8 \t\n"

                  "AND r5, r4, 0xff \t\n"
                  "ORR r6, r5, r6 \t\n"
                  "LSL r6, r6, #8 \t\n"
                  "LSR r4, r4, #8 \t\n"

                  "AND r5, r4, 0xff \t\n"
                  "ORR r6, r5, r6 \t\n"

                  "STR r6, [%[dst]] \t\n"
                  :[dst]"+r"(dst), [src]"+r"(src)
                  :
                  :"r4", "r5", "r6"
                  );

    return dst;
}

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
    uint32_t dst = *swapByte(&src);

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

#include "Example2.h"

Example2::Example2()
: _answer("")
{
}

Example2::~Example2()
{
}

std::string& Example2::calcAnswer()
{
    std::string buf1 = "";
    std::string buf2 = "12345";
    size_t size = 6;

    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

    copyMemory(&buf1, &buf2, size);

    std::chrono::system_clock::time_point end = std::chrono::system_clock::now();

    double elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
    printf("処理時間: %f[μs]\n", elapsed);

    _answer = buf1;

    return _answer;
}

void Example2::copyMemory(void *dst, const void *src, size_t size)
{
    memcpy(dst, src, size);
}
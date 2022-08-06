#include <Windows.h>
#include <iostream>

#include "memory.hpp"
#include "dump.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("[!] Incorrect usage.\n[>] Usage: %s abc.exe", argv[0]);
        return -1;
    }

    if (!memory::init(argv[1]))
    {
        printf("[!] Failed to initialize memory\n");
        return -1;
    }

    if (!dumper::dump())
    {
        printf("[!] Failed to dump process\n");
        return -1;
    }

    return 0;
}
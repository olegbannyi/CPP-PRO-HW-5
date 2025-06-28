#include "util.h"
#include <cstring>

bool is_reference_mode(int argc, char **argv)
{
    const char *refMode = "--ref";

    if (argc < 2)
    {
        return false;
    }

    for (int i = 1; i < argc; ++i)
    {
        if (std::strcmp(refMode, argv[i]) == 0)
        {
            return true;
        }
    }

    return false;
}

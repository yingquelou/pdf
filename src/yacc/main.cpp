#include "pch.h"
int main(int argc, char const *argv[])
{
    yyset_debug(0);
    for (size_t i = 1; argv[i]; i++)
    {
        FILE *f = fopen(argv[i], "rb");
        yyset_in(f);
        yy::parser parser;
        parser();
        fclose(f);
    }

    return 0;
}

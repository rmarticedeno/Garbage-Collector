#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "engine.h"

extern char** board;
int count;

int main(int args, const char** argv)
{
    int i;
    void* dl = dlopen("./Engine/mov.so", RTLD_LAZY);
    int(*fdm)(char**,int) = dlsym(dl, "fdm");
    init();
    count = 1;
    for(i = 0; i < 250; ++i, ++count)
    {
        move(fdm(board,count));
        if (count % 4 == 0)
        {
            gg();
        }
        print();
        sleep(1);
    }
    dlclose(dl);
    dispose();
}

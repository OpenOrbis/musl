int main();

extern void(*__init_array_start[])(void);
extern void(*__init_array_end[])(void);

static int _init_and_main(int argc, void* argv, void* envp)
{
    for(void(**i)(void) = __init_array_start; i != __init_array_end; i++)
        i[0]();
    return main(argc, argv, envp);
}

#define main _init_and_main
#include "crt1.c"

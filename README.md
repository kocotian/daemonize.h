# daemonize.h
simply daemonize your program

## simple usage:
1. `#include "daemonize.h"` in your project
2. write `daemonize()` on beginning of your main with parameters:
    1. **chdir** directory, for example `"/"`
    2. **umask**, for example `0022`
3. remember to write `void signalize(void)` function, otherwise linker will errorize.

## license:
do what the fuck you want to

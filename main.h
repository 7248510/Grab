//Core header files
//-Wextra = extra warning flags
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined (_WIN32)
    #include <windows.h>
    #include "windows/windows.c"
#endif
#if __linux__
    #include "linux/linux.c" 
#endif

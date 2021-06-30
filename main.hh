//Core header files
//-Wextra = extra warning flags
#include <stdio.h> //c
#include <stdlib.h> //c
#include <string.h> //c
#include <iostream> //c++
#include <string> //c++
#include "cross.cc"
#if defined (_WIN32)
    #include <windows.h>
    #include "windows/windows.c"
#endif
#if __linux__
    #include "linux/linux.c" 
#endif

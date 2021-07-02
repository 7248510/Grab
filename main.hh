//Core header files
//-Wextra = extra warning flags
#include <stdio.h> //C
#include <stdlib.h> //C
#include <string.h> //C
#include <iostream> //C++
#include <string> //C++
#include "cross.cc"
//For the GCC compiler/I do not know if cl has the same parameters for headers.
#if defined (_WIN32)
    #include <windows.h>
    #include "windows/windows.c"
#endif
#if __linux__
    #include "linux/linux.c" 
#endif

//Core header files
//-Wextra = extra warning flags(Linux)
#include <iostream> //C++
#include <stdio.h> //C
#include <stdlib.h> //C
#include <string.h> //C
#include <stdbool.h> //false keyword
//For the GCC compiler/I do not know if cl has the same parameters for headers.
#if defined (_WIN32)
    #include "windows/windows.h"
    #include "windows/builds.c"
    #include "windows/windows.c"
    #include "cross.cc" //Independent file. This will call the launch function in Windows or Linux.
#endif
#if __linux__
    #include "linux/linux.c" 
    #include "cross.cc"
#endif

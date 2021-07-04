//This program may be insecure. I'm in the process of learning secure programming!
//Initial a programs to download and execute binary files on Windows & Linux
//curl http://10.0.1.4/sampleZip.zip -o test.zip
//https://us-cert.cisa.gov/bsi/articles/knowledge/coding-practices/fgets-and-gets_s
//https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/fgets-fgetws?view=msvc-160
//https://www.ibm.com/docs/en/i/7.4?topic=functions-fgets-read-string
//Effective C
#define WIN32_LEAN_AND_MEAN
//Define WIN32_LEAN_AND_MEAN to exclude APIs such as Cryptography, DDE, RPC, Shell, and Windows Sockets.
//^MSDN
#include <windows.h>
#pragma comment(lib, "netapi32.lib") 
//NetUserChangePassword
#include <lmaccess.h> //nstatus
#include <windows.h> //Create process
#include <stdio.h>
#include <stdbool.h> //false keyword
/*This program will download files using curl on Windows 10. 
This program will be in 3 repositorys. 
Low level as a template. 
Windows for an example and Initial as a core component/module.
*/
//cl /EHsc /sdl /W4 /TC main.c
//cl /EHsc /sdl /W4 /TC downloadProc.c && downloadProc.exe 
void passURL(char * passedURL) {
    //https://docs.microsoft.com/en-us/windows/win32/procthread/creating-processes
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    SecureZeroMemory (&si, sizeof(si));
    si.cb = sizeof(si);
    SecureZeroMemory (&pi, sizeof(pi));
    LPCSTR applicationName = NULL;
    LPSECURITY_ATTRIBUTES defaultAttr = NULL;
    LPSECURITY_ATTRIBUTES handleThread = NULL;
    BOOL inheritHandle = false;
    DWORD createFlags = 0; 
    LPVOID environment = NULL;
    LPCSTR currentDir = NULL;
    if (!CreateProcess(
        applicationName,
        passedURL, //Binary to download
        defaultAttr, //The security handles can be default    
        handleThread, //Thread does not need to be inherited  
        inheritHandle, //The handles do not need to be inherited
        createFlags, //The process inherits both the error mode of the caller and the parent's console. MSDN
        environment, //Use the new processes environment for the calling process
        currentDir, //Use the current directory
        &si, //Get SI's pointer
        &pi //Pi's pointer
    ));
    else {
        if (GetLastError() == 0) {
            printf("Successfully executed\n"); //The operation completed successfully. https://docs.microsoft.com/en-us/windows/win32/debug/system-error-codes--0-499-
        }
        if (GetLastError() != 0) {
            printf("\nError Code: %d", GetLastError()); //Error occurs see https://docs.microsoft.com/en-us/windows/win32/debug/system-error-codes
        }
    }
    // Wait until child process exits.
    WaitForSingleObject(pi.hProcess, INFINITE);
    // Close process and thread handles. 
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}
void download()
{
    //I recommend hosting a local HTTP server. URL'S to some of the sites are extremely long. I'll publish an HTTP server in Python or Golang. With sample files
    char * urls[3] = {"curl -O http://10.0.1.4/py.zip", 
    "curl -O http://10.0.1.4/files.zip",
    "curl -O http://10.0.1.4/aspnet_core_mvc.zip"}; //Replace the urls with custom ones.
    for (int index = 0; index < sizeof(urls); index++) {
        passURL(urls[index]);
    }
}
int main()
{
    download();
}

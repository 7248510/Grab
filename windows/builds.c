//cyber
//development
//internet
//all
//Implement Structs & createprocess
/*
    Origninally I planned on using classes. Currently I do not need hide and data or need access control.
    Structs appear to be better in this sitution
*/
//After downloading X amount of VM's the password became annoying.
struct initRemove {
    int status = 0;
    const wchar_t domainName = NULL; //Using the current domain
    const wchar_t userName = NULL; //Using the current logged in user
    const wchar_t *oldPassword = L"Passw0rd!"; //The default microsoft VM password
    const wchar_t *newPassword = L""; //The new password value is blank. I'm removing the password. If you'd like a password type one within the quotes.
    int removePassword() {
        NET_API_STATUS nStatus;
        nStatus = NetUserChangePassword(NULL,NULL,oldPassword,newPassword);
        if (nStatus == 0){
            printf("The password has been succesfully changed.");
            status = EXIT_SUCCESS;
            return status;
        }
        if (nStatus == 86) {
            printf("You've entered the wrong password in the old password variable.\n");
            status = EXIT_FAILURE;
            return status;
        }
        else if (nStatus != 86 && nStatus != 0) {
            printf("Unknown error. Error code: %d", nStatus);
            status = EXIT_FAILURE;
            return status;
        }
        return 0;
    }
};

void makeDirectories(char *folderName)
{
        int default = CreateDirectory(folderName, NULL);
        if (default == 0) {
        { 
            int errorCode = GetLastError();
            if (errorCode == 183) {
                printf("Do not worry. Error code: %d means that the directory is already created!\n", errorCode);
            }
            else {
                printf("CreateDirectory failed (%d)\n", GetLastError()); 
                printf("Error codes https://docs.microsoft.com/en-us/windows/win32/debug/system-error-codes--0-499-");
                return;
            }
        } 
    }
}
//These functions are generic. Local encapsulation is not required. The data can be visible :)

void buildFolders(int key)
{
    int default = CreateDirectory("builds", NULL);
        if (default == 0) {
        { 
            int errorCode = GetLastError();
            if (errorCode == 183) {
                printf("Do not worry. Error code: %d means that the directory is already created!\n", errorCode);
            }
            else {
                printf("CreateDirectory failed (%d)\n", GetLastError()); 
                printf("Error codes https://docs.microsoft.com/en-us/windows/win32/debug/system-error-codes--0-499-");
                return;
            }
        } 
    }
        char * urls[4] = {"builds/all", "builds/cyber","builds/development","builds/web"}; //Replace the folder names for each build
        makeDirectories(urls[key]);
}
void passURL(char * programName, char* buildDirectory) {
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
    //LPCSTR currentDir = NULL;

    if (!CreateProcess(
        applicationName,
        programName, //Binary to download
        defaultAttr, //The security handles can be default    
        handleThread, //Thread does not need to be inherited  
        inheritHandle, //The handles do not need to be inherited
        createFlags, //The process inherits both the error mode of the caller and the parent's console. MSDN
        environment, //Use the new processes environment for the calling process
        buildDirectory, //Use the current directory/Use the given build's folder
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

struct cyber {
    void cyberInit() {
        printf("Cyber build selected\n");
    }
    void downloadCyber()
    {
        //"builds/all", "builds/cyber","builds/development","builds/web"
        char * cyberDirectory = "builds/cyber";
        char * urls[1] = {"curl -O http://10.0.1.4/development.txt"}; //Replace the urls with custom ones.
        for (int index = 0; index < sizeof(urls); index++) {
            passURL(urls[index], cyberDirectory);
        }
    }
};

struct dev {
    void devInit() {
        printf("Developer build selected\n");
    }
    void downloadDev()
    {
        char * devDirectory = "builds/development";
        char * urls[2] = {"curl -O http://10.0.1.4/development.txt", 
        "curl -O http://10.0.1.4/web.txt"}; //Replace the urls with custom ones.
        for (int index = 0; index < sizeof(urls); index++) {
            passURL(urls[index], devDirectory);
        }
    }
};

struct internet {
    void internetInit() {
        printf("Internet build selected\n");
    }
    void downloadInternet()
    {
        char * internetDirectory = "builds/web";
        char * urls[3] = {"curl -O http://10.0.1.4/development.txt", 
        "curl -O http://10.0.1.4/web.txt",
        "curl -O http://10.0.1.4/cyber.txt"}; //Replace the urls with custom ones.
        for (int index = 0; index < sizeof(urls); index++) {
            passURL(urls[index], internetDirectory);
        }
    }
};

struct all {
    void allInit() {
        printf("All build selected.\n");
    }
    void downloadAll()
    {
        char * allDirectory = "builds/all";
        char * urls[4] = {"curl -O http://10.0.1.4/development.txt", 
        "curl -O http://10.0.1.4/web.txt",
        "curl -O http://10.0.1.4/cyber.txt",
        "curl -O http://10.0.1.4/all.txt"}; //Replace the urls with custom ones.
        for (int index = 0; index < sizeof(urls); index++) {
            passURL(urls[index], allDirectory);
        }
    }
};
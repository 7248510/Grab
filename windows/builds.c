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

struct cyber {
    void cyberInit() {
        printf("Cyber build selected\n");
    }
};

struct dev {
    void devInit() {
        printf("Developer build selected\n");
    }
};

struct internet {
    void internetInit() {
        printf("Internet build selected\n");
    }
};

struct all {
    void allInit() {
        printf("All build selected.\n");
    }
};
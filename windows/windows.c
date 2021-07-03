
//cl /EHsc /TC /W4 /sdl initial.c
//WIP currently I am not working on this function of Initial. 
/*
int curlGrab()
{
    int statusTracker = 0; //by default the program will return a valid status
    puts("Please enter the link you'd like to download");
    char link[2048]; //Hopefully that's enough for most links... If it's not it will be caught
    size_t length = sizeof(link); //2048 bytes
    if (printf("> ") < 0) {
        statusTracker = EXIT_FAILURE; //change the status and return with an error code
        return EXIT_FAILURE;
    };
    char *linkBuf = fgets(link, length, stdin);
    if (linkBuf == NULL || feof(stdin) == EOF) { //if the input buffer is equal to a null pointer or the file stream is equal to End-of-file.
        int errorCode = feof(stdin); //stdin is a file stream
        if (printf("Error code: %d", errorCode) < 0) {return EXIT_FAILURE;};
        if (printf("\nNull character entered.") < 0) {return EXIT_FAILURE;};
        statusTracker = EXIT_FAILURE; //change the status and return with an error code
        return EXIT_FAILURE; //ERROR OCCURRED
    };
    if (printf(linkBuf) < 0) {return EXIT_FAILURE;};
    //curl -o linkBuf
    //Createprocess or system.
    //Modify downloadProc so a user can enter a URL/Create another function similar to download proc.
    return statusTracker;
}
*/

int launch(int key) {
    int status = 0;
    //Because I'm passing a value a check on printf is needed.
    if (printf("Build key: %d\n", key) < 0)
    {
        status = EXIT_FAILURE;
        return status;
    }
    if (key == 1) {
        struct cyber build;
        build.cyberInit();
    }
    if (key == 2) {
        struct dev build;
        build.devInit();
    }
    if (key == 3) {
        struct internet build;
        build.internetInit();
    }
    if (key == 4) {
        struct all build;
        build.allInit();
    }
    
    return status;
}
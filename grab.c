//This program may be insecure. I'm in the process of learning secure programming!
//Grab a programs to download and execute binary files on Windows & Linux
//curl http://10.0.1.4/sampleZip.zip -o test.zip
//https://us-cert.cisa.gov/bsi/articles/knowledge/coding-practices/fgets-and-gets_s
//https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/fgets-fgetws?view=msvc-160
//https://www.ibm.com/docs/en/i/7.4?topic=functions-fgets-read-string
//Effective C
//cl /EHsc /TC /W4 /sdl grab.c
#include "grab.h"

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
        if (printf("Error code: %d", errorCode) < 0);
        if (printf("\nNull character entered.") < 0);
        statusTracker = EXIT_FAILURE; //change the status and return with an error code
        return EXIT_FAILURE; //ERROR OCCURRED
    };
    if (printf(linkBuf) < 0);
    return statusTracker;
}

int main(void)
{
    if(printf("Welcome to Grab\n") < 0);
    curlGrab();
    return;
}


//https://man7.org/linux/man-pages/man3/exec.3.html
//https://www.suchprogramming.com/new-linux-process-c/
#include <unistd.h>
int linuxInstall(const char *passedProgram) 
{
    //printf("%s\n", passedProgram);
    const char *yesFlag = "-y";
    const char *programmingLanguage = "sudo apt install g++ -y";
    const char *shellPath = "/bin/bash";

    char test1[] = "sudo apt-get install git -y";
    system(test1);

    if (execl(shellPath,programmingLanguage, NULL) != 0) {
        printf("FAIL");
        return EXIT_FAILURE;
    }; 
}

int launchLinux() {
    const char *gPlusPlus = "sudo apt get install git -y";
    linuxInstall(gPlusPlus);
}
void talk()
{
    printf("talk\n");
}
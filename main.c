#include "main.h"
int welcome() 
{
    if(puts("Welcome to Initial") == EOF) {
        return EXIT_FAILURE;
    };
}

int main(void)
{
    welcome();
    launchLinux();
    return 0;
}


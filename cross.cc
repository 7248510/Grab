//cl /EHsc /sdl /W4 main.c
//Operating system independent functions.
int welcome() 
{
    if(puts("Welcome to Initial") == EOF) {
        return EXIT_FAILURE;
    };
    return EXIT_SUCCESS;
}

void arguments(int argc, char** argv)
{
    if (argc == 1) {
        //https://docs.microsoft.com/en-us/cpp/cpp/program-termination?view=msvc-160
        printf("\nNo command line arguments were passed\n");
        std::cout << "Terminiating the program";
        exit(EXIT_SUCCESS);
    }
    if (argc > 1) {
        //Because ARGV is a char * you need to set argv to a string to make a comparison. 
        std::string help, loopCompare, compareValue,helpCompare,choice ,windows, linux;
        compareValue = argv[0];//ARGV has to be set
        loopCompare = argv[1];
        help = "-h";
        windows = "-w";
        linux = "-l";
        //for(int i=0; i < argc; i++) {
        helpCompare = argv[1];
        if (helpCompare == help)
        {
            std::cout << "Help options" << std::endl;
            std::cout << "To set up a Windows environment use the -w flag" << std::endl;
            std::cout << "To set up a Linux environment use the -l flag";
        }
        if (helpCompare == linux) {
            //Input Linux options
        }
        if (helpCompare == windows) {
            std::cout << "Enter the Windows build you'd like" << std::endl;
            std::cout << "1. Download cyber security tools\nIncludes: Ghidra, OpenJDK, Python" << std::endl;
            std::cout << "2. Download development tools\nIncludes: Visual Studio Code, Visual studio's Installer, GIT" << std::endl;
            std::cout << "3. Download internet tools\nIncludes: FireFox, Chrome, Node, Python, Visual Studio's Installer" << std::endl;
            std::cout << "4. Download all of the above." << std::endl;
            std::cin >> choice;
            if (choice == "1") {
                 std::cout << "Cyber security build" << std::endl;
            }
            if (choice == "2") {
                std::cout << "Development build" << std::endl;
            }
            if (choice == "3") {
            std::cout << "Internet tools/Web Dev" << std::endl;
            }
            if (choice == "4") {
                std::cout << "All of the above" << std::endl;
            }               
        }
    }
}
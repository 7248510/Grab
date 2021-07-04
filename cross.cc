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
        printf("No command line arguments were supplied\nWindows menu -w\nLinux menu -l\n");
        printf("Terminiating the program");
        exit(EXIT_FAILURE); 
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
            std::cout << "Enter the Linux build you'd like.";
            //Input Linux options
        }
        if (helpCompare == windows) {
            std::cout << "Enter the Windows build you'd like" << std::endl;
            std::cout << "1. Download cyber security tools\nIncludes: Ghidra, OpenJDK, Python" << std::endl;
            std::cout << "2. Download development tools\nIncludes: Visual Studio Code, Visual studio's Installer, GIT" << std::endl;
            std::cout << "3. Download internet tools\nIncludes: FireFox, Chrome, Node, Python, Visual Studio's Installer" << std::endl;
            std::cout << "4. Download all of the above." << std::endl;
            std::cout << "5. Remove the initial password from the Windows 10 VM" << std::endl;
            std::cin >> choice;
            if (choice == "1") {
                 std::cout << "Cyber security build selected" << std::endl;
                 launch(1);
            }
            if (choice == "2") {
                std::cout << "Development build selected" << std::endl;
                launch(2);
            }
            if (choice == "3") {
            std::cout << "Internet tools/Web Dev selected" << std::endl;
                launch(3);
            }
            if (choice == "4") {
                std::cout << "All of the above selected" << std::endl;
                launch(4);
            }
            if (choice == "5") {
                std::cout << "Removing password:" << std::endl;
                launch(5);
            }
            if (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5") { 
                //Currently their are 4 build options in this program. If choice is != to one of the four(may be more || less on Linux)
                printf("Invalid build terminating program.");
                exit(EXIT_FAILURE);
            }               
        }
        if (helpCompare != windows || helpCompare != linux) {
            std::cout << "Unknown argument." << std::endl; std::cout << "Terminating program.";
            exit(EXIT_FAILURE);
        }
    }
}
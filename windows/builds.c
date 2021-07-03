//cyber
//development
//internet
//all
//Implement Structs & createprocess
/*
    Origninally I planned on using classes. Currently I do not need hide and data or need access control.
    Structs appear to be better in this sitution
*/
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
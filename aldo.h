/*
 * aldo.h
 *
 * A custom header files containing my custom functions and shit
 */

void clearscreen() {
    /**
     * A function that detects the running operating system and makes the
     * necessary function calls to clear the screen.
     */
    #if defined(__WIN32__)
        system("cls");
    #endif

    #if defined(__linux__)
        system("clear");
    #endif
}

char inputChar() {
    /*
     * A function that facilitates the handling of one-character inputs,
     * automatically removing newlines whenever necessary.
     */
    char in = 0;
    fflush(stdin);
    
    
}

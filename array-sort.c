/**
 * array-sort.c
 *
 * A small CLI program that simulates three array sorting algorithms, while
 * showing each step visually
 *
 * Written by Aldo Rey Balagulan and Katherine Rollo
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "aldo.h" 

void displayArray(int array[], int arraySize) {
    /*
     * Displays the given array inside a shiny box
     */
    int i;

    printf("| ");
    for(i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
        printf("| ");
    }
}

void insertionSort(int array[], int arraySize, int instant) {
    /** 
     * The insertion sorting algorithm.
     */
    int i, j, k, B, comps;
    int tempArray[arraySize];

    clearscreen();
    printf("INSERTION SORT\n");

    // Transfer the array contents into a temp display array
    for(i = 0; i < arraySize; i++) {
        tempArray[i] = array[i];
    }

    // Display the original array
    printf("\nOriginal Array:\n");
    displayArray(tempArray, arraySize);
    printf("\n");

    k = 1;
    comps = 0;
    for(i = 1; i < arraySize; i++) {
        j = i;
        B = tempArray[i];
        while(j > 0 && tempArray[j - 1] > B) {
            comps += 1;
            tempArray[j] = tempArray[j - 1];
            j--;
        }
        tempArray[j] = B;
        printf("\nArray after iteration %d:\n", k);
        displayArray(tempArray, arraySize);
        printf("\nComparisons: %d\n", comps);
        k = k + 1;

        // Pause if we're not on instant conversion
        if(!instant) {
            getchar();
        }
    }
    printf("\nSorting complete. Press any key to continue.\n");

    getchar();
}

void selectionSort(int array[], int arraySize, int instant) {
    /**
     * The selection sorting algorithm.
     */
    int i, j, k, min, temp;
    int comps, swaps;
    int tempArray[arraySize];

    clearscreen();
    printf("SELECTION SORT\n");

    // Transfer the array into a temporary display array
    for(i = 0; i < arraySize; i++) {
        tempArray[i] = array[i];
    }

    // Display the original array
    printf("\nOriginal Array:\n");
    displayArray(tempArray, arraySize);
    printf("\n");

    k = 1;
    comps = swaps = 0;
    for(i = 0; i < arraySize; i++) {
        min = i;
        for(j = i + 1; j < arraySize; j++) {
            if(tempArray[j] < tempArray[min]) {
                min = j;
            }
            comps += 1;
        }
        // Swap the values
        temp = tempArray[min];
        tempArray[min] = tempArray[i];
        tempArray[i] = temp;
        swaps += 1;

        // Display the array
        printf("\nArray after iteration %d:\n", k);
        displayArray(tempArray, arraySize);
        printf("\nComparisons: %d Swaps: %d\n", comps, swaps);
        k = k + 1;

        // Pause if we are not on instant sorting
        if(!instant) {
            getchar();
        }
    }
    printf("\nSorting complete. Press any key to continue.\n");

    getchar();
}
void bubbleSort(int array[], int arraySize, int instant) {
    /**
     * The bubble sorting algorithm.
     */
    int i, j, k, temp;
    int comps, swaps;
    int tempArray[arraySize];
    
    clearscreen();
    printf("BUBBLE SORT\n");

    // Transfer the contents of the array to a temp array
    for(i = 0; i < arraySize; i++) {
        tempArray[i] = array[i];
    }
   
    // Display the priginal array
    printf("\nOriginal Array:\n");
    displayArray(tempArray, arraySize);
    printf("\n");

    k = 1;
    comps = swaps = 0;
    for(i = arraySize - 1; i > 0; i--) {
        for(j = 0; j < i; j++) {
            if(tempArray[j] > tempArray[j + 1]) {
                // Swap the values
                temp = tempArray[j + 1];
                tempArray[j + 1] = tempArray[j];
                tempArray[j] = temp;
                swaps += 1;
            }
            comps += 1;
        }
        printf("\nArray after iteration %d:\n", k);
        displayArray(tempArray, arraySize);
        printf("\nComparisons: %d Swaps: %d\n", comps, swaps);
        k = k + 1;

        // Pause if we're not on instant sorting
        if(!instant) {
            getchar();
        }
    }
    printf("\nSorting complete. Press any key to continue.\n");

    getchar();
}

void simulate(int arraySize) {
    int array[arraySize];
    int i;
    char opt, opt2;

    clearscreen();

    // Initialize the values of the array to 0
    for(i = 0; i < arraySize; i++) {
        array[i] = 0;
    }

    // First we need to input the values for the array
    for(i = 0; i < arraySize; i++) {
        printf("Enter value for index %d: ", i);
        scanf(" %d%*c", &array[i]);
    }

    // Now we have to make the user choose the sorting algo
    do {
        clearscreen();

        // Display the array.
        printf("Your array:\n");
        displayArray(array, arraySize);

        printf("\n\nChoose your sorting algorithm:\n");
        printf("[a] Bubble\n");
        printf("[b] Selection\n");
        printf("[c] Insertion\n");
        printf("\n[q] Quit\n");
        printf("\nOption: ");
       
        scanf(" %c%*c", &opt);
        opt = tolower(opt);

        switch(opt) {
            case 'a':
                // Bubble sort
                printf("\nWould you like to do it step-by-step? [y/n]: ");
                
                scanf(" %c%*c", &opt2);
                opt2 = tolower(opt2);

                if(opt2 == 'y')
                    bubbleSort(array, arraySize, 0);
                else
                    bubbleSort(array, arraySize, 1);
                break;
            case 'b':
                // Selection sort
                printf("\nWould you like to do it step-by-step? [y/n]: ");
                
                scanf(" %c%*c", &opt2);
                opt2 = tolower(opt2);

                if(opt2 == 'y')
                    selectionSort(array, arraySize, 0);
                else
                    selectionSort(array, arraySize, 1);
                break;
            case 'c':
                // Insertion sort
                printf("\nWould you like to do it step-by-step? [y/n]: ");
                
                scanf(" %c%*c", &opt2);
                opt2 = tolower(opt2);

                if(opt2 == 'y')
                    insertionSort(array, arraySize, 0);
                else
                    insertionSort(array, arraySize, 1);
                break;
            case 'q':
                // Quitting
                printf("Press enter again to quit.\n");
                break;
        }
    }   while(opt != 'q');
}

int main() {
    char opt;
    int arraySize;

    do {
        clearscreen();

        printf("Array sort simulator\n");
        printf("Created by Aldo Rey Balagulan\n\n");
        printf("[a] Simulate\n");
        printf("[q] Quit\n");

        scanf(" %c%*c", &opt);
        opt = tolower(opt);

        switch(opt) {
            case 'a':
                // User wants to simulate
                // Get the size of the array
                do {
                    printf("Enter your array size: ");
                    scanf(" %d%*c", &arraySize);

                    if(arraySize <= 0)
                        printf("Invalid array size!\n");
                }   while(arraySize <= 0);
                simulate(arraySize);
                getchar();
                break;
            case 'q':
                // User wants to quit
                printf("Goodbye!\n");
                getchar();
                break;
        }

    }   while(opt != 'q');

    clearscreen();

    return 0;
}

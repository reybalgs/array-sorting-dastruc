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
#include "aldo.h" 

void displayArray(int array[], int arraySize) {
    /*
     * Displays the given array inside a shiny box
     */
    int i, boxWidth;

    printf("| ");
    for(i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
        printf("| ");
    }
}

void insertionSort(int array[], int arraySize) {
    /** 
     * The insertion sorting algorithm.
     */
    int i, j, k, B;
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
    for(i = 1; i < arraySize; i++) {
        j = i;
        B = tempArray[i];
        while(j > 0 && tempArray[j - 1] > B) {
            tempArray[j] = tempArray[j - 1];
            j--;
        }
        tempArray[j] = B;
        printf("\nArray after iteration %d:\n", k);
        displayArray(tempArray, arraySize);
        printf("\n");
        k = k + 1;
    }
    printf("\nSorting complete. Press any key to continue.\n");

    getchar();
    getchar();
}

void selectionSort(int array[], int arraySize) {
    /**
     * The selection sorting algorithm.
     */
    int i, j, k, min, temp;
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
    for(i = 0; i < arraySize; i++) {
        min = i;
        for(j = i + 1; j < arraySize; j++) {
            if(tempArray[j] < tempArray[min]) {
                min = j;
            }
        }
        // Swap the values
        temp = tempArray[min];
        tempArray[min] = tempArray[i];
        tempArray[i] = temp;

        // Display the array
        printf("\nArray after iteration %d:\n", k);
        displayArray(tempArray, arraySize);
        printf("\n");
        k = k + 1;
    }
    printf("\nSorting complete. Press any key to continue.\n");

    getchar();
    getchar();
}
void bubbleSort(int array[], int arraySize) {
    /**
     * The bubble sorting algorithm.
     */
    int i, j, k, temp;
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
    for(i = arraySize - 1; i > 0; i--) {
        for(j = 0; j < i; j++) {
            if(tempArray[j] > tempArray[j + 1]) {
                // Swap the values
                temp = tempArray[j + 1];
                tempArray[j + 1] = tempArray[j];
                tempArray[j] = temp;
            }
        }
        printf("\nArray after iteration %d:\n", k);
        displayArray(tempArray, arraySize);
        printf("\n");
        k = k + 1;
    }
    printf("\nSorting complete. Press any key to continue.\n");

    getchar();
    getchar();
}

void simulate(int arraySize) {
    int array[arraySize];
    int i;
    char opt;

    clearscreen();

    // Initialize the values of the array to 0
    for(i = 0; i < arraySize; i++) {
        array[i] = 0;
    }

    // First we need to input the values for the array
    for(i = 0; i < arraySize; i++) {
        printf("Enter value for index %d: ", i);
        scanf("%d", &array[i]);
    }

    // Display the array.
    printf("Your array:\n");
    displayArray(array, arraySize);

    // Now we have to make the user choose the sorting algo
    do {
        clearscreen();

        printf("\nChoose your sorting algorithm:\n");
        printf("[a] Bubble\n");
        printf("[b] Selection\n");
        printf("[c] Insertion\n");
        printf("\n[q] Quit\n");
        printf("\nOption: ");
        
        opt = getchar();
        opt = tolower(opt);

        switch(opt) {
            case 'a':
                // Bubble sort
                bubbleSort(array, arraySize);
                break;
            case 'b':
                // Selection sort
                selectionSort(array, arraySize);
                break;
            case 'c':
                // Insertion sort
                insertionSort(array, arraySize);
                break;
        }
    }   while(opt != 'q');
}

int main() {
    char opt;
    int arraySize;

    clearscreen();

    printf("Array sort simulator\n\n");

    do {
        printf("[a] Simulate\n");
        printf("[q] Quit\n");

        opt = getchar();
        opt = tolower(opt);

        printf("Opt: %c\n", opt);

        switch(opt) {
            case 'a':
                // User wants to simulate
                // Get the size of the array
                do {
                    printf("Enter your array size: ");
                    scanf("%d", &arraySize);

                    if(arraySize <= 0)
                        printf("Invalid array size!\n");
                }   while(arraySize <= 0);
                simulate(arraySize);
                break;
            case 'q':
                // User wants to quit
                printf("Goodbye!\n");
                break;
        }

    }   while(opt != 'q');

    clearscreen();

    return 0;
}

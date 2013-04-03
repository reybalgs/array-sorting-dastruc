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

void insertionSort(int array[], int arraySize) {
    /** 
     * The insertion sorting algorithm.
     */
    int i, j, B;
    for(i = 1; i < arraySize; i++) {
        j = i;
        B = array[i];
        while(j > 0 && array[j - 1] > B) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = B;
    }
}

void selectionSort(int array[], int arraySize) {
    /**
     * The selection sorting algorithm.
     */
    int i, j, min, temp;
    for(i = 0; i < arraySize; i++) {
        min = i;
        for(j = i + 1; j < arraySize; j++) {
            if(array[j] < array[min]) {
                min = j;
            }
        }
        // Swap the values
        temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }
}

void bubbleSort(int array[], int arraySize) {
    /**
     * The bubble sorting algorithm.
     */
    int i, j, temp;
    for(i = arraySize - 1; i > 0; i--) {
        for(j = 0; j < i; j++) {
            if(array[j] > array[j + 1]) {
                // Swap the values
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void simulate(int arraySize) {
    int array[arraySize];
    int i;
    char opt;

    // First we need to input the values for the array
    for(i = 0; i < arraySize; i++) {
        printf("Enter value for index %d: ", i);
        scanf(" %d ", &array[i]);
    }

    // Now we have to make the user choose the sorting algo
    do {
        printf("\nChoose your sorting algorithm:\n");
        printf("[a] Bubble\n");
        printf("[b] Selection\n");
        printf("[c] Insertion\n");
        printf("\n[q] Quit\n");
        printf("\nOption: ");
        
        opt = getchar();
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
        opt = getchar();
        opt = tolower(opt);

        switch(opt) {
            case 'a':
                // User wants to simulate
                // Get the size of the array
                do {
                    printf("Enter your array size: ");
                    scanf(" %d ", &arraySize);

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

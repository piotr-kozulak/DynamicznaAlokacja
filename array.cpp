//
// Created by Piotr on 16.05.2024.
//
#include "array.h"
#include <stdio.h>
#include <stdlib.h>
FILE * fptr;
int findMaximumValue(int array[], int SIZE) {
    int max = array[0];
    for (int i = 0; i < SIZE; ++i )
    {
        if(array[i] > max) max = array[i];
    }
    return max;
}
int findMiniumValue(int array[], int SIZE) {
    int min = array[0];
    for (int i = 0; i < SIZE; ++i )
    {
        if(array[i] < min) min = array[i];
    }
    return min;
}
float calculateAverage(int array[], int SIZE){
    int sum = 0;
    for (int i = 0; i < SIZE; ++i ) {
        sum = sum + array[i];
    }
    float avg = (float)sum / SIZE;
    return avg;
}
void fileenter(int array[], int SIZE)
{
    fptr = fopen("letters.txt", "w+");
    if (fptr == 0)
    {
        exit(1);
    }
    for (int u = 0; u < SIZE ; ++u)
    {
        fputc(array[u], fptr);
    }

    fclose(fptr);
}
void readFile(int array[], int SIZE)
{
    fptr = fopen("letters.txt", "r+");
    fseek(fptr, 0, SEEK_SET);
    printf("File content:\n");
    for (int i = 0; i < SIZE; i++)
    {
        array [i] = fgetc(fptr);
        fseek(fptr, 0, SEEK_CUR);
        printf("%d\n", array [i]);
    }
    printf("\n");
    fclose(fptr);
}
int* enterValue(int *array, int *s) {
    int element;
    (*s)++;
    array = (int *)realloc(array, (*s) * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation error!");
        exit(1);
    }
    printf("Enter number to add: ");
    scanf("%d", &element);
    array[(*s) - 1] = element;
    return array;
}
void printArray(int array[], int s)
{
    for (int i = 0; i < s; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    printf("\n");
}
int* deleteValues(int *array, int *s) {
    if (*s == 0) {
        printf("Array is already empty!\n");
        return array;
    }
    (*s)--;
    array = (int *)realloc(array, (*s) * sizeof(int));
    if (array == NULL && *s > 0) {
        printf("Memory allocation error!");
        exit(1);
    }
    return array;
}
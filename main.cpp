#include <stdio.h>
#include <stdlib.h>
#include "array.h"
void menu() {
    printf("1- intput Values\n");
    printf("2- Delete Values\n");
    printf("3- Print Array\n");
    printf("4- Find Maximum Value\n");
    printf("5- Find MinimumValue\n");
    printf("6- Calculate Average\n");
    printf("7- Enter to file\n");
    printf("8- Read  file\n");
    printf("9- Stop Program\n");
}

int main() {
    int *array = NULL;
    int option = 0;
    int min;
    int max;
    float avg;
    int SIZE = 0;
    while(option!=9) {
        menu();
        printf("choice = ");
        scanf("%d", &option);
        switch(option){
            case 1 :
                array = enterValue(array, &SIZE);
                break;
            case 2 :
                deleteValues(array,&SIZE);
                break;
            case 3 :
                printArray(array, SIZE);
                break;

            case 4 :
                max = findMaximumValue(array,SIZE);
                printf("maximium value = %d\n",max);
                break;
            case 5 :
                min = findMiniumValue(array,SIZE);
                printf("minimum value = %d\n",min);
                break;
            case 6:
                avg= calculateAverage(array,SIZE);
                printf("Average value = %f\n", avg);
            case 7 :
                fileenter(array,SIZE);
                puts("Array written");
                break;
            case 8 :
                readFile(array,SIZE);
                break;
            case 9 :
                break;



        }
    }
    free(array);
}
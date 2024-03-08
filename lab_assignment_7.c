//Arav Tulsi
//Dr. Nslisah Torosdalgi
//COP3502C
//Lab Assignment 6

//libraries
#include <stdio.h>
#include <stdlib.h>

//prototypes
int bubbleSort (int arr [], int size); //moves each value as far right as possible
void swap (int* arr, int index1, int index2); //swap values in an array
int selectSort (int arr [], int size); //moves smallest value as far left as possible
void printArray (int * arr, int size); //prints an entire int array

//Programme start
int main (void) //driver code
{
    //var decalaration
    int arr1 [9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2 [9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int count;

    //Pass each array int the function to 
    //create a copy, thereby preserving 
    //the source for each run

    printf ("\n----------Programme Start---------- \n"); //Design -Header

    //Bubble sort each array
    printf("\n**********\n"); //Design -Border
    count = bubbleSort(arr1, 9);
    printf ("BubbleSort Arr1 has %d swaps\n", count);

    printf("\n**********\n"); //Design -Border
    count = bubbleSort(arr2, 9);
    printf ("BubbleSort Arr2 has %d swaps\n", count);

    //Select sort each array
    printf("\n**********\n"); //Design -Border
    count = selectSort(arr1, 9);
    printf ("SelectSort Arr1 has %d swaps\n", count);
    
    printf("\n**********\n"); //Design -Border
    count = selectSort(arr2, 9);
    printf ("SelectSort Arr2 has %d swaps\n", count);

    printf ("\n----------Programme End---------- \n"); //Design - footer
}
//Programme end


//User defined functions:

//logic:
//store first value 
//check next value
//if larger, swap
//sorts last value first
int bubbleSort (int arr [], int size)
{   
    //variabe declaration;
    int count = 0; //total number of swaps
    int i, j, numswap; //temporary variables for traversal

    //display pre-sort array
    printf("\nArray before sort: \n");
    printArray(arr, size);

    //outer traversal loop
    for ( i = 0; i < size-1; i++)
    {
        numswap = 0; //number of times value moved
        
        //inner traversal and swapping loop
        for ( j = i +1; j < size; j++)
        {
            //only swap if value is smaller than
            //in-sort item
            if (arr[i] > arr[j])
            {
                swap (arr, i, j);
                count++;
                numswap++;
            }
        }
        printf ("Number of times %d is moved is: %d. \n", arr[i], numswap);
    }

    //display post-sort array
    printf("\nArray after sort: \n");
    printArray(arr, size);

    return count;
}

//swaps values
void swap (int* arr, int index1, int index2)
{
    int temp = arr[index1];
    arr [index1] = arr [index2];
    arr [index2] = temp;
}

//logic:
//find smallest value
//move to front
//find next smallest value
//move it after front
//sorts smallest value first
int selectSort (int arr [], int size)
{
    int count = 0; //total number of swaps
    int minIndex = -1; //uninitialised
    int i, j, numswap; //temporary sorting variables

    //display pre-sort array
    printf("\nArray before sort: \n");
    printArray(arr, size);

    //outer traversal loop
    for ( i = 0; i < size; i++)
    {
        numswap =0; //num swaps of each value

        //inner searching loop
        for (j = i; j <size -1; j++)
        {   
            //store location of smallest value
            if (arr [j] < minIndex)
            minIndex = j;
        }

        //swap the ith index with the smallest
        if (i != minIndex)
        {    swap (arr, i, minIndex);
            count++;
            numswap++;
        }

        printf ("Number of times %d is moved is: %d \n", arr[i], numswap);
    }

    //display post-sort array
    printf("\nArray after sort: \n");
    printArray(arr, size);

    return count;
}

void printArray (int * arr, int size)
{
    printf ("{ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf ("}\n\n");
}
// q1.c - Assignment 03 - Muhammad Saad Iqbal
#include <stdio.h>
#include <stdlib.h>

// data structure representing dates
typedef struct {
    int day;
    int month;
    int year;
} date;

// helper function to compare given 2 dates
int CompareDates(date d1, date d2) {
    // if there are different years
    if (d1.year != d2.year) {
        return d1.year - d2.year;
    }

    // if there are different months
    if (d1.month != d2.month) {
        return d1.month - d2.month;
    }

    // return difference between days
    return d1.day - d2.day;
}


// DateSort() function to sort array of dates using quicksort method
void DateSort(date *dates, int low, int high) {

    date temp;

    // Avoid cases of one or zero elements
    if (low >= high) {
        return;
    }

    // setting pivot point
    int pivot = low;

    // partition array around the pivot
    int i = low;
    int j = high;

    while (i < j) {

        // elements belonging to right side of pivot
        while (CompareDates(dates[i], dates[pivot]) < 0) {
            i++;
        }

        // elements belonging to left side of pivot
        while (CompareDates(dates[j], dates[pivot]) > 0) {
            j--;
        }

        // swapping elements
        if (i < j) {
            temp = dates[i];
            dates[i] = dates[j];
            dates[j] = temp;
        }
    }

    // for last elements, set manually
    temp = dates[pivot];
    dates[pivot] = dates[j];
    dates[j] = temp;

    // recursive calls to sort the left and right partitions
    DateSort(dates, low, j-1);
    DateSort(dates, i+1, high);
}


int main(void) {

    // read in number of dates
    int n;
    printf("Enter the number of dates: ");
    scanf("%d", &n);

    // list of dates
    date *dates = malloc(n * sizeof(date));
    // read in each individual date
    for (int i = 0; i < n; i++) {
        printf("Enter date #%d (DD MM YYYY): ", i + 1);
        scanf("%d%d%d", &dates[i].day, &dates[i].month, &dates[i].year);
    }

    // sort the dates
    DateSort(dates, 0, n - 1);

    // print the sorted dates
    printf("\nSorted dates:\n");
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("{%02d, %02d, %d}", dates[i].day, dates[i].month, dates[i].year);

        if (i!= n-1) printf(", ");
    }
    printf("}");

    // free up memory
    free(dates);

    return 0;
}

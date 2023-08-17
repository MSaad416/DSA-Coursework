// Iqbal, Muhammad Saad

int quickSort2(int *a, int left, int right) {
        if (verbose)
            printf ("\nQuicksort: left = %d   right = %d\n", left, right);
        if (left < right) {
            int  pivotndx = partition (a, left, right);
            if (verbose) {
                printf ("    Completed partition, pivot at: %d\n", pivotndx);
                printarrowatposition (pivotndx);
                printarray (NULL, a, 0, MAXINDEX, 1000);
            }

            if ( (pivotndx != left) && (pivotndx - left) < 32 ){
                insertionsort (a, left, pivotndx-1);
            }
            else {
                quickSort2 (a, left, pivotndx-1);
            }

            if ( (pivotndx != right) && (right - pivotndx) < 32 ){
                insertionsort (a, pivotndx+1, right);
            }
            else {
                quickSort2 (a, pivotndx+1, right);
            }

        }
        return swaps;
}
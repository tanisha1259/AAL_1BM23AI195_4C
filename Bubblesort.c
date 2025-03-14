#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void bubbleSort(int arr[], int n, int *operations, double *time_taken) 
{
    int i, j, temp;
    *operations=0;
    clock_t start, end;

    start=clock();
    for (i=0; i<n-1; i++) 
    {
        for (j=0; j<n-i-1; j++) 
        {
            (*operations)++;
            if (arr[j]>arr[j+1]) 
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                (*operations)++;
            }
        }
    }
    end=clock();
    *time_taken=((double)(end-start))/CLOCKS_PER_SEC;
}

int main() 
{
    int sizes[]={10, 50, 100, 1000};
    int num_sizes=sizeof(sizes)/sizeof(sizes[0]);
    int arr[1000];
    int i, j, n, operations;
    double time_taken;
    double log_n, n_by_count, n_squared_by_count, nlog_n_by_count;

    srand(time(0));
    printf("Metric         10          50         100        1000\n");

    printf("log(n)/count  ");
    for (i=0; i<num_sizes; i++) 
    {
        n=sizes[i];
        for (j=0; j<n; j++) 
        { 
            arr[j]=rand()%1000+1;
        }
        bubbleSort(arr, n, &operations, &time_taken);
        log_n=log(n)/operations;
        printf("%10.6f ", log_n);
    }
    printf("\n");
    printf("n/count       ");
    for (i=0; i<num_sizes; i++) 
    {
        n=sizes[i];
        n_by_count=(double)n/operations;
        printf("%10.6f ", n_by_count);
    }
    printf("\n");

    printf("n^2/count     ");
    for (i=0; i<num_sizes; i++) 
    {
        n=sizes[i];
        n_squared_by_count=(double)(n*n)/operations;
        printf("%10.6f ", n_squared_by_count);
    }
    printf("\n");

    printf("nlog(n)/count ");
    for (i=0; i<num_sizes; i++) 
    {
        n=sizes[i];
        nlog_n_by_count=(n*log(n))/operations;
        printf("%10.6f ", nlog_n_by_count);
    }
    printf("\n");
    return 0;
}

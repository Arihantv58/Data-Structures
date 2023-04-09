#include<stdio.h>
#include<math.h>

void swap(int* x, int* y)
{
    int temp;
    temp= *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int arr[],int n)
{
    int i,j,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            swap(&arr[min],&arr[i]);
        }
    }
}

void print_array(int arr[],int n)
{
    int i;
    printf("Sorted array is :\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[]={12,11,13,6,4,5,3};
    int n= sizeof(arr)/sizeof(arr[0]);

    selection_sort(arr,n);
    print_array(arr,n);

    return 0;
}
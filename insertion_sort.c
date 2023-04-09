#include<stdio.h>
#include<math.h>

void insertion_sort(int arr[],int n)
{
    int i,j,key;
    for(i=0;i<n;i++)
    {
        key=arr[i];
        j=i-1;

        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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

    insertion_sort(arr,n);
    print_array(arr,n);

    return 0;
}
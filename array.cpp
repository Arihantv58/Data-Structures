#include<iostream>
using namespace std;

int main()
{
    int arr[20];
    int n,key;
    cout<<"Enter n : ";
    cin>>n;
    cout<<"Enter all the values :\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the key value you want to to insert : ";
    cin>>key;
    
    for(int i=n-1;i>=0;i--)
    {
        arr[i+1]=arr[i];
    }
    n=n+1;
    arr[0]=key;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
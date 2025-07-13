#include<iostream>
using namespace std;

int main()
{
    int a;
    cout<<"Enter the size of array: "<<" ";
    cin>>a;

    int arr[a];
    cout<<"Enter the array elements : "<<" ";
    for(int i=0;i<a;i++)
    {
        cin>>arr[i];
    }

    int low=0,high=a-1;
    int count=0;

    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==0)
        {
            count=mid;
            high=mid-1;

        }
        else{
            low=mid+1;

        }
    }

    cout<<"The No Of Zeroes are : "<<a-count;
    return 0;
}
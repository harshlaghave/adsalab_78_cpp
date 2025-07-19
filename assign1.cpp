/*
Problem:Arrays of 1's and 0's which have all 1's followed by 0's.Find no of zeroes.Give count 
of no of zeroes in given arrays

Input:1 1 1 1 0 0
Output:The no of zeroes are:2 

Approach : Using Binary search Algorithm

*/




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

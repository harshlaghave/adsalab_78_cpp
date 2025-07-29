/*
problem:Implement problem of smallest number with atleast no. of trailing zeroes in a 
factorial

input:n=2
output:10

*/




#include<iostream>
using namespace std;

int countzero(int x)
{
    int count=0;
    while(x>=5)
    {   
        count=count+(x/5);
        x/=5;

    }

    return count;
}

int counttrailingzero(int n)
{
    int low=1;
    int high=5*n;
    int res=-1;

    while(low<=high && n!=5)
    {
        int mid=(low+high)/2;
        int zero=countzero(mid);
        if(zero>=n)
        {
            res=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return res;
}

int main()
{   

    int n;
    cout<<"Enter the number: "<<" ";
    cin>>n;

    cout<<"The smallest factorial number is :  "<<counttrailingzero(n);

    return 0;
}
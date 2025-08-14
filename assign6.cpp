/*
Problem:Implement a problem of activity selection problem with K persons. Statement: Given two arrays S[] and E[] of size N denoting starting and closing time of the shops and an integer value K denoting the number of people, the task is to find out the maximum number of shops they can visit in total if they visit each shop optimally based on the following conditions:
• A shop can be visited by only one person.
A person cannot visit another shop if its timing collides with it.

input:Enter Number Of Shops:
ENter The starting time:6,2,5
enter ending time:4,8,6

Output:3

*/



#include<iostream>
using namespace std;
#define MAX 100

struct makeone
{
    int start;
    int end;

};

void shopsort(makeone one[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(one[j].end>one[j+1].end)
            {
                makeone temp=one[j];
                one[j]=one[j+1];
                one[j+1]=temp;
            }
        }
    }

}

int  shopvisit(int size,makeone a[],int person)
{
   
  

    shopsort(a,size);

    int personvisit[MAX]={0};

    int count=0;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<person;j++)
        {
            if(personvisit[j]<=a[i].start)
            {
                personvisit[j]=a[i].end;
                count++;
                break;

            }
        }

    }
    return count;
}

int main()
{   
    

    int shops;
    cout<<"Enter the number of shops : "<<" ";
    cin>>shops;
    makeone n[MAX];

    int start[shops];
    cout<<"Enter the starting time : "<<" ";
    for(int i=0;i<shops;i++)
    {
        cin>>n[i].start;
    }

    int end[shops];
    cout<<"Enter the Ending time : "<<" ";
    for(int i=0;i<shops;i++)
    {
        cin>>n[i].end;
    }

   int ans= shopvisit(shops,n,2);
    cout<<ans;
    
   


    return 0;

}
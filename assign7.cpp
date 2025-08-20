/*Problem statement:Implement a problem of maximize Profit by trading 
stocks based on given rate per day.
Statement: Given an array arr[] of N positive integers 
which denotes the cost of selling and buying a stock on 
each of the N days. The task is to find the maximum 
profit that can be earned by buying a stock on or selling 
all previously bought stocks on a particular day.
Input: arr[] = {2, 3, 5} Output: 5
Input: arr[] = {8, 5, 1} Output: 0 */



#include<iostream>
using namespace std;

int main()
{   
    int n;
    cout<<"Enter the No of Days: "<<" ";
    cin>>n;
    int a[n];
    cout<<"Enter The stocks Prices:  " <<" "; 
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int  profit=0;
int max=0;
    for(int i=n-1;i>0;i--)
    {
        
        if(max<a[i]){
            max=a[i];
        }
        if(max>a[i-1])
        {
            profit+=max-a[i-1];
        }

        else{
            max=a[i-1];
        }
       
    }

    cout<<"Maximum Profit is : "<<profit;
    return 0;

}
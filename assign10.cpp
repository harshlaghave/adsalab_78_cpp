/*Implement Coin Change problem.  Statement: - Given an integer array 
of coins [ ] of size N representing different types of currency and an 
integer sum, The task is to find the number of ways to make sum by 
using different combinations from coins[]. */

#include<iostream>
using namespace std;

int ccchange(int coins[],int n,int total)
{
    
    int dp[100]={0};
    dp[0]=1;

     for (int i=0;i<n;i++) {
        for (int j = coins[i]; j <= total; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[total];
}

int main()
{   
    int coins[] = {1,2,3};
    int n = sizeof(coins) / sizeof(coins[0]);
    int total = 4;

    cout<<"Number Of Ways are: "<<ccchange(coins,n,total);
    
    return 0;
}
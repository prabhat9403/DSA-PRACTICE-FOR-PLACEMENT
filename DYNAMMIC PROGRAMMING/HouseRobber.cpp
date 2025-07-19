// A thief needs to rob money in a street. The houses in the street are arranged in a circular manner. Therefore the first and the last house are adjacent to each other. The security system in the street is such that if adjacent houses are robbed, the police will get notified.

// Given an array of integers “Arr'' which represents money at each house, we need to return the maximum amount of money that the thief can rob without alerting the police.
#include <bits/stdc++.h>
// 6
// 7
// 1
// 30
// 8
// 2
// 4
// 10
// 15
// 3
// 20
// 2
// 1
// 7
using namespace std;
// Recursion
int maxMoney(vector<int> &arr, int idx, int n)
{
    if (idx >= n)
    {
        return 0;
    }
    return max((arr[idx] + maxMoney(arr, idx + 2, n)), maxMoney(arr, idx + 1, n));
}
// Memoization
int maxMoneyMemo(vector<int> &arr, int idx, int n,vector<int>&dp)
{
    if (idx >= n)
    {
        return 0;
    }
    if(dp[idx]!=-1)return dp[idx];
    return dp[idx]=max((arr[idx] + maxMoney(arr, idx + 2, n)), maxMoney(arr, idx + 1, n));
}
// Tabulation
int maxMoneyTabu(vector<int> &arr, int n,int e)
{
    vector<int> dp(n , -1);
    dp[n]=0;
    dp[n+1]=0;


    for(int i=n-1;i>=e;i--){
        dp[i]=max(arr[i]+dp[i+2],dp[i+1]);
    }
    return dp[0];
} 
int maxMoneySPO(vector<int> &arr, int n,int e)
{
    vector<int>dp(n,-1);
    int next=0;
    int next2=0;


    for(int i=n-1;i>=e;i--){
        dp[i]=max(arr[i]+next2,next);
        next2=next;
        next=dp[i];
    }
    return next;
} 

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> dp(n , -1);
    
    cout << max(maxMoneyMemo(arr, 0, n - 1,dp), maxMoneyMemo(arr, 1, n,dp))<<endl;
    cout << max(maxMoneyTabu(arr, 0, n - 1), maxMoneyTabu(arr, 1, n))<<endl;
    cout << max(maxMoneySPO(arr, n - 1,0), maxMoneySPO(arr,n,1))<<endl;
    return 0;
}
/*
Given an array prices[] of length N, representing the prices of the stocks on different days, the task is to find the maximum profit possible by buying and selling the stocks on different days when at most one transaction is allowed. Here one transaction means 1 buy + 1 Sell.
*/


#include<iostream>
using namespace std;

int profit(int prices[],int n){
    int netProfit=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){                             /*   T.c->>o(n^2)  */       
            if(prices[j]-prices[i]>netProfit){
                netProfit=prices[j]-prices[i];
            }
        }
    }
    return netProfit;
}
// approach 2

int profit2(int prices[],int n){
    int netProfit=0;
    int minBuysoFar=prices[0];
    for(int i=0;i<n;i++){                               
            if(prices[i]-minBuysoFar>netProfit){
                netProfit=prices[i]-minBuysoFar; 
            }
            minBuysoFar=min(minBuysoFar,prices[i]);
        
    }
    return netProfit;
}
int main(){
    int n;
    cin>>n;
    int *prices=new int[n];
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    cout<<"Net Profit is : "<<profit2(prices,n);
    return 0;

}
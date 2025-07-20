// Problem Statement: Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j]

#include<bits/stdc++.h>
using namespace std;

// 1.Brute Force
int ReversePairCount(vector<int>&arr){
    int n=arr.size();
    int pairs=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>2*arr[j])pairs++;
        }
    }
    return pairs;
}
// 2.optimal answer


int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for (size_t i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"........................................"<<endl;
    cout<<ReversePairCount(arr);
    return 0;
}
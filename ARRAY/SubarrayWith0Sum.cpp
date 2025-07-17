/* Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.*/
#include<iostream>
#include<vector>
using namespace std;


int LongestSubarrayWith0Sum(vector<int>&arr){
    int len=1;
    int i=0;
    int j=0;
    int sum=0;
    while(i<arr.size()){
        sum+=arr[j];
        if(sum==0){
            len=max(len,j-i+1);
        }
    }
    
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for (size_t i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    return 0;

}
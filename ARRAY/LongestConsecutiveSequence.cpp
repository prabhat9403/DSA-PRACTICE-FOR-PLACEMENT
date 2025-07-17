//  You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.


#include<iostream>
#include<vector>
using namespace std;
// Brute Force
bool search(vector<int>&arr,int num){
    for (int i = 0; i < arr.size(); i++)
    {
       if(arr[i]==num)return true;

    }
    return false;
    
}
int LengthOfLongConsSeque(vector<int>&arr){
    int maxLength=1;
    for (int i = 0; i < arr.size(); i++)
    {   int len=1;
        int x=arr[i];

        while(search(arr,x+1)){
            x+=1;
            len++;
        }
        maxLength=max(maxLength,len);
        
    }
    return maxLength;
    
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for (size_t i = 0; i < arr.size(); i++)
    {
        cin>>arr[i];
    }
    cout<<"Longest Consecutive sequence length: "<<LengthOfLongConsSeque(arr);
    
    return 0;
}
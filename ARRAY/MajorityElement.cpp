#include<iostream>
#include<unordered_map>
using namespace std;
// 1.Brute Force
// T.c=>O(n^2) s.c=O(1)

int majorityElement(int arr[],int n){
   
    for (size_t i = 0; i < n; i++)
    {   int count=0;
        for (size_t j = 0; j < n; j++)
        {
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count>=(n+1)/2){
            return arr[i];
        }
        
    }
    return -1;

}
// Approach 2 using Hashmap;
int MajorityEL(int arr[],int n){
    unordered_map<int ,int>mp;
    for (size_t i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for(auto it:mp){
        if(it.second>=(n+1)/2){
            return it.first;
        }
    }
    return -1;
    
}
int main(){
    int n;
    cin>>n;
    int*arr=new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"The Majority Element is: "<<MajorityEL(arr,n);
    
    return 0;
}
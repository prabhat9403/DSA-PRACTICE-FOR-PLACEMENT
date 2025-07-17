/* You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.*/


#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
unordered_set<int>st;

bool LinearSearch(vector<int>&arr,int ele){
    for(int i=0;i<arr.size();i++){
        if(ele==arr[i])return true;
    }
    return false;
}
int MissingAndRepeat(vector<int>&arr){
    int miss=-1;
  
    for(int i=1;i<=arr.size();i++){
        if(!(LinearSearch(arr,i))){
            miss=i;
        }
    }
    return miss;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for (size_t i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<MissingAndRepeat(arr);
    return 0;
}
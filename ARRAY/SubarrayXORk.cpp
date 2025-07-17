#include<iostream>
#include<vector>
using namespace std;
int XorSUbArray(vector<int>&arr,int k){
    int count=0;
    for (size_t i = 0; i < arr.size(); i++)
    {   int xr=0;
        for (size_t j = i; j < arr.size(); j++)
        {
            xr=xr^arr[j];
            if(xr==k)count++;
        }
        
    }
    return count ;
    
}

int main(){
      int n;
      int k;
    cin >> n;
    cin>>k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<"The number of k Xor Subarray is : "<<XorSUbArray(arr,k);
    return 0;
}
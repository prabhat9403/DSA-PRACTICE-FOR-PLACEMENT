#include<iostream>
#include<vector>
using namespace std;


int inversion(vector<int>&arr){
    int count=0;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]>arr[j])count++;
        }
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for (size_t i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<inversion(arr);
    return 0;
}
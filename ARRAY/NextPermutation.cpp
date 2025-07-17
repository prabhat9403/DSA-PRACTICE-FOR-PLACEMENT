#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
using namespace std;
void print(vector<int>arr,int n){
    for (size_t i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}
// Brute Force
void generatePermutation(vector<int>arr,vector<vector<int>> &ds,int idx){
    if(idx==arr.size()-1){
        ds.push_back(arr);
    }
    for(int i=idx;i<arr.size();i++){
        swap(arr[idx],arr[i]);
        generatePermutation(arr,ds,idx+1);
        swap(arr[idx],arr[i]);
    }
    
}
void my_next_permutation(vector<int>&arr){
    vector<vector<int>>ds;
    generatePermutation(arr,ds,0);
    sort(ds.begin(),ds.end());

    for (int i = 0; i < ds.size(); i++)
    {
        if(ds[i]==arr){
            if(i+1==ds.size()){

                arr=ds[0];
                break;
            }
            else{
                arr=ds[i+1];
                break;
            }
        }
    }
   
}

vector<int> permutation(vector<int>&arr){
    // find the break point
    int n=arr.size();
    int bkp=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            bkp=i;
            break;
        }
    }
     if (bkp == -1) {
    
        reverse(arr.begin(), arr.end());
        return arr;
    }

    
    for(int i=n-1;i>bkp;i--){
        if(arr[i]>arr[bkp]){
            swap(arr[i],arr[bkp]);
            break;
        }
    }
    reverse(arr.begin()+bkp+1,arr.end());
    return arr;
}


int main(){
    int n;
    cin>>n;
    // int *arr=new int[n];
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    print(arr,n);
    arr=permutation(arr);
    print(arr,n);
    return 0;
}
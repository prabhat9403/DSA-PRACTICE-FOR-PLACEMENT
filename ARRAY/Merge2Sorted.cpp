#include<iostream>
#include<vector>
using namespace std;
// Brute Force
vector<int>mergeSorted(vector<int>&arr1,vector<int>&arr2){
    vector<int>ans;
    int i=0;
    int j=0;
    while(i<arr1.size()&&j<arr2.size()){
        if(arr1[i]<=arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }
        else{
            ans.push_back(arr2[j]);
            j++;
        }
    }
    if(j<arr2.size()){
        ans.push_back(arr2[j]);
        j++;
    }
    if(i<arr1.size()){
        ans.push_back(arr1[i]);
        j++;
    }
    return ans;
}
void print(vector<int>arr){
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}
int main(){
    int n,m;
    cin>>n;
    cin>>m;
    vector<int>arr1(n);
    vector<int>arr2(m);
    for (int i = 0; i < n; i++)
    {
        
        cin>>arr1[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin>>arr2[j];
    }
    print(arr1);
    print(arr2);
    vector<int>ans=mergeSorted(arr1,arr2);
    print(ans);
    
    return 0;
}
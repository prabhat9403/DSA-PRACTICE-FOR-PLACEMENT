// Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side in the array.





#include<iostream>
#include<vector>
using namespace std;

// Brute Force
vector<int>leaderElement(vector<int>&arr){
    int n=arr.size();
    vector<int>ans;
    for (size_t i = 0; i < n; i++)
    {   bool flag=true;
        for (size_t j = i+1; j < n; j++)
        {
            if(arr[i]<arr[j]){
                flag=false;
                break;
            }

        }
        if(flag){
            ans.push_back(arr[i]);
        }

        
    }
    return ans;
    
}
vector<int>LeaderElement(vector<int>&arr){
    int n=arr.size();
    int maxi=arr[n-1];
    vector<int>ans;
    ans.push_back(arr[n-1]);

    for(int i=n-2;i>=0;i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
            maxi=arr[i];
        }
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
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    vector<int>ans=LeaderElement(arr);
    print(ans);

    return 0;
}
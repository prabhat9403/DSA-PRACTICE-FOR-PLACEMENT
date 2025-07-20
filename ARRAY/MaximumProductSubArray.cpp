#include<bits/stdc++.h>
using namespace std;
// 1.Brute force
int maxProductSubArray(vector<int>&arr){
    int n=arr.size();
    int proMax=INT_MIN;
    for (size_t i = 0; i < n; i++)
    {   int pro=1;
        for (size_t j = i; j < n; j++)
        {
            pro*=arr[j];
            proMax=max(proMax,pro);
        }
    }
    return proMax;
}
int OptimalAnswer(vector<int>&arr){
    int n=arr.size();
    
    int pre=1;
    int suff=1;
    int Promax=INT_MIN;
    for(int i=0;i<n;i++){
        if(pre==0)pre=1;
        if(suff==0)pre=1;
        pre*=arr[i];
        suff*=arr[n-i-1];
        Promax=max(Promax,max(pre,suff));

    }
    return Promax;

}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for (size_t i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<OptimalAnswer(arr);
    return 0;
}
/*
                            Given an array arr[] of n integers and a target value, the task is to find whether there is a pair of elements in the array whose sum is equal to target
*/

#include <iostream>
#include<unordered_set>
using namespace std;

bool find(int arr[],int target,int n){
                                                
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){                             /*   T.c->>o(n^2)  */       
            if(arr[i]+arr[j]==target)return true;
        }
    }
    return false;
}
bool find2(int arr[],int target,int n){
    unordered_set<int>st;
    for (int i = 0; i < n; i++)
    {   int toFind=target-arr[i];
        if (st.find(toFind)==st.end()){
            st.insert(arr[i]);
        }
        else{
            return true;
        }
    }
   return false; 
}

int main(){
    
    int n,target;
    cin>>n>>target;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    bool hasPair= find2(arr,target,n);
   hasPair==1? cout<<"true": cout<<"False";
    return 0;

}

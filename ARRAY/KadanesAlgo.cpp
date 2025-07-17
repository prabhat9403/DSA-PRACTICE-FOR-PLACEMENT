#include <iostream>
#include<vector>
using namespace std;
// Brute Force
int maximumSubArraySum(int arr[], int n)
{
    int maxSum = INT32_MIN;
    for (size_t i = 0; i < n; i++)
    {
        int sum = 0;
        for (size_t j = i; j < n; j++)
        {
            sum += arr[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

// Kadanes Algorithm
int kadanesAlgorithmSum(int arr[],int n,vector<int>&ds){
    int sum=0;
    int maxSum=INT32_MIN;
    for (size_t i = 0; i < n; i++)
    {
        sum+=arr[i];
        if(sum<0){
            sum=0;
        }
        maxSum=max(maxSum,sum);

    }
    return maxSum;
}
// Follow to print that subarray;
void PrintMaximumSubarray(int arr[],int n,vector<int>&ds){
    int sum=0;
    int maxSum=INT32_MIN;
    for (size_t i = 0; i < n; i++)
    {
        sum+=arr[i];
        ds.push_back(arr[i]);
        if(sum<0){
            sum=0;
            while(!ds.empty()){
                ds.pop_back();
            }
        }
        maxSum=max(maxSum,sum);

    }
    cout << "Maximum Subarray Sum is : "<<maxSum<<endl;
    cout<< "The Array is : ";
    for (size_t i = 0; i < ds.size(); i++)
    {  
        cout<<ds[i]<<" ";
    }
}
int main()
{
    // int n;
    // cin >> n;
    // int *arr = new int[n];
    // for (size_t i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int arr[] = { 2, 3, -8, 7, -1, 2, 3};

    vector<int>ds;
    PrintMaximumSubarray(arr, 7,ds);
    // cout << "Maximum Subarray Sum is : " << kadanesAlgorithmSum(arr, 9,ds);

    return 0;
}
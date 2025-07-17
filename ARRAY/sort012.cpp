#include <iostream>
using namespace std;
// First Approach
int size;
void sortZOT(int arr[])
{
    int zeroCount = 0, oneCount = 0, twoCount = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
            zeroCount++;
        else if (arr[i] == 1)
            oneCount++;
        else
            twoCount++;
    }
    int i = 0;
    while ( i < size)
    {
        while (zeroCount)
        {
            arr[i++] = 0;
            zeroCount--;
        }
        while (oneCount)
        {
            arr[i++] = 1;
            oneCount--;
        }
        while (twoCount)
        {
            arr[i++] = 2;
            twoCount--;
        }
        break;
    }
}
void print(int arr[])
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}

// approach 2(Dutch flag algorithm)
void sort012(int arr[]){
    int low=0;
    int high=size-1;
    int mid=0;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid++],arr[low++]);
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid++],arr[high--]);
        }
    }

}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    size = n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    print(arr);
    sort012(arr);
    print(arr);
    return 0;
}
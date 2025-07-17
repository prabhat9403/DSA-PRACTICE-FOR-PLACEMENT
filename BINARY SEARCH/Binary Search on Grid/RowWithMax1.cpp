#include <iostream>
using namespace std;
int n, m;
// 1.Approach Brute Force
int maxRowWithOneIndex(int **arr)
{

    int maxCountIndex = -1;
    int maxCount = 0;
    for (size_t i = 0; i < n; i++)
    {
        int oneCount = 0;

        for (size_t j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
                oneCount++;
        }
        if (oneCount > maxCount)
        {
            maxCountIndex = i;
            maxCount = oneCount;
        }
    }
    return maxCountIndex;
}

int firstOccurence(int arr[],int val){
    int firstOccurenceIndex=-1;
    int low=0;
    int high=m-1;
    int mid=low+(high-low)/2;
    while(low<=high){
        if(arr[mid]==val){
            firstOccurenceIndex=mid;
            high--;
        }
        else{
            low++;
        }
        mid=low+(high-low)/2;
    }
    return firstOccurenceIndex;
}
// 2.OptimalApproach(using binary search T.C=>O(n*log(m)))
int maxRowWith1Index(int **arr){
    int maxCount=0;
    int index=-1;
    for (size_t i = 0; i < n; i++)
    {
        int numOfOnes=m-firstOccurence(arr[i],1);
        if(numOfOnes>maxCount){
            index=i;
            maxCount=numOfOnes;
        }
    }
    return index;
    
}

int main()
{
    
    cin >> n >> m;
    int **arr = new int *[n];


    for (int i = 0; i < n; ++i)
    {
        arr[i] = new int[m];
    }
//    int initValues[3][4] = {
//     {1, 0, 0, 1},
//     {0, 1, 1, 0},
//     {1, 1, 0, 0}
// };

// for (int i = 0; i < n; ++i)
//     for (int j = 0; j < m; ++j)
//         arr[i][j] = initValues[i][j];



    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "Index with the maximum number of 1 : " << maxRowWith1Index(arr) << endl;
    return 0;
}
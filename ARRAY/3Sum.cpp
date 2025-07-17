#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute Force

vector<int> Tsum(vector<int> &arr)
{
    vector<int> number;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    number.push_back(arr[i]);
                    number.push_back(arr[j]);
                    number.push_back(arr[k]);
                }
            }
        }
    }
    return number;
}
vector<vector<int>> ThrSum(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> number;

    for (int i = 0; i < arr.size(); i++)

    {

        if (i != 0 && arr[i] == arr[i - 1])
        {
            continue;
        }

        int j = i + 1;
        int k = arr.size() - 1;

        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == 0)

            {
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                temp.push_back(arr[k]);
                number.push_back(temp);
                j++;
                k--;
                if (j < k && arr[j] == arr[j - 1])
                    continue;

                if (j < k && arr[j] == arr[j + 1])

                    continue;
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return number;
}
void print(vector<int> arr)
{
    cout << "[  ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "  ]";
    cout << endl;
}
void print2D(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        cout << "[ ";
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << " ]";
        cout << endl;
    }
    cout << " ]";
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // vector<int> number = Tsum(arr);
    vector<vector<int>> number1 = ThrSum(arr);
    // print(number);
    print2D(number1);

    return 0;
}
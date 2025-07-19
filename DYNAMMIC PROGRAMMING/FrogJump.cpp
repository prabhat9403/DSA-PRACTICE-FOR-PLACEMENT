// Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. At a time the frog can climb either one or two steps. A height[N] array is also given. Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.

#include <bits/stdc++.h>
using namespace std;

// Recursion
int energyConsumed(vector<int> &stairs, int idx)
{
    if (idx == stairs.size() - 1)
    {
        return 0;
    }
    int SingleJumb = abs(stairs[idx] - stairs[idx + 1]) + energyConsumed(stairs, idx + 1);
    int DoubleJumb = INT_MAX;
    if (idx + 2 < stairs.size())
    {

        DoubleJumb = abs(stairs[idx] - stairs[idx + 2]) + energyConsumed(stairs, idx + 2);
    }
    return min(SingleJumb, DoubleJumb);
}
// Memoization
int energyConsumedMemo(vector<int> &stairs, vector<int> &dp, int idx)
{
    if (idx == stairs.size() - 1)
    {
        return 0;
    }
    if (dp[idx] != -1)
        return dp[idx];
    int SingleJumb = abs(stairs[idx] - stairs[idx + 1]) + energyConsumed(stairs, idx + 1);
    int DoubleJumb = INT_MAX;
    if (idx + 2 < stairs.size())
    {

        DoubleJumb = abs(stairs[idx] - stairs[idx + 2]) + energyConsumed(stairs, idx + 2);
    }
    return dp[idx] = min(SingleJumb, DoubleJumb);
}

// Tabulation
int energyConsumedTabu(vector<int> &stairs)
{
    int n = stairs.size();
    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    for (int idx = 1; idx < n; idx++)
    {

        int SingleJumb = abs(stairs[idx] - stairs[idx - 1]) + dp[idx - 1];
        int DoubleJumb = INT_MAX;
        if (idx > 1)
        {
            DoubleJumb = abs(stairs[idx] - stairs[idx - 2]) + dp[idx - 2];
        }
        dp[idx] = min(SingleJumb, DoubleJumb);
    }
    return dp[n - 1];
}
int spaceOptimised(vector<int> &stairs)
{
    int n = stairs.size();
    vector<int> dp(n + 1, -1);
    int prev=0;
    int prev2=0;

    for (int idx = 1; idx < n; idx++)
    {

        int SingleJumb = abs(stairs[idx] - stairs[idx - 1]) + prev;
        int DoubleJumb = INT_MAX;
        if (idx > 1)
        {
            DoubleJumb = abs(stairs[idx] - stairs[idx - 2]) + prev2;
        }
        prev2=prev;
        prev = min(SingleJumb, DoubleJumb);
    }
    return prev;
}

int main()
{
    int n;
    cin >> n;
    vector<int> stairs(n);
    vector<int> dp(n + 1, -1);
    for (size_t i = 0; i < n; i++)
    {
        cin >> stairs[i];
    }

    cout << spaceOptimised(stairs);
    return 0;
}
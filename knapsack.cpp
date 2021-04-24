#include <iostream>
using namespace std;

int knapSack(int maxW, int wt[], int val[], int n)
{
    int dp[n + 1][maxW + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= maxW; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (wt[i - 1] > j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j],val[i - 1] + dp[i - 1][j - wt[i - 1]]);
            }
        }
    }
    return dp[n][maxW];
}
int main()
{
    int wt[] = { 2,3,4 };
    int val[] = {1,3,2};
    int maxW =5;
    int n = sizeof(val) / sizeof(val[0]);
    cout<< knapSack(maxW, wt, val, n);
}

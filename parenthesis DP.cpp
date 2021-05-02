#include<iostream>
#include<algorithm>

using namespace std;

int pp(int i,int j,int num[],char op[])
{
    if(i==j) return num[i];

    else
    {
        int maxn = -999;

        for(int k=i; k<j; k++)
        {
            int val;

            if(op[k] == '+')
            {
                val = pp(i,k,num,op) + pp(k+1,j,num,op);
            }
            else if(op[k] == '-')
            {
                val = pp(i,k,num,op) - pp(k+1,j,num,op);
            }
            else if(op[k] == '*')

            {
                val = pp(i,k,num,op) * pp(k+1,j,num,op);
            }

            if(val > maxn) maxn = val;
        }
        return maxn;
    }
}

int pp_dp(int num[],char op[],int n)
{
    int dp[n][n];
    int result = -999;

    //Base Case
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            dp[i][j] = -1;

            if(i==j) dp[i][j] = num[i];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=j)
            {
                int val,maxn = -9999;

                if(i < j)
                {
                    for(int k=i; k<j; k++)
                    {
                        if(op[k] == '+')
                        {
                            val = dp[i][k] + dp[k+1][j];
                        }
                        else if(op[k] == '-')
                        {
                            val = dp[i][k] - dp[k+1][j];
                        }
                        else
                        {
                            val = dp[i][k] * dp[k+1][j];
                        }

                        if(val > maxn) maxn = val;
                    }

                    dp[i][j] = maxn;
                }

                else
                {
                    for(int k=j; k<i; k++)
                    {
                        if(op[k] == '+')
                        {
                            val = dp[j][k] + dp[k+1][i];
                        }
                        else if(op[k] == '-')
                        {
                            val = dp[j][k] - dp[k+1][i];
                        }
                        else
                        {
                            val = dp[j][k] * dp[k+1][i];
                        }

                        if(val > maxn) maxn = val;
                    }

                    dp[i][j] = maxn;
                }
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(dp[i][j] > result)
            {
                result = dp[i][j];
            }
        }
    }

    return result;
}

int main()
{
    int n;

    cin>>n;

    int num[n];

    for(int i=0; i<n; i++)
    {
        cin>>num[i];
    }

    char op[n-1];

    for(int i=0; i<n-1; i++)
    {
        cin>>op[i];
    }

    int result = pp_dp(num,op,n);

    cout<<result<<endl;

    return 0;
}

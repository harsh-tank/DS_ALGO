#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9 + 7;

int main()
{
    ll a, b;
    cin >> a >> b;
    vector<vector<ll>> dp(501, vector<ll>(501, INT_MAX));
    for (ll i = 1; i <= 500; i++)
    {
        dp[i][1] = i - 1;
    }
    for (ll j = 1; j <= 500; j++)
    {
        dp[1][j] = j - 1;
    }
    for (ll i = 1; i <= 500; i++)
    {
        dp[i][i] = 0;
    }
    for (ll i = 2; i <= 500; i++)
    {
        for (ll j = 2; j <= 500; j++)
        {
            for (ll k = 1; k < i; k++)
            {
                dp[i][j] = min(dp[i][j], (dp[k][j] + dp[i - k][j] + 1));
            }
            for (ll k = 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], (dp[i][k] + dp[i][j - k] + 1));
            }
        }
    }
    cout << dp[a][b] << "\n";
    return 0;
}
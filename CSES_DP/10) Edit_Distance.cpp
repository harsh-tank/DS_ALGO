#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    ll n = s1.size();
    ll m = s2.size();
    if (n > m)
    {
        swap(n, m);
        swap(s1, s2);
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    for (ll i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (ll j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
            }
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}
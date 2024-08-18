#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9+7;
int main()
{
    ll n;
    cin>>n;
    vector<ll>dp(n+1,0);
    dp[0]=1;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=6;j++){
            if(i-j>=0){
                dp[i] = (dp[i]%mod + dp[i-j]%mod)%mod;
            }
        }
    }
    cout<<dp[n]%mod<<"\n";
    return 0;
}
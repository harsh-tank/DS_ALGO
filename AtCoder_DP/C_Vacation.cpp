#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n;
    cin>>n;
    vector<vector<ll>>dp(n, vector<ll>(3,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<3;j++){
            ll x;
            cin>>x;
            dp[i][j]=x;
        }
    }
    for(ll i=1;i<n;i++){
        dp[i][0]+=max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]+=max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]+=max(dp[i-1][0],dp[i-1][1]);
    }
    cout<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]))<<"\n";
    return 0;
}
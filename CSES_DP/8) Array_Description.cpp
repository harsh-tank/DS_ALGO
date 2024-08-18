#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;
int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    vector<vector<ll>>dp(n,vector<ll>(m+1,0));
    if(a[0]==0){
        for(ll j=1;j<=m;j++){
            dp[0][j]=1;
        }
    }
    else{
        dp[0][a[0]]=1;
    }
    for(ll i=1;i<n;i++){
        if(a[i]==0){
            for(ll j=1;j<=m;j++){
                dp[i][j]=(dp[i][j]+dp[i-1][j]+dp[i-1][j-1])%mod;
                if(j+1<=m)dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;
            }
        }
        else{
            dp[i][a[i]]=(dp[i][a[i]]+dp[i-1][a[i]]+dp[i-1][a[i]-1])%mod;
            if(a[i]+1<=m)dp[i][a[i]]=(dp[i][a[i]]+dp[i-1][a[i]+1])%mod;
        }
    }
    if(a[n-1]==0){
        ll sum = 0;
        for(ll j=1;j<=m;j++){
            sum = (sum + dp[n-1][j])%mod;
        }
        cout<<sum%mod<<"\n";
    }
    else cout<<(dp[n-1][a[n-1]])%mod<<"\n";
}
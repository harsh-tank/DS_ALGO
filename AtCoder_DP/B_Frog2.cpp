#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    vector<ll>dp(n,INT_MAX);
    dp[0]=0;
    for(ll i=1;i<n;i++){
        for(ll j=1;j<=k;j++){
            if(i-j>=0)dp[i]=min(dp[i],dp[i-j]+abs(a[i]-a[i-j]));
        }
    }
    cout<<dp[n-1]<<"\n";
    return 0;
}
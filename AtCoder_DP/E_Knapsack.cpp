#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n,weight;
    cin>>n>>weight;
    vector<ll>w(n),v(n);
    ll sum=0;
    for(ll i=0;i<n;i++){
        cin>>w[i]>>v[i];
        sum+=v[i];
    }
    vector<vector<ll>>dp(n+1, vector<ll>(sum+1,1e18L));
    dp[0][0]=0;
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=sum;j++){
            dp[i][j]=dp[i-1][j];
            if(v[i-1]<=j){
                dp[i][j]=min(dp[i][j], dp[i-1][j-v[i-1]]+w[i-1]);
            }
        }
    }
    ll maxi_ans=0;
    for(ll j=0;j<=sum;j++){
        if(dp[n][j]<=weight)maxi_ans=max(maxi_ans, j);
    }
    cout<<maxi_ans<<"\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n,weight;
    cin>>n>>weight;
    vector<ll>w(n),v(n);
    for(ll i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    vector<vector<ll>>dp(n+1, vector<ll>(weight+1,0));
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=weight;j++){
            dp[i][j]=dp[i-1][j];
            if(w[i-1]<=j){
                dp[i][j]=max(dp[i][j], dp[i-1][j-w[i-1]]+v[i-1]);
            }
        }
    }
    cout<<dp[n][weight]<<"\n";
    return 0;
}
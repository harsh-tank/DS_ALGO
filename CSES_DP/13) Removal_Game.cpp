#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    vector<ll>pre(n);
    pre[0]=a[0];
    for(ll i=1;i<n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    vector<vector<ll>>dp(n,vector<ll>(n,0));
    for(ll i=0;i<n;i++){
        dp[i][i]=a[i];
    }
    for(ll i=0;i<n-1;i++){
        dp[i][i+1]=max(a[i],a[i+1]);
    }
    for(ll k=2;k<n;k++){
        for(ll i=0;i<n;i++){
            ll j=i+k;
            if(j>=n)break;
            ll pre1 = pre[j]-pre[i];
            ll pre2 = pre[j-1];
            if(i-1>=0)pre2-=pre[i-1];
            dp[i][j] = max((a[i]+pre1-dp[i+1][j]), (a[j]+pre2-dp[i][j-1]));
        }
    }
    cout<<dp[0][n-1]<<"\n";
}
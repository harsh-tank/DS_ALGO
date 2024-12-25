#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    vector<ll>dp(n,0);
    for(ll i=1;i<n;i++){
        if(i-1>=0)dp[i]=dp[i-1]+abs(a[i]-a[i-1]);
        if(i-2>=0)dp[i]=min(dp[i],dp[i-2]+abs(a[i]-a[i-2]));
    }
    cout<<dp[n-1]<<"\n";
    return 0;
}
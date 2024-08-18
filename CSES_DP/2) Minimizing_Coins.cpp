#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n,x;
    cin>>n>>x;
    vector<ll>a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    vector<ll>dp(x+1,INT_MAX);
    dp[0]=0;
    for(ll i=1;i<=x;i++){
        for(ll j=0;j<n;j++){
            if(a[j]<=i){
                dp[i]=min(dp[i], dp[i-a[j]]+1);
            }
        }
    }
    cout<<((dp[x]==INT_MAX)?-1:dp[x])<<"\n";
    return 0;
}
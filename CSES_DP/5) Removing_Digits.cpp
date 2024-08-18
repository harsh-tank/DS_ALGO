#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n;
    cin>>n;
    vector<ll>dp(n+1,1e7);
    dp[0]=0;
    for(ll i=1;i<=n;i++){
        ll temp = i;
        while(temp>0){
            ll rem = temp%10;
            dp[i]=min(dp[i], dp[i-rem]+1);
            temp/=10;
        }
    }
    cout<<dp[n]<<"\n";
}
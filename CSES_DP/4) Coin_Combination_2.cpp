#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;
int main(){
    ll n,x;
    cin>>n>>x;
    vector<ll>a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    vector<ll>dp(x+1,0);
    dp[0]=1;
    for(ll i=0;i<n;i++){
        for(ll j=1;j<=x;j++){
            if(a[i]<=j){
                dp[j] = (dp[j]+dp[j-a[i]])%mod;
            }
        }
    }
    cout<<dp[x]%mod<<"\n";
    return 0;
}

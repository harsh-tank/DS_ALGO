#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;
vector<vector<ll>>dp(1000001,vector<ll>(2,0));
void solve(){

    //dp[i][0] ka matlab hai ki (i+1)th level pe 1 (1*2) ka block extend ho raha ho

    //dp[i][1] ka matlab hai ki (i+1)th level pe 2 (1*1) ke block extend ho rahe hai
    dp[1][0]=1;
    dp[1][1]=1;
    for(ll i=2;i<1000001;i++){
        dp[i][0] = ((2*dp[i-1][0])+(dp[i-1][1]))%mod;
        dp[i][1] = ((4*dp[i-1][1])+dp[i-1][0])%mod;
    }
}
int main(){
    solve();
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<(dp[n][0]+dp[n][1])%mod<<"\n";
    }
    return 0;
}
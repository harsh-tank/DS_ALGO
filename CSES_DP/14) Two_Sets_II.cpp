#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;
int main(){
    ll n;
    cin>>n;
    ll sum = (n*(n+1))/2;
    if(sum%2){
        cout<<"0\n";
    }
    else{
        sum/=2;
        vector<vector<ll>>dp(n+1, vector<ll>(sum+1,0));
        for(ll i=0;i<=n;i++){
            dp[i][0]=1;
        }

        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=sum;j++){
                if(j>=i-1){
                    dp[i][j] = (dp[i-1][j-(i-1)]+dp[i-1][j])%mod;
                }
                else dp[i][j]=(dp[i-1][j]%mod);
            }
        }
        cout<<(dp[n][sum])%mod<<"\n";
    }   
    return 0;
}
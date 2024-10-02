#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    ll sum=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
    for(ll i=0;i<=n;i++){
        dp[i][0]=true;
    }
    set<ll>s1;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=sum;j++){
            if(a[i-1]<=j){
                dp[i][j] = (dp[i-1][j] || dp[i-1][j-a[i-1]]);
            }
            else dp[i][j]=dp[i-1][j];
            if(dp[i][j])s1.insert(j);
        }
    }
    cout<<s1.size()<<"\n";
    for(auto &it:s1)cout<<it<<" ";
    cout<<"\n";
    return 0;
}
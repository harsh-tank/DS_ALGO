#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n,x;
    cin>>n>>x;
    vector<ll>a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    ll limit = (1<<n);
    vector<pair<ll,ll>>dp(limit); //{no of rides, weight of last ride}
    dp[0]={1,0};
    for(ll mask=1; mask<limit; mask++){
        pair<ll,ll> res = {INT_MAX, INT_MAX};
        for(ll i=0;i<n;i++){
            if(((mask)&(1<<i))==0)continue;
            auto temp = dp[((mask)^(1<<i))];
            if(temp.second+a[i]>x){
                temp.first++;
                temp.second=a[i];
            }
            else{
                temp.second+=a[i];
            }
            res = min(res, temp);
        }
        dp[mask]=res;
    }
    cout<<dp[limit-1].first<<"\n";
    return 0;
}
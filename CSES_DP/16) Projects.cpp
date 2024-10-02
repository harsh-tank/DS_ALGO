#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n;
    cin>>n;
    vector<pair<ll, pair<ll,ll>>>a;
    for(ll i=0;i<n;i++){
        ll st,ed,pr;
        cin>>st>>ed>>pr;
        a.push_back({ed,{st,pr}});
    }
    sort(a.begin(),a.end());
    vector<ll>end_time;
    for(ll i=0;i<n;i++){
        end_time.push_back(a[i].first);
    }
    vector<ll>dp(n);
    dp[0]=a[0].second.second;
    for(ll i=1;i<n;i++){
        ll st_time = a[i].second.first;
        ll idx = lower_bound(end_time.begin(),end_time.end(),st_time)-end_time.begin();
        if(idx-1>=0){
            dp[i]=max(dp[i-1],dp[idx-1]+a[i].second.second);
        }
        else{
            dp[i]=max(dp[i-1],a[i].second.second);
        }
    }
    cout<<dp[n-1]<<"\n";
    return 0;
}

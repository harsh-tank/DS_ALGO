#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n,x;
    cin>>n>>x;
    vector<ll>c(n),p(n);
    for(ll i=0;i<n;i++)cin>>c[i];
    for(ll i=0;i<n;i++)cin>>p[i];
    vector<ll>prev(x+1,0);
    for(int i=1;i<=n;i++){
        vector<ll>cur(x+1,0);
        for(int j=1;j<=x;j++){
            if(c[i-1]<=j){
                cur[j] = max(prev[j], prev[j-c[i-1]]+p[i-1]);
            }
            else cur[j]=prev[j];
        }
        prev = cur;
    }
    cout<<prev[x]<<"\n";
    return 0;
}
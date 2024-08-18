#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;
int main(){
    ll n;
    cin>>n;
    vector<string>grid;
    for(ll i=0;i<n;i++){
        string s;
        cin>>s;
        grid.push_back(s);
    }
    vector<vector<ll>>ans(n,vector<ll>(n,0));
    for(ll i=0;i<n;i++){
        if(grid[i][0]=='.')ans[i][0]=1;
        else break;
    }
    for(ll j=0;j<n;j++){
        if(grid[0][j]=='.')ans[0][j]=1;
        else break;
    }
    for(ll i=1;i<n;i++){
        for(ll j=1;j<n;j++){
            if(grid[i][j]=='.'){
                ans[i][j]=(ans[i-1][j]+ans[i][j-1])%mod;
            }
        }
    }
    cout<<ans[n-1][n-1]<<"\n";
    return 0;
}
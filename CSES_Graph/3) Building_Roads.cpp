#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void dfs(int i, vector<ll>&vis, vector<ll>adj[], ll &last_vis){
    //cout<<"node is "<<i<<"\n";
    last_vis=i;
    vis[i]=1;
    for(auto it: adj[i]){
        if(vis[it]==0){
            dfs(it,vis,adj,last_vis);
        }
    }
}
int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll>adj[n+1];
    ll cnt = 0;
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<pair<ll,ll>>edges;
    vector<ll>vis(n+1,0);
    ll last_vis = 1; 
    for(ll i=1;i<=n;i++){
        if(vis[i]==0){
            if(last_vis!=i){
                cnt++;
                edges.push_back({last_vis,i});
            }
            dfs(i,vis,adj,last_vis);
        }
    }
    cout<<edges.size()<<"\n";
    for(auto it:edges){
        cout<<it.first<<" "<<it.second<<"\n";
    }
    return 0;
}
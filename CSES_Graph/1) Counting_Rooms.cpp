#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void dfs(int i, int j, int n,int m,vector<vector<char>>&grid, vector<vector<ll>>&vis){
    //cout<<"at ("<<i<<","<<j<<")\n";
    vis[i][j]=1;
    if(i+1<n && vis[i+1][j]==0 && grid[i+1][j]=='.'){
        dfs(i+1,j,n,m,grid,vis);
    }
    if(j+1<m && vis[i][j+1]==0 && grid[i][j+1]=='.'){
        dfs(i,j+1,n,m,grid,vis);
    }
    if(j-1>=0 && vis[i][j-1]==0 && grid[i][j-1]=='.'){
        dfs(i,j-1,n,m,grid,vis);
    }
    if(i-1>=0 && vis[i-1][j]==0 && grid[i-1][j]=='.'){
        dfs(i-1,j,n,m,grid,vis);
    }
}
int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    ll cc=0;
    vector<vector<ll>>vis(n, vector<ll>(m,0));
    for(int i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(grid[i][j]=='.' && vis[i][j]==0){
                cc++;
                //cout<<"cc is "<<cc<<"\n";
                dfs(i,j,n,m,grid,vis);
            }
            else{
                vis[i][j]=1;
            }
        }
    }
    cout<<cc<<"\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool bfs(int si, int sj, int n,int m,vector<vector<char>>&grid, vector<vector<ll>>&vis,ll ei, ll ej, vector<vector<char>>&dir,string &ans){
    queue<pair<ll,ll>>q;
    q.push({si,sj});
    vis[si][sj]=1;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(i==ei && j==ej){
            while(1){
                ans.push_back(dir[i][j]);
                if(ans.back()=='D')i--;
                else if(ans.back()=='U')i++;
                else if(ans.back()=='R')j--;
                else if(ans.back()=='L')j++;
                if(i==si && j==sj){
                    break;
                } 
            }
            return true;
        }
        if(j-1>=0 && vis[i][j-1]==0 && grid[i][j-1]!='#'){
            vis[i][j-1]=1;
            q.push({i,j-1});
            dir[i][j-1]='L';
        }
        if(j+1<m && vis[i][j+1]==0 && grid[i][j+1]!='#'){
            vis[i][j+1]=1;
            q.push({i,j+1});
            dir[i][j+1]='R';
        }
        if(i-1>=0 && vis[i-1][j]==0 && grid[i-1][j]!='#'){
            vis[i-1][j]=1;
            q.push({i-1,j});
            dir[i-1][j]='U';
        }
        if(i+1<n && vis[i+1][j]==0 && grid[i+1][j]!='#'){
            vis[i+1][j]=1;
            q.push({i+1,j});
            dir[i+1][j]='D';
        }
    }
    return false;
}
int main(){
    ll n,m;
    cin>>n>>m;
    ll si=-1,sj=-1,ei=-1,ej=-1;
    vector<vector<char>>grid(n,vector<char>(m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='A'){
                si=i;
                sj=j;
            }
            if(grid[i][j]=='B'){
                ei=i;
                ej=j;
            }
        }
    }
    string ans="";
    vector<char>s;
    vector<vector<ll>>vis(n,vector<ll>(m,0));
    vector<vector<char>>dir(n,vector<char>(m,'0'));
    if(si!=-1 && sj!=-1 && ei!=-1 && ej!=-1){
        if(bfs(si,sj,n,m,grid,vis,ei,ej,dir,ans)){
            cout<<"YES\n";
            cout<<ans.size()<<"\n";
            reverse(ans.begin(),ans.end());
            cout<<ans<<"\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}
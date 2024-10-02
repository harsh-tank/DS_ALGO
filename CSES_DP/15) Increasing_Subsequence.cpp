#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    vector<ll>temp;
    temp.push_back(a[0]);
    for(ll i=0;i<n;i++){
        if(a[i]>temp.back()){
            temp.push_back(a[i]);
        }
        else{
            ll idx = lower_bound(temp.begin(), temp.end(), a[i])-temp.begin();
            temp[idx]= a[i];
        }

    }
    cout<<temp.size()<<"\n";
    return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
//ai*i*p>=m
//ai*(i-1)*p<m
//p>=(m/ai*i)
//p<m/(i*(ai-1))
int L=0,R=INT_MAX;
int n,m;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        L=max(L,(int)ceil(m*1.0/(i*x)));
        if(x!=1)
            R=min(R,(int)floor(m*1.0/(i*(x-1))));
    }
    //cout<<L<<' '<<R<<'\n';
    if(R==INT_MAX){
        cout<<"xiaogougege";
        return 0;
    }
    cout<<R-L+1;
}
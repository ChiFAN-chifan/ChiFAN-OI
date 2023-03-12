#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans,u[N],v[N],deg[N],bk[N];
vector<int>G[N];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i];
        deg[u[i]]++,deg[v[i]]++;
    }
	for(int i=1;i<=m;i++){
		if(deg[u[i]]>deg[v[i]]||deg[u[i]]==deg[v[i]]&&u[i]>v[i])swap(u[i],v[i]);
		G[u[i]].push_back(v[i]);
	}
	for(int x=1;x<=n;x++){
		for(int i=0;i<G[x].size();i++)bk[G[x][i]]=1;
		for(int i=0;i<G[x].size();i++)for(int j=0;j<G[G[x][i]].size();j++)ans+=bk[G[G[x][i]][j]];
		for(int i=0;i<G[x].size();i++)bk[G[x][i]]=0;
	}
	cout<<ans;
}

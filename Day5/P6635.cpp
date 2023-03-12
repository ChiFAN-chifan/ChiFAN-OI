#include <bits/stdc++.h>
using namespace std;
#define N 2000010
#define ll long long
#define ull unsigned long long
#define pll pair<ull,ull>
#define mkp(a,b) make_pair(a,b)
ull seed=13244074693642402ull;
inline ull Rand() {
    seed^=seed<<13,seed^=seed>>7,seed^=seed<<17;
    return seed;
}
ull f[N],g[N],Map1[N],Map2[N];
pll val[N];
inline void Add(int l,int r,int dat,int Dat) {
    f[l]^=dat,f[r+1]^=dat,g[l]^=Dat,g[r+1]^=Dat;
}
int tot=1;
int fir[N],nex[N<<1],got[N<<1];
inline void AddEdge(int x,int y) {
    nex[++tot]=fir[x],fir[x]=tot,got[tot]=y;
    nex[++tot]=fir[y],fir[y]=tot,got[tot]=x;
}
int dfn[N],siz[N],Max[N],idx;
inline void dfs(int x,int fa,int n) {
    siz[x]=1,dfn[x]=++idx;
    for (int i=fir[x];i;i=nex[i]) if (got[i]!=fa)
        dfs(got[i],x,n),siz[x]+=siz[got[i]],Max[x]=max(Max[x],siz[got[i]]);
    Max[x]=max(Max[x],n-siz[x]);
    for (int i=fir[x];i;i=nex[i]) {
        if (got[i]==fa || siz[got[i]]!=Max[x]) continue;
        Add(dfn[got[i]],dfn[got[i]]+siz[got[i]]-1,Map1[Max[x]],Map2[Max[x]]);
    }
    if (n-siz[x]==Max[x]) {
        Add(1,dfn[x]-1,Map1[Max[x]],Map2[Max[x]]);
        Add(dfn[x]+siz[x],n,Map1[Max[x]],Map2[Max[x]]);
    }
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) Map1[i]=Rand();
    for (int i=1;i<=n;i++) Map2[i]=Rand();
    for (int i=1;i<=n-1;i++) AddEdge(read(),read());
    dfs(1,0,n);
    for (int i=1;i<=n;i++) f[i]^=f[i-1],g[i]^=g[i-1];
    for (int i=1;i<=n;i++) val[i]=mkp(f[i],g[i]);
    sort(val+1,val+n+1);
    vector<int> ans; int cnt=1; val[n+1]=mkp(-1,-1);
    for (int i=2;i<=n+1;i++) {
        if (val[i]!=val[i-1]) 
            ans.push_back(cnt),cnt=0;
        cnt++;
    }
    printf("%d\n",ans.size());
    sort(ans.begin(),ans.end());
    for (auto tmp:ans) printf("%d\n",tmp);
    return 0;
}
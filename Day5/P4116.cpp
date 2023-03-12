#include<bits/stdc++.h>
using namespace std;
const int maxn =1e5+100;
int bl[maxn];//每个点祖先中最近的关键点
int ans[maxn];//i - bl[i] 的答案 没有答案为 -1
int fa[maxn];
int col[maxn];
vector<int> edge[maxn];
int n,q;
int sq;
void dfs(int u){
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if(v==fa[u]) continue;
        fa[v]=u;
        dfs(v);
    }
}
int found(int u){
    if(bl[u]==u) return u;
    else return found(fa[u]);
}
void inti(){
    for(int i=1;i<=n;i++){
        if(rand()%sq==0) bl[i]=i;
    }
    bl[1]=1;
    for(int i=1;i<=n;i++){
        if(bl[i]==0){
            bl[i]=found(i);
        }
    }
    for(int i=1;i<=n;i++){
        int u=i;
        ans[i]=-1;
    }
}
void ch_dfs(int u,int anser){
    if(col[u]==1&&anser==-1) anser=u; 
    ans[u]=anser;
    for(int i=0;i<edge[u].size();i++){   
        int v=edge[u][i];   
        if(v==fa[u]||bl[v]==v) continue;
        ch_dfs(v,anser);
    }
}
void change(int u){
    col[u]^=1;
    ch_dfs(bl[u],-1);
}
int ask(int u){
    int res=-1;
    while(u!=0){
        if(ans[u]!=-1)
            res=ans[u];
        u=fa[bl[u]];
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin>>n>>q;
    sq=sqrt(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1);
    inti();
    for(int i=1;i<=q;i++){
        int op;
        cin>>op;
        if(op==0){
            int x;
            cin>>x;
            change(x);
        }
        else{
            int x;
            cin>>x;
            cout<<ask(x)<<'\n';
        }
    }
}


#include<bits/stdc++.h>
using namespace std;
const int maxn =1e6+10;
struct node{
    int x,y,id;
}p[maxn];
bool cmp1(node a,node b){
    return a.x>b.x;
}
bool cmp2(node a,node b){
    return a.y>b.y;
}
struct Node{
    int u,v,w;
}edge[maxn];
int fa[maxn];
int found(int u){
    if(fa[u]==u) return u;
    else return fa[u]=found(fa[u]);
}
//路径压缩
int tot;
bool cmp3(Node a,Node b){
    return a.w<b.w;
}
int n,res;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        fa[i]=i;
        cin>>p[i].x>>p[i].y;
        p[i].id=i;
    }
    sort(p+1,p+n+1,cmp1);
    for(int i=1;i<n;i++){
        int u=p[i].id;
        int v=p[i+1].id;
        int w=min(abs(p[i].x-p[i+1].x),abs(p[i].y-p[i+1].y));
        edge[++tot].u=u;
        edge[tot].v=v;
        edge[tot].w=w;
    }
    sort(p+1,p+n+1,cmp2);
    for(int i=1;i<n;i++){
        int u=p[i].id;
        int v=p[i+1].id;
        int w=min(abs(p[i].x-p[i+1].x),abs(p[i].y-p[i+1].y));
        edge[++tot].u=u;
        edge[tot].v=v;
        edge[tot].w=w;
    }
    sort(edge+1,edge+tot+1,cmp3);
    for(int i=1;i<=tot;i++){
        int u=edge[i].u;
        int v=edge[i].v;
        int w=edge[i].w;
        if(found(u)!=found(v)){
            fa[found(u)]=found(v);
            res+=w;
        }
    }
    cout<<res;
}
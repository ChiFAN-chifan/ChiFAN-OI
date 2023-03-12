#include<bits/stdc++.h>
#define double long double
using namespace std;
const int maxn=4e5+5;
struct node{
    int x,y,lx,ly;
}p[maxn];
bool cmp(node A,node B){
    if(A.x<B.x||(A.x==B.x&&A.y<B.y))
        return 1;
    else
        return 0;
}
int dis(node A,node B){
    return (A.lx-B.lx)*(A.lx-B.lx)+(A.ly-B.ly)*(A.ly-B.ly);
}
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int X,Y;
        cin>>X>>Y;
        p[i].lx=X;
        p[i].ly=Y;
        p[i].x=X*cos(1.14)-Y*sin(1.14);
        p[i].y=X*sin(1.14)+Y*cos(1.14);
    }
    stable_sort(p+1,p+n+1,cmp);
    int ans=0;
    for(int i=1;i<=min(12000,n);i++){
        for(int j=n-min(12000,n)+1;j<=n;j++){
            ans=max(ans,dis(p[i],p[j]));
        }
    }
    cout<<ans<<'\n';
}
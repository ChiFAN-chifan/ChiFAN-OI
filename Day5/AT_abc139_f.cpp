#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+100;
const double eps = 1e-15;
const double pi = acos(-1);
struct Vector{
    double x,y;
    Vector(double X=0,double Y=0){x=X,y=Y;}
}p[maxn];
Vector operator+(Vector x,Vector y){
    return Vector(x.x+y.x,x.y+y.y);
}
Vector operator-(Vector x,Vector y){
    return Vector(x.x-y.x,x.y-y.y);
}
Vector operator*(Vector x,double y){
    return Vector(x.x*y,x.y*y);
}
double polar(Vector x){
    return atan2(x.x,x.y);
}
double len(Vector x){
    return sqrt(x.x*x.x+x.y*x.y);
}
bool cmp(Vector p1,Vector p2)
{
    return polar(p1)<polar(p2);
}
int n;
double ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
    }
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;i++)
        p[i+n]=p[i];
    for(int i=1;i<=2*n;i++){
        for(int j=i;j<=2*n;j++){
            if((j-i+1)>n) continue;
            Vector res=Vector(0,0);
            for(int k=i;k<=j;k++){
                res=res+p[k];
            }
            ans=max(ans,len(res));
        }
    }
    printf("%.13f",ans);
}
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+100;
const double eps = 1e-10;
const double pi = acos(-1);
struct Vector{
    double x,y;
    Vector(double X=0,double Y=0){x=X,y=Y;}
};
struct Point{
    double x,y;
    Point(double X=0,double Y=0){x=X,y=Y;}
}p[maxn],s[maxn];
int dcmp(double x){
    return (x>=eps ? x:-x);
}
Vector operator+(Vector x,Vector y){
    return Vector(x.x+y.x,x.y+y.y);
}
Point operator+(Point x,Vector y){
    return Point(x.x+y.x,x.y+y.y);
}
Vector operator-(Vector x,Vector y){
    return Vector(x.x-y.x,x.y-y.y);
}
Vector operator-(Point x,Point y){
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
double dot(Vector x,Vector y){
    return x.x*y.x+x.y*y.y;
}
double cross(Vector x,Vector y){
    return x.x*y.y-x.y*y.x;
}
double theta(Vector x,Vector y){
    return acos(dot(x,y)/len(x)/len(y));
}
double dis(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(Point p1,Point p2)//排序函数，这个函数别写错了，要不然功亏一篑 
{
    double tmp=cross(p[1]-p1,p[1]-p2);
    if(tmp>0) 
		return 1;
    if(tmp==0&&dis(p[0],p1)<dis(p[0],p2)) 
		return 1;
    return 0;
}
Vector rotate(Vector a,double B){
    return Vector(a.x*cos(B)-a.y*sin(B),a.x*sin(B)+a.y*cos(B));
}
struct Line{
    Point a;
    Vector b;
    Line(Point X,Vector Y){a=X,b=Y;}
    Line(Point X,Point Y){a=X,b=Y-X;}
}; 
Point Intersection(Line x,Line y){
    Vector u = x.a-y.a;
    double t = cross(y.b,u)/cross(x.b,y.b);
    return x.a+x.b*t;
}
double Convex(Point *p,int n){//多边形面积
    double area=0;
    for(int i=1;i<n-1;i++){
        area+=cross(p[i]-p[0],p[i+1]-p[0]);
    }
    return area/2;
}
Point Get(Point A,Point B,Point C){
	double a1=theta(A-B,C-B);
    Vector v1=rotate(C-B,a1/3);
    double a2=theta(A-C,B-C);
    Vector v2=rotate(B-C,-a2/3);
    return Intersection(Line(B,v1),Line(C,v2));
} 
int n,cnt;
double a,b,r;
double x,y,Theta;
int main(){
    cin>>n>>a>>b>>r;
    a-=2*r;
    b-=2*r;
    double l=sqrt(a*a+b*b)/2;
    double phi=atan(a/b);
    for(int i=1;i<=n;i++){
        cin>>x>>y>>Theta;
        double dx=cos(Theta+phi)*l;
        double dy=sin(Theta+phi)*l;
        p[(i-1)*4+1]=Point(x+dx,y+dy);
        p[(i-1)*4+2]=Point(x-dx,y-dy);
        dx=cos(Theta-phi)*l;
        dy=sin(Theta-phi)*l;
        p[(i-1)*4+3]=Point(x+dx,y+dy);
        p[(i-1)*4+4]=Point(x-dx,y-dy);
    }
    double mid;
    for(int i=1;i<=4*n;i++){
        cin>>p[i].x>>p[i].y;
        if(i!=1&&(p[i].y<p[1].y||(p[i].y==p[1].y&&p[i].x<p[1].x))){
            mid=p[1].y;
            p[1].y=p[i].y;
            p[i].y=mid;
            mid=p[1].x;
            p[1].x=p[i].x;
            p[i].x=mid;
        }
    }
    sort(p+2,p+4*n+1,cmp);
    s[++cnt]=p[1];

    for(int i=2;i<=4*n;i++){
        while(cnt>1&&cross(s[cnt-1]-s[cnt],s[cnt]-p[i])<=0){
            cnt--;
        }
        cnt++;
        s[cnt]=p[i];
    }
    s[cnt+1]=p[1];
    double ans=0;
    for(int i=1;i<=cnt;i++){
        ans+=dis(s[i],s[i+1]);
    }
    printf("%.2lf\n",ans+pi*2*r);
}
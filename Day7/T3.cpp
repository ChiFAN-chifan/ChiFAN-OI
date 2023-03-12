#include<bits/stdc++.h>
using namespace std;
const int maxn =4e6+10;
struct Node{
    int l,r,val;
}s[maxn];
int value;
int a[maxn];
int n;
int ans;
int tot;
int k;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        if(i==1) value=a[i];
        else value=__gcd(value,a[i]);
    }
    for(int i=1;i<=n;i++){
        a[i]/=value;
    }
    int flag=0,val;
    for(int i=1;i<=n;i++){
        if(a[i]!=1&&flag==0){
            s[++tot].l=i;
            flag=1;
            val=a[i];
        }
        if(a[i]==1&&flag==1){
            flag=0;
            s[tot].r=i-1;
            s[tot].val=val;
        }
        if(flag==1) val=__gcd(val,a[i]);
    }
    if(flag==1){
        flag=0;
        s[tot].r=n;
    }
    /*
    for(int i=1;i<=tot;i++){
        if(i==1){
            ans+=s[1].r-s[1].l+1+k;
            if(s[tot].val!=1){
                ans++;
            }
        }
        else{
            ans+=s[i].r-s[i].l+1+k;
            if(s[i].l-s[i-1].r-1<=k){
                ans+=s[i].l-s[i-1].r-1;
                ans-=k;
            }
            else{
                if(s[i].val!=1){
                    if(s[i].l==s[i-1].r){
                        ans-=k;
                        ans++;
                    }
                    else{
                        ans++;
                    }
                }
            }
        }
    }

    */
    cout<<ans;
}
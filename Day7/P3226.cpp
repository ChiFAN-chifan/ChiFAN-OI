#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2010;
typedef long long ll;
ll mod=1000000007;
ll n,k,x[maxn],y[maxn],ans,s1,s2;
ll powmod(ll a,ll x)
{
    ll ret=1ll,nww=a;
    while(x)
    {
        if(x&1)ret=ret*nww%mod;
        nww=nww*nww%mod;x>>=1;
    }
    return ret;
}
ll inv(ll x){return powmod(x,mod-2);}
int main()
{
    scanf("%lld",&k);
    n=10;
    x[1]=
    y[1]=
    for(int i=1;i<=n;i++)
    {
        s1=y[i]%mod;s2=1ll;
        for(int j=1;j<=n;j++)if(i!=j)s1=s1*(k-x[j])%mod,s2=s2*((x[i]-x[j]%mod)%mod)%mod;
        ans+=s1*inv(s2)%mod;ans=(ans+mod)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
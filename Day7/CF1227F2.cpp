#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod=998244353;
const int maxn=2e5+5;
ll n,k;
ll h[maxn],fac[maxn];
int dif;

ll qpow(ll a,ll b){
	ll ret=1;while(b){
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;b>>=1; 
	}return ret;
}
void init(){
	fac[0]=1;
	for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
}
ll C(ll n,ll m){
	return fac[n]*qpow(fac[m]*fac[n-m]%mod,mod-2)%mod;
}

void V_me_50(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&h[i]);
	for(int i=1;i<=n;i++) if(h[i]!=h[i==n?1:(i+1)]) dif++;
	ll sum=qpow(2,mod-2)*qpow(k,dif);
	for(int a=0;2*a<=dif;a++){
		sum-=qpow(2,mod-2)*C(dif,a)%mod*C(dif-a,dif-2*a)%mod*qpow(k-2,dif-2*a)%mod;
		sum=(sum%mod+mod)%mod;
	}
	sum=sum*qpow(k,n-dif)%mod;
	printf("%lld",sum);
}

int main(){
	init();
	V_me_50();
}
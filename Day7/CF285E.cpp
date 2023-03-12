#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10;
const int mod=1e9+7;
int fac[N],C[N][N],f[N][N][5];
signed main()
{
	int n,m,ans=0;
	cin>>n>>m;
	fac[0]=C[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		fac[i]=fac[i-1]*i%mod;
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	f[1][0][0]=1;
	if(n>1) f[1][1][2]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			(f[i][j][0]+=f[i-1][j][0]+f[i-1][j][1])%=mod;
			(f[i][j][1]+=f[i-1][j][2]+f[i-1][j][3])%=mod;
			if(j==0) continue;
			(f[i][j][0]+=f[i-1][j-1][0])%=mod;
			(f[i][j][1]+=f[i-1][j-1][2])%=mod;
			if(i<n) (f[i][j][2]+=f[i-1][j-1][0]+f[i-1][j-1][1])%=mod;
			if(i<n) (f[i][j][3]+=f[i-1][j-1][2]+f[i-1][j-1][3])%=mod;
		}
	}
	for(int i=m;i<=n;i++)
	{
		int opt=((i-m)&1?-1:1),sum=f[n][i][0]+f[n][i][1];
		ans=(ans+opt*C[i][m]*sum%mod*fac[n-i]%mod+mod)%mod;
	}
	cout<<ans;
	return 0;
}

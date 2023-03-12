#include<bits/stdc++.h>
using namespace std;
const int maxn = 600,maxm=1e5+114,mod=19260817;
struct Node{
    int k,d;
}a[maxn];
int n,m,sum,ans,q;
int dp[2][maxm];
bool cmp(Node x,Node y){
    return x.d>y.d;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].k>>a[i].d;
        sum+=a[i].k*a[i].d;
    }
    if(sum<=m){
        cout<<1;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    dp[0][0]=1;
    	for(int i=1;i<=n;i++)
	{
		sum-=a[i].k*a[i].d;a[i].k--;q^=1;
		for(int u=0;u<a[i].d;u++)
		{
			int maxp=(m-u)/a[i].d,now=0;
			for(int p=0;p<=maxp;p++)
			{
				if(p-a[i].k-1>=0)
					now=(now+mod-dp[q^1][u+(p-a[i].k-1)*a[i].d])%mod;
				dp[q][u+p*a[i].d]=now=(dp[q^1][u+p*a[i].d]+now)%mod;
			}
		}
		for(int j=max(m-sum-a[i].d+1,0);j<=m-sum;j++)
			ans=(ans+dp[q][j])%mod;a[i].k++;
		for(int u=0;u<a[i].d;u++)
		{
			int maxp=(m-u)/a[i].d,now=0;
			for(int p=0;p<=maxp;p++)
			{
				if(p-a[i].k-1>=0)
					now=(now+mod-dp[q^1][u+(p-a[i].k-1)*a[i].d])%mod;
				dp[q][u+p*a[i].d]=now=(dp[q^1][u+p*a[i].d]+now)%mod;
			}
		}
	}
	cout<<ans;
	return 0;
}
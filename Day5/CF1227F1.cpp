#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn =2e3+10,mod=998244353;
int a[maxn],b[maxn];
int dp[maxn][maxn<<1];
int n,k;
signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) b[i]=a[i%n+1];
    int ans=0;
    dp[0][n]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=(n<<1);j++){
            if(a[i]==b[i]) dp[i][j]=dp[i-1][j]*k%mod;
            else dp[i][j]=(dp[i-1][j+1]+dp[i-1][j-1]+dp[i-1][j]*(k-2))%mod;
        }
    }
    for(int i=n+1;i<=(n<<1);i++){
        ans=(ans+dp[n][i])%mod;
    }
    cout<<ans;
}
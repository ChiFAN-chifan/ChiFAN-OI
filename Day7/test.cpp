#include<bits/stdc++.h>
using namespace std;
int read() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
#define int long long
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i ) 
const int mod = 1000000001;
const int maxn = ( 1 << 18 ) - 1;
const int N = 100000 + 5;
const int M = 20 ;
int n, book[N], Ans, line[M], g[maxn], a[M][M], end, dp[M][maxn], num, lim[M];
void init( int x ) {
	rep( i, 1, 11 ) {
		if( i == 1 ) a[i][1] = x;
		else a[i][1] = a[i - 1][1] * 3;
		//初始化矩形 
		if( a[i][1] > n ) break ; 
		
		end = i, line[i] = 1, book[a[i][1]] = 1;
		//line表示第i行有多少列 
		rep( j, 2, 18 ) {
			a[i][j] = a[i][j - 1] * 2;
			if( a[i][j] > n ) break;
			line[i] = j, book[a[i][j]] = 1; // 用book标记这个元素被选过 
		}
		lim[i] = ( 1 << line[i] ) - 1; // lim表示第i行的数有多少个，起限制作用 
	}
}
void solve(int x) {
	num = 0 ;
	rep( i, 0, lim[1] ) dp[1][i] = g[i];
	rep( i, 2, end ) rep( j, 0, lim[i] ) {
		if( !g[j] ) continue ; //如果状态j不合法，就跳过 
		dp[i][j] = 0;
		rep( k, 0, lim[i - 1] )
			if( g[k] && ( (k & j) == 0 ) ) //如果状态k合法，且k与j没有位置相同 
			dp[i][j] += dp[i - 1][k], dp[i][j] %= mod;
	}
	rep( i, 0, lim[end] ) num += dp[end][i], num %= mod ;
}
signed main()
{
	n = read() ; Ans = 1;
	rep( i, 0, maxn ) g[i] = ( (i << 1) & (i) ) ? 0 : 1; //初始化哪些状态合法。 
	
	rep( i, 1, n ) if( !book[i] )  //如果这个数没有被选过。 
		init(i), solve(i), Ans = Ans * num % mod; //先构造矩形，然后状压dp 
	
	printf("%lld\n", Ans );
	return 0;
}
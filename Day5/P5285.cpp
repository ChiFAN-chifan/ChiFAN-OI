#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define ui unsigned int
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define RL Reg LL
#define RU Reg ull
#define Con const
#define CI Con int&
#define CL Con long long&
#define CU Con ull&
#define I inline
#define W while
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define Gmax(x,y) (x<(y)&&(x=(y)))
#define Gmin(x,y) (x>(y)&&(x=(y)))
using namespace std;
class FastIO
{
	private:
		#define FS 100000
		#define tc() (A==B&&(B=(A=FI)+fread(FI,1,FS,stdin),A==B)?EOF:*A++)
		#define pc(c) (C^FS?FO[C++]=c:(fwrite(FO,1,C,stdout),FO[(C=0)++]=c))
		#define tn (x<<3)+(x<<1)
		#define D isdigit(c=tc())
		int T,C;char c,*A,*B,FI[FS],FO[FS],S[FS];
	public:
		I FastIO() {A=B=FI;}
		Tp I bool read(Ty& x) {x=0;W(!D) ;if(c=='?') return false;W(x=tn+(c&15),D);return true;}
		Tp I void write(Ty x) {x<0&&(pc('-'),x=-x);W(S[++T]=x%10+48,x/=10);W(T) pc(S[T--]);}
		Ts I bool read(Ty& x,Ar&... y) {return read(x)&&read(y...);}
		Tp I void writeln(Con Ty& x) {write(x),pc('\n');}
		Tp I void read_with_X(Ty& x,CL X) {x=0;W(!D);W(x=(tn%X+(c&15))%X,D);}
		I void reads(string& x) {x="";W(isspace(c=tc()));W(x+=c,!isspace(c=tc())&&~c);}
		I void writec(Con char& x) {pc(x);}
		I void clear() {fwrite(FO,1,C,stdout),C=0;}
}F;
template<class T>
T mul(T x,T y,T P){
	return (x*y-(int)((long double)x/P*y)*P+P)%P;
}
template<class T>
T fastpow(T a,T b,const T mod) {
	T ans = 1;
	for(;b;b>>=1,a=mul(a,a,mod)) {
		if(b&1){
			ans=mul(ans,a,mod);
		}
	}
	return ans;
}
inline int M(__int128 x,const int p){
	return(x%p+p)%p;
}
const int maxn = 1e6+10;
int prime[maxn],u[maxn],pcnt,P[maxn];
void inti(){
	u[1]=1;
	for(int i=2;i<=1000000;i++){
		if(prime[i]!=0) continue;
		P[++pcnt]=i;
		for(int j=1;j*i<=1000000;j++){
			prime[i*j]++;
			if(i*j%(i*i)==0) u[i*j]=2;
		}
	}
	for(int i=2;i<=1000000;i++){
		if(u[i]==2){
			u[i]=0;
			continue;
		}
		u[i]=(prime[i]%2==0?1:-1);
	}
}
struct {/*Miller Rabin 质数判定算法*/
	vector<int> primes= {2,3,5,7,11,13,17,19,23};
	bool operator()(int p) {
		if (p==1)return 0;
		int t,k;
		for (t=p-1,k=0; !(t&1); k++,t>>=1);
		for (int i : primes) {
			if (p==i) return true;
			int a=fastpow(i,t,p),b=a;
			for (int j=1; j<=k; j++) {
				b=M(((__int128)a)*a,p);
				if (b==1&&a!=1&&a!=p-1) return false;
				a=b;
			}
			if (a!=1) return false;
		}
		return true;
	}
} MillerRabin;
int qpow(int a,int b){
    if(b==0) return 1;
    if(b==1) return a;
    int res=(a,b/2);
    res*=res;
    if(b%2==1) res*=a;
    return res;
}
namespace task1{
	int n;
	const int phim = 998244352;
	void Solve(){
		int bmodphi=0;
		char ch;
		bool flag=false;
		while((ch=getchar())<'0'||ch>'9');
		while(bmodphi=bmodphi*10ll+(ch^'0'),(ch=getchar())>='0'&&ch <='9'){
			if(bmodphi >= phim){flag=1;bmodphi%=phim;}
		}
		if(bmodphi >= phim){flag=1;bmodphi%=phim;}
		if(flag)bmodphi+=phim;
		cout<<fastpow(19ll,bmodphi,998244353ll)<<'\n';
	}
	int solve(){
		cin>>n;
		while(n--){
			Solve();
		}
		return 0;
	}
};
namespace task2{
	int n;
	const int phim = 1145140;
	void Solve(){
		int bmodphi=0;
		char ch;
		bool flag=false;
		while((ch=getchar())<'0'||ch>'9');
		while(bmodphi=bmodphi*10ll+(ch^'0'),(ch=getchar())>='0'&&ch <='9'){
			if(bmodphi >= phim){flag=1;bmodphi%=phim;}
		}
		if(bmodphi >= phim){flag=1;bmodphi%=phim;}
		if(flag)bmodphi+=phim;
		cout<<fastpow(19ll,bmodphi,1145141ll)<<'\n';
	}
	int solve(){
		cin>>n;
		while(n--){
			Solve();
		}
		return 0;
	}
};
namespace task3{
	ull n;
	const ull phim = 5211600617818708272;
	void Solve(){
        ull bmodphi;
		cin>>bmodphi;
		cout<<fastpow((ull)19,bmodphi,(ull)5211600617818708273)<<'\n';
	}
	ull solve(){
		cin>>n;
		while(n--){
			Solve();
		}
		return 0;
	}
};
namespace task4{
	int n;
    #define A 55244
    #define B 45699
	signed a[A+B+114];
	void Solve(){
        int x;
        cin>>x;
        cout<<a[x<=A?x:(x-A)%B+A]<<'\n';
	}
	int solve(){
		a[0]=1;
		for(int i=1;i<=A+B;i++) a[i]=19*a[i-1]%998244353;
		cin>>n;
		while(n--){
			Solve();
		}
		return 0;
	}

};
namespace task5{
	int t;
	void Solve(){
		int l,r;
		cin>>l>>r;
		for(int i=l;i<=r;i++){
			if(MillerRabin(i)==0){
				putchar('.');
			}
			else{
				putchar('p');
			}
		}
		putchar('\n');
	}
	int solve(){
		cin>>t;
		while(t--){
			Solve();
		}
		return 0;
	}
};
class LineSiever//线性筛
{
	private:
		#define SZ 1000000
	public:
		int Pc,mu[SZ+5],P[SZ+5];
		I void Sieve(CI S)
		{
			for(RI i=(mu[1]=1,2),j;i<=S;++i)
				for(!P[i]&&(mu[P[++Pc]=i]=-1),j=1;j<=Pc&&1LL*i*P[j]<=S;++j)
					if(P[i*P[j]]=1,i%P[j]) mu[i*P[j]]=-mu[i];else break;
		}
}L;
class MuSolver//求一段区间内每个数的μ值
{
	private:
		#define S 1000000
		#define C(x) ((x)?(~(x)?'+':'-'):'0')
		int g[S+5];ull v[S+5];
	public:
		I void Solve()
		{
			RI n,i,j,lim,len;RU x,y,l,r;for(L.Sieve(S),F.read(n);n;--n)
			{
				if(F.read(l,r),l<=S)//对于筛过的数，直接输出μ值
				{
					for(i=l,lim=min(r,S);i<=lim;++i) F.writec(C(L.mu[i]));
					if(F.writec('\n'),r<=S) continue;l=S+1;
				}
				for(len=r-l+1,i=len;i;--i) g[i]=v[i]=1;//初始化
				for(i=L.Pc;i;--i) for(j=(l+L.P[i]-1)/L.P[i]*L.P[i]-l+1;j<=len;j+=L.P[i])//枚举质数及其倍数
					(l+j-1)/L.P[i]%L.P[i]?g[j]&&(g[j]*=-1,v[j]*=L.P[i]):(g[j]=0);//统计μ值
				for(i=1;i<=len;++i) g[i]&&(i+l-1)^v[i]&&(MillerRabin(x=(i+l-1)/v[i])?//如果不为1
					g[i]*=-1:(y=sqrt(x),y*y==x)&&(g[i]=0)),F.writec(C(g[i]));//为质数则将μ值乘-1，为完全平方数则将μ值变为0，然后输出
				F.writec('\n');
			}
		}
		#undef S
}Mu;
string t;
int table[10000000];
int cnt;
signed main(){
	inti();
    F.reads(t);
    if(t=="1_998244353"){
        task1::solve();
    }
    if(t=="1?"){
        task2::solve();
    }
    if(t=="1?+"){
        task3::solve();
    }
    if(t=="1wa_998244353"){
        task4::solve();
    }
    if(t=="2p"){
		task5::solve();
	}
	if(t=="2u"){
		Mu.Solve();
	}
}
#include<bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, cnt, rot;

struct node
{
	int ls, rs, val, siz, cnt, dep, mxd;
}nod[N];

void Push_up(int x)
{
	int ls = nod[x].ls, rs = nod[x].rs;
	nod[x].siz = nod[ls].siz + nod[rs].siz + nod[x].cnt;
	nod[x].mxd = max(nod[ls].mxd, nod[rs].mxd);
} 

bool cmp(const node& a, const node& b)
{
	return a.val < b.val;
}

int Build(int l, int r, int dep)
{
	if(l > r) return 0;
	int mid = l + r >> 1;
	nod[mid].ls = Build(l, mid - 1, dep + 1);
	nod[mid].rs = Build(mid + 1, r, dep + 1);
	nod[mid].dep = dep;
	Push_up(mid);
	return mid;
}

void rebuild()
{
	sort(nod + 1, nod + 1 + cnt, cmp);
	rot = Build(1, cnt, 1);
}

void Insert(int &rt, int x, int dep)
{
	if(rt == 0)
	{
		rt = ++cnt;
		nod[rt].siz = nod[rt].cnt = 1;
		nod[rt].val = x;
		nod[rt].dep = nod[rt].mxd = dep;
		return;
	}
	if(nod[rt].val == x)
	{
		nod[rt].cnt ++;
		nod[rt].siz ++;
		return;
	}
	if(nod[rt].val < x)
	{
		Insert(nod[rt].rs, x, dep + 1);
		Push_up(rt);
		return;
	}
	if(nod[rt].val > x)
	{
		Insert(nod[rt].ls, x, dep + 1);
		Push_up(rt);
		return;
	}
}

int Findmin(int &rt)
{
	if(nod[rt].ls)
	{
		int ret = Findmin(nod[rt].ls);
		Push_up(rt);
		return ret;
	}
	int ret = rt;
	rt = nod[rt].rs;
	return ret; 
}

void Delete(int &rt, int x)
{
	if(nod[rt].val == x)
	{
		if(nod[rt].cnt > 1) 
		{
			nod[rt].cnt --;
			nod[rt].siz --;
			return;
		}
		else
		{
			if(nod[rt].ls == 0)
			{
				rt = nod[rt].rs;
				return;
			}
			if(nod[rt].rs == 0)
			{
				rt = nod[rt].ls;
				return;
			}
			else
			{
				int nd = Findmin(nod[rt].rs);
				nod[rt].val = nod[nd].val;
				nod[rt].cnt = nod[nd].cnt;
				Push_up(rt);
				return;
			}
		}
	}
	if(nod[rt].val < x)
	{
		Delete(nod[rt].rs, x);
		Push_up(rt);
		return;
	}
	if(nod[rt].val > x)
	{
		Delete(nod[rt].ls, x);
		Push_up(rt);
		return;
	}
}

int Getk(int rt, int x)
{
	if(nod[rt].val == x) return nod[nod[rt].ls].siz + 1;
	else if(nod[rt].val < x) return nod[nod[rt].ls].siz + nod[rt].cnt + Getk(nod[rt].rs, x);
	else if(nod[rt].val > x) return Getk(nod[rt].ls, x);
}

int Getkth(int rt, int x)
{
	if(nod[nod[rt].ls].siz + 1 <= x && nod[nod[rt].ls].siz + nod[rt].cnt >= x) return nod[rt].val;
	if(nod[nod[rt].ls].siz + 1 > x) return Getkth(nod[rt].ls, x);
	if(nod[nod[rt].ls].siz + nod[rt].cnt < x) return Getkth(nod[rt].rs, x - (nod[nod[rt].ls].siz + nod[rt].cnt));
}

int Getpre(int rt, int x)
{
	int p = rt, ans;
	while(p)
	{
		if(x <= nod[p].val) p = nod[p].ls;
		else ans = p, p = nod[p].rs;
	}
	return nod[ans].val;
}

int Getsuc(int rt, int x)//succeed
{
	int p = rt, ans;
	while(p)
	{
		if(x >= nod[p].val) p = nod[p].rs;
		else ans = p, p = nod[p].ls;
	}
	return nod[ans].val;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
	{
		int opt, x;
		scanf("%d%d", &opt, &x);
		if(opt == 1) Insert(rot, x, 1);
		if(opt == 2) Delete(rot, x);
		if(opt == 3) printf("%d\n", Getk(rot, x));
		if(opt == 4) printf("%d\n", Getkth(rot, x));
		if(opt == 5) printf("%d\n", Getpre(rot, x));
		if(opt == 6) printf("%d\n", Getsuc(rot, x));
		if(nod[rot].mxd > 100) rebuild();
	}
}
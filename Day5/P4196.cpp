#include<bits/stdc++.h>
using namespace std;
const int N = 1145;
struct Node{
	double x,y;
	Node operator - (const Node A) {return (Node){x-A.x,y-A.y};}
	Node operator + (const Node A) {return (Node){x+A.x,y+A.y};}
	Node operator * (double t) {return (Node){x*t,y*t};}
	double crs(Node A) {return x*A.y-y*A.x;}
}A[N],B[N],C[N];
int n,m,tot,node;

void Add(Node a1,Node a2,Node b1,Node b2)
{
	Node a=a2-a1,b=b2-b1,c=b1-a1;
	double t=b.crs(c)/b.crs(a);
	C[++tot]=a1+a*t;
}
void Cut(Node a,Node b)
{
	tot=0;A[node+1]=A[1];
	for(int i=1;i<=node;i++)
		if((a-A[i]).crs(b-A[i])>=0)
		{
			C[++tot]=A[i];
			if((a-A[i+1]).crs(b-A[i+1])<0)
				Add(A[i],A[i+1],a,b);
		}
		else if((a-A[i+1]).crs(b-A[i+1])>=0)
			Add(A[i],A[i+1],a,b);
	for(int i=1;i<=tot;i++) A[i]=C[i];
	node=tot;
}
double CalcS()
{
	double res=0;
	for(int i=2;i<node;i++) res+=(A[i]-A[1]).crs(A[i+1]-A[1]);
	return res/2;
}
int main()
{
	cin>>n>>m;node=m;n--;
	for(int i=1;i<=m;i++) cin>>A[i].x>>A[i].y;
	while(n--)
	{
		cin>>m>>B[1].x>>B[1].y;B[m+1]=B[1];
		for(int i=2;i<=m;i++) cin>>B[i].x>>B[i].y;
		for(int i=1;i<=m;i++) Cut(B[i],B[i+1]);
	}
	return printf("%.3f\n",CalcS()),0;
}

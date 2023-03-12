#include <bits/stdc++.h>
#define int long long
#define PII pair <int, int>
using namespace std;
constexpr int mod = 1145141;
constexpr int N = 1e5, MAX_N = N + 3;
constexpr int M = 1e5, MAX_M = M + 3;
int n, m;
vector <PII> E [2] [MAX_N];
int dis [2] [MAX_N], cnt [2] [MAX_N];
bool vis [MAX_N];
void Dijkstra (int s, bool d) {
	static priority_queue <PII, vector <PII>, greater <PII>> Q;
	memset (vis, 0, sizeof vis);
	memset (dis [d], 0x3f, sizeof dis [d]);
	cnt [d] [s] = 1;
	Q.push ({dis [d] [s] = 0, s});
	while (!Q.empty ()) {
		int u = Q.top ().second; Q.pop ();
		if (vis [u]) continue;
		vis [u] = 1;
		for (PII i : E [d] [u]) {
			int v = i.first;
			int w = i.second;
			if (dis [d] [u] + w < dis [d] [v]) {
				cnt [d] [v] = cnt [d] [u];
				Q.push ({dis [d] [v] = dis [d] [u] + w, v});
			}
			else if (dis [d] [u] + w == dis [d] [v])
				(cnt [d] [v] += cnt [d] [u]) %= mod;
		}
	}
}
int s, t;
struct edge {int u, v, w;} a [MAX_M];
signed main () {
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; ++i) {
		static int u, v, w;
		cin >> u >> v >> w;
		a [i] = {u, v, w};
		E [0] [u].push_back ({v, w});
		E [1] [v].push_back ({u, w});
	}
	Dijkstra (s, 0);
	Dijkstra (t, 1);
	for (int i = 1; i <= m; ++i) {
		static int u, v, w, tmp, d;
		u = a [i].u; v = a [i].v; w = a [i].w;
		d = dis [0] [u] + w + dis [1] [v];
		if (d == dis [0] [t]) {
			if (cnt [0] [u] * cnt [1] [v] % mod == cnt [0] [t]) {
				cout << "YES\n";
				continue;
			}
		}
		tmp = d - dis [0] [t] + 1;
		if (w - tmp > 0) cout << "CAN " << tmp << '\n';
		else cout << "NO\n";
	}
}
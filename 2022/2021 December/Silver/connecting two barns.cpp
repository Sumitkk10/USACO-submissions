Connecting Two Barns (C++17)
Sumit Kumar (sumitkk10)
Submitted: Fri, Dec 17, 2021 14:35:46 EST
Contest: USACO 2021 December Contest, Silver
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
using namespace std;
const int N = 1e6 + 5;
long long n, m, component[N];

int find(int x){
	while(true){
		if(x == component[x])
			return x;
		component[x] = component[component[x]];
		x = component[x];
	}
}

void merge(int a, int b){
	int u = find(a), v = find(b);
	if(u == v) return;
	component[u] = v;
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i <= n; ++i)
		component[i] = i;
	for(int i = 1; i <= m; ++i){
		int u, v;
		cin >> u >> v;
		merge(u, v);
	}
	int str = find(1), endd = find(n);
	if(str == endd){
		cout << "0\n";
		return;
	}
	set<long long> a, b;
	long long ans = LLONG_MAX;
	map<int, vector<int> > mp;
	for(int i = 1; i <= n; ++i){
		int x = find(i);
		if(x == str)
			a.insert(i);
		if(x == endd)
			b.insert(i);
		mp[x].push_back(i);
	}
	vector<bool> vis(n + 1, 0);
	for(auto k : a){
		long long pos = *b.upper_bound(k);
		ans = min(ans, (pos - k) * (pos - k));
		if(b.upper_bound(k) != b.begin()){
			pos = *(--b.upper_bound(k));
			ans = min(ans, (pos - k) * (pos - k));
		}
	}
	for(int i = 2; i < n; ++i){
		int x = find(i);
		if(x == str or x == endd or vis[x])
			continue;
		long long from = LLONG_MAX, to = LLONG_MAX;
		for(auto k : mp[x]){
			long long pos = *a.upper_bound(k);
			from = min(from, (pos - k) * (pos - k));
			if(a.upper_bound(k) != a.begin()){
				pos = *(--a.upper_bound(k));
				from = min(from, (pos - k) * (pos - k));
			}
			pos = *b.upper_bound(k);
			to = min(to, (pos - k) * (pos - k));
			if(b.upper_bound(k) != b.begin()){
				pos = *(--b.upper_bound(k));
				to = min(to, (pos - k) * (pos - k));
			}
		}
		ans = min(ans, from + to);
		vis[x] = true;
 	}
	cout << ans << '\n';
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    	solve();
	return 0;
}

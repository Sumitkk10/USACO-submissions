#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>     
#include <ext/pb_ds/tree_policy.hpp>  
#define godspeed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
const int N = 1e6 + 5, MOD = 1e9 + 7;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

void sublime(){
	#ifndef ONLINE_JUDGE
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
}

void solve(){
	int n, k;
	cin >> n >> k;
	vector<pair<int, int> > all;
	int tree_pos[n];
	for(int i = 0; i < n; ++i){
		cin >> tree_pos[i];
		all.pb(make_pair(tree_pos[i], -1));
	}
	vector<pair<int, pair<int, int> > > v(k);
	for(int i = 0; i < k; ++i){
		cin >> v[i].S.F >> v[i].F >> v[i].S.S;
		all.pb(make_pair(v[i].F, i));
	}
	sort(all.begin(), all.end());
	priority_queue<int> removed;
	ordered_set keep;
	for(auto k : all){
		if(k.S == -1){
			// its a tree
			removed.push(k.F);
		}
		else{
			int ind = k.S;
			int req = v[ind].S.S;
			int from = v[ind].S.F;
			int have = keep.size() - keep.order_of_key(from);
			req = req - have;
			while(req > 0 and !removed.empty()){
				--req;
				int tp = removed.top();
				removed.pop();
				keep.insert(tp);
			}
		}
	}
	cout << removed.size() << '\n';
}

int32_t main(){
	sublime();
	godspeed;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

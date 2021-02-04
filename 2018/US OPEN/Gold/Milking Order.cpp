#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5 + 2;
vector<int> v[N], graph[N];
int n, k, in[N];
bool vis[N];

bool possible(int till_where){
    memset(in, 0, sizeof in);
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < till_where; ++i){
        for(int j = 1; j < v[i].size(); ++j) {
            graph[v[i][j - 1]].push_back(v[i][j]);
            in[v[i][j]]++;
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; ++i)
        if(!in[i])
            q.push(i);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        vis[node] = true;
        for(auto k : graph[node]){
            in[k]--;
            if(!in[k])
                q.push(k);
        }
    }
    for(int i = 1; i <= n; ++i)
        graph[i].clear();
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            return false;
    return true;
}

void solve() {
    cin >> n >> k;
    for(int i = 0; i < k; ++i){
        int m;
        cin >> m;
        while(m--){
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    int low = 1, high = k, ans1 = 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(possible(mid)){
            ans1 = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    memset(in, 0, sizeof in);
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < ans1; ++i){
        for(int j = 1; j < v[i].size(); ++j) {
            graph[v[i][j - 1]].push_back(v[i][j]);
            in[v[i][j]]++;
        }
    }
    vector<int> ans;
    priority_queue<int> q;
    for(int i = 1; i <= n; ++i)
        if(!in[i])
            q.push(-i);
    while(!q.empty()){
        int node = q.top();
        q.pop();
        ans.push_back(-node);
        for(auto k : graph[-node]){
            in[k]--;
            if(!in[k])
                q.push(-k);
        }
    }
    for(int i = 0; i < ans.size(); ++i){
        if(i != ans.size() - 1)
            cout << ans[i] << " ";
        else
            cout << ans[i];
    }
}

int main() {
    fast;
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}

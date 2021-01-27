#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 100 + 5;
const int MOD = 1e9 + 7;
int n, k, m, sol;
set<pair<int, pair<int, pair<int, int> > > > s;
bool ok, vis[N][N];
map<pair<int, int>, int> mp;

void check(int i, int j){
    if(i <= 0 or j <= 0 or i > n or j > n or vis[i][j])
        return;
    sol += mp[{i,j}];
    vis[i][j] = true;
    if(s.find({i, {j, {i + 1, j}}}) == s.end())
        check(i + 1, j);
    if(s.find({i, {j, {i - 1, j}}}) == s.end())
        check(i - 1, j);
    if(s.find({i, {j, {i, j + 1}}}) == s.end())
        check(i, j + 1);
    if(s.find({i, {j, {i, j - 1}}}) == s.end())
        check(i, j - 1);
}

int main() {
    fast;
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    cin >> n >> k >> m;
    for(int i = 0; i < m; ++i){
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        s.insert({a, {b, {x, y}}});
        s.insert({x, {y, {a, b}}});
    }
    vector<pair<int, int> > cows;
    for(int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        mp[{u, v}]++;
    }
    long long ans1 = 0;
    vector<int> ans;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(!vis[i][j]){
                check(i, j);
                ans.push_back(sol);
                sol = 0;
            }
        }
    }
    for(int i = 0; i < ans.size(); ++i)
        for(int j = i + 1; j < ans.size(); ++j)
            ans1 += (ans[i] * ans[j]);
    cout << ans1 << '\n';
    return 0;
}

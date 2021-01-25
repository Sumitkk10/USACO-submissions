#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;
const int N = 1000 + 5;
const int MOD = 1e9 + 7;
int cow[N][2], n;
vector<int> graph[N];
bool vis[N];

void dfs(int source){
    vis[source] = 1;
    for(auto k : graph[source])
        if(!vis[k])
            dfs(k);
}

bool possible(long long dis){
    for(int i = 1; i <= n; ++i)
        graph[i].clear();
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            long long distance = abs(cow[i][0] - cow[j][0]) * abs(cow[i][0] - cow[j][0]) + abs(cow[i][1] - cow[j][1]) * abs(cow[i][1] - cow[j][1]);
            if(distance <= dis){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    dfs(1);
    bool ok = 1;
    for(int i = 1; i <= n; ++i){
        if(!vis[i])
            ok = 0;
        vis[i] = false;
    }
    return ok;
}

int main() {
    fast;
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> cow[i][0] >> cow[i][1];
    long long low = 0, ans = 0, high = 1e12;
    while(low <= high){
        long long mid = low + (high - low) / 2;
        if(possible(mid)){
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << ans << '\n';
    return 0;
}

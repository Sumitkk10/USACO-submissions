#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 1000 + 5;
const int MOD = 1e9 + 7;
int n, cur_area, cur_perimeter;
char a[N][N];
bool vis[N][N];

void dfs(int i, int j){
    if(a[i][j] != '#' or i < 0 or j < 0 or i >= n or j >= n) {
        cur_perimeter++;
        return;
    }
    if(vis[i][j])
        return;
    vis[i][j] = true;
    ++cur_area;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

int main() {
    fast;
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> a[i][j];
    vector<pair<int, int> > area;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(!vis[i][j] and a[i][j] == '#'){
                dfs(i, j);
                area.push_back({cur_area, cur_perimeter});
                cur_perimeter = cur_area = 0;
            }
        }
    }
    sort(area.rbegin(), area.rend());
    int i = 0, x = area[0].first;
    while(area[i].first == x)
        ++i;
    --i;
    cout << area[i].first << ' ' << area[i].second << '\n';
    return 0;
}

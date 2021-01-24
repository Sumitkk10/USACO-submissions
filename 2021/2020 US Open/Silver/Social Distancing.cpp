#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long int n, m;
pair<long long int, long long int> grass[N];

bool check(long long int dis){
    int cnt = 1, j = 0;
    long long pre = grass[0].first;
    for(int i = 1; i < n; ++i){
        if(j >= m)
            break;
        pre += dis;
        if(pre <= grass[j].second) {
            if(pre < grass[j].first)
                pre = grass[j].first;
            ++cnt;
        }
        else{
            pre -= dis;
            ++j;
            --i;
        }
    }
    return (cnt >= n);
}

int main() {
    fast;
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        grass[i].first = u, grass[i].second = v;
    }
    sort(grass, grass + m);
    long long int low = 1, high = LLONG_MAX / 10000, ans = 1;
    while(low <= high){
        long long int mid = (low + high) / 2;
        if(check(mid)){
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}

/*
ID: messiku1
LANG: C++
PROG: milk2
*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
const int N = 1000002; 
using namespace std;
int n, diff[N];

void solve(){
    cin >> n;
    pair<int, int> a[n];
    int from = INT_MAX, till = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
        diff[a[i].first] += 1;
        diff[a[i].second] -= 1;
        from = min(from, a[i].first);
        till = max(till, a[i].second);
    }
    int pre_sum[N], mx = 0, mx1 = 0, ans = 0, ans1 = 0;
    pre_sum[0] = diff[0];
    for(int i = 1; i < N; ++i)
        pre_sum[i] = pre_sum[i - 1] + diff[i];
    for(int i = from; i < till; ++i){
        int x = pre_sum[i];
        if(x > 0){
            ++ans;
            ans1 = 0;
        }
        else{
            ++ans1;
            ans = 0;
        }
        if(ans > mx)
            mx = ans;
        if(ans1 > mx1)
            mx1 = ans1;
    }
    cout << mx << ' ' << mx1 << '\n';
}

int main(){
    fast;
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}

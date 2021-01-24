#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long int n, a[N], k;

bool check(int mid){
    priority_queue<int> q;
    int j = 0;
    while(j < mid){
        q.push(-a[j]);
        ++j;
    }
    int mx = 0;
    while(q.size()){
        mx += max(0, -q.top() - mx);
        q.pop();
        if(j < n){
            q.push(-(a[j] + mx));
            ++j;
        }
    }
    return (mx <= k);
}

int main() {
    fast;
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    long long int low = 1, high = n, ans = n;
    while(low <= high){
        int mid = (low + high) / 2;
        if(check(mid)){
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << ans << '\n';
    return 0;
}

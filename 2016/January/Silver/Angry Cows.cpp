#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long int n, a[N], k;

bool check(long long int range){
    int pre = a[0], ans = 1;
    for(int i = 1; i < n; ++i){
        if(a[i] > pre + 2*range) {
            ++ans;
            pre = a[i];
        }
    }
    return (ans <= k);
}

int main() {
    fast;
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin >> n >> k;
    long long ans = 0;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    long long int low = 0, high = 1000000005;
    while(low <= high){
        long long mid = (low + high) / 2;
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

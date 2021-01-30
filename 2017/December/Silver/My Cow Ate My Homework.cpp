#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define pb push_back
using namespace std;
const int N = 20 + 5;
const int MOD = 1e9 + 7;

int main(){
    fast;
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);
    int n;
    cin >> n;
    long long int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    long long suffix_sum[n + 1], min_till_now[n + 1];
    suffix_sum[n - 1] = a[n - 1], min_till_now[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; --i) {
        suffix_sum[i] = suffix_sum[i + 1] + a[i];
        min_till_now[i] = min(a[i], min_till_now[i + 1]);
    }
    long double ans = INT_MIN;
    for(int i = 0; i < n - 1; ++i){
        long long sum = suffix_sum[i + 1], mn = min_till_now[i + 1];
        sum -= mn;
        long double avr = (long double) sum / (long double) (n - i - 2);
        ans = max(ans, avr);
    }
    for(int i = 0; i < n - 1; ++i){
        long long sum = suffix_sum[i + 1], mn = min_till_now[i + 1];
        sum -= mn;
        long double avr = (long double) sum / (long double) (n - i - 2);
        if(avr == ans)
            cout << i + 1 << "\n";
    }
    return 0;
}

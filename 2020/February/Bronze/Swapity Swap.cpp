#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, k, A1, A2, B1, B2;

void solve(){
    cin >> n >> k >> A1 >> A2 >> B1 >> B2;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        a[i] = i + 1;
    if(A2 < B1 or B2 < A1){
        if(k % 2){
            reverse(a.begin() + A1 - 1, a.begin() + A2);
            reverse(a.begin() + B1 - 1, a.begin() + B2);
        }
    }
    else{
        map<vector<int>, bool> vis;
        vector<int> temp = a;
        vis[temp] = true;
        int cnt = 0;
        while(true){
            ++cnt;
            reverse(temp.begin() + A1 - 1, temp.begin() + A2);
            reverse(temp.begin() + B1 - 1, temp.begin() + B2);
            if(vis[temp]) break;
            vis[temp] = true;
        }
        k = (k % cnt);
        while(k--){
            reverse(a.begin() + A1 - 1, a.begin() + A2);
            reverse(a.begin() + B1 - 1, a.begin() + B2);
        }
    }
    for(int i = 0; i < n; ++i)
        cout << a[i] << '\n';
}

int main(){
    fast;
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}

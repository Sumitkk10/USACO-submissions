#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(c < a){
        swap(a, c);
        swap(b, d);
    }
    if(c > b)
        cout << (b - a) + (d - c) << '\n';
    else{
        if(d > b)
            cout << d - a << '\n'; 
        else
            cout << b - a << '\n';
    }
}

int main(){
    fast;
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}

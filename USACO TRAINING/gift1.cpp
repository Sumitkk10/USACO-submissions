/*
ID: messiku1
LANG: C++
PROG: gift1
*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    string s[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> s[i];
    map<string, int> mp;
    for(int i = 1; i <= n; ++i){
        string x;
        cin >> x;
        // money is from this person's account;
        int money, people;
        cin >> money >> people;
        mp[x] -= money;
        for(int j = 0; j < people; ++j){
            string bonus;
            cin >> bonus;
            mp[bonus] += (money / people);
        }
        if(people != 0)
            mp[x] += money % people;
    }
    for(int i = 1; i <= n; ++i)
        cout << s[i] << " " << mp[s[i]] << "\n";
}

int main(){
    fast;
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}

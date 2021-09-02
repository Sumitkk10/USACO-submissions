/*
ID: messiku1
LANG: C++
PROG: palsquare
*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
const int N = 1000002; 
using namespace std;
int b;

char reVal(int num){
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

string fromDeci(int base, int inputNum){
    string res = "";
    while (inputNum > 0) {
        res += reVal(inputNum % base);
        inputNum /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool is_palindrome(string a){
    string c = a;
    reverse(c.begin(), c.end());
    return (c == a);
}

void solve(){
    cin >> b;
    for(int i = 1; i <= 300; ++i){
        int sq = i*i;
        string cur = fromDeci(b, sq);
        string cur1 = fromDeci(b, i);
        if(is_palindrome(cur))
            cout << cur1 << ' ' << cur << '\n';
    }
}

int main(){
    fast;
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}

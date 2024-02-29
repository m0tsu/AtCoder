#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
const ll INF = 1e18;
#define print(x) cout << (x) << endl;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    if (S == "SAT") {
        cout << 1 << endl;
    }
    else if (S == "SUN") {
        cout << 7 << endl;
    }
    else if (S == "MON") {
        cout << 6 << endl;
    }
    else if (S == "TUE") {
        cout << 5 << endl;
    }
    else if (S == "WED") {
        cout << 4 << endl;
    }
    else if (S == "THU") {
        cout << 3 << endl;
    }
    else if (S == "FRI") {
        cout << 2 << endl;
    }
}
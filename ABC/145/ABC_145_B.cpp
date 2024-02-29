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
    int N;
    string S;
    cin >> N;
    cin >> S;
    string sub = S.substr(0,N/2);
    string sub2 = S.substr(N/2);
    // cout << sub << endl;
    // cout << sub2 << endl;
    if (sub == sub2) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
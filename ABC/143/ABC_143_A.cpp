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
    int A, B;
    cin >> A >> B;
    if (B*2 > A) {
        cout << 0 << endl;
    }
    else {
        cout << A - B * 2 << endl;
    }
}
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
    ll N;
    cin >> N;
    ll num = 1;
    for (ll i = round(sqrt(N)); i > 0; i--) {
        if (N % i == 0) {
            num = i;
            break;
        }
    }
    // cout << round(sqrt(N)) << endl;
    // cout << num << endl;
    cout << num + N/num - 2 << endl;
}
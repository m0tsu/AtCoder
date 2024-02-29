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
    long double a, b, x;
    long double ans = 0;
    cin >> a >> b >> x;
    if (x/a < a*b/2) {
        ans = atan(a*b*b/2/x);
    }
    else {
        ans = atan(2*b/a - 2*x/a/a/a);
    }
    cout << std::fixed << std::setprecision(20) << ans/2/3.141592653589*360 << endl;
}
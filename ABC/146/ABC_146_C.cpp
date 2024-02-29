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
    ll A, B, X;
    cin >> A >> B >> X;
    ll now = 0;
    for (ll i = 0; i < 10; i++) {
        if ((X - B * (i+1))/A >= pow(10, i) && (X - B * (i+1))/A < pow(10, i+1)) {
            now = max(now, (X-B*(i+1))/ A);
        } else if ((X - B * 10)/A >= pow(10, 9)) {
            now = 1000000000;
        } else if ((X - B * (i+1))/A >= pow(10, i+1) && (X - B * (i+2))/A < pow(10, i+1))
        {
            now = max(now, (X-B*(i+2))/ A);
        }
    }
    if (now > 1000000000) {
        cout << 1000000000 << endl;
    } else {
        cout << now << endl;
    }
    // if(1 >= pow(10, 0)) cout << "あ" << endl;
}
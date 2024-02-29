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
    int n;
    cin >> n;
    char pre;
    char now;
    int ans = 1;
    cin >> pre;
    for (int i = 1; i < n; i++) {
        cin >> now;
        if (pre != now) {
            ans++;
        }
        pre = now;
    }
    cout << ans << endl;
}
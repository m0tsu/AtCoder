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
    vector<int> d(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> d.at(i);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += d.at(i) * d.at(j);
        }
    }
    cout << ans << endl;
}
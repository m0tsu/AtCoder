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
    vector<int> L(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> L.at(i);
    }
    sort(L.begin(), L.end());
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            auto Iter = lower_bound(L.begin(), L.end(), L.at(i) + L.at(j));
            int num = Iter - L.begin();
            ans += num - j - 1;
        }
    }
    cout << ans << endl;
}
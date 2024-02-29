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
    vector<int> a(n,0);
    vector<int> keep(n,0);
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        a.at(ai)++;
        keep.at(ai)++;
    }
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        int remove = a.at(i);
        int ans = 0;
        while (a.at(i) != 0) {
            for (int j = 0; j < i; j++) {
            a.at(j) -= remove;
            }
            ans += remove;
            sort(a.begin(), a.end(), greater<int>());
        }
        cout << ans << endl;
    }
}
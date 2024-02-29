#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
const int INF = 1e9 + 10;
const int MAX_N = 300;
#define print(x) cout << (x) << endl;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, l;
    cin >> n >> m >> l;
    int d[MAX_N][MAX_N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                d[i][i] = 0;
            }
            else {
                d[i][j] = INF;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        from--;
        to--;
        d[from][to] = cost;
        d[to][from] = cost;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }
    int dbool[MAX_N][MAX_N];
    for (int i = 0; i < n; i++) dbool[i][i] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] <= l) {
                dbool[i][j] = 1;
            }
            else {
                dbool[i][j] = INF;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                dbool[j][k] = min(dbool[j][k], dbool[j][i] + dbool[i][k]);
            }
        }
    }
    int q;
    cin >> q;
    vector<int> ans(q);
    for (int i = 0; i < q; i++) {
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        if (dbool[s][t] < INF) {
            ans.at(i) = dbool[s][t] - 1;
        }
        else {
            ans.at(i) = -1;
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans.at(i) << endl;
    }
}
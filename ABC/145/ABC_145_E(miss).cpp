#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
const ll INF = 1e18;
#define print(x) cout << (x) << endl;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)

    int n, W;
    int weight[3010], value[3010];

// DPテーブル
    int dp[3010][10010];

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);

    cin >> n >> W;
    W = W-1;
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
    }

  // DP初期条件: dp[0][w] = 0
    for (int w = 0; w <= W; ++w) dp[0][w] = 0;

  // DPループ
    for (int i = 0; i < n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (w >= weight[i]) {
                dp[i+1][w] = max(dp[i][w-weight[i]] + value[i], dp[i][w]);
            }
            else {
                dp[i+1][w] = dp[i][w];
            }
        }
    }
    cout << dp[n][W] << endl;
}
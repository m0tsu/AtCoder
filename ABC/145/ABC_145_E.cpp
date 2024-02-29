#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
const ll INF = 1e18;
#define print(x) cout << (x) << endl;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)

int n, W;
int weight[3010], value[3010]; // 品物の個数は 100 個なので少し余裕持たせてサイズ 110 に

// DPテーブル
int dp[3010][10010] = {0}; // テーブルの初期値はすべて 0 にしておきます

// 復元用テーブル
int prev_w[3010][10010];

int main() {
    // 入力受け取り
    cin >> n >> W;
    W = W-1;
    for (int i = 0; i < n; ++i) cin >> weight[i] >> value[i];

    vector<vector<int> > xy(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        xy.at(i).at(1) = i;
        xy.at(i).at(0) = value[i];
    }

    // DPループ
    for (int i = 0; i < n; ++i) {
        for (int w = 0; w <= W; ++w) {

            // i 番目の品物を選ぶ場合を考える
            if (w >= weight[i]) {
                if (dp[i+1][w] < dp[i][w-weight[i]] + value[i]) {
                    dp[i+1][w] = dp[i][w-weight[i]] + value[i];
                    prev_w[i+1][w] = w - weight[i];
                }
            }

            // i 番目の品物を選ばない場合を考える
            if (dp[i+1][w] < dp[i][w]) {
                dp[i+1][w] = dp[i][w];
                prev_w[i+1][w] = w;
            }
        }
    }

    // 最適値の出力
    // cout << dp[n][W] << endl;


    // 復元
    // cout << "Selected items are..." << endl;
    int cur_w = W;
    for (int i = n-1; i >= 0; --i) {
        // 選んでいた場合
        if (prev_w[i+1][cur_w] == cur_w - weight[i]) {
            // cout << i << " th item (weight = " << weight[i] << ", value = " << value[i] << ")" << endl;
            xy.at(i).at(0) = 0;
        }

        // 復元テーブルをたどる
        cur_w = prev_w[i+1][cur_w];
    }
    sort(xy.begin(), xy.end());
    cout << dp[n][W] + xy.at(n-1).at(0) << endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
const ll INF = 1e18;
#define print(x) cout << (x) << endl;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)

const int MAX = 1000005;
const int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit() {
fac[0] = fac[1] = 1;
finv[0] = finv[1] = 1;
inv[1] = 1;
for (int i = 2; i < MAX; i++){
fac[i] = fac[i - 1] * i % MOD;
inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
finv[i] = finv[i - 1] * inv[i] % MOD;
}
}
// 二項係数計算
long long COM(int n, int k){
if (n < k) return 0;
if (n < 0 || k < 0) return 0;
return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll X, Y;
    cin >> X >> Y;
    long double ratio = Y/X;
    long double ratio2 = X/Y;
    COMinit();
    if ((X+Y)%3==0 && ratio<=2 && ratio2<=2) {
        cout << COM((X+Y)/3,((X+Y)/3*2-X)) << endl;
    } else {
        cout << 0 << endl;
    }
}
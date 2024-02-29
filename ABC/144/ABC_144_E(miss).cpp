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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<ll> preF(N);
    vector<vector<ll>> F(N, vector<ll>(2,0));
    for (ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    for (ll i = 0; i < N; i++) {
        cin >> F.at(i).at(0);
        preF.at(i) = F.at(i).at(0);
        F.at(i).at(1) = i;
    }
    sort(F.begin(), F.end());
    for (ll i = N-1; i > 0; i--) {
        if (K > A.at(F.at(i).at(1))) {
            K -= A.at(F.at(i).at(1));
            A.at(F.at(i).at(1)) = 0;
        }
        else if (0 < A.at(F.at(i).at(1))) {
            A.at(F.at(i).at(1)) -= K;
            K = 0;
            break;
        }
        else {
            break;
        }
        cout << "K: "<< K << endl;
    }
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        ans += A.at(i) * preF.at(i);
        cout << A.at(i) << " " << preF.at(i) << endl;
    }
    cout << ans << endl;
}
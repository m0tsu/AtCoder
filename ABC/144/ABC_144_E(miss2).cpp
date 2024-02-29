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
    vector<vector<ll>> VAF(N, vector<ll>(3,0));
    vector<ll> V(N);
    ll sum = 0;
    for (ll i = 0; i < N; i++) {
        cin >> VAF.at(i).at(1);
    }
    for (ll i = 0; i < N; i++) {
        cin >> VAF.at(i).at(2);
        sum += VAF.at(i).at(2);
        VAF.at(i).at(0) = VAF.at(i).at(1)*VAF.at(i).at(2);
    }
    sort(VAF.begin(), VAF.end());
    ll max = VAF.at(N-1).at(0);
    ll min = 0;
    ll ans = 100;
    while (max >= min) {
        ll mid = min + (max - min)/2;
        ll midK = 0;
        ll counter = 0;
        for (ll i = 0; i < N; i++) {
            counter += mid / VAF.at(i).at(2);
        }
        midK = sum - counter;
        if (midK == K) ans = mid;
        else if (midK > K) max = mid - 1;
        else if (midK < K) min = mid + 1;
    } 
    cout << max << endl;
    cout << ans << endl;
}
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
    int N, K;
    cin >> N >> K;
    vector<int> Kcheck(N,0);
    vector<int> H(N,0);
    for (int i = 0; i<N; i++) {
        cin >> H.at(i);
    }
    for (int i = 0; i < K; i++) {
        std::vector<int>::iterator iter = std::max_element(x.begin(), x.end());
        size_t index = std::distance(x.begin(), iter);
        Kcheck.at(index) = 1;
        if(index == 0 || index == 1) {

        }
    }
}
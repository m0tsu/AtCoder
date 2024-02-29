#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const ll INF = 1e18;
#define pu push
#define pb push_back
#define mp make_pair
#define print(x) cout << (x) << endl;
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define SORT(x) sort(x.begin(),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define fi first
#define sc second

int main() {
    int N, K;
    cin >> N >> K;
    vector<bool> d(N,false);
    rep(i,K) {
        int di;
        cin >> di;
        rep(j,di) {
            int aki;
            cin >> aki;
            d.at(aki-1) = true;
        }
    }
    int ans = 0;
    rep(i,N) {
        if (d.at(i) == false) {
            ans++;
        }
    }
    cout << ans << endl;
}
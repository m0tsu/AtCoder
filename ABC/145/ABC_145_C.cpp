#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using vll = vector<ll>;
const ll INF = 1e18;
#define print(x) cout << (x) << endl;
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define SORT(x) sort(x.begin(),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define fi first
#define se second

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<pair<ld,ld>> xy(N);
    rep(i,N) {
        cin >> xy.at(i).fi >> xy.at(i).se;
    }
    ld sum = 0;
    ld count = 0;
    vector<int> perm;
    rep(i,N) {
        perm.push_back(i);
    }
    do {
        rep(i,N-1) {
            sum += hypot(xy.at(perm.at(i)).first-xy.at(perm.at(i+1)).first,xy.at(perm.at(i)).second-xy.at(perm.at(i+1)).second);
        }
        count++;
    }while (next_permutation(perm.begin(),perm.end()));
    cout << setprecision(15) << sum/count << endl;
}
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
    int N;
    cin >> N;
    vector<int> BplusA(N);
    vector<int> BminusA(N);
    rep(i,N) {
        int A;
        cin >> A;
        BplusA.at(i) = A + i + 1;
        BminusA.at(i) = -(A - i - 1);
    }
    SORT(BplusA);
    SORT(BminusA);
    ll ans = 0;
    rep(i,N) {
        auto low = lower_bound(BminusA.begin(), BminusA.end(), BplusA.at(i));
        auto up = upper_bound(BminusA.begin(), BminusA.end(), BplusA.at(i));
        ans += up-low;
    }
    cout << ans << endl;
}
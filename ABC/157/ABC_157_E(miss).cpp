#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using vll = vector<ll>;
using Graph = vector<vector<int>>;
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
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    rep(i,Q) {
        int q1;
        cin >> q1;
        if (q1 == 1) {
            int iq;
            char cq;
            cin >> iq >> cq;
            S.at(iq-1) = cq;
        }
        if (q1 == 2) {
            int l, r;
            cin >> l >> r;
            string subS;
            subS = S.substr(l-1,l-r+1);
            set<int> SSet;
            rep(j,subS.size()) {
                SSet.insert(subS.at(j));
            }
            cout << SSet.size() << endl;
        }
    }
}
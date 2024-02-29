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
    int X;
    cin >> X;
    vector<ll> A(8000,0);
    vector<ll> B(8000,0);
    rep(i,8000) {
        A.at(i) = (i-4000)*(i-4000)*(i-4000)*(i-4000)*(i-4000);
    }
    B = A;
    bool check = false;
    rep(i,8000) {
        rep(j,8000) {
            if (A.at(i)-B.at(j)==X) {
                cout << i-4000 << " " << j-4000 << endl;
                check = true;
                break;
            }
            // if (i==7999&&j==7999) {
            //     cout << "解なし" << endl;
            // }
        }
        if (check) break;
    }
}
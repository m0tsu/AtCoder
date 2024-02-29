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
    cin.tie(0);
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(10);
    string S;
    // rep(i,220000) {
    //     S.push_back('1');
    //     S.push_back('2');
    //     S.push_back('3');
    //     S.push_back('4');
    //     S.push_back('5');
    //     S.push_back('6');
    //     S.push_back('7');
    //     S.push_back('8');
    //     S.push_back('9');
    // }
    cin >> S;
    ll ans = 0;
    int T = 0;
    int pow10 = 1;
    vector<int> count(2019,0);
    count.at(0)++;
    for (int i = S.size()-1; i >= 0; i--) {
        int Snum = S.at(i) - '0';
        T = (T+Snum*pow10)%2019;
        pow10 = pow10*10%2019;
        count.at(T)++;
        // cout << T << endl;
    }
    rep(i,2019) {
        ans += count.at(i)*(count.at(i)-1)/2;
    }
    cout << ans << endl;
}
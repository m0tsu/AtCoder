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

vector< int64_t > divisor(int64_t n) {
    vector< int64_t > ret;
    for(int64_t i = 1; i * i <= n; i++) {
        if(n % i == 0) {
        ret.push_back(i);
        if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // cout << fixed << setprecision(10);
    ll N;
    cin >> N;
    vector< int64_t > N1div = divisor(N-1);
    // rep(i,div.size()) {
    //     cout << div.at(i) << endl;
    // }
    ll N1divSize = N1div.size()-1;
    
    vector< int64_t > Ndiv = divisor(N);
    ll NdivAnsSize = 0;
    for (ll i = 1; i < Ndiv.size(); i++) {
        ll num = N;
        while(num>0) {
            if(num%Ndiv.at(i)==0) {
                num /= Ndiv.at(i);
            } else if (num%Ndiv.at(i)==1) {
                NdivAnsSize++;
                break;
            } else {
                break;
            }
        }
    }
    cout << N1divSize + NdivAnsSize << endl;
    // cout << N1divSize << endl;
}
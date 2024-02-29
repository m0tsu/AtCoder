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
    int K, N;
    cin >> K >> N;
    vector<int> A(N);
    rep(i,N) {
        cin >> A.at(i);
    }
    vector<int> dist(N);
    rep(i,N-1) {
        dist.at(i) = A.at(i+1)-A.at(i);
    }
    dist.at(N-1) = A.at(0) + K - A.at(N-1);
    SORT(dist);
    cout << K - dist.at(N-1) << endl;
}
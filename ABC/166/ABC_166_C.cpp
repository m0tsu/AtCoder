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
    int N, M;
    cin >> N >> M;
    vector<int> H(N);
    rep(i,N) cin >> H.at(i);
    vector<vector<int>> AB(N,vector<int>());
    rep(i,M){
        int A,B;
        cin >> A >> B;
        A--;
        B--;
        AB.at(A).push_back(B);
        AB.at(B).push_back(A);
    }
    int ans = 0;
    rep(i,N) {
        bool check = true;
        rep(j,AB.at(i).size()) {
            if(H.at(i)<=H.at(AB.at(i).at(j))) check = false;
        }
        if (check == true) {
            ans++;
            // cout << i+1 << "はいい" << endl;
        }
    }
    cout << ans << endl;
}

//setのatが使えないことを確認
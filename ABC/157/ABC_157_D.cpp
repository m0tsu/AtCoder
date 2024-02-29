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

struct UnionFind {
    vector<ll> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(ll N) : par(N) { //最初は全てが根であるとして初期化
        for(ll i = 0; i < N; i++) par[i] = i;
    }

    ll root(ll x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(ll x, ll y) { // xとyの木を併合
        ll rx = root(x); //xの根をrx
        ll ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(ll x, ll y) { // 2つのデータx, yが属する木が同じならtrueを返す
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, K;
    cin >> N >> M >> K;
    UnionFind tree(N);

    vector<vector<ll>> AB(N, vector<ll>());
    rep(i,M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        AB.at(a).push_back(b);
        AB.at(b).push_back(a);
        tree.unite(a,b);
    }
    vector<vector<ll>> CD(N, vector<ll>());
    rep(i,K) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        CD.at(a).push_back(b);
        CD.at(b).push_back(a);
    }
    // set<ll> groups;
    // rep(i,N) {
    //     groups.insert(tree.root(i));
    // }
    // ll NumGroups = groups.size();
    vector<vector<ll>> MemberGroup(N, vector<ll>());
    rep(i,N) {
        MemberGroup.at(tree.root(i)).push_back(i);
    }
    vector<ll> ans(N,0);
    rep(i,N) {
        if (MemberGroup.at(i).size() != 0) {
            SORT(MemberGroup.at(i));
        }
    }
    rep(i,N) {
        if (MemberGroup.at(i).size() != 0) {
            rep(j,MemberGroup.at(i).size()) {
                //MemberGroup.at(i)についてそれぞれ見ていく
                ll person = MemberGroup.at(i).at(j);
                ll personAns = MemberGroup.at(i).size()-1;
                rep(k, AB.at(person).size()) {
                    if (binary_search(MemberGroup.at(i).begin(), MemberGroup.at(i).end(), AB.at(person).at(k))) {
                        personAns--;
                    }
                }
                rep(k, CD.at(person).size()) {
                    if (binary_search(MemberGroup.at(i).begin(), MemberGroup.at(i).end(), CD.at(person).at(k))) {
                        personAns--;
                    }
                }
                ans.at(person) = personAns;
            }
        }
    }
    // rep(i,N) {
    //     rep(j,MemberGroup.at(i).size()) {
    //         cout << MemberGroup.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }
    rep(i,N) {
        cout << ans.at(i) << " ";
    }
    cout << endl;
}
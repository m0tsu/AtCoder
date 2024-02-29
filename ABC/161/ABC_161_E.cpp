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
    // cout << fixed << setprecision(10);
    int N,K,C;
    string S;
    cin >> N >> K >> C >> S;
    int cnt = 0; //働いた日数
    int pnt = 0; //走査ポイント
    vector<int> frw(K,0);
    vector<int> rev(K,0);
    while(cnt<K&&pnt<N) {
        if(S.at(pnt)=='o') {
            frw.at(cnt) = pnt;
            cnt++;
            pnt+=(C+1);
        } else {
            pnt++;
        }
    }
    cnt = 0;
    pnt = N-1;
    while(cnt<K&&pnt>=0) {
        if(S.at(pnt)=='o') {
            rev.at(cnt) = pnt;
            cnt++;
            pnt-=(C+1);
        } else {
            pnt--;
        }
    }
    SORT(rev);
    rep(i,K) {
        if(frw.at(i)==rev.at(i)) {
            cout << frw.at(i)+1 << endl;
        }
    }
    // rep(i,K) {
    //     cout << frw.at(i) << endl;
    // }
    // rep(i,K) {
    //     cout << rev.at(i) << endl;
    // }
}
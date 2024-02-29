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
    cout << fixed << setprecision(10);
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<int> p(A);
    vector<int> q(B);
    vector<int> r(C);
    rep(i,A) cin >> p.at(i);
    rep(i,B) cin >> q.at(i);
    rep(i,C) cin >> r.at(i);
    sort(p.begin(),p.end(),greater<int>());
    sort(q.begin(),q.end(),greater<int>());
    sort(r.begin(),r.end(),greater<int>());
    vector<pair<int,int>> pq; //pairの後ろは0ならp,1ならq,2ならr
    rep(i,X) {
        pq.push_back(make_pair(p.at(i),0));
    }
    rep(i,Y) {
        pq.push_back(make_pair(q.at(i),1));
    }
    SORT(pq);
    bool Acomp = false;
    bool Bcomp = false;
    int pqcnt = 0;
    int rcnt = 0;
    int Acnt = 0;
    int Bcnt = 0;
    // cout << "ここまで" << endl;
    while((Acnt<=X||Bcnt<=Y)&&pqcnt<X+Y&&rcnt<C) {
        if(pq.at(pqcnt).first<r.at(rcnt)) {
            if(pq.at(pqcnt).second==0) {
                Acnt++;
                if(Acnt<=X) {
                    pq.at(pqcnt).first=r.at(rcnt);
                    rcnt++;
                }
            } else {
                Bcnt++;
                if(Bcnt<=Y) {
                    pq.at(pqcnt).first=r.at(rcnt);
                    rcnt++;
                }
            }
            pqcnt++;
        }
        else {
            break;
        }
            // cout << "1交換" << endl;
    }
    ll sum = 0;
    for(int i = 0; i < pq.size(); i++) {
        sum += pq.at(i).first;
    }
    cout << sum << endl;
}
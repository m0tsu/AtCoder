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
    int H, W;
    cin >> H >> W;
    vector<vector<char>> s(H,vector<char>(W));
    vector<vector<int>> dist(H,vector<int>(W));
    rep(i,H){
        rep(j,W){
            cin >> s.at(i).at(j);
        }
    }
    if (s.at(0).at(0)=='#') {
        dist.at(0).at(0) = 1;
    } else {
        dist.at(0).at(0) = 0;
    }
    rep(i,H){
        if(i==0) continue;
        if(s.at(i).at(0)=='#'&&s.at(i-1).at(0)=='.') {
            dist.at(i).at(0)=dist.at(i-1).at(0)+1;
        } else {
            dist.at(i).at(0)=dist.at(i-1).at(0);
        }
    }
    rep(j,W){
        if(j==0) continue;
        if(s.at(0).at(j)=='#'&&s.at(0).at(j-1)=='.') {
            dist.at(0).at(j)=dist.at(0).at(j-1)+1;
        } else {
            dist.at(0).at(j)=dist.at(0).at(j-1);
        }
    }
    rep(i,H){
        rep(j,W){
            if (i==0||j==0) {
                continue;
            }
            int celldist = 10000;
            if(s.at(i).at(j)=='#') {
                if(s.at(i-1).at(j)=='#') {
                    celldist = dist.at(i-1).at(j);
                }
                if(s.at(i).at(j-1)=='#') {
                    celldist = min(celldist,dist.at(i).at(j-1));
                }
                if(s.at(i-1).at(j)=='.') {
                    celldist = min(celldist,dist.at(i-1).at(j)+1);
                }
                if(s.at(i).at(j-1)=='.') {
                    celldist = min(celldist,dist.at(i).at(j-1)+1);
                }
            }
            if(s.at(i).at(j)=='.') {
                if(s.at(i-1).at(j)=='#') {
                    celldist = dist.at(i-1).at(j);
                }
                if(s.at(i).at(j-1)=='#') {
                    celldist = min(celldist,dist.at(i).at(j-1));
                }
                if(s.at(i-1).at(j)=='.') {
                    celldist = min(celldist,dist.at(i-1).at(j));
                }
                if(s.at(i).at(j-1)=='.') {
                    celldist = min(celldist,dist.at(i).at(j-1));
                }
            }
            dist.at(i).at(j) = celldist;
        }
    }
    cout << dist.at(H-1).at(W-1) << endl;
    // rep(i,H){
    //     rep(j,W){
    //         cout << dist.at(i).at(j);
    //     }
    //     cout << endl;
    // }
}
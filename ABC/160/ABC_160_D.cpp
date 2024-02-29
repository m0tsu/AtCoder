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
    int N, X, Y;
    cin >> N >> X >> Y;
    X--;
    Y--;
    //start(0):S,end(N-1):Eと表記
    int SX = X-1;
    int XY = Y-X;
    int YE = N-1-Y;
    vector<int> dist(N-1);
    rep(i,N-1){
        for(int j = i+1; j < N; j++) {
            if(i<=X) {
                if(j<=(X+Y)/2) {
                    dist.at(j-i)++;
                }
                if((X+Y)/2<j&&j<=Y) {
                    dist.at(Y-j+1+X-i)++;
                }
                if(Y<j) {
                    dist.at(j-Y+1+X-i)++;
                }
            }
            else if(i<(X+Y)/2) {
                if(j<=Y) {
                    dist.at(min(j-i,Y-X+1-j+i))++;
                }
                if(Y<j) {
                    dist.at(j-Y+i-X+1)++;
                }
            }
            else if((X+Y)/2<=i) {
                dist.at(j-i)++;
            }
        }
    }
    rep(i,N-1){
        if(i==0) continue;
        cout << dist.at(i) << endl;
    }
    cout << 0 << endl;
}
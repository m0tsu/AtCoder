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
    ll K;
    cin >> K;
    vector<ll> lunlun;
    priority_queue<ll, vector<ll>, greater<ll>> que;
    for(int i = 1; i <= 9; i++) {
        que.push(i);
        lunlun.push_back(i);
    }
    ll pushnum = 9;
    while(pushnum < 3234566667) {
        ll pre = que.top();
        que.pop();
        int endn = pre%10;
        for (int i = -1; i <= 1; i++){
            if(endn==0&&i==-1) {
                continue;
            } else if(endn==9&&i==1) {
                continue;
            } else {
                pushnum = pre*10+(endn+i);
            }
            que.push(pushnum);
            lunlun.push_back(pushnum);
        }
    }
    cout << lunlun.at(K-1) << endl;
}
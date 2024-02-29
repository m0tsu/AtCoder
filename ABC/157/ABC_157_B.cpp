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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> A(9,0);
    vector<bool> Abool(9,false);
    rep(i,9) cin >> A.at(i);
    int N;
    bool ans = false;
    cin >> N;
    rep(i,N) {
        int b;
        cin >> b;
        rep(j,9) {
            if(A.at(j)==b) {
                Abool.at(j) = true;
            }
        }
    }
    if (Abool.at(0)&Abool.at(1)&Abool.at(2)) {
        ans = true;
    }
    else if (Abool.at(3)&Abool.at(4)&Abool.at(5)) {
        ans = true;
    }
    else if (Abool.at(6)&Abool.at(7)&Abool.at(8)) {
        ans = true;
    }
    else if (Abool.at(0)&Abool.at(3)&Abool.at(6)) {
        ans = true;
    }
    else if (Abool.at(1)&Abool.at(4)&Abool.at(7)) {
        ans = true;
    }
    else if (Abool.at(2)&Abool.at(5)&Abool.at(8)) {
        ans = true;
    }
    else if (Abool.at(0)&Abool.at(4)&Abool.at(8)) {
        ans = true;
    }
    else if (Abool.at(2)&Abool.at(4)&Abool.at(6)) {
        ans = true;
    }
    if (ans) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
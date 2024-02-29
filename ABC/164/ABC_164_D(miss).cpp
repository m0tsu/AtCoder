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
    //cout << fixed << setprecision(10);
    string S;
    rep(i,2200) {
        S.push_back('1');
        S.push_back('2');
        S.push_back('3');
        S.push_back('4');
        S.push_back('5');
        S.push_back('6');
        S.push_back('7');
        S.push_back('8');
        S.push_back('9');
    }
    // cin >> S;
    ll count = 0;
    vector<bool> residue(2019,false);
    vector<bool> preresidue(2019,false);
    for (int i = 0; i < S.size(); i++) {
        int Snum = S.at(i) - '0';
        for (int j = 0; j < 2019; j++) {
            if (preresidue.at(j) == true) {
                residue.at((10*j+Snum)%2019) = true;
                if ((10*j+Snum)%2019==0) {
                    count++;
                    // cout << 10*j+Snum << ":" << j << ":" << Snum << endl;
                }
            }
        }
        residue.at(Snum) = true;
        preresidue = residue;
        fill(residue.begin(), residue.end(), false);
    }
    cout << count << endl;
}
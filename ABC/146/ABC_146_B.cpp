#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
const ll INF = 1e18;
#define print(x) cout << (x) << endl;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<char> Schar(S.size());
    for (int i = 0; i < S.size(); i++) {
        Schar.at(i) = S.at(i);
    }
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < S.size(); i++) {
            if (Schar.at(i) == 'Z') {
                Schar.at(i) = 'A';
            }
            else {
                Schar.at(i)++;
            }
        }
    }
    for (int i = 0; i < S.size(); i++) {
        cout << Schar.at(i);
    }
    cout << endl;
}
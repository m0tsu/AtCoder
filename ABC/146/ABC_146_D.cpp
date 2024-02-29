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
    vector<vector<int>> aborder(N,vector<int>(2));
    // vector<vector<int>> ab(N,vector<int>(N,0));
    vector<int> ab(N,0);
    for (int i = 0; i < N-1; i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        aborder.at(i).at(0) = a;
        aborder.at(i).at(1) = b;
        ab.at(a)++;
        ab.at(b)++;
    }
    int maxconnect = 0;
    for (int i = 0; i < N-1; i++) {
        maxconnect = max(maxconnect, ab.at(i));
    }
    cout << maxconnect << endl;
    vector<vector<int>> sumco(N,vector<int>(maxconnect,0));
    for (int i = 0; i < N-1; i++) {
        int a, b;
        a = aborder.at(i).at(0);
        b = aborder.at(i).at(1);
        int abmin;
        for (int j = 0; j < maxconnect; j++) {
            if (sumco.at(a).at(j) == 0 && sumco.at(b).at(j) == 0) {
                abmin = j;
                break;
            }
        }
        cout << abmin+1 << endl;
        sumco.at(a).at(abmin) = 1;
        sumco.at(b).at(abmin) = 1;
    }
}
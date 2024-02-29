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
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> N_factor2(N); //0~N-1の2の素因数の数が入る
    vector<int> factorialN_factor2(N); //0!~(N-1)!の2の素因数の数が入る
    vector<int> nCi(N); //パスカルの三角形の偶奇が入る
    rep(i,N){
        int cnt = 0;
        int num = i;
        while(num>0) {
            if(num%2==0) {
                cnt++;
                num/=2;
            } else {
                break;
            }
        }
        N_factor2.at(i) = cnt;
    }
    factorialN_factor2.at(0) = 0;
    rep(i,N-1) {
        factorialN_factor2.at(i+1) = factorialN_factor2.at(i) + N_factor2.at(i+1);
        // cout << factorialN_factor2.at(i);
    }
    // cout << factorialN_factor2.at(N-1) << endl;
    rep(i,N) {
        int NumOfPow2 = 0;
        NumOfPow2 = factorialN_factor2.at(N-1)-factorialN_factor2.at(i)-factorialN_factor2.at(N-i-1);
        if (NumOfPow2>0) {
            nCi.at(i) = 0;
        } else {
            nCi.at(i) = 1;
        }
        // cout << nCi.at(i);
    }
    // cout << endl;
    int num1 = 0, num2 = 0, num3 = 0;
    ll preAns = 0;
    int ans = 0;
    string str;
    cin >> str;
    int charcnt = 0;
    for(char ch: str) {
        a.at(charcnt) = ch - '0';
        charcnt++;
    }
    rep(i,N) {
        int prea = a.at(i);
        if (prea == 1) num1++;
        if (prea == 2) num2++;
        if (prea == 3) num3++;
        // cout << a.at(i);
    }
    if (num2 == 0) {
        rep(i,N) {
            int booly;
            booly = (a.at(i)-1)/2;
            preAns+=nCi.at(i)*booly;
        }
        ans = preAns%2;
        ans *= 2;
    } else if (num1 == 0) {
        rep(i,N) {
            int booly;
            booly = a.at(i)-2;
            preAns+=nCi.at(i)*booly;
        }
        ans = preAns%2;
    } else if (num3 == 0) {
        rep(i,N) {
            int booly;
            booly = a.at(i)-1;
            preAns+=nCi.at(i)*booly;
        }
        ans = preAns%2;
    } else {
        rep(i,N) {
            int booly;
            booly = 1-a.at(i)%2;
            preAns+=nCi.at(i)*booly;
        }
        ans = preAns%2;
    }
    cout << ans << endl;
}
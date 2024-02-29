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
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<int> ABC = {A,B,C};
    vector<vector<int>> ABCs(N,vector<int>(3,0)); //触る番号のところが1に
    vector<vector<int>> si(N,vector<int>()); //毎回の触る番号が入っている 1,2
    vector<char> order;
    rep(i,N) {
        string S;
        cin >> S;
        ABCs.at(i).at(S.at(0)-'A') = 1;
        ABCs.at(i).at(S.at(1)-'A') = 1;
        si.at(i).push_back(S.at(0)-'A');
        si.at(i).push_back(S.at(1)-'A');
        si.at(i).push_back(3-(S.at(0)-'A')-(S.at(1)-'A'));
    }
    bool psbl = true;
    if(ABC.at(si.at(0).at(0))==0&&ABC.at(si.at(0).at(1))==0) {
        psbl = false;
    } else if(ABC.at(si.at(0).at(0))==1&&ABC.at(si.at(0).at(1))==0&&ABC.at(si.at(0).at(1))==0) {
        rep(i,N) {
            int si1 = si.at(i).at(0);
            int si2 = si.at(i).at(1);
            if (ABC.at(si1)<=0&&ABC.at(si2)<=0) {
                psbl = false;
                break;
            } else if (ABC.at(si1)==1&&ABC.at(si2)==0) {
                ABC.at(si1) = 0;
                ABC.at(si2) = 1;
                order.push_back('A'+si2);
            } else if (ABC.at(si1)==0&&ABC.at(si2)==1) {
                ABC.at(si1) = 1;
                ABC.at(si2) = 0;
                order.push_back('A'+si1);
            }
        }
    } else if(ABC.at(si.at(0).at(0))==0&&ABC.at(si.at(0).at(1))==1&&ABC.at(si.at(0).at(1))==0) {
        rep(i,N) {
            int si1 = si.at(i).at(0);
            int si2 = si.at(i).at(1);
            if (ABC.at(si1)<=0&&ABC.at(si2)<=0) {
                psbl = false;
                break;
            } else if (ABC.at(si1)==1&&ABC.at(si2)==0) {
                ABC.at(si1) = 0;
                ABC.at(si2) = 1;
                order.push_back('A'+si2);
            } else if (ABC.at(si1)==0&&ABC.at(si2)==1) {
                ABC.at(si1) = 1;
                ABC.at(si2) = 0;
                order.push_back('A'+si1);
            }
        }
    } else {
        rep(i,N) {
            int si1 = si.at(i).at(0);
            int si2 = si.at(i).at(1);
            if (ABC.at(si1)>ABC.at(si2)) {
                ABC.at(si1)--;
                ABC.at(si2)++;
                order.push_back('A'+si2);
            } else if (ABC.at(si2)>ABC.at(si1)) {
                ABC.at(si1)++;
                ABC.at(si2)--;
                order.push_back('A'+si1);
            } else if (ABC.at(si1)==1&&ABC.at(si2)==1) {
                if (i == N-1) {
                    order.push_back('A'+si1);
                } else {
                    int si3next = si.at(i+1).at(2);
                    if (si1==si3next) {
                        ABC.at(si1)--;
                        ABC.at(si2)++;
                        order.push_back('A'+si2);
                    } else if (si2==si3next) {
                        ABC.at(si1)++;
                        ABC.at(si2)--;
                        order.push_back('A'+si1);
                    } else {
                        ABC.at(si1)--;
                        ABC.at(si2)++;
                        order.push_back('A'+si2);
                    }
                }
            } else {
                ABC.at(si1)++;
                ABC.at(si2)--;
                order.push_back('A'+si1);
            }
        }
    }

    if(!psbl) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        rep(i,N){
            cout << order.at(i) << endl;
        }
    }
}
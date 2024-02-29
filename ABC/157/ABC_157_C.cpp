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
    int N, M;
    int ans = -1;
    cin >> N >> M;
    if (N==1) {
        vector<bool> Num(10,true);
        rep(i,M) {
            int s, c;
            cin >> s >> c;
            rep(j,10) {
                if (j!=c) {
                    Num.at(j)=false;
                }
            }
        }
        rep(j,10) {
            if(Num.at(j)==true) {
                ans =  j;
                break;
            }
        }
    }
    if (N==2) {
        vector<bool> Num(90,true);
        rep(i,M) {
            int s, c;
            cin >> s >> c;
            if (s==2) {
                rep(j,90) {
                    if ((j+10)%10!=c) {
                        Num.at(j)=false;
                    }
                }
            }
            if (s==1) {
                rep(j,90) {
                    if ((j+10)/10!=c) {
                        Num.at(j)=false;
                    }
                }
            }
        }
        rep(j,90) {
            if(Num.at(j)==true) {
                ans = j+10;
                break;
            }
        }
    }
    if (N==3) {
        vector<bool> Num(900,true);
        rep(i,M) {
            int s, c;
            cin >> s >> c;
            if (s==3) {
                rep(j,900) {
                    if ((j+100)%10!=c) {
                        Num.at(j)=false;
                    }
                }
            }
            if (s==2) {
                rep(j,900) {
                    if (((j+100)/10)%10!=c) {
                        Num.at(j)=false;
                    }
                }
            }
            if (s==1) {
                rep(j,900) {
                    if ((j+100)/100!=c) {
                        Num.at(j)=false;
                    }
                }
            }
        }
        rep(j,900) {
            if(Num.at(j)==true) {
                ans = j+100;
                break;
            }
        }
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
#define problem "test"
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) (v).resize(unique(ALL(v)) - (v).begin())
#define BIT(x,i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
using namespace std;
const int N = 5e3;
const ll INF = 1e18;

int n,k,d;
int t[N + 5];
int a[N + 5],b[N + 5];
ll res;

template<class X,class Y>
    inline void minimize(X &x,Y y){
        if (x > y)
            x = y;
    }

namespace subtask3{
    ll dp[2][N + 5];

    void process(){
        for (int i=0;i<= d;i++ ){
            dp[0][i] = dp[1][i] = INF;
        }
        dp[1][1] = a[t[1]];
        for (int i=1;i< n;i++ ){
            for (int num=1;num<= min(i,d);num++ ){
                if (num < d)
                    minimize(dp[(i + 1) & 1][num + 1],dp[i & 1][num] + (t[i + 1] != t[i] ? a[t[i + 1]] : b[t[i + 1]]));
                minimize(dp[(i + 1) & 1][1],dp[i & 1][num] + (t[i + 1] != t[i - num] ? a[t[i + 1]] : b[t[i + 1]]));

                dp[i & 1][num] = INF;
            }
        }

        res = INF;
        for (int i=1;i<= d;i++ ){
            res = min(res,dp[n & 1][i]);
        }
        cout<<res<<'\n';
    }
};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin>>numTest;
    while (numTest-- ){
        cin>>n>>k>>d;
        for (int i=1;i<= n;i++ )    cin>>t[i];
        for (int i=1;i<= k;i++ )    cin>>a[i];
        for (int i=1;i<= k;i++ )    cin>>b[i];

        subtask3 :: process();
    }
}

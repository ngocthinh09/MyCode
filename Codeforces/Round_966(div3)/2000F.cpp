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
const int N = 1e3;
const int K = 1e2;
const int INF = 1e9;

int n,k;
struct Rectangle{
    int h,w;
    Rectangle(int _h = 0,int _w = 0) : h(_h), w(_w){}

    friend istream &operator >> (istream &is,Rectangle &rec){
        return is >> rec.h >> rec.w;
    }

    bool operator < (const Rectangle &other) const{
        return min(h,w) < min(other.h,other.w);
    }
} rec[N + 5];
ll dp[N + 5][K + 5];
ll cost[N + 5][2*K + 5];

ll solve(){
    sort(rec + 1,rec + n + 1);
    for (int i=1;i<= n;i++ ){
        int numOperation = 0;
        cost[i][0] = 0;
        int minVal = min(rec[i].h,rec[i].w);
        int maxVal = max(rec[i].h,rec[i].w);
        for (int j=1;j<= maxVal - minVal;j++ ){
            ++numOperation;
            cost[i][numOperation] = cost[i][numOperation - 1] + minVal;
        }

        int len = minVal;
        for (int j=1;j<= 2*minVal;j++ ){
            if (j % 2 == 0)    len--;
            ++numOperation;
            cost[i][numOperation] = cost[i][numOperation - 1] + len;
        }
    }

    for (int i=0;i<= n;i++ )
        for (int j=0;j<= k;j++ )
            dp[i][j] = INF;

    dp[0][0] = 0;
    for (int i=0;i< n;i++ )
        for (int j=0;j<= k;j++ )
            if (dp[i][j] != INF){
                for (int add=0;add<= k - j && add <= rec[i + 1].h + rec[i + 1].w;add++ )
                    dp[i + 1][j + add] = min(dp[i + 1][j + add],dp[i][j] + cost[i + 1][add]);
            }

    return dp[n][k];
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin>>numTest;
    while (numTest-- ){
        cin>>n>>k;
        int sum = 0;
        for (int i=1;i<= n;i++ ){
            cin>>rec[i];
            sum += (rec[i].h + rec[i].w);
        }
        if (sum < k)    cout<<-1<<'\n';
        else{
            cout<<solve()<<'\n';
        }
    }
}
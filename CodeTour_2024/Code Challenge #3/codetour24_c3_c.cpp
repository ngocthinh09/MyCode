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
const int N = 1e6;
const int LOG = 20;

int n,q;
ll a[N + 5],prefix[N + 5];
int lastPrefix[N + 5],INF,nextPos[LOG + 1][N + 5];
vector<ll> value;

inline int solve(int l,int r){
    int ans = 0,x = l;
    int lg = 31 - __builtin_clz(r - l + 1);
    for (;lg >= 0;lg-- ){
        if (nextPos[lg][x] <= r){
            x = nextPos[lg][x];
            ans |= MASK(lg);
        }
    }

    return ans;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin>>n>>q;
    value.push_back(prefix[0]);
    for (int i=1;i<= n;i++ ){
        cin>>a[i];
        prefix[i] = prefix[i - 1] + a[i];
        value.push_back(prefix[i]);
    }
    sort(ALL(value));
    UNIQUE(value);

    for (int i=0;i<= n;i++ )
        prefix[i] = lower_bound(ALL(value),prefix[i]) - value.begin();
    
    memset(lastPrefix,0x3f,sizeof(lastPrefix));
    INF = lastPrefix[0];

    nextPos[0][n + 1] = INF;
    for (int i=n;i>= 0;i-- ){
        nextPos[0][i] = lastPrefix[prefix[i]];
        lastPrefix[prefix[i]] = i;
        nextPos[0][i] = min(nextPos[0][i],nextPos[0][i + 1]);
    }

    for (int lg=1;MASK(lg) <= n;lg++ ){
        memset(nextPos[lg],0x3f,sizeof(nextPos[lg]));
        for (int i=0;i<= n;i++ )
            if (nextPos[lg - 1][i] != INF)
                nextPos[lg][i] = nextPos[lg - 1][nextPos[lg - 1][i]];
    }

    for (int i=1;i<= q;i++ ){
        int l,r;    cin>>l>>r;
        int res = solve(l - 1,r);
        cout<<res<<'\n';
    }
}
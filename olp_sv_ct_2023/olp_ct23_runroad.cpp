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
const int N = 2e5;
const ll mod = 1e9 + 7;

template <class X,class Y>
    void add (X &x,Y y){
        x += y;
        if (x >= mod)
            x -= mod;
    }


int n,t;
int h[N + 5];
vector<int> adj[N + 5];
bool used[N + 5];
ll sz[N + 5];

void dfs(int u,int p,int lim){
    sz[u] = 1;
    for (int v : adj[u])
        if (v != p && !used[v] && h[v] <= lim){
            used[v] = true;
            dfs(v,u,lim);
            sz[u] += sz[v];
        }
}

ll calc(int u,int p,int lim,int total){
    ll res = 0;
    
    for (int v : adj[u])
        if (v != p && !used[v] && h[v] <= lim){
            used[v] = true;
            res += 1LL*(total - sz[v])*sz[v]*(total - 2) % mod;
            add(res,calc(v,u,lim,total));
        }

    return res;
}

ll solve(int lim){
    for (int i=1;i<= n;i++ )
        used[i] = false;

    for (int i=1;i<= n;i++ )
        if (!used[i] && h[i] <= lim)
            dfs(i,-1,lim);

    ll res = 0;

    for (int i=1;i<= n;i++ )
        used[i] = false;
    
    for (int i=1;i<= n;i++ )
        if (!used[i] && h[i] <= lim)
            add(res,calc(i,-1,lim,sz[i]));

    return res;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin>>n>>t;
    for (int i=1;i<= n;i++ )
        cin>>h[i];

    for (int i=1;i<= n - 1;i++ ){
        int u,v;    cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<(solve(t) - solve(t - 1) + mod) % mod;
}
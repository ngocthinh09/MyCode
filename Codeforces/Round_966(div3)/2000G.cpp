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
const int N = 1e5;
const ll INF = 1e18;

int n,m;
struct Edge{
    int v;
    ll bus,walk;
    Edge (int _v = 0,ll _bus = 0,ll _walk = 0) : v(_v), bus(_bus), walk(_walk) {}
};
vector<Edge> adj[N + 5];
ll timeSta,timeFin,latest;
ll minTime[N + 5];

template<class X,class Y>
    bool minimize(X &x,Y y){
        if (x > y){
            x = y;
            return true;
        }
        return false;
    }

bool check(ll mid){
    for (int i=1;i<= n;i++ )    minTime[i] = INF;
    priority_queue<pll,vector<pll>,greater<pll>>    myq;
    while (!myq.empty())    myq.pop();

    minTime[1] = mid;
    myq.push({minTime[1],1});
    while (!myq.empty()){
        int u = myq.top().se;
        ll timeU = myq.top().fi;
        myq.pop();
        if (timeU > minTime[u]) continue;
        
        for (Edge it : adj[u]){
            int v = it.v;
            ll bus = it.bus;
            ll walk = it.walk;
            if (minimize(minTime[v],minTime[u] + walk))
                myq.push({minTime[v],v});
            if (timeFin <= timeU && minimize(minTime[v],timeU + bus))
                myq.push({minTime[v],v});
            if (timeSta <= timeU && timeU < timeFin && minimize(minTime[v],timeFin + bus))
                myq.push({minTime[v],v});
            if (timeU < timeSta){
                if (timeU + bus <= timeSta && minimize(minTime[v],timeU + bus))
                    myq.push({minTime[v],v});
                if (timeU + bus > timeSta && minimize(minTime[v],timeFin + bus))
                    myq.push({minTime[v],v});
            }
        }
    }

    return (minTime[n] <= latest); 
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin>>numTest;
    while (numTest-- ){
        cin>>n>>m;
        cin>>latest>>timeSta>>timeFin;
        for (int i=1;i<= n;i++ )
            vector<Edge> ().swap(adj[i]);
        for (int i=1;i<= m;i++ ){
            int u,v,l1,l2;  cin>>u>>v>>l1>>l2;
            adj[u].push_back(Edge(v,l1,l2));
            adj[v].push_back(Edge(u,l1,l2));
        }

        ll lo = 0,hi = latest,ans = -1;
        while (lo <= hi){
            ll mid = (lo + hi) >> 1;
            if (check(mid)){
                ans = mid;
                lo = mid + 1;
            } 
            else hi = mid - 1;
        }

        cout<<ans<<'\n';
    }
}
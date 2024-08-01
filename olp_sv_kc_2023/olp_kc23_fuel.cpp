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
const ll INF = 1e9;

ll n,m;
ll pos[N + 5],height[N + 5],sumHeight[N + 5];
int q;
pll query[N + 5];
int res[N + 5];
ll pref[N + 5],suff[N + 5];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<= n;i++ )    cin>>pos[i];
    pos[n + 1] = m;
    for (int i=1;i<= n;i++ ){
        cin>>height[i];
        sumHeight[i] = sumHeight[i - 1] + height[i];
    }
    cin>>q;
    for (int i=1;i<= q;i++ ){
        cin>>query[i].fi;
        query[i].se = i;
    }
    sort(query + 1,query + q + 1);

    deque<int> dq;
    height[0] = INF;
    dq.push_back(0);
    for (int i=1;i<= n;i++ ){
        while (!dq.empty() && height[dq.back()] <= height[i])
            dq.pop_back();
        int last = dq.back();
        pref[i] = pref[last] + 1LL*(pos[i] - pos[last])*height[i] - (sumHeight[i] - sumHeight[last]);
        dq.push_back(i); 
    }

    while (!dq.empty()) dq.pop_back();
    height[n + 1] = INF;
    dq.push_back(n + 1);
    for (int i=n;i>= 1;i-- ){
        while (!dq.empty() && height[dq.back()] <= height[i])
            dq.pop_back();
        int _next = dq.back();
        suff[i] = suff[_next] + 1LL*(pos[_next] - pos[i])*height[i] - (sumHeight[_next - 1] - sumHeight[i - 1]);
        dq.push_back(i);
    }

    int l = 0,r = n + 1;
    for (int i=1;i<= q;i++ ){
        ll flow = query[i].fi;
        int id = query[i].se;
        while (l < n && pref[l + 1] < flow) l++;
        while (r > 1 && flow > suff[r - 1]) r--;
        if (l > r)  res[id] = n;
        else    res[id] = l + (n - r + 1);
    }
    

    for (int i=1;i<= q;i++ )
        cout<<res[i]<<'\n';
}
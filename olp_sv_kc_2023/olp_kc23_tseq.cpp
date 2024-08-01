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
const ll INF = 2e18;

int n,m;
int a[N + 5];
int segCount[4*N + 5];
ll segSum[4*N + 5];
ll res;

template<class X,class Y>
    bool minimize(X &x,Y y){
        if (x > y){
            x = y;
            return true;
        }
        return false;
    }

void updateSum(int id,int l,int r,int u,int v,ll val){
    if (l > r || v < l || r < u)    return;
    if (u <= l && r <= v){
        segSum[id] += val;
        return;
    }
    int mid = (l + r) >> 1;
    if (segSum[id] != 0){
        segSum[2*id] += segSum[id];
        segSum[2*id + 1] += segSum[id];
        segSum[id] = 0;
    }
    updateSum(2*id,l,mid,u,v,val);
    updateSum(2*id + 1,mid + 1,r,u,v,val);
}

void updateCount(int id,int l,int r,int u,int v){
    if (l > r || v < l || r < u)    return;
    if (u <= l && r <= v){
        segCount[id]++;
        return;
    }
    int mid = (l + r) >> 1;
    if (segCount[id] != 0){
        segCount[2*id] += segCount[id];
        segCount[2*id + 1] += segCount[id];
        segCount[id] = 0;
    }
    updateCount(2*id,l,mid,u,v);
    updateCount(2*id + 1,mid + 1,r,u,v);
}

ll getValue(int need){
    int id = 1,l = 0,r = m - 1;
    while (l < r){
        int mid = (l + r) >> 1;
        if (segSum[id] != 0){
            segSum[2*id] += segSum[id];
            segSum[2*id + 1] += segSum[id];
            segSum[id] = 0;
        }
        if (segCount[id] != 0){
            segCount[2*id] += segCount[id];
            segCount[2*id + 1] += segCount[id];
            segCount[id] = 0;
        }
        if (need <= mid){
            id = 2*id;
            r = mid;
        }
        else{
            id = 2*id + 1;
            l = mid + 1;
        }
    }

    return (segSum[id] - 1LL*segCount[id]*need);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<= n;i++ )    cin>>a[i];
    
    for (int i=1;i< n;i++ ){
        if (a[i] == a[i + 1])   continue;
        else if (a[i] < a[i + 1]){
            updateSum(1,0,m - 1,0,a[i],a[i + 1] - a[i]);
            if (a[i + 1] < m - 1)
                updateSum(1,0,m - 1,a[i + 1] + 1,m - 1,a[i + 1] - a[i]);
            updateSum(1,0,m - 1,a[i] + 1,a[i + 1],1 + a[i + 1]);
            updateCount(1,0,m - 1,a[i] + 1,a[i + 1]);
        }
        else{
            updateSum(1,0,m - 1,a[i + 1] + 1,a[i],(m - a[i]) + a[i + 1]);
            if (a[i] < m - 1){
                updateSum(1,0,m - 1,a[i] + 1,m - 1,1 + a[i + 1] + m);
                updateCount(1,0,m - 1,a[i] + 1,m - 1);
            }
            updateSum(1,0,m - 1,0,a[i + 1],1 + a[i + 1]);
            updateCount(1,0,m - 1,0,a[i + 1]);
        }

    }

    res = INF;
    for (int x=0;x<= m - 1;x++ )
        res = min(res,getValue(x));

    cout<<res;
}
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
const int maxA = 2e6;
const int INF = 1e9;

int n,m,numValue;
int a[N + 5];
vector<int> value;
pair<char,int> query[N + 5];

struct SegmentTree{
    // struct Range{
    //     int len,sta;
    //     Range (int _len = 0,int _sta = 0){
    //         len = _len, sta = _sta;
    //     }
    //     bool operator < (const Range &other)    const{
    //         return (len == other.len ? sta > other.sta : len < other.len);
    //     }
    // };
    
    vector<int> maxExist,minExist;
    vector<int> maxRange;
    SegmentTree (int _n = 0){
        maxExist.resize(4*_n + 5,0);
        minExist.resize(4*_n + 5,INF);
        maxRange.resize(4*_n + 5,0);
    }

    void setState(int pos,int state){    // 0 : off --> on    1 : on --> off 
        int id =1,lo = 1,hi = numValue;
        while (lo < hi){
            int mid = (lo + hi) >> 1;
            if (pos <= mid){
                hi = mid;
                id = 2*id;
            }
            else{
                lo = mid + 1;
                id = 2*id + 1;
            }
        }
        maxExist[id] = (state == 0 ? pos : 0);
        minExist[id] = (state == 0 ? pos : INF);
        while (id > 1){
            id >>= 1;
            maxExist[id] = max(maxExist[2*id],maxExist[2*id + 1]);
            minExist[id] = min(minExist[2*id],minExist[2*id + 1]);
        }
    }

    pii getMinMax(int id,int l,int r,int u,int v){  // {max,min}
        if (l > r || v < l || r < u)    return pii(0,INF);
        if (u <= l && r <= v)
            return pii(maxExist[id],minExist[id]);
        int mid = (l + r) >> 1;
        pii _left = getMinMax(2*id,l,mid,u,v);
        pii _right = getMinMax(2*id + 1,mid + 1,r,u,v);
        return pii(max(_left.fi,_right.fi),min(_left.se,_right.se));
    }

    void updateValueRange(int pos,int len){
        int id = 1,lo = 1,hi = numValue;
        while (lo < hi){
            int mid = (lo + hi) >> 1;
            if (pos <= mid){
                hi = mid;
                id = 2*id;
            }
            else{
                lo = mid + 1;
                id = 2*id + 1;
            }
        }
        maxRange[id] = len;
        while (id > 1){
            id >>= 1;
            maxRange[id] = max(maxRange[2*id],maxRange[2*id + 1]);
        }
    }

    void add(int pos){
        int _left = getMinMax(1,1,numValue,1,pos - 1).fi;
        int _right = getMinMax(1,1,numValue,pos + 1,numValue).se;
        updateValueRange(_left,value[pos - 1] - value[_left - 1]);
        updateValueRange(pos,value[_right - 1] - value[pos - 1]);
    }

    void del(int pos){
        int _left = getMinMax(1,1,numValue,1,pos - 1).fi;
        int _right = getMinMax(1,1,numValue,pos + 1,numValue).se;
        updateValueRange(pos,0);
        updateValueRange(_left,value[_right - 1] - value[_left - 1]);
    }

    int walk(int len){
        if (maxRange[1] < len)  return -1;
        int id = 1,lo = 1,hi = numValue;
        while (lo < hi){
            int mid = (lo + hi) >> 1;
            if (maxRange[2*id] >= len){
                hi = mid;
                id = 2*id;
            }
            else{
                lo = mid + 1;
                id = 2*id + 1;
            }
        }

        return (maxRange[id] >= len ? lo : -1);
    }
};

void solve(){
    SegmentTree tree(numValue);
    tree.setState(1,0);
    tree.updateValueRange(1,value[numValue - 1] - value[0]);
    tree.setState(numValue,0);
    
    for (int i=1;i<= n;i++ ){
        tree.setState(a[i],0);
        tree.add(a[i]);
    }

    for (int i=1;i<= m;i++ ){
        if (query[i].fi == '+'){
            tree.setState(query[i].se,0);
            tree.add(query[i].se);
        }
        else if (query[i].fi == '-'){
            tree.setState(query[i].se,1);
            tree.del(query[i].se);
        }
        else{
            int pos = tree.walk(query[i].se + 1);
            cout<<value[pos - 1] + 1<<' ';
        }
    }
    cout<<'\n';
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin>>numTest;
    while (numTest-- ){
        cin>>n;
        vector<int> ().swap(value);
        value.push_back(0);
        value.push_back(2*maxA + 1);
        a[0] = 0;
        a[n + 1] = 2*maxA + 1;
        for (int i=1;i<= n;i++ ){
            cin>>a[i];
            value.push_back(a[i]);
        }
        cin>>m;
        for (int i=1;i<= m;i++ ){
            cin>>query[i].fi>>query[i].se;
            if (query[i].fi == '+')
                value.push_back(query[i].se);
        }
        sort(ALL(value));
        UNIQUE(value);
        numValue = (int)value.size();
        for (int i=1;i<= n;i++ )
            a[i] = lower_bound(ALL(value),a[i]) - value.begin() + 1;
        for (int i=1;i<= m;i++ ){
            if (query[i].fi != '?')
                query[i].se = lower_bound(ALL(value),query[i].se) - value.begin() + 1;
        }

        solve();
    }
}
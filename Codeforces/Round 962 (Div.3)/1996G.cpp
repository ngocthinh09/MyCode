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

int n,m;
struct SegTreeCountMin{
    struct Node{
        int minValue,cnt,lazy;
        Node (int _minValue = 0,int _cnt = 0,int _lazy = 0){
            minValue = _minValue, cnt = _cnt,lazy = _lazy;
        }

        friend Node operator + (const Node &lhs,const Node &rhs){
            if (lhs.minValue < rhs.minValue)
                return Node(lhs.minValue,lhs.cnt,0);
            else if (lhs.minValue > rhs.minValue)
                return Node(rhs.minValue,rhs.cnt,0);
            else return Node(lhs.minValue,lhs.cnt + rhs.cnt,0);
        }
    };
    
    vector<Node> node;
    SegTreeCountMin(int _n){
        node.resize(4*_n + 5);
    }

    void build(int id,int l,int r){
        if (l > r)  return;
        if (l == r){
            node[id].minValue = 0;
            node[id].cnt = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(2*id,l,mid);
        build(2*id + 1,mid + 1,r);
        node[id] = node[2*id] + node[2*id + 1];
    }

    void update(int id,int l,int r,int u,int v,int val){
        if (l > r || v < l || r < u)    return;
        if (u <= l && r <= v){
            node[id].minValue += val;
            node[id].lazy += val;
            return;
        }
        int mid = (l + r) >> 1;
        if (node[id].lazy != 0){
            node[2*id].minValue += node[id].lazy;
            node[2*id + 1].minValue += node[id].lazy;
            node[2*id].lazy += node[id].lazy;
            node[2*id + 1].lazy += node[id].lazy;
            node[id].lazy = 0;
        }
        update(2*id,l,mid,u,v,val);
        update(2*id + 1,mid + 1,r,u,v,val);
        node[id] = node[2*id] + node[2*id + 1];
    }
};

int L[N + 5],R[N + 5];
struct Event{
    int type,ord,id;
    Event (int _type = 0,int _ord = 0,int _id = 0){
        type = _type, ord = _ord, id = _id;
    }

    bool operator < (const Event &other) const{
        return (ord < other.ord);
    }
};
vector<Event> event;

void solve(){
    SegTreeCountMin tree(n);
    event.clear();
    for (int i=1;i<= m;i++ ){
        cin>>L[i]>>R[i];
        event.emplace_back(Event(1,L[i],i));
        event.emplace_back(Event(2,R[i],i));
    }
    sort(ALL(event));
    int res = n;
    
    tree.build(1,1,n);
    for (int i=1;i<= m;i++ )
        tree.update(1,1,n,L[i],R[i] - 1,1);

    res = min(res,n - (tree.node[1].minValue == 0 ? tree.node[1].cnt : 0));

    for (Event it : event){
        int type = it.type;
        int id = it.id;
        if (type == 1){
            tree.update(1,1,n,L[id],R[id] - 1,-1);
            if (L[id] > 1)
                tree.update(1,1,n,1,L[id] - 1,1);
            tree.update(1,1,n,R[id],n,1);
        }
        else{
            if (L[id] > 1)
                tree.update(1,1,n,1,L[id] - 1,-1);
            tree.update(1,1,n,R[id],n,-1);
            tree.update(1,1,n,L[id],R[id] - 1,1);
        }

        res = min(res,n - (tree.node[1].minValue == 0 ? tree.node[1].cnt : 0));
    }

    cout<<res<<'\n';
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin>>numTest;
    while(numTest-- ){
        cin>>n>>m;
        solve();
    }
}
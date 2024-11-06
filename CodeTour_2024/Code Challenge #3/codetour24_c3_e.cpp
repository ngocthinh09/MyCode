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

struct Event{
    int l,r,type;
    Event (int _l = 0,int _r = 0,int _type = 0) : l(_l),r(_r),type(_type){}

    friend bool operator < (const Event &lhs,const Event &rhs){
        if (lhs.l == rhs.l){
            if (lhs.r == rhs.r)     
                return lhs.type > rhs.type;
            return lhs.r > rhs.r;
        }
        return lhs.l < rhs.l;
    }
};

int n,m;
vector<Event> event;
vector<int> value;
int bit[4*N + 5],numValue;

void updatePos(int x){
    for (;x <= numValue;x += (x & (-x)))
        bit[x]++;
}

int getPos(int x){
    int ret = 0;
    for (;x > 0;x -= (x & (-x)))
        ret += bit[x];
    return ret;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<= n;i++ ){
        int l,r;    cin>>l>>r;
        value.push_back(l);
        value.push_back(r);
        event.push_back(Event(l,r,1));
    }

    for (int i=1;i<= m;i++ ){
        int l,r;    cin>>l>>r;
        value.push_back(l);
        value.push_back(r);
        event.push_back(Event(l,r,2));
    }

    sort(ALL(value));
    UNIQUE(value);
    numValue = (int)value.size();
    
    for (Event &it : event){
        it.l = lower_bound(ALL(value),it.l) - value.begin() + 1;
        it.r = lower_bound(ALL(value),it.r) - value.begin() + 1;
    }

    sort(ALL(event));
    int res = 0;

    for (int i=(int)event.size() - 1;i >= 0;i-- ){
        if (event[i].type == 1)
            updatePos(event[i].r);
        else{
            res = max(res,getPos(event[i].r));
        }
    }

    cout<<res;
}
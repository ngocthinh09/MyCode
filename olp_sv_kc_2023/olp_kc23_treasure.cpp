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

int n,s;
vector<int> divs;
struct Point{
    int x,y,id;
    Point (int _x = 0,int _y = 0){
        x = _x,y = _y;
    }

    friend istream &operator>>(istream &is,Point &pt){
        is >> pt.x >> pt.y;
        return is;
    }

    bool operator < (const Point &other)    const{
        return (x != other.x ? x < other.x : y < other.y);
    }

    bool operator == (const Point &other)   const{
        return (x == other.x && y == other.y);
    }
};
Point ptX[N + 5],ptY[N + 5];
int Ox[N + 5],Oy[N + 5];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin>>n>>s;
    s = 2*s;
    for (int i=1;i*i<= s;i++ ){
        if (s % i == 0){
            divs.push_back(i);
            int j = s/i;
            if (i != j)
                divs.push_back(j);
        }
    }

    for (int i=1;i<= n;i++ ){
        cin>>ptX[i];
        ptX[i].id = i;
        ptY[i] = ptX[i];
        swap(ptY[i].x,ptY[i].y);
    }
    
    sort(ptX + 1,ptX + n + 1);
    sort(ptY + 1,ptY + n + 1);

    ll res = 0;

    for (int div : divs){
        int dx = div;
        int dy = s/div;

        int r = 1;
        for (int i=1;i<= n;i++ ){
            while (r < n && ptX[r].x < ptX[i].x + dx)   r++;
            if (ptX[r].x == ptX[i].x + dx){
                while (r < n && ptX[r].x == ptX[i].x + dx && ptX[r].y < ptX[i].y)    r++;
            }
            int it = r;
            while (it <= n && ptX[it] == Point(ptX[i].x + dx,ptX[i].y)){
                Ox[ptX[i].id]++;
                Ox[ptX[it].id]++;
                it++;
            }
        }

        r = 1;
        for (int i=1;i<= n;i++ ){
            while (r < n && ptY[r].x < ptY[i].x + dy)   r++;
            if (ptY[r].x == ptY[i].x + dy){
                while (r < n  && ptY[r].x == ptY[i].x + dy && ptY[r].y < ptY[i].y)    r++;
            }
            int it = r;
            while (it <= n && ptY[it] == Point(ptY[i].x + dy,ptY[i].y)){
                Oy[ptY[i].id]++;
                Oy[ptY[it].id]++;
                it++;
            }
        }

        for (int i=1;i<= n;i++ ){
            res += Ox[i]*Oy[i];
            Ox[i] = Oy[i] = 0;
        }

    }

    cout<<res;
}

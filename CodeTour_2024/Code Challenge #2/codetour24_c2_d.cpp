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

int n;
char A[N + 5],B[N + 5];
int numR,numS,numP;
char change[N + 5];

int compete(char u,char v){
    if (u == v) return 0;
    else{
        if (u == 'P'){
            if (v == 'R')   return 1;
            else return -1;
        }
        else if (u == 'S'){
            if (v == 'P')   return 1;
            else return -1;
        }
        else{
            if (v == 'S')   return 1;
            else return -1;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin>>n;
    for (int i=1;i<= n;i++ ){
        cin>>A[i];
        if (A[i] == 'R')    numR++;
        else if (A[i] == 'S')   numS++;
        else numP++;
    }
    for (int i=1;i<= n;i++ )    cin>>B[i];

    for (int i=1;i<= n;i++ ){
        if (B[i] == 'R'){
            if (numP)   change[i] = 'P',numP--;
        }
        if (B[i] == 'S'){
            if (numR)   change[i] = 'R',numR--;
        }
        if (B[i] == 'P'){
            if (numS)   change[i] = 'S',numS--;
        }
    }

    for (int i=1;i<= n;i++ ){
        if (change[i] != 0) continue;
        if (B[i] == 'R'){
            if (numR)   change[i] = 'R',numR--;
        }
        if (B[i] == 'S'){
            if (numS)   change[i] = 'S',numS--;
        }
        if (B[i] == 'P'){
            if (numP)   change[i] = 'P',numP--;
        }
    }

    int res = 0;
    for (int i=1;i<= n;i++ ){
        if (change[i] == 0) res--;
        else res += compete(change[i],B[i]);
    }

    cout<<res;
}
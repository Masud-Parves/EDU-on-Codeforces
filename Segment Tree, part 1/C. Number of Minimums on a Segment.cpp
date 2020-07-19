#include<bits/stdc++.h>

using namespace std;

/*

        Bismillahir Rahmanir Rahim
        Problem :
        Problem Link :
        Topics :
        Solver : Masud Parves
        I Love Code More than Sharks Love Blood <3
*/

#define ff first
#define ss second
#define mp make_pair
#define SZ(a)           (int)a.size()
#define all(a)  a.begin(), a.end()
#define allr(a)  a.rbegin(), a.rend()


#define sf(a)           scanf("%d",&a)
#define sff(a,b)        scanf("%d %d",&a,&b)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)

#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)

#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define TEST_CASE(t) for(int zz=1 ; zz<=t ; zz++)
#define PRINT_CASE printf("Case %d: ",zz)
#define endl            "\n"
#define Debug(x)            cout<<#x " = "<<(x)<<endl
#define NOT_VISITED 0
#define IS_VISITED 1
#define WHITE 0
#define GRAY 1
#define BLACK 2

int fx[4]= {1,-1,0,0};
int fy[4]= {0,0,1,-1};

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N  (1<<pos);}
//int Reset(int N,int pos){return N= N & ~(1<<pos);}
//bool Check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)3e5+5;


typedef long long ll;
const ll inf = 5e18+100;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, ll> pill;
typedef vector<int> vi;
int n, m;
int a[maxn+5];
pii tree[4*maxn+5];

void buildTree(int node, int b, int e){
	if(b == e) {
        tree[node] = {a[b], 1};
        return;
    }

    int mid = (b+e)/2, left = node+node, right = left+1;

    buildTree(left, b, mid);
    buildTree(right, mid+1, e);

    if(tree[left].ff > tree[right].ff){
        tree[node] = tree[right];
    }
    else if(tree[left].ff < tree[right].ff){
        tree[node] = tree[left];
    } else {
        tree[node].ff = tree[left].ff;
        tree[node].ss = tree[left].ss + tree[right].ss;
    }
    return;
}


void update(int node, int b, int e, int idx, int val){
    if(idx < b || e < idx) return;
    if(idx <= b && e <= idx)
    {
        tree[node] = {val, 1};
        return;
    }

    int mid = (b+e)/2, left = node+node, right = left+1;

    update(left, b, mid, idx, val);
    update(right, mid+1, e, idx, val);

    if(tree[left].ff > tree[right].ff){
        tree[node] = tree[right];
    }else if(tree[left].ff < tree[right].ff){
        tree[node] = tree[left];
    } else {
        tree[node].ff = tree[left].ff;
        tree[node].ss = tree[left].ss + tree[right].ss;
    }
    return;
}


pii query(int node, int b, int e, int l, int r)
{
    if(r < b || e < l) return {INT_MAX / 2, 0};
    if(l <=b && e <= r) return tree[node];

    int mid = (b+e)/2, left = node+node, right = left+1;

    pii lft = query(left,b, mid ,l, r);
    pii rgt = query(right,mid+1, e, l, r);
    if(lft.ff < rgt.ff){
        return lft;
    }else if(lft.ff > rgt.ff){
        return rgt;
    }else{
        pii ret = lft;
        ret.ss += rgt.ss;
        return ret;
    }
}

void solve(){

	cin >> n >> m;

	f0(i, n) cin >> a[i];

	buildTree(1, 0, n-1);
    while(m--)
    {
        int type, a, b;
        cin >> type >> a >> b;
        if(type == 1) {
            update(1, 0, n - 1, a, b);
        } else {
            pii ret = query(1, 0, n - 1, a, b - 1);
            cout << ret.ff << " " << ret.ss << endl;
        }
    }

    return;
}

int main()
{
    CIN

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    //cout << "Fi Amanillah" << endl;

    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
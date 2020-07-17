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
const int maxn = (int)1e5+5;


typedef long long ll;
const ll inf = 5e18+100;
typedef unsigned long long ull;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
typedef vector<int> vi;
int n, m, a[maxn], tree[4*maxn];

void buildTree(int node, int b, int e){
	if(b==e){
		tree[node] = a[b];
		return;
	}

	int mid = (b+e)/2, left = 2*node, right = left+1;
	buildTree(left, b, mid);
	buildTree(right, mid+1, e);

	tree[node] = min(tree[left], tree[right]);
	return;
}

void update(int node , int b, int e, int idx, int val){

	if(idx<b or idx>e) return;

    if (b >= idx && e <= idx){
        tree[node] = val;
        return;
    }

	int mid = (b+e)/2 , left = 2*node, right = left+1;

	update(left, b , mid, idx , val);
	update(right, mid+1, e, idx, val);

	tree[node] = min(tree[left], tree[right]);
	return;
}

int query(int node, int b, int e, int l, int r){

    if(r<b or l>e){
		return INT_MAX;
	}

    if(b>=l && e<=r){
        return tree[node];
    }

	int mid = (b+e)/2, left = 2*node, right = left+1;

	int lft = query(left, b, mid, l, r);
	int rgt = query(right, mid+1, e, l, r);
	return min(lft, rgt);
}




void solve(){

	scanf("%d %d", &n, &m);
	for(int i=1 ; i<=n ; i++){
		scanf("%d", &a[i]);
	}

	buildTree(1, 1, n);

	while(m--){
		int type, u, v;
		scanf("%d %d %d", &type, &u, &v);

		if(type == 1){
			update(1, 1, n, u+1, v);
		} else {
			int minValue = query(1, 1 , n, u+1, v);
			printf("%d\n", minValue);
		}
	}

    return;
}

int main()
{

    //cout << "Fi Amanillah" << endl;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
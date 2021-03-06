
#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;


typedef vector<int> vec;
typedef vector<vec> mat;

const int M = 10000;

//A*B
mat mul(mat &A, mat & B)
{
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<A.size();i++)
    {
        for(int k=0;k<B.size();k++)
        {
            for(int j=0;j<B[0].size();j++)
            {
                C[i][j] = (C[i][j]+A[i][k]*B[k][j])%M;
            }
        }
    }
    return C;
}
//cal A^n
mat pow(mat A,ll n)
{
    mat B(A.size(),vec(A.size()));
    for(int i=0;i<A.size();i++)
    {
        B[i][i] = 1;
    }

    while(n>0)
    {
        if(n&1) B= mul(B,A);
        A = mul(A,A);
        n>>=1;
    }
    return B;
}

ll n;
//fib

void solve(ll n)
{
    mat A(2,vec(2));
    A[0][0]=1;A[0][1] =1;
    A[1][0]=1;A[1][1] =0;

    A = pow(A,n);
    printf("%d\n",A[1][0]);

}
int main()
{
	ios::sync_with_stdio(false);

    while(cin>>n)
    {
        solve(n);
    }

	return 0;
}



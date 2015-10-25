/*
 * Problem - Darth Vader And Tree
 * Use DP and Matrix Exponentiation to reduce a problem of
 * counting num of vertices at atmost X dist from root
 * Check - http://abitofcs.blogspot.com/2015/02/codeforces-round-291-div-2-e-darth.html
 */
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <iomanip>
using namespace std;
const double eps(1e-8);
typedef long long lint;

const lint mod = 1000000007LL;
int n, x, t[110];

struct Matrix
{
    lint a[110][110];
    Matrix()
    {
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= 101; i++)
            a[i][i] = 1;
    }
};

Matrix operator + (Matrix m1, Matrix m2)
{
    Matrix ret;
    for(int i = 1; i <= 101; i++)
        for(int j = 1; j <= 101; j++)
            ret.a[i][j] = (m1.a[i][j] + m2.a[i][j]) % mod;
    return ret;
}

Matrix operator * (Matrix m1, Matrix m2)
{
    Matrix ret;
    for(int i = 1; i <= 101; i++)
        for(int j = 1; j <= 101; j++)
        {
            ret.a[i][j] = 0;
            for(int k = 1; k <= 101; k++)
                ret.a[i][j] = (ret.a[i][j] + m1.a[i][k]*m2.a[k][j] % mod) % mod;
        }
    return ret;
}

Matrix quick_pow(Matrix base, int pow)
{
    Matrix I;
    while(pow)
    {
        if(pow & 1)
            I = I*base;
        base = base*base;
        pow >>= 1;
    }
    return I;
}

lint dp[110];

int main()
{
    scanf("%d %d", &n, &x);
    int tt;
    memset(t, 0, sizeof(t));
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &tt);
        t[tt]++;
    }
    Matrix A;
    /*for(int i =0;i <= 100; i++){
        for(int j =0;j<= 100;j++){
            cout<<A.a[i][j]<<" ";
        }
        cout<<"\n";
    }*/

    //cout<<"\n\n\n";
    memset(A.a, 0, sizeof(A.a));

    /*for(int i =0;i <= 100; i++){
        for(int j =0;j<= 100;j++){
            cout<<A.a[i][j]<<" ";
        }
        cout<<"\n";
    }*/

    for(int i = 1; i <= 100; i++)
        A.a[i][1] = A.a[i][101] = t[i];
    for(int i = 1; i < 100; i++)
        A.a[i][i + 1] = 1;
    A.a[101][101] = 1;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= 100; i++)
        for(int j = 1; i - j >= 0 && j <= 100; j++)
            dp[i] = (dp[i - j]*t[j] + dp[i]) % mod;
    if(x <= 100)
    {
        lint ans = 0;
        for(int i = 0; i <= x; i++) ans = (ans + dp[i]) % mod;
        cout<<ans<<endl;
        return 0;
    }
    A = quick_pow(A, x - 99);
    lint S = 0;
    for(int i = 0; i <= 99; i++) S = (S + dp[i]) % mod;
    lint ans = 0;
    for(int i = 1; i <= 100; i++)
        ans = (ans + dp[100 - i]*A.a[i][101]) % mod;
    ans = (ans + S*A.a[101][101]) % mod;
    cout<<ans<<endl;
    return 0;
}
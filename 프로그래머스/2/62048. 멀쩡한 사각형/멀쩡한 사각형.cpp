#include <string>
#include <vector>
using namespace std;

long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long solution(int w, int h)
{
    long long W = w;
    long long H = h;
    
    long long g = gcd(W, H);
    return W * H - (W + H - g);
}
#include<iostream>
#include<unordered_map>
#include<cmath>
using ll = long long;
int main()
{
    int t;
    std::cin >> t;
    
    while(t--)
    {
        std::unordered_map<ll, ll> a;
        ll x, y;
        std::cin >> x >> y;
        ll total = x * y;
        for(ll n:{x,y})
        {
            while(n%2==0)
            {
                a[2]++;
                n /= 2;
            }
            for (ll i = 3; i * i < n;i++)
            {
                if(n%i==0)
                {
                    a[n]++;
                    n /= i;
                }
            }
        }
        ll num = 1;
        for(auto &fi:a)
        {
            if(fi.second/2>0)
            {
                fi.second /= 2;
                while(fi.second--)
                {
                    num *= fi.first;
                }
            }
        }
        std::cout << num << ' ' << total / num << '\n';
    }
    return 0;
}
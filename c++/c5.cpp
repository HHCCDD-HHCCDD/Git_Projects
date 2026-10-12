#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
int main()
{
    int x, y, s, m, k;
    std::cin >> x >> y >> s >> m >> k;
    std::vector<std::pair<int, int>> a;
    int n, u = 2;
    std::cin >> n;
    std::vector<int> b(n, 0), c(n, 0);
    while (u)
    {
        for (int i = 0; i < n; i++)
        {
            if (u == 2)
                std::cin >> b[i];
            else
            {
                int q;
                std::cin >> q;
                a.push_back({b[i], q});
            }
        }
        u--;
    }
    std::sort(a.begin(), a.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b)
              {
        if(a.first>b.first)
            return true;
        else if(a.first==b.first)
        {
            if(a.second<=b.second)
                return true;
            else
                return false;
        }
        else{
            return false;
        } });
    std::vector<int> d(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            d[i] = a[i].first;              // 顾客给多少钱
            c[i] = k * x + a[i].second * y; // 小红要花费多少钱；
        }
        else
        {
            d[i] += d[i - 1] + a[i].first;
            c[i] += c[i - 1] + k * x + a[i].second * y;
        }
    }
    for (int i = 0; i < n;i++)
    {
        std::cout << b[i] << '\n';
    }
        auto it = lower_bound(c.begin(), c.end(), s) - c.begin();
    if (it == n)
    {
        if (n * k > m)
        {
            int num = m / k;
            std::cout << d[num - 1] << '\n';
        }
        else
        {
            std::cout << d[n - 1] << '\n';
        }
    }
    else
    {
        if (s == c[it])
        {
            int num = k * (it + 1);
            if (m > num)
            {
                std::cout << d[it] << '\n';
            }
            else
            {
                int num = m / k;
                std::cout << d[num - 1] << '\n';
            }
        }
        else
        {
            int num = k * it;
            if (num > m)
            {
                std::cout << d[m / k - 1] << '\n';
            }
            else
            {
                std::cout << d[it - 1] << '\n';
            }
        }
    }
    return 0;
}
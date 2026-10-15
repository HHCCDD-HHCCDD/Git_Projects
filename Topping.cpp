#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
    int n, p;
    std::cin >> n >> p;
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0;i < n;i++)
    {
        int x;
        std::cin >> x;
        a[i] = {x, i + 1};
    }
    long long total = 0;
    for (int i = 0; i < n - 2;i++)
    {
        for (int j = i + 1; j < n - 1;j++)
        {
            for (int z = j + 1; z < n;z++)
            {
                if(a[i].second+a[j].second+a[z].second<=p)
                {
                    long long sum = a[i].first + a[j].first + a[z].first;
                    total = std::max(sum, total);
                }
                else{
                    break;
                }
            }
        }
    }
    std::cout << total << '\n';
    return 0;
}
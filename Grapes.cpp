#include<iostream>
int main()
{
    int n, m;
    std::cin >> n >> m;
    int le = m / n;
    int u = m % n;
    int a[n] = {0}; 
        for (int i = 0; i < n;i++)
        {
            a[i] = le;
            if(i<u)
            {
                a[i] += 1;
            }
        }
    for (int i = 0; i < n;i++)
    {
        std::cout << a[i] << '\n';
    }
        return 0;
}
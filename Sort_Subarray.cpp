#include<iostream>
#include<algorithm>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n, k;
    std::cin >> n >> k;
    int a[n] = {0}, b[n] = {0};
    for (int i = 0; i < n;i++)
    {
        std::cin >> a[i];
        b[i] = a[i];
    }
    std::sort(b, b + n);
    bool ok = true, ju = true;
    int l = 0, r = n - 1;
    while(l<r)
    {
        if(ok)
        {
            if(a[l]==b[l])
            {
                l++;
            }
            else{
                ok = false;
            }
        }
        if(ju)
        {
            if(a[r]==b[r])
            {
                r--;
            }
            else{
                ju = false;
            }
        }
        if(!ok&&!ju)
        {
            break;
        }
    }
    if(k>=r-l+1)
    {
        std::cout << "Yes" << '\n';
    }
    else{
        std::cout << "No" << '\n';
    }
    return 0;
}
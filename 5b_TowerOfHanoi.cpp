#include <bits/stdc++.h>
using namespace std;

// using recursion
void towerOfHanoi(int n, char src, char dest, char helper)
{
    if (n == 0)
    {
        return;
    }

    towerOfHanoi(n - 1, src, helper, dest);
    cout << "Move form " << src << " to " << dest << endl;
    towerOfHanoi(n - 1, helper, dest, src);
}

int main()
{

#ifndef RUN
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    towerOfHanoi(3, 'A', 'C', 'B');
}

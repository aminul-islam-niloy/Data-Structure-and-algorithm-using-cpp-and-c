#include <bits/stdc++.h>
using namespace std;

int maxProduct(int arr[], int size)
{
    if (size < 2)
    {
        cout << "Enter two element" << endl;
        return 0;
    }

    // INT_MIN initialized with the smallest possible int value

    int max_product = INT_MIN;
    int second_max_product = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max_product)
        {
            second_max_product = max_product;
            max_product = arr[i];
        }
        else if (arr[i] > second_max_product)
        {
            second_max_product = arr[i];
        }
    }

    return max_product * second_max_product;
}

int main()
{
    // take array size as n and arr[n] size.
    int n;
    cout << "Enter array size " << endl;
    cin >> n;
    cout << "Enter array  ";
    
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // function call and result store in result variable
    int result = maxProduct(arr, n);
    cout << "Maximum product of two integers: " << result << endl;
}

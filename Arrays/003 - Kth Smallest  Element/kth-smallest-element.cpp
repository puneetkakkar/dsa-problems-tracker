// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// User function template for C++

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {
        int pi = randomPartition(arr, l, r);

        if (k - 1 == pi)
            return arr[pi];
        else if (k - 1 < pi)
            return kthSmallest(arr, l, pi - 1, k);
        else
            return kthSmallest(arr, pi + 1, r, k);
    }

    int randomPartition(int arr[], int l, int r)
    {
        int n = r - l + 1;
        int rpivot = rand() % n;
        swap(arr[l + rpivot], arr[r]);
        return partition(arr, l, r);
    }

    int partition(int arr[], int l, int r)
    {
        int j = l;
        for (int i = l; i < r; i++)
        {
            if (arr[i] <= arr[r])
            {
                swap(arr[i], arr[j]);
                ++j;
            }
        }

        swap(arr[j], arr[r]);

        return j;
    }

    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
};

int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        int number_of_elements;
        cin >> number_of_elements;
        int a[number_of_elements];

        for (int i = 0; i < number_of_elements; i++)
            cin >> a[i];

        int k;
        cin >> k;
        Solution ob;
        cout << ob.kthSmallest(a, 0, number_of_elements - 1, k) << endl;
    }
    return 0;
}
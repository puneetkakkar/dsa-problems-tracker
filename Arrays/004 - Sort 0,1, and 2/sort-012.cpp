// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int low = 0; 
        int mid = 0; 
        int high = n-1;
        for(int i = 0; i <= high && mid <= high; ++i) {
            if(a[i] == 0) {
                swap(a[i], a[low]);
                ++low;
                ++mid;
            } else if(a[i] == 2) {
                swap(a[i], a[high]);
                --high;
                --i;
            } else {
                ++mid;
            }
        }
    }
    
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
};

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}
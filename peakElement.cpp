//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int peakElement(vector<int> &arr) 
    {
        // Your code here
        for(int i = 0; i < arr.size(); i++)
        {
            long long int left = 0;
            long long int right = 0;
            if(i != 0)
            {
                left = arr[i] - arr[i-1];
            }
            if(i != arr.size()-1)
            {
                right = arr[i] - arr[i+1];
            }
            if(left > 0 && right > 0)
            {
                return i;
            }
            if(i == 0)
            {
                if(right > 0)
                {
                    return i;
                }
            }
            if(i == arr.size()-1)
            {
                if(left > 0)
                {
                    return i;
                }
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int idx = ob.peakElement(a);
        int n = a.size();
        bool f = 0;
        if (idx < 0 and idx >= n)
            cout << "false" << endl;
        else {
            if (n == 1 and idx == 0)
                f = 1;
            else if (idx == 0 and a[0] > a[1])
                f = 1;
            else if (idx == n - 1 and a[n - 1] > a[n - 2])
                f = 1;
            else if (a[idx] > a[idx + 1] and a[idx] > a[idx - 1])
                f = 1;
            else
                f = 0;
            if (f)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
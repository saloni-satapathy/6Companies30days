// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    ull arr[n];
	    arr[0]=1;
	    int p2=0,p3=0,p5=0;
	    for(int i=1;i<n+1;i++){
	        arr[i]= min((2*arr[p2]),min((3*arr[p3]),(5*arr[p5])));
	         if(arr[i]==2*arr[p2])
	         p2++;
	         if(arr[i]==3*arr[p3])
	         p3++;
	         if(arr[i]==5*arr[p5])
	         p5++;
	    }
	    return arr[n-1];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
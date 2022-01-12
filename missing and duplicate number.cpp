// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
    int xor1=0;
    for(int i=0;i<n;i++){
        xor1 ^=arr[i];
        xor1 ^=(i+1);
        
    }
    int set_bit=xor1 & ~(xor1-1);
    int x=0,y=0;
    for(int i=0;i<n;i++){
        if(arr[i]&set_bit){
            x^=arr[i];
        }
        else{
            y^=arr[i];
        }
    }
    for(int i=1;i<=n;i++){
        if(set_bit&i){
           x^=i;
        }
        else{
            y^=i;
        }
    }
    int *a;
    for(int i=0;i<n;i++){
        if(x==arr[i]){
            a[0]=x;
            a[1]=y;
            break;
        }
        if(y==arr[i]){
            a[0]=y;
            a[1]=x;
            break;
        }
    }
return a;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends

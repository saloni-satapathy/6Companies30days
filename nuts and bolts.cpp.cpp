// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
   int partition(char arr[],int low,int high,char pivot){
       int i=low;
       for(int j=low;j<high;j++){
          if(arr[j]<pivot){
              swap(arr[j],arr[i]);
              i++;
          } else if(arr[j]==pivot){
              swap(arr[j],arr[high]);
              j--;
          }
       }
       swap(arr[high],arr[i]);
       
       return i;
   }

  void match(char nuts[],char bolts[],int low,int high){
      if(low<high){
          int pivot=partition(nuts,low,high,bolts[high]);
          pivot=partition(bolts,low,high,nuts[pivot]);
          
          match(nuts,bolts,low,pivot-1);
          match(nuts,bolts,pivot+1,high);
      }
      return;
      
  }

	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    match(nuts,bolts,0,n-1);
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
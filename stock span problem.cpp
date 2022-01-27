// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<int>s;
       vector<int>ans;
       ans.push_back(1);
       s.push(0);
        for(int i=1;i<n;i++){
             while(!s.empty() && price[s.top()]<=price[i]) // take care of the condition it should be price[top] less than equal to price[i]
               s.pop();
               
             ans.push_back( (s.empty()) ? (i+1) : (i-s.top()) );
                 
        }

        //another method same logic bt without using stack thereby reducing the space complexity
        /* for(int i=1;i<n;i++){
              int counter=1;
              while(i-counter>=0 && price[i]>=price[i-counter]){
               counter+=ans[i-counter];                  
              }
              ans.push_back(counter);
         }*/
         return ans;
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends

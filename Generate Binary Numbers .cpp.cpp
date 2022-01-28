// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.

string get(int a){
   string s;
    int rem=0;
   if(a==1)
    return "1";
while(a!=0){
      rem=a%2;
      s+=to_string(rem);
      a=a/2;
    }
    reverse(s.begin(),s.end());
    return s;
}

vector<string> generate(int N)
{
	// Your code here
	 vector<string>ans;
	 for(int i=1;i<=N;i++){
	     ans.push_back(get(i));
	 }
	  return ans;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
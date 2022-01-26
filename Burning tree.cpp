// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    int Burning(Node* p,map<Node*,Node*>parent ){
queue<Node*>q;
           int t=0;
           Node*curr=p;
             q.push(curr);
              map<Node*,int>visited;
              visited[curr]=1;
              while(!q.empty()){
                //Node*p=q.front();
                int flag=0;
                int k=q.size();
                while(k--){
                  Node*p=q.front();
                  q.pop();
                if(p->left!=NULL && visited[p->left]==0){
                    flag=1;
                  visited[p->left]=1;
                  q.push(p->left);
                }
                if(p->right!=NULL && visited[p->right]==0){
                    flag=1;
                  visited[p->right]=1;
                  q.push(p->right);
                  }
                if(parent[p]!=NULL && visited[parent[p]]==0){   
                   flag=1;
                   q.push(parent[p]);
                   visited[parent[p]]=1;
                }
               
                }
                if(flag==1)t++;
              }
              
             return t;
    }
    
    Node* BFSTraversal( Node* root, map<Node*,Node*>&parent,int target){
           Node*ptr=root;
        queue<Node*>q;
        q.push(ptr);
        Node*t;
        while(!q.empty()){
            Node*p=q.front();
            
            if(p->data==target)
               t=p;
            q.pop();
            if(p->left!=NULL){
                q.push(p->left);
                parent[p->left]=p;
            }
             if(p->right!=NULL){
                 q.push(p->right);
                 parent[p->right]=p;
             }
        }

       
         return t;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*,Node*>parent;
        Node* start=BFSTraversal(root,parent,target);
      int ans=Burning(start,parent);
        return ans;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends

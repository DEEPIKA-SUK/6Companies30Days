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
    void find_time(Node* root,map<Node*,Node*> &mp,int &mx){
        queue<Node*>q;
        q.push(root);
        set<Node*>s;
        while(!q.empty()){
            int n=q.size(),fl=0;
            while(n--){
            Node* temp=q.front();
            q.pop();
            if(temp->left && s.count(temp->left)==0){
                fl=1;
                s.insert(temp->left);
                q.push(temp->left);
            }
            if(temp->right && s.count(temp->right)==0){
                fl=1;
                s.insert(temp->right);
                q.push(temp->right);
            }
            if(mp[temp]&& s.count(mp[temp])==0){
                fl=1;
                s.insert(mp[temp]);
                q.push(mp[temp]);
            }
            }
            if(fl)mx++;
        }
    }
    Node* find_parent(map<Node*,Node*> &mp,Node* root,int s){
        Node* ans;
        queue<Node*>q;
        q.push(root);
        mp[root]=NULL;
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            if(temp->data==s)ans=temp;
            if(temp->left){
                mp[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                mp[temp->right]=temp;
                q.push(temp->right);
            }
        }
        return ans;
    }
    int minTime(Node* root, int s) 
    {
        // Your code goes here
        map<Node*,Node*> mp;
        Node* temp= find_parent(mp,root,s);
        int mx=0;
        find_time(temp,mp,mx);
        return mx;
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
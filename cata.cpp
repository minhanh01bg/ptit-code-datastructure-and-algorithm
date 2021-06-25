#include<bits/stdc++.h>
    #define ll long long
// test

    #define BEGIN() int t;cin>>t;while(t--)
    #define FAST() ios_base::sync_with_stdio(0);cin.tie(0);
	
// acronym
    #define pob pop_back
    #define EL printf("\n")
    #define pb push_back
    #define FOR(i,l,r) for (int i=l;i<=r;i++)
    #define FORD(i,r,l) for (int i=r;i>=l;i--)
    
    using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
};
Node *insert(Node *t, int x){
	if (t == NULL){
		Node *temp = new Node;
		temp->data =x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	} 
    else {
		if (x < t->data) 
			t->left = insert(t->left, x);
        else 
        	t->right = insert(t->right, x);
	}
    return t;
}
void LRN(Node *root) {
    if (root) {
        LRN(root->left);
        LRN(root->right);
        cout << root->data<<" ";
    }
}
void LNR(Node *root){
    if (root) {
        LNR(root->left);
        cout<<root->data<<" ";
        LNR(root->right);
    }
}
void NLR(Node *root){
    if (root) {
        cout<<root->data<<" ";
        NLR(root->left);
        NLR(root->right);
    }
}
int main(){
    FAST()
    BEGIN(){
        int n;
        cin>>n;
        int x,a[n];
        Node * root = NULL;
        FOR(i,0,n-1){
            cin >> a[i];
            root = insert(root,a[i]);
        }
        NLR(root);
        cout<<endl;
    }           
}

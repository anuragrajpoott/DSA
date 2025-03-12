#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* BST(Node* root,int data){
    if(root==NULL){
        root = new Node(data);
        return root;
    }

    if(data>root->data){
        root->right=BST(root->right,data);
    }else{
        root->left=BST(root->left,data);
    }
    return root;
}

void levelOrderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);

    while(!Q.empty()) {
        Node* FrontNode = Q.front();
        Q.pop();

        if(FrontNode == NULL) {
            cout << endl;
            
            if(!Q.empty()) {
                Q.push(NULL);
            }
        } else {
            cout << FrontNode->data << " ";

            if(FrontNode->left) {
                Q.push(FrontNode->left);
            }

            if(FrontNode->right) {
                Q.push(FrontNode->right);
            }
        }
    }
}

int minVal(Node* root) {
    if(root == NULL) {
        return -1;
    }

    Node* temp = root;
    while(temp->left) {
        temp = temp->left;
    }

    return temp->data;
}

Node* DeletionInBST(Node* root, int data) {
    if(root == NULL) {
        return root;
    }

    if(root->data == data) {
        
        // 0 Child
        if(root->left==NULL && root->right==NULL) {
            delete root;
            return NULL;
        }

        // 1 Child
        // Left Child
        if(root->left!=NULL && root->right==NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Right Child
        if(root->left==NULL && root->right!=NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 Child
        if(root->left!=NULL && root->right!=NULL) {
            int mini = minVal(root->right);
            root->data = mini;
            root->right = DeletionInBST(root->right, mini);
            return root;
        }

    } else if(data > root->data) {
        root->right = DeletionInBST(root->right, data);
        return root;
    } else {
        root->left = DeletionInBST(root->left, data);
        return root;
    }
}



int main(){
    int data;
    Node* root=NULL;
    cout<<"enter data"<<endl;
    cin>>data;
    while(data!=-1){
        BST(root,data);
        cin>>data;
    }
    levelOrderTraversal(root);
    
}
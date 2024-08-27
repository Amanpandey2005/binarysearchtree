#include<iostream> 
using namespace std ;
#include<queue>

class node{
public:
int data ;
node* left ;
node* right ;
// constructor 
node(int data ){
    this -> data = data ;
    this -> left = NULL;
    this -> right = NULL;
}
};

node*buildBST(node* root){
cout << "Enter the data "<< endl;
int data ;
cin >> data;
root = new node(data);
if (data == -1){
    return NULL;
}
cout << "Enter the data inserting in the left of the "<< data << endl;
root ->left = buildBST(root -> left);
cout << "Enter the data inserting in the right of the "<< data<< endl;
root -> right = buildBST(root ->right);
}

void levelordertraversal(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
        if(!q.empty()){
            q.push(NULL);
        }
    }
    else{
        cout << temp -> data << "  ";
        if(temp -> left)
        {
            q.push(temp-> left);
        }
        if(temp -> right){
            q.push(temp -> right);
        }
    }   
}
}

void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root-> left);
    cout << root -> data << "  ";
    inorder(root -> right);
}

void preorder(node*root){
    if(root == NULL){
        return;
    }
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(node*root){
    if(root == NULL){
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

node*buildfromlevelorder(node*root){
    queue <node*> p;
    cout << "Enter the data for root"<< endl;

    int data;
    cin >> data;
    root = new node(data);
    p.push(root);

    while(!p.empty()){
        node* temp = p.front();
        p.pop();

        cout << "Enter the left node for "<< temp -> data << endl;
        int leftdata;
        cin >> leftdata;
        if(leftdata!= -1){
            temp -> left = new node(leftdata);
            p.push(temp -> left);
        }
        cout << "Enter the right node for "<< temp -> data << endl;
        int rightdata;
        cin >> rightdata;
        if(rightdata!= -1){
            temp -> right = new node(rightdata);
            p.push(temp -> right);
        }
   }
}


int main(){
    node * root = NULL;
     root = buildBST(root);
    cout << "level order traversal if binary search tree is"<<endl;
    levelordertraversal(root);
    cout << "inorder traversal if binary search tree is"<<endl;
    inorder(root);
    cout << "preorder traversal if binary search tree is"<<endl;
    preorder(root);
    cout << "postorder traversal if binary search tree is"<<endl;
    postorder(root);
    cout << "build from level order traveral is" <<endl;
    buildfromlevelorder(root);
}
#include<iostream> 
#include<queue>
using namespace std;
class node{
    public :
    int data ;
    node* left ;
    node * right ;

    // by using  Condtructor 
    node(int data ){
        this -> data = data ;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildBST(node* root){
    cout << "Enter the dta you want to enter " << endl;
    int data ;
    cin>> data ;
if( data ==  -1){
    return NULL;
}

root = new node(data);
cout << "Enter the data you want to insert in the left of " << data << endl;
root -> left = buildBST(root -> left);

cout << "Enter the data you want to insert in the right of " << data << endl;
root -> right = buildBST(root -> right);
return root;
}

void levelordertraversal(node*root){
queue<node*>q;
q.push(root);
q.push(NULL);
while(!q.empty()){
    node* temp = q.front();
    q.pop();

    if (temp == NULL){
        cout << endl;
        if(!q.empty()){
            q.push(NULL);
        }
    }
    else{
        cout << temp -> data <<"  ";
        if(temp -> left){
            q.push(temp -> left);

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

void buildfromlevelorder(node * root){
    queue<node*>q;
    cout << "Enter the data for root";
    int data ;
    cin >> data ;
    root = new node(data);

    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << " Enter left node for "<< temp ->data <<endl;
    int leftdata ;
    cin >> leftdata ;

    if(leftdata != -1){
        temp -> left = new node (leftdata);
        q.push(temp -> left);
    }
    cout << "Enter right node for "<< temp -> data << endl;
    int rightdata ;
    cin >> rightdata ;
    if (rightdata != -1){
        temp -> right = new node(rightdata);
        q.push(temp -> right);
    }
    }
}

int main(){
    node * root = NULL;
     root = buildBST(root);
     //cout << " Printing the level order Traversal"<< endl;
     //levelordertraversal(root);
     //cout << "inorder traversal is" << endl;
     // inorder(root) ;
      //cout << "preorder traversal is" << endl;
      //preorder(root);
      //cout << "postorder traversal is" << endl;
      //postorder(root);
      cout << "Build from level order traversal is" << endl;
      buildfromlevelorder(root);
      levelordertraversal(root);
}
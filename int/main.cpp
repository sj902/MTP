// CPP code for inorder succesor
// and predecessor of tree
#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node
{
    int data;
    Node* left,*right;
};

// Function to return data
Node * getnode(int a)
{
    Node *newNode= new Node;
    newNode->data=a;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

/*
since inorder traversal results in
ascending order visit to node , we
can store the values of the largest
no which is smaller than a (predecessor)
and smallest no which is large than
a (succesor) using inorder traversal
*/
void find_p_s(Node* root,int a,
              Node* &p, Node* &q)
{
    // cout<<"root"<<root<<endl;
    // If root is null return
    if (root == NULL)  return ;


    // traverse the left subtree
    cout<<"hey! find left\n";
    find_p_s(root->left, a, p, q);
    cout<<"after left";
    // root data is greater than a
    if(root != NULL && root->data > a)
    {

        // q stores the node whose data is greater
        // than a and is smaller than the previously
        // stored data in *q which is sucessor
        if((!q) || (q) && q->data > root->data)

        {
            q = root;
        }
    }

        // if the root data is smaller than
        // store it in p which is predecessor
    else if(root != NULL && root->data < a)
    {
        cout<<"root is less than key";
        p = root;
    }

    // traverse the right subtree
    find_p_s(root->right, a, p, q);
}
void inorder(Node *root)
{
    Node *ptr=root;
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        cout<<ptr->data<<" ";
        inorder(ptr->right);
    }

}

// Driver code
int main()
{
    Node* root1 = getnode(50);
    root1->left = getnode(20);
    root1->right = getnode(60);
    root1->left->left = getnode(10);
    root1->left->right = getnode(30);
    root1->right->left = getnode(55);
    root1->right->right = getnode(70);
    Node* p = NULL, *q = NULL;
    inorder(root1);
    find_p_s(root1, 55, p, q);

    if(p!=NULL)
        cout << p->data;
    if(q!=NULL)
        cout << " " << q->data;
    return 0;
}
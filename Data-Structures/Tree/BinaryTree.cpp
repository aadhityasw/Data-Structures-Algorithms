#include<iostream>
#include<stdlib.h>
using namespace std;

template <class temp>
class Node
{
    public :
        temp data;
        Node *left, *right;

        Node(temp d)
        {
            data = d;
            left = NULL;
            right = NULL;
        }
};

template <class temp>
class BinaryTree
{
    public :
        Node<temp> *root, *ptr;

        BinaryTree()
        {
            root = NULL;
        }

        void formTree()
        {
            root = new Node<temp>('-');

            root->left = new Node<temp>('-');
            root->left->left = new Node<temp>('+');
            root->left->left->left = new Node<temp>('x');
            root->left->left->right = new Node<temp>('y');
            root->left->right = new Node<temp>('*');
            root->left->right->left = new Node<temp>('2');
            root->left->right->right = new Node<temp>('x');

            root->right = new Node<temp>('+');
            root->right->left = new Node<temp>('*');
            root->right->right = new Node<temp>('/');
            root->right->left->left = new Node<temp>('x');
            root->right->left->right = new Node<temp>('z');
            root->right->right->left = new Node<temp>('y');
            root->right->right->right = new Node<temp>('z');
        }

        void preorder(Node<temp> *ptr)
        {
            if(ptr!=NULL)
            {
                cout<<ptr->data<<'\t';
                preorder(ptr->left);
                preorder(ptr->right);
            }
            return;
        }

        void inorder(Node<temp> *ptr)
        {
            if(ptr!=NULL)
            {
                inorder(ptr->left);
                cout<<ptr->data<<'\t';
                inorder(ptr->right);
            }
            return;
        }

        void postorder(Node<temp> *ptr)
        {
            if(ptr!=NULL)
            {
                postorder(ptr->left);
                postorder(ptr->right);
                cout<<ptr->data<<'\t';
            }
            return;
        }

        void printOptions()
        {
            cout<<"The avalible options are : "<<endl;
            cout<<"1) In-Order traversal of the tree."<<endl;
            cout<<"2) Pre-Order traversal of the tree."<<endl;
            cout<<"3) Post-Order traversal of the tree."<<endl;
            cout<<"4) Exit"<<endl;
        }
};

int main()
{
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\tWelcome\n";
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    
    BinaryTree<char> tree;
    int cho, num;
    tree.formTree();
    do
    {
        tree.printOptions();
        cout<<"Enter your option : ";
        cin>>cho;
        switch(cho)
        {
            case 1 :
                tree.inorder(tree.root);
                cout<<endl;
                break;
            case 2 :
                tree.preorder(tree.root);
                cout<<endl;
                break;
            case 3 :
                tree.postorder(tree.root);
                cout<<endl;
                break;
            case 4 :
                cout<<"End of program."<<endl;
                break;
            default :
                cout<<"Invalid Option"<<endl;
        }
        cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    } while (cho!=4);
}
#include<iostream>
using namespace std;
struct Node
{
    char info;
    struct Node *right;
    struct Node* left;
};
typedef struct Node Nodetype;
Nodetype *root;

Nodetype * insertion(Nodetype *root, int item){

    if(root==NULL){
        Nodetype * newnode= new Nodetype;
        newnode->info=item;
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }
    else if(item < (root->info)){

         root->left= insertion(root->left,item);

    }
    else{
        root->right=insertion(root->right,item);
    }
    return root;

}

void display(Nodetype*root){   //inorder
    if(root!=NULL){
        display(root->left);
        cout<<root->info<<" ";
        display(root->right);
    }

}





int main(){
  
  int choice;
  char item;
    while (1)
    {
        cout<<"PRESS 1 to push\n";
        cout<<"PRESS 2 to display\n";
        cout<<"PRESS 3 to exit\n";

        cin >> choice;

        switch (choice)
        {
        

        case 1:
            cout << "enter the data to be inserted \n";
            cin >> item;
            root=insertion(root,item);
            break;
        case 2:
            display(root);
            break;

        case 3:
            cout << "Exiting the program\n";
            exit(0);
            break;

        default:
            cout << "INVALID CHOICE\n";
        }
    }

    return 0;
}




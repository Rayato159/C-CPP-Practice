#include <iostream>
#include <cstdlib>
#include "QueueCPP.h"
using namespace std;

class Tree{
    public:
        Node *root;
        Tree(){
            root=NULL;
        }

        void createTree(){
            Node *p, *t;
            int x;
            Queue q(100);
            
            cout << "Enter root: " << flush;
            cin >> x;
            root = new Node;
            root->data = x;
            root->lchild = root->rchild = NULL;
            
            q.enqueue(root);

            while(!q.isEmpty()){
                p = q.dequeue();
                cout << "Enter lchild of " << p->data << ": " << flush;
                cin >> x;

                if(x != -1){
                    t = new Node;
                    t->data = x;
                    t->lchild = t->rchild = NULL;
                    p->lchild = t;
                    q.enqueue(t);
                }
                cout << "Enter rchild of " << p->data << ": " << flush;
                cin >> x;

                if(x != -1){
                    t = new Node;
                    t->data = x;
                    t->lchild = t->rchild = NULL;
                    p->rchild = t;
                    q.enqueue(t);
                }
            }
        }

        void preorder(Node *p){
            if(p){
                cout << p->data << " " << flush;
                preorder(p->lchild);
                preorder(p->rchild);
            }
        }

        void inorder(Node *p){
            if(p){
                inorder(p->lchild);
                cout << p->data << " " << flush;
                inorder(p->rchild);
            }
        }
        void postorder(Node *p){
            if(p){
                postorder(p->lchild);
                postorder(p->rchild);
                cout << p->data << " " << flush;
            }
        }

        void levelorder(Node *root){
            Queue q(100);
            createTree();

            cout << root->data << " " << flush;
            q.enqueue(root);

            while(!q.isEmpty()){
                root = q.dequeue();
                if(root->lchild){
                    cout << root->lchild->data << " " << flush;
                    q.enqueue(root->lchild);
                }
                if(root->rchild){
                    cout << root->rchild->data << " " << flush;
                    q.enqueue(root->rchild);
                }
            }
        }

        void hight(Node *root);
};

int main(){
    Tree tree;
    tree.createTree();
    tree.preorder(tree.root);
    return 0;
}
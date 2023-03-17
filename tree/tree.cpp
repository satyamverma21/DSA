#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *build(node *root)
{
    cout << "ENTER THE DATA : ";
    int data;
    cin >> data;

    root = new node(data);
    if (data == -1)
        return NULL;

    cout << "enter data instering in left of : " << data << endl;
    root->left = build(root->left);
    cout << "enter data instering in right : " << data << endl;
    root->left = build(root->right);

    return root;
}

// level order traversal ;
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    int i = 10;
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
        cout << q.front()->data << "-";
    }
    cout << "done";
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

int main()
{
    system("cls");

    node *root = NULL;

    root = build(root);
    levelOrderTraversal(root);

    return 0;
}
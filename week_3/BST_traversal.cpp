#include <iostream>
#include <string>

using namespace std;

struct node
{
    int value;
    node* left;
    node* right;

    node(int value) : value(value) {left = NULL; right = NULL;}
};

void insert(node* tree, int value) {
    if (value == tree->value)
    {
        return ;
    }
    
    if (value < tree->value)
    {
        if (tree->left == NULL)
        {
            tree->left = new node(value);
        } else {
            insert(tree->left, value);
        }
    } else {
        if (tree->right == NULL)
        {
            tree->right = new node(value);
        } else {
            insert(tree->right, value);
        }
    }
}

void preOrder(node* head) {
    if (head == NULL) return ;

    cout << head->value << ' ';
    preOrder(head->left);
    preOrder(head->right);
}

int main() {
    int x;
    node* tree = NULL;
    string command;

    cin >> command;

    while (command != "#")
    {
        cin >> x;

        if (tree == NULL)
        {
            tree = new node(x);
        } else {
            insert(tree, x);
        }

        cin >> command;
    }
    preOrder(tree);

    return 0;
}

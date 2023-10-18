#include <iostream>
#include <string>

using namespace std;

struct node
{
    int id;
    node* left;
    node* mid;
    node* right;

    node(int id) : id(id) {left = mid = right = NULL;}
    node(int id, node* left, node* mid, node* right) : id(id), left(left), mid(mid), right(right) {}
};

void makeRoot(node** head, int u) {
    *head = new node(u);
}

bool insert(node* head, int u, int v) {
    if (head == NULL) return false;
    if (head->id == v)
    {
        if (head->left == NULL)
        {
            head->left = new node(u);
            return true;
        } else if (head->mid == NULL)
        {
            head->mid = new node(u);
            return true;
        } else
        if (head->right == NULL)
        {
            head->right = new node(u);
            return true;
        } else
        if (head->left->id == u || head->mid->id == u || head->right->id == u)
        {
            return true;
        }
    }
    if (insert(head->left, u, v)) return true;
    if (insert(head->mid, u, v)) return true;
    if (insert(head->right, u, v)) return true;

    return false;
}

void preOrder(node* head) {
    if (head == NULL) return ;

    cout << head->id << ' ';
    preOrder(head->left);
    preOrder(head->mid);
    preOrder(head->right);
}

void inOrder(node* head) {
    if (head == NULL) return ;
    
    inOrder(head->left);
    cout << head->id << ' ';
    inOrder(head->mid);
    inOrder(head->right);
}

void postOrder(node* head) {
    if (head == NULL) return ;
    
    postOrder(head->left);
    postOrder(head->mid);
    postOrder(head->right);
    cout << head->id << ' ';
}

int main() {
    int u, v;
    node* head;
    string command;

    cin >> command;

    while (command != "*")
    {
        if (command == "MakeRoot")
        {
            cin >> u;
            makeRoot(&head, u);
        } else if (command == "Insert")
        {
            cin >> u >> v;
            insert(head, u, v);
        } else if (command == "PreOrder") {
            preOrder(head);
            cout << endl;
        } else if (command == "InOrder") {
            inOrder(head);
            cout << endl;
        } else if (command == "PostOrder") {
            postOrder(head);
            cout << endl;
        }

        cin >> command;
    }
    
    return 0;
}
#include <iostream>
#include <cstdint>
#include <cstring>

using namespace std;

typedef struct sequence
{
    int value;
    sequence* next;
};

void display(sequence* s) {
    while (s != NULL)
    {
        cout << s->value << ' ';
        s = s->next;
    }
}

void addLast(sequence** s, int k) {
    sequence* temp = *s;
    while (temp != NULL)
    {
        if (temp->value == k)
        {
            return;
        }
        temp = temp->next;
    }

    if (*s == NULL)
    {
        *s = new sequence;
        (*s)->value = k;
        (*s)->next = NULL;
    } else {
        sequence* temp = *s;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new sequence;
        temp->next->value = k;
        temp->next->next = NULL;
    }
}

void addAfter(sequence* s, int u, int v) {
    sequence* temp = s;
    while (s != NULL)
    {
        if (s->value == u)
        {
            return;
        }
        s = s->next;
    }
    s = temp;
    
    while (s->value != v && s != NULL)
    {
        if (s->value == u) return;
        s = s->next;
    }
    if (s == NULL)
    {
        return;
    }
    temp = new sequence;
    temp->value = u;
    temp->next = s->next;
    s->next = temp;
}

void addBefore(sequence* s, int u, int v) {
    if (s == NULL) return;

    while (s->next != NULL && s->next->value != v)
    {
        if (s->value == u) return;
        s = s->next;
    }
    sequence* temp = new sequence;
    temp->value = u;
    temp->next = s->next;
    s->next = temp;
}

void remove(sequence* s, int k) {
    while (s != NULL && s->next != NULL)
    {
        while (s->next != NULL && s->next->value == k) {
            s->next = s->next->next;
        }
        s = s->next;
    }
}

sequence* reverse(sequence* s) {
    sequence *tempL, *tempR;

    tempL = s;
    tempR = s->next;
    s->next = NULL;
    while (tempR != NULL)
    {
        s = tempR;
        tempR = tempR->next;
        s->next = tempL;
        tempL = s;
    }
    return s;
}

int main() {
    char command[9];
    int n, a;
    sequence* head = NULL;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a;

        addLast(&head, a);
    }
    
    cin >> command;
    while (strcmp(command, "#") != 0)
    {
        if (strcmp(command, "addlast") == 0)
        {
            int k;

            cin >> k;

            addLast(&head, k);
        } else if (strcmp(command, "addfirst") == 0)
        {
            int k;

            cin >> k;

            sequence* temp = new sequence;
            temp->value = k;
            temp->next = head;
            head = temp;
        } else if (strcmp(command, "addafter") == 0)
        {
            int u, v;

            cin >> u >> v;

            addAfter(head, u, v);
        } else if (strcmp(command, "addbefore") == 0)
        {
            int u, v;

            cin >> u >> v;

            if (head != NULL && head->value == v)
            {
                sequence* temp = new sequence;
                temp->value = u;
                temp->next = head;
                head = temp;
            }
            else addBefore(head, u, v);
        } else if (strcmp(command, "remove") == 0)
        {
            int k;

            cin >> k;

            while (head->value == k)
            {
                head = head->next;
            }
            remove(head, k);
        } else if (strcmp("reverse", command) == 0)
        {
            if (head != NULL)
            {
                head = reverse(head);
            }
        }
        
        cin >> command;  
    }

    display(head);
    
    return 0;
}
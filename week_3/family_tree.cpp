#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct member {
    string name;
    member* child;

    member(string name) : name(name) {child = NULL;}
    member(string name, member* child) : name(name), child(child) {}
};

bool insert(vector<member*> family, string child, string parent) {
    member* temp;

    for (int i = 0; i < family.size(); i++)
    {
        temp = family[i];

        if (temp->name == parent)
        {
            while (temp->child != NULL)
            {
                temp = temp->child;
            }
            temp->child = new member(child);

            return true;
        }
    }
    
    return false;
}

int descendant(vector<member*> family, string name) {
    int count = 0;
    member* member;

    for (int i = 0; i < family.size(); i++)
    {
        if (family[i]->name == name) {
            member = family[i];

            while (member->child != NULL)
            {
                member = member->child;
                count++;
                count += descendant(family, member->name);
            }
        }
    }

    return count;
}

int generation(vector<member*> family, string name) {
    int count = 0;
    member* temp;

    for (int i = 0; i < family.size(); i++)
    {
        if (family[i]->name == name)
        {
            count++;

            int max = 0;
            temp = family[i];

            while (temp->child != NULL)
            {
                temp = temp->child;
                int _max = generation(family, temp->name);

                if (_max > max) max = _max;
            }
            count += max;
        }
    }
    
    return count;
}

void display(vector<member*> family) {
    member* temp;

    for (int i = 0; i < family.size(); i++)
    {
        cout << family[i]->name << ": ";
        temp = family[i];
        while (temp->child != NULL)
        {
            temp = temp->child;
            cout << temp->name << ' ';
        }
        cout << endl;
    }   
}

int main() {
    vector<member*> family;
    string child, parent;

    cin >> child;
    while (child != "***")
    {
        cin >> parent;
        
        if (!insert(family, child, parent))
        {
            family.push_back(new member(parent, new member(child)));
        }

        cin >> child;
    }

    // display(family);

    cin >> child;
    while (child != "***")
    {
        cin >> parent;

        if (child == "descendants")
        {
            cout << descendant(family, parent) << endl;
        } else {
            cout << generation(family, parent) << endl;
        }

        cin >> child;
    }
    
    return 0;
}
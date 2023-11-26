#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct order {
    string customer;
    int value;
};

order makeOrder(string s, int a) {
    order _order;
    
    _order.customer = s;
    _order.value = a;
    
    return _order;
}

map<string, vector<order>> orders;
int revenue_of_shop = 0, total_number_orders = 0, total_revenue = 0;
long long revu[100001] = {};

int converter(string t) {
    return ((t[0] - '0') * 10 + t[1] - '0') * 3600 + ((t[3] - '0') * 10 + t[4] - '0') * 60 + ((t[6] - '0') * 10 + t[7] -'0');
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    string command, product, shop, customer, time, start_time, end_time;
    int price;
    
    cin >> command;
    while (command != "#") {
        cin >> product >> price >> shop >> time;
        
        total_number_orders++;
        total_revenue += price;
        
        orders[shop].push_back(makeOrder(command, price));
        revu[converter(time)] += price;

        cin >> command;
    }

    for(int i = 1; i <= 100000; i++)
    {
        revu[i] = revu[i] + revu[i-1];
    }

    cin >> command;
    while (command != "#") {
        if (command == "?total_number_orders") {
            cout << total_number_orders << '\n';
        }
        else if (command == "?total_revenue") {
            cout << total_revenue << '\n';
        }
        else if(command == "?revenue_of_shop") {
            cin >> shop;
            
            revenue_of_shop = 0;
            for(order i : orders[shop]){
                revenue_of_shop += i.value;
            }

            cout << revenue_of_shop << '\n';
        }
        else if (command == "?total_consume_of_customer_shop") {
            cin >> customer >> shop;
            
            revenue_of_shop=0;
            for (order i : orders[shop]) {
                if (i.customer == customer) {
                    revenue_of_shop += i.value;
                }
            }

            cout << revenue_of_shop << '\n';
        }
        else if (command == "?total_revenue_in_period") {
            revenue_of_shop = 0;
            
            cin >> start_time >> end_time;
            
            cout << revu[converter(end_time)] - revu[converter(start_time) - 1] << '\n';
        }

        cin >> command;
    }

    return 0;
}
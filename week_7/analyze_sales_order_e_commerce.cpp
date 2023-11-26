#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

struct order {
    string customerID;
    string productID;
    unsigned short price;
    string shopID;
    string time_point;

    bool operator<(const order other) const {
        return time_point < other.time_point;
    }
};

struct customer_shop {
    int total; // Total revenue of shop
    unordered_map<string, int> cus_rev; // Total revenue of shop - customer
};

int main() {
    // freopen("input.txt", "r", stdin);
    
    int total_revenue = 0;
    map<string, int> flow;
    unordered_map<string, customer_shop> revenue;
    string command;
    vector<order> list_order;

    cin >> command;
    while (command != "#")
    {
        static order temp;
        static customer_shop* t = &(revenue[temp.shopID]);

        temp.customerID = command;
        cin >> temp.productID >> temp.price >> temp.shopID >> temp.time_point;

        list_order.push_back(temp);
        t = &(revenue[temp.shopID]);
        (*t).total += temp.price;
        (*t).cus_rev[temp.customerID] += temp.price;

        cin >> command;
    }

    sort(list_order.begin(), list_order.end());
    for (auto i : list_order) {
        total_revenue += i.price;
        flow[i.time_point] = total_revenue;
    }

    cin >> command;
    while (command != "#")
    {
        if (command == "?total_number_orders")
        {
            cout << list_order.size() << endl;
        } else if (command == "?total_revenue")
        {
            cout << total_revenue << endl;
        } else if (command == "?revenue_of_shop")
        {
            cin >> command;

            cout << revenue[command].total << endl;
        }
         else if (command == "?total_consume_of_customer_shop")
        {
            string customer, shop;
            cin >> customer >> shop;

            cout << revenue[shop].cus_rev[customer] << endl;
        } else if (command == "?total_revenue_in_period") {
            string time_in, time_out;

            cin >> time_in >> time_out;

            auto from_iterator = flow.lower_bound(time_in);
            auto to_iterator = flow.lower_bound(time_out);

            int from_revenue = (from_iterator != flow.begin()) ? prev(from_iterator)->second : 0;
            int to_revenue = (to_iterator != flow.end()) ? prev(to_iterator)->second : total_revenue;

            cout << to_revenue - from_revenue << endl;
        }

        cin >> command;
    }
    
    return 0;
}
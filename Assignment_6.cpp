#include <bits/stdc++.h>

using namespace std;

struct Item
{
    int code;
    string name;
    float cost;
    int quantity;
};

class Records
{
private:
    vector<Item> item_list;
    int total_items;

    static bool compareByCode(const Item &a, const Item &b)
    {
        return a.code < b.code;
    }
    static bool compareByName(const Item &a, const Item &b)
    {
        return a.name < b.name;
    }
    static bool compareByCost(const Item &a, const Item &b)
    {
        return a.cost < b.cost;
    }
    static bool compareByQuantity(const Item &a, const Item &b)
    {
        return a.quantity < b.quantity;
    }

    void PrintItem(const Item &itm)
    {
        cout << "Code: " << itm.code << endl;
        cout << "Name: " << itm.name << endl;
        cout << "Cost: " << itm.cost << endl;
        cout << "Quantity: " << itm.quantity << endl;
    }
public:
    Records()
    {
        total_items = 0;
    }
    void getInput()
    {
        cout << "How many items?? ";
        cin >> total_items;
        for (int i = 0; i < total_items; i++) {
            cout << "For item - " << i+1 << endl;
            Item temp_item;
            cout << "Enter name: ";
            cin >> temp_item.name;
            cout << "Enter code: ";
            cin >> temp_item.code;
            cout << "Enter cost: ";
            cin >> temp_item.cost;
            cout << "Enter Quantity: ";
            cin >> temp_item.quantity;
            item_list.push_back(temp_item);
            cout << endl;
        }
    }
    void Sort(const int code = 1)
    {
        switch (code)
        {
        case 1: 
            cout << "\n\nsorting by code..\n";
            sort(item_list.begin(), item_list.end(), compareByCode);
            return;
        case 2: 
            cout << "\n\nsorting by name..\n";
            sort(item_list.begin(), item_list.end(), compareByName);
            return;
        case 3: 
            cout << "\n\nsorting by cost..\n";
            sort(item_list.begin(), item_list.end(), compareByCost);
            return;
        case 4:
            cout << "\n\nsorting by quantity..\n";
            sort(item_list.begin(), item_list.end(), compareByQuantity);
            return;
        default:
            cout << "Invalid sorting option.\n";
        }
    }
    void Search(const int choice)
    {
        if (choice == 1) {
            int code;
            cout << "Enter a code: "; cin >> code;
            auto it = find_if(item_list.begin(), item_list.end(), [=] (Item const& itm)
            {
                return (itm.code == code);
            });
            bool found = (it != item_list.end());
            if (found) {
                cout << "\n\nThe item of code " << code << " is found.\n";
                cout << "The details are as follows:\n";
                PrintItem(*it);
            }
            else
                cout << "Item not found.\n";
        }
        else if (choice == 2) {
            string name;
            cout << "Enter a name: "; cin >> name;
            auto it = find_if(item_list.begin(), item_list.end(), [=] (Item const& itm) {
                return (itm.name == name);
            });
            bool found = (it != item_list.end());
            if (found) {
                cout << "\n\nThe item of name " << name << " is found.\n";
                cout << "The details are as follows:\n";
                PrintItem(*it);
            }
            else
                cout << "Item not found.\n";
        }
        else
            cout << "Invalid searching option.\n";
    }
    void Print()
    {
        for (int i = 0; i < total_items; i++) {
            PrintItem(item_list[i]);
            cout << endl;
        }
    }
};

int main()
{
    Records rc;
    rc.getInput();
    while (true) {
        int choice;
        cout << "\nWhat do you want to do?\n";
        cout << "Enter:\n\t1 for searching an item in record.\n\t2 for sorting the record.\n\t0 to exit.\n:";
        cin >> choice;
        if (choice == 0) break;
        else if (choice == 1) {
            cout << "\nHow do you want to search??\nEnter:\n\t1 for search by code.\n\t2 for search by name.\n:";
            cin >> choice;
            rc.Search(choice);
        }
        else if (choice == 2) {
            cout << "\nHow do you want to sort??\nEnter:\n\t1 to sort by code.\n\t2 to sort by name.\n\t3 to sort by cost.\n\t4 to sort by quantity.\n:";
            cin >> choice;
            rc.Sort(choice);
            rc.Print();
        }
        else
            cout << "INVALID CHOICE. Enter Again.\n";
    }
    return 0;
}
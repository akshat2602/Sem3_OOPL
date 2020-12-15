#include <bits/stdc++.h>

using namespace std;

void PrintMap(const unordered_map<string, string>& mp)
{
    for (auto x : mp)
        cout << setw(20) << x.first << ":\t" << x.second << endl;
    cout << endl;
}

int main()
{
    unordered_map<string, string> mp;

    ifstream infile("states_and_pop.txt");
    int cnt = 0;
    for(string line; getline(infile, line); )
    {
        cnt++;
        string state = line.substr(0, line.find_last_of(" "));
        string population = line.substr(line.find_last_of(" ")+1);
        mp[state] = population;
    }
    cout << "Total States Available: " << cnt << endl;

    while (true)
    {
        cout << "Enter\n\t1 Print population of all states.\n\t2 Print population of particular state.\n";
        cout << "\t0 to Exit.\n:";

        int choice;
        cin >> choice;

        if (choice == 0)
            break;
        else if (choice == 1)
            PrintMap(mp);
        else if (choice == 2)
        {
            string curr_state;
            cout << "Enter state: ";
            while (curr_state.length() == 0)
                getline(cin, curr_state);
            if (mp.find(curr_state) == mp.end())
                cout << curr_state << " is Not Found in Database!\n";
            else
                cout << "The population of " << curr_state << " is " << mp[curr_state] << endl;
        }
        else
            cout << "INVALID CHOICE. Try Again.\n";
    }
    return 0;
}
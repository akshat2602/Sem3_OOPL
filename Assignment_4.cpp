#include<bits/stdc++.h>
using namespace std;


int main() 
{ 
    bool flag = true;
    int resp;
    string s; 
    do
    {
        cout << "1) Read from a file \n2) Write to a file \n3) Exit" << endl;
        cin >> resp;
        if (resp == 1)
        {
            ofstream fout;
            fout.open("sample.txt", ios::app); 
            while (fout) 
            { 
                getline(cin, s); 
                if (s == "/") 
                    break; 
   
                fout << s << endl; 
                fout.close(); 
            } 
        }
        else if (resp == 2)
        {
            ifstream fin; 
            fin.open("sample.txt"); 
            while (fin) 
            { 
                getline(fin, s); 
                cout << s << endl; 
            } 
            fin.close(); 
        }
        else if (resp == 3)
        {
            flag == false;
        }
    } while (flag == true);
    
    return 0; 
} 
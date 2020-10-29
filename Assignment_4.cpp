#include<bits/stdc++.h>
using namespace std;


int main() 
{ 
    ofstream fout;
    string s; 
    fout.open("sample.txt", ios::app); 
    while (fout) { 
        getline(cin, s); 
        if (s == "/") 
            break; 
   
        fout << s << endl; 
    } 
    fout.close(); 
    // string s;
    ifstream fin; 
    fin.open("sample.txt"); 
    while (fin) { 
        getline(fin, s); 
        cout << s << endl; 
    } 
    fin.close(); 
    return 0; 
} 
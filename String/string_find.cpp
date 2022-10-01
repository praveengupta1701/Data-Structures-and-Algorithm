// CPP program to demonstrate working of string
// find to search a string
#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

int main()
{

     #ifndef ONLINE_JUDGE    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	 #endif
    // Vector of string to save tokens
    vector <string> tokens;
     
    
	string str = "geeksforgeeks a computergeeks science";
	string str1 = "geeks";
	// stringstream class check1
    stringstream check1(str);
     
    string intermediate;
     
    // Tokenizing w.r.t. space ' '
    size_t found,l;
    while(getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
        cout<<intermediate<<" ";
    }
    cout<<endl;

  for_each(tokens.begin(),tokens.end(),[](string s){cout<<s<<" ";}); //lamdas
    cout<<endl;

        found = str.find(str1);
        while(found != string::npos)
        {
		cout << "Next occurrence is " << found << endl;
        found = str.find(str1, found+1);
        }
        cout<<endl;
    
	return 0;
}



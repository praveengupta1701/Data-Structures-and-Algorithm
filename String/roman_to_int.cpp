#include <stdio.h>
#include <string.h>
#include<bits/stdc++.h>
using namespace std;

// This function returns value
// of a Roman symbol
int value(char r)
{
    switch(r)
    {
    case 'I' :
        return 1;
        break;
    case 'V' :
        return 5;
        break;
    case 'X':
        return 10;
        break;
    case 'L':
        return 50;
        break;
    case 'C':
        return 100;
        break;
    case 'D':
        return 500;
        break;
    case 'M':
        return 1000;
        break;
    default:
        return -1;
        break;
    }
}
int roman_to_cpp(string str)
{

        int res = 0;
 
    for (int i = 0; i < str.length(); i++) {
        int s1 = value(str[i]);
        if (i + 1 < str.length()) {
                int s2 = value(str[i + 1]);
            if (s1 >= s2) {
                res = res + s1;
            }
            else {
                res = res + s2 - s1;
                i++;
            }
        }
        else {
            res = res + s1;
        }
    }
    return res;
}



int main(int argc, char const *argv[])
{
    string s="IX";
    cout<<roman_to_cpp(s);
    return 0;
}
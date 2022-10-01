#include <stdio.h>
#include <string.h>
#include<bits/stdc++.h>
using namespace std;

// This function returns value
// of a Roman symbol
    string value(int r)
{
    switch(r)
    {
    case 1 :
        return "I";
        break;
    case 4 :
        return "VI";
        break;
    case 5 :
        return "V";
        break;
     case  9:
        return "XI";
        break;
    case  10:
        return "X";
        break;
    case 40 :
        return "LX";
        break;
    case 50:
        return "L";
        break;
    case  90:
        return "CX";
        break;
    case 100:
        return "C";
        break;
    case 400:
        return "DC";
        break;
    case 500:
        return "D";
        break;
    case  900:
        return "MC";
        break;
    case 1000:
        return "M";
        break;
    default:
        return "";
        break;
    }
}

string int_to_roman(int x)
{
        string ans="",a="";
    int f=0,i=0,d=x,s=0,val=0,p=0;
    while(x>0)
    {
        f=x%10;
        cout<<f<<"f ";
        if(f>=5)
        {
            if(f==5 || f==9)
            {
                p=pow(10,i);
                val=f*p;
             cout<<val<<" val "<<p<<" ";

                a+=value(val);
                ans+=a;
                cout<<a<<" a ";
            }
            else
            {
                s=f%5;
                p=pow(10,i);
                val=1*p;
                  cout<<"s "<<s<<" "<<val<<" val "<<p<<" ";
                while(s--)
                {
                    a+=value(val);
                    ans+=a;
                cout<<a<<" a ";
                 a="";
                }
                  p=pow(10,i);
                val=5*p;
              cout<<val<<" val "<<p<<" ";
                a+=value(val);
                ans+=a;
                cout<<a<<" a ";
            }
        }
        else
        {
            if(f==4)
            {

                p=pow(10,i);
                val=f*p;
               cout<<val<<" val "<<p<<" ";
                a+=value(val);
                ans+=a;
                cout<<a<<" a ";   
            }
            else
            {
                p=pow(10,i);
                val=1*p;
                cout<<val<<" val "<<p<<" ";
                while(f--)
                {
                    a+=value(val);
                    ans+=a;
                cout<<a<<" a ";
                 a="";
                }
            }

        }
        cout<<" "<<i<<"i \n";
        ++i;
        x/=10;
        val=0;
        a="";
    }
    // cout<<" "<<ans<<" ";
   reverse(ans.begin(),ans.end());
    return ans;
        
    }


//method 2
    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
 //   method 3
 //   like number 1234  in while loop -1000 >num -1000  or -900 -500 -400 -100 -90 -50 -40 -10 -9 -5 -4 -1 like that we can do
int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int i=5;
    while(i--)
   { int x;
    cin>>x;
    cout<<int_to_roman(x)<<"\n";
    }
    return 0;
}

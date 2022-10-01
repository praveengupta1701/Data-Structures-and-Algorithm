#include<bits/stdc++.h>
using namespace std;
int s_toi(string s)
{ int ans=0;
    for(auto i=0;i<s.size();i++)
    {
        ans=ans*10+s[i]-'0';
        cout<<ans<<" ";
    }
cout<<"\n"<<typeid(ans).name()<<"\n";
      return ans;
}
string i_tos(int i)
{
    int x,j=0;
    string res="";
    
    while(i>0)
    {
        x=i%10;
        res+='0';
        res[j]=x+res[j];
        i/=10;
        j++;
    }
    // cout<<res<<endl;
    reverse(res.begin(),res.end());
    cout<<res<<endl;
    return res;

}
int main()
{
 int inte=s_toi("1234");
 string str=i_tos(inte);

}
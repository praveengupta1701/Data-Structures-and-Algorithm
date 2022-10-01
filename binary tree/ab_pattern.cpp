#include<iostream>
using namespace std;


int main()
{

	int t;
	cin>> t;
	while(t--)
	{
	string s;
	cin>>s;

	int k=s.size(), flag =0,count =0;

	if (k&1==1 && k==0)
	{
		cout<<"No\n";
	}	
	else
	{
		flag =1;
		count =1;
		for(int i=1;i<k && flag!=3;i++)
		{
			if(s[i-1]=='a'&&s[i]=='a')
			{
				count+=1;
				flag=1;
			}
			else if(s[i-1]=='a' &&  s[i]=='b')
			{
				count-=1;
				 flag=2;
			} else if(s[i-1]=='b'&&s[i]=='b')
			{
				count-=1;
				flag=2;
				if(count<0)
				{
					flag =3;
					break;
				}
			}
			else
			{
				flag=3;
				break;
			}
		}
		if(flag==3 || count!=0)
		{
			cout<<"No"<<endl;
		}
		else
		{
			cout<<"Yes"<<endl;
		}
	}
}}
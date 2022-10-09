// Created by ...
/* Author -Praveen Gupta*/

#include <bits/stdc++.h>
#include <thread>
#include <mutex>
#include <chrono>
#include <memory>
#include <condition_variable>
using namespace std;
using namespace std::chrono;

double myPow(double x, int n) {
         double ans = 1.0;
  long long nn = n;
  if (nn < 0)
  nn = -1 * nn; // coverting negative to positive
  while (nn) {
    if (nn&1)//for odd
    {
      ans = ans * x;
      nn = nn - 1;// since it is double not integere so we minus bt one
    } else 
    {
      x = x * x;
      nn = nn>>1;//divide by 2 right shift
    }
  }
  if (n < 0) 
  ans = (double)(1.0) / (double)(ans);// for negative --> 1 divide by ans
  return ans;
}

int32_t main()
{   
	 #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif
	cout << myPow(2, 10) << endl;



    return 0;
}


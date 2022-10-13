#include <bits/stdc++.h>

using namespace std;

struct Item {
   int value;
   int weight;
};
class Solution {
   public:

      //comparator for value per weight
      bool static comp(Item a, Item b) {
         double r1 = (double) a.value / (double) a.weight;
         double r2 = (double) b.value / (double) b.weight;
         return r1 > r2;
      }
   // function to return fractionalweights
   double fractionalKnapsack(int W, Item arr[], int n) {

       sort(arr, arr + n, comp);//sorted on value/weight basis

      int curWeight = 0;
      double finalvalue = 0.0;

      for (int i = 0; i < n; i++) {
            
         if (curWeight + arr[i].weight <= W)//  if full weight taken
         {
            curWeight += arr[i].weight;//add full weight
            finalvalue += arr[i].value;//add full value
         } 
         // if full weight can't take then  take fractional
         else
          {
            int remain = W - curWeight;
            finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
            break;
         }
      }

      return finalvalu

   }
};
int main() {
   int n = 3, weight = 50;
   Item arr[n] = { {100,20},{60,10},{120,30} };
   Solution obj;
   double ans = obj.fractionalKnapsack(weight, arr, n);
   cout << "The maximum value is " << setprecision(2) << fixed << ans;
   return 0;
}
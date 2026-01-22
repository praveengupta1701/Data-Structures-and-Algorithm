#include <bits/stdc++.h>
using namespace std ;

typedef pair<int,pair<int,int>> pii;
int a[4][2] = {{6,5},{3,2},{-2,0},{0,1}}  ;

class Solution {

public:
 void k_closest_points_to_origin( int k)
{

        priority_queue<pii>pq ;  
        int n = 4  ;
       for (int i = 0; i < 4; i++) 
        {
            pq.push({a[i][0]*a[i][0] + a[i][1]*a[i][1],{a[i][0],a[i][1]}})  ;
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        while(pq.size()>0)
        {   
            cout<<pq.top().second.first<<" "<<pq.top().second.second;
            cout<<endl;
            pq.pop();
        }
}


} ;
int main() {


    Solution obj ;
    obj.k_closest_points_to_origin( 3)  ;

    return 0 ;
}

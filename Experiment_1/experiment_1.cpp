#include <bits/stdc++.h>
using namespace std;

long long ops=0;
int maxdepth=0;

void complexRec(int n,int depth) {
    maxdepth=max(maxdepth,depth);

   if (n <= 2) {
       return;
   }


   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           ops++;
       }
       p >>= 1;
   }


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       ops++;
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
       ops=ops+n;
   } else {
       reverse(small.begin(), small.end());
       ops=ops+n;
   }


   complexRec(n / 2,depth+1);
   complexRec(n / 2,depth+1);
   complexRec(n / 2,depth+1);
}
int main()
{
    vector<int> sizes={4,32,512,2048};
    
    cout<<"Recurrence Relation: 3T(n/2) + nlogn"<<endl;
    cout<<"Master Theorem Used: case 1 -> a>b^k"<<endl;
    cout<<"Time complexity: n^log(2,3)"<<endl<<endl;
    
    for(int n:sizes){
        ops=0;
        maxdepth=0;
    
        auto start = chrono::high_resolution_clock::now();
        complexRec(n, 1);
        auto end = chrono::high_resolution_clock::now();

        long long ms = chrono::duration_cast<chrono::milliseconds>(end- start).count();
        
        cout<<"Input size: "<<n<<endl;
        cout<<"Operations: "<<ops<<endl;
        cout<<"Max depth: "<<maxdepth<<endl;
        cout<<"Execution time: "<<ms<<" ms"<<endl<<endl;
    }    
}

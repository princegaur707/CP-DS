#include<bits/stdc++.h>
using namespace std;
int table[105] = {0};
int CalculateTable(char *p)
 {
     int i = 0;
     int j = 1;
     int lp = strlen(p);
     int table[lp] = {0};
     while(j < lp)
     {
         while(i > 0 and p[i] != p[j])
         {
             i = table[i - 1];
         }
         if(p[i] == p[j])
         {
             table[j] = i + 1;
             i++;  
             j++;
         }
         else
         {
             j++;
         }
     }
     for(int i = 0; i < lp; i++)
     {
        cout << table[i] << " ";
     }
     cout << endl;
}
int main()
{
    char p[] = "abcdabaca";
    CalculateTable(p);
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[] = "My name is prince";
    //string s = "XYZ" strtok works only for character array
    char *token = strtok(s, " ");
    cout << token << endl;
    while(token != NULL)
    {
        token = strtok(NULL, " ");
        cout << token << endl;
    }
    int arr[] = {1,2,3,4,5};
    cout << arr << endl; //this represent the address of the array
    cout << arr + 1 << endl; //address of the 2nd element of the array
    cout << *(arr + 1) << endl; // element on 2nd address with the help of pointer
    cout << arr[1];  //[] is overloaded [] means *(arr)
 }
#include<bits/stdc++.h>
using namespace std;;
int main()
{
	//strtok works only for character array
	string s = "My name is prince";
    //char *s = &st[0]; preferred method to convert string to character array unless 
    //there is need for copy like in this case
    char *token = strtok((char*)s.c_str(), " "); //token is equivalent to character array
    cout << token << endl;
    while(token != NULL) //As character arrays always end with NULL pointer while string do not.
    {
        token = strtok(NULL, " "); //strtok remembers the previous string 
        cout << token << endl;
    }
    int arr[] = {1,2,3,4,5};
    cout << "HELLO";
    cout << arr << endl; //this represent the address of the array
    cout << arr + 1 << endl; //address of the 2nd element of the array
    cout << *(arr + 1) << endl; // element on 2nd address with the help of pointer
    cout << arr[1];  //[] is overloaded [] means *(arr)
 }

 //

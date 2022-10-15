#include<bits/stdc++.h>
using namespace std;
void printMapping(int A[], int B[], int N, int M)
{
    unordered_map<int, list<int>> m;
    for (int i=0; i<N; i++)
        m[A[i]].push_back(i);
    for (int i=0; i<M; i++)
    {
        if (m.find(B[i]) != m.end() && m[B[i]].size() > 0)
        {
            cout << m[B[i]].front() << " ";
            m[B[i]].pop_front();
        }

        else // No mapping found
        {
            cout << "NA ";
        }
    }
}
int main()
{
    int A[] = {2, 1, 2, 3, 3, 4, 2, 4, 1};
    int N = sizeof(A) / sizeof(A[0]);
    int B[] = {1, 2, 5, 1, 2, 4, 2, 3, 2, 1};
    int M = sizeof(B) / sizeof(B[0]);
    printMapping(A, B, N, M);
        return 0;
}

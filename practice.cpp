#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int Travel_cards() {
    int n, a, b, k, f;
    cin >> n >> a >> b >> k >> f;
 
    map<pair<string, string>, int>m;//C++ this cannot be unordered.
 
    string prev_dest = "";
 
    for (int i = 0; i < n; i++) {
 
        string start_dest, ending_dest;
        cin >> start_dest >> ending_dest;
        int price;
 
        if (prev_dest == start_dest) {//This is a Tranashipment
            price = b;
        } else {
            price = a;
        }
        prev_dest = ending_dest;
 
        if (start_dest > ending_dest) {
            swap(start_dest, ending_dest);
        }
        if (m.find({start_dest, ending_dest}) != m.end()) {
            //Update the cost
            m[make_pair(start_dest, ending_dest)] += price;
        } else {
            //This key or trip was not in the map hence add it
            m[make_pair(start_dest, ending_dest)] = price;
        }
    }
    vector<int>v;
    int total_cost = 0;
 
    for (auto x : m) {
        //cout << endl << "1" << endl;
        v.push_back(x.second);
        total_cost += x.second;
    }
    //cout << "total_cost: " << total_cost << endl;
 
    sort(v.rbegin(), v.rend());
 
    // sort(v.begin, v.end(), greater<int>());
    int size = v.size();
    int t = 0;
    while( t < size and t < k){
        if (v[t] > f) 
        {
            total_cost = total_cost - v[t] + f;
            t++;
        } 
        else 
        {
            break;
        }
    }
 
    return total_cost;
 
}
 
 
int32_t main() {
    cout << Travel_cards() << endl;
}
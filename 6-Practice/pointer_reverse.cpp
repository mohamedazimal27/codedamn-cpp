#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int a;
    cin >> a ;
    cout << endl;
    int *arrPtr = new int[a];
    for(int i = 0; i < a; i++)
    {
        cin >> *(arrPtr + i);
    }
    for(int i = a - 1; i >= 0; i--)
    {
        cout << *(arrPtr + i);
    }
    return 0;
    
}
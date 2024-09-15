/* 
    Input: Take input adjacency matrix
    Number of Node:3
    The edges are 1-2 (cost 5), 2-3 (cost 8), 1-3 (cost 3),All edges are bidirectional

           1 2 3
        1  0 5 3
        2  5 0 8
        3  3 8 0  

    adjMat[i][j] means there is a edge between i and j node.

*/

#include<bits/stdc++.h>
using namespace std;
const int mx = 1e3+123; 
int adjMat[mx][mx];   //This graph can store a maximum of mx nodes

int main()
{
    int n;
    cin >> n;
    
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= n; j++ ) cin >> adjMat[i][j];
    }

    return 0;
}



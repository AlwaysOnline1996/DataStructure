#include "DenseGraph.h"
#include "ReadGraph.h"
#include "SparseGraph.h"
#include <iostream>
using namespace std;

int main(void)
{
    string filename = "/home/zengtong/CLionProjects/graph/test.txt";
    DenseGraph g1(13,false);
    SparseGraph g2(13,false);
    ReadGraph<DenseGraph> readgraph1(g1,filename);
    ReadGraph<SparseGraph> readgraph2(g2,filename);
    g1.show();
    cout << endl << "---------------------------------" << endl;
    g2.show();
    return 0;
}
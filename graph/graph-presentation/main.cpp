#include "DenseGraph.h"
#include "ReadGraph.h"
#include <iostream>
using namespace std;

int main(void)
{
    string filename = "test.txt";
    DenseGraph g1(13,false);

    ReadGraph<DenseGraph> readgraph(g1,filename);
    g1.show();
    return 0;
}
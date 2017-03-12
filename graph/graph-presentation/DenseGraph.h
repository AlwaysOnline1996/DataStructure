#ifndef DENSEGRAPH_H
#define DENSEGRAPH_H
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// Adjacency matrix
class DenseGraph
{
private:
    int n ,m;
    bool directed; //有向图 还是无向图
    vector<vector<bool> > g;
public:
    DenseGraph(int n, bool directed){  
        this->n = n; // 顶点数 [0....n-1]
        this->m = 0; //边数
        this->directed = directed; //是否有向
        for(int i = 0; i < n; i++){
            g.push_back( vector<bool>(n, false) ); // g push 进 n 个vector ,这个vector有 n 个元素，每个元素值都是false
        }
    }
    ~DenseGraph(){
    }
    int V() { return n; } //顶点数
    int E() { return m; }//边数
    void addEdge(int v,int w){
        assert( v>= 0 && v < n);
        assert( w>= 0 && w < n);

        if(hasEdge(v,w))   //如果不写这句，程序会隐含一个Bug .当 v,w 之间存在边的时候, g[v][w] =true 没有问题，但是 m 边数仍然会+1
            return;  // 同时避免了 平行边的情况

        g[v][w] = true;
        if(!directed)
            g[w][v] = true;
        this->m++;
    }
    bool hasEdge(int v, int w){
        assert( v>= 0 && v < n);
        assert( w>= 0 && w < n);
        return g[v][w];
    }
    void show(){
        for(int i = 0; i < n; i++){
            cout << "Vertex" << i << ":\t";
            for(int j = 0; j < g[i].size(); j++){
                    cout << g[i][j] << "\t" ;
            }
            cout << endl;
        }
    }
    class adjIterator
    {
    private:
        int v;
        int index;
        DenseGraph &G;
    public:
        adjIterator(int v, DenseGraph graph):G(graph){
            this->v = v;
            index = 0;
        }
        int begin(){
               index = -1;
               return next();
        }
        int next(){
            index++;
            if(index < G.g[v].size()){
                if(G.g[v][index])
                    return index;
                else next();
            }
            else 
                return -1;
        }
        bool end(){
            return index >= G.g[v].size();
        }
    };

};


#endif 
#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

template <typename Graph>
class Component
{
public:
    Component(Graph &graph):G(graph){
        visited = new bool[G.V()];
        id = new int[G.V()];
        ccount = 0;
        for(int i = 0; i < G.V();i++){
            visited[i] = false;
            id[i] = -1;
        }
        // 以上为初始化
        for(int i = 0; i < G.V();i++){
            if(!visited[i]){
                dfs(i);
                ccount++;
            }
        }
    }
    ~Component(){
        delete [] visited;
        delete [] id;
    }
    int count(){ return ccount;} // 返回联通分量个数
    bool isConnected(int v ,int w){
        assert(v >= 0 && v < G.V());
        assert(w >= 0 && w < G.V());
        return id[w] == id[v];
    }
private:
    void dfs(int v){
        visited[v] = true;
        id[v] = ccount;
        typename Graph::adjIterator adj(G,v);
        for(int i = adj.begin(); !adj.end(); i = adj.next()){
            if(!visited[i]){
                dfs(i);
            }
        }
    }
    bool *visited;  //记录是否被访问过
    int ccount;  // 联通分量个数
    int *id;
    Graph &G;
};

#endif

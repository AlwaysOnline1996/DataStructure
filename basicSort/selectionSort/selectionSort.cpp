#include <iostream>
#include <cstdlib>
using namespace std;

// 选择每次排序最大值的索引
template<typename T>
void selectionSort(T* arr, int n)
{
    for(int i = 0; i <= n; i++)
    {
        int minIndex = i;
        for(int j = i; j <= n; j++)
        {
            if(arr[j] < arr[minIndex] )
                minIndex = j;
        }
        swap(arr[i],arr[minIndex]);
    }
}


int main(void)
{
    int n = 10;

    int arr[10] = {3,21,2,23,1,45,26,43,76,34};

    selectionSort(arr,n-1); // 双闭区间
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

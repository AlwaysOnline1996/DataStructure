#include <iostream>
#include <cstdlib>
using namespace std;

template<typename T>
void insertionSort(T* arr,int n)
{
    for(int i = 1; i <= n; i++) //索引为0的地方，默认已经排好了顺序。因为只有它一个数。因此排序从索引1开始
    {
        for(int j = i;j >= 1 && arr[j - 1] > arr[j]; j--) 
            if(arr[j - 1] > arr[j])
                swap(arr[j],arr[j-1]);
    }
}

int main(void)
{
    int n = 12;

    int arr[12] = {3,21,2,23,1,45,26,43,76,34,39,65};

    insertionSort(arr,n-1); // 双闭区间
    for(int i = 0; i < n; i++)
    {
    cout << arr[i] << " ";
    }
    return 0;
}
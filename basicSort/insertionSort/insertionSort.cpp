#include <iostream>
#include <cstdlib>
using namespace std;
//插入排序对于近乎有序的数组可以实现高效的排序。因此在考虑排序算法时，若数组近乎有序，不妨考虑使用插入排序。
//此外，shell sort是基于插入排序的优化算法。针对插入排序对近乎有序数组排序的高效性，设置步进使原本相对无序的排序变得相对有序，然后慢慢将步进减小，最后步进为1，即为插入排序。
template<typename T>
void insertionSort(T* arr,int n)
{
    for(int i = 1; i <= n; i++) //索引为0的地方，默认已经排好了顺序。因为只有它一个数。因此排序从索引1开始
    {
        for(int j = i;j >= 1 && arr[j - 1] > arr[j]; j--) 
            if(arr[j - 1] > arr[j])  // arr[j - k] k 为shell sort 的步进 
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
#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename T>
void __merge(T* arr,int l,int mid, int r)
{
    T* aux = new T[r - l + 1];
    for(int i = l; i <= r; i++)
    {
        aux[i - l] = arr[i];
    }

    int i = l, j = mid + 1;

    for(int k = l; k <= r; k++)
    {
        if( i > mid)
        {
            arr[k] = aux[j - l];
            j++;
        }
        else if( j > r)
        {
            arr[k] = aux[i -l];
            i++;
        }
        else if(aux[i-l] > aux[j-l])
        {
            arr[k] = aux[j - l];
            j++;
        }
        else
        {
            arr[k] = aux[i -l];
            i++;
        }
    }
    delete [] aux;
}

template<typename T>
void __mergeSort(T* arr, int l,int r)
{
    if( l >= r)
        return;
    int mid = l + (r - l) / 2; // 等价于 mid = ( r + l) /2 ,为避免 l ,r 都是比较大的，r+l溢出的情况，所以采用此方法。
    __mergeSort(arr, l , mid);
    __mergeSort(arr, mid + 1, r);
    __merge(arr, l , mid, r);
}

template<typename T>  
void mergeSort(T* arr,int n)   //双闭区间
{
    __mergeSort(arr, 0, n - 1);
}


int main(void)
{
    int n = 12;

    int arr[12] = {3,21,2,23,1,45,26,43,76,34,39,65};

    mergeSort(arr,n);
    for(int i = 0; i < n; i++)
    {
    cout << arr[i] << " ";
    }
    return 0;
}
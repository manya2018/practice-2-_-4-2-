#include <iostream>
#include <vector>

using namespace std;
// TASK 4
void MERGESORT(int arr[], int start, int end)
{
    if (end-start <2)
    {
        return;
    }
    if (end-start == 2)
    {
       if (arr[start]> arr[start+1])
       {
           swap(arr[start],arr[start+1]);
       }
    }
    MERGESORT(arr,start,start+(end-start)/2);
    MERGESORT(arr,start+(end-start)/2,end);
    vector <int> b;
    size_t b1= start;
    size_t e1 =start + (end - start)/ 2;
    size_t b2 = e1;
    while (b.size()<(end - start))
    {
        if (b1 >=e1 || (b2 < end && arr[b2] <= arr[b1]))
        {
            b.push_back(arr[b2]);
            ++b2;

        }
        else
        {
            b.push_back(arr[b1]);
            ++b1;
        }
    }
    for (size_t i=start; i< end; i++)
    {
        arr[i]=b[i-start];
    }
}
void MergeSort( int arr[], const int size)
{
    MERGESORT(arr,0,size);
}

// TASK 5
void quick_sort(int arr[],const int size) {
    int i = 0;
    int j = size - 1;

    int mid = arr[size / 2];
    do {
        while(arr[i] < mid) {
            i++;
        }

        while(arr[j] > mid) {
            j--;
        }

        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    if(j > 0)
    {
        quick_sort(arr, j + 1);
    }
    if (i < size)
    {

        quick_sort(arr, size - i);
    }
}

int main() {
    int arr[]={0,8,7,9,6,1,3};
    quick_sort(arr,7);
    for (int k=0;k<7;k++)
    {
        cout << arr[k]<< endl; ;
    }
    int A[]={0,8,7,9,6,1,3};
    MergeSort(A,7);
    for (int k=0;k<7;k++)
    {
        cout << A[k] ;
    }

    return 0;
}

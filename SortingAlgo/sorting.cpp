#include <bits/stdc++.h>
using namespace std;
class Sorting
{
public:
    int partition(int arr[], int low, int high)
    {
        int piviot = arr[high];
        int fisrt = (low - 1);
        for (int i = low; i <= high; i++)
        {
            if (arr[i] < piviot)
            {
                fisrt++;
                swap(arr[i], arr[fisrt]);
            }
        }
        swap(arr[fisrt + 1], arr[high]);
        return fisrt + 1;
    }
    void QuickSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int part = partition(arr, low, high);
            QuickSort(arr, low, part - 1);
            QuickSort(arr, part + 1, high);
        }
        return;
    }
    void merging(int arr[], int low, int mid, int high)
    {
        int i = low;
        int j = mid + 1;
        int temp[high + 1];
        int index = 0;

        while (i <= mid && j <= high)
            if (arr[i] >= arr[j])
                temp[index++] = arr[j++];
            else
                temp[index++] = arr[i++];

        while (i <= mid)
            temp[index++] = arr[i++];
        while (j <= high)
            temp[index++] = arr[j++];

        for (i = low; i <= high; i++)
            arr[i] = temp[i - low];
        return;
    };

    void mergerSort(int arr[], int low, int high)
    {
        if (low >= high)
            return;
        int mid = low + ((high - low) / 2);
        mergerSort(arr, low, mid);
        mergerSort(arr, mid + 1, high);
        merging(arr, low, mid, high);
        return;
    }
};
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    Sorting ds;
    ds.QuickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
// finding minimum and maximum using divide and conquer

#include <iostream>
using namespace std;

void find_min_max(int arr[], int low, int high, int &min, int &max)
{

    if (low == high) 
    {
        if (max < arr[low]) 
            max = arr[low];
        if (min > arr[high])
            min = arr[high];
        return;
    }

    if (high - low == 1) 
    {
        if (arr[low] < arr[high])
        {
            if (min > arr[low])
                min = arr[low];
            if (max < arr[high])
                max = arr[high];
        }
        else 
        {
            if (min > arr[high])
                min = arr[high];
            if (max < arr[low])
                max = arr[low];
        }
        return;
    }

    // finding middle element
    int mid = (low + high) / 2;

    // recursion
    find_min_max (arr, low, mid, min, max);  // left subarray
    find_min_max (arr, mid+1, high, min, max); // right subarray
}
int main()
{
    int min = 100000, max = -100000;
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter element "<<i+1<<":";
        cin>>arr[i];
    }
    find_min_max(arr, 0, n-1, min, max);
    
    cout<<"The minimum element is "<<min<<endl;
    cout<<"The maximum element is "<<max<<endl;
    return 0;
}
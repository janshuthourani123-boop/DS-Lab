#include <iostream>

using namespace std;
void InsertionSort(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        int key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int BinarySearch(int arr[],int size,int value){
    int right = size-1;
    int left = 0;
    while (left<=right)
    {
        int mid = left + (right-left)/2;
        if (arr[mid]==value)
        {
            return mid;
        }
        else if (arr[mid]<left)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
int main() {
      int arr[10]; //= {3,1,2,5,8,9,6,1,2,68};
      int size = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        cout<<"arr["<<i+1<<"]. ";
        cin>>arr[i];
    }
    cout<<"Displaying UnSorted Array"<<endl;
    for(int value:arr){
        cout<<value<<" ";
    }
    cout<<endl;
    InsertionSort(arr,size);
    cout<<"Displaying Sorted Array"<<endl;
    for(int value:arr){
        cout<<value<<" ";
    }
    cout<<endl;
    int n;
    cout << "Enter no. to find. ";
    cin>>n;
    int Index = BinarySearch(arr,size,n);
    if (Index!=-1)
    {
      cout<<"value. "<<arr[Index]<<" Found at index. "<<Index<<endl;
    }
    else
    {
      cout<<"Not found"<<endl;
    }
    return 0;
}

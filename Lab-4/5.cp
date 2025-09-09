#include <iostream>

using namespace std;
int InterpolationSearch(int arr[],int size,int value){
    int right = size-1;
    int left = 0;
    while (left<=right)
    {
        int pos = left + ((value-arr[left])*(right-left)/(arr[right]-arr[left]));
        if (arr[pos]==value)
        {
            return pos;
        }
        else if (arr[pos]<value)
        {
            left = pos + 1;
        }
        else
        {
            right = pos - 1;
        }
    }
    return -1;
}
int main() {
     int arr[10]; //{1,2,3,5,6,7,8,9,10,11};
      int size = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        cout<<"arr["<<i+1<<"]. ";
        cin>>arr[i];
    }
    int n;
    cout<<"Enter number to find. ";
    cin>>n;
    int Index = InterpolationSearch(arr,size,n);
    if (Index!=-1)
    {
        cout<<"Value. "<<arr[Index]<<" found at index. "<<Index<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }
    return 0;
}

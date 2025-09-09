#include <iostream>

using namespace std;
int LinearSearch(int arr[],int size,int value){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==value)
        {
            return i;
        }
    }
    return -1;
}
int main() {
    int arr[10];
      int size = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        cout<<"arr["<<i+1<<"]. ";
        cin>>arr[i];
    }
    int n;
    cout<<"Enter number to find. ";
    cin>>n;
    int Index = LinearSearch(arr,size,n);
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

#include <iostream>

using namespace std;
void SelectionSort(int arr[],int size){
    for (int i = 0; i < size-1; i++)
    {
        int min_Index = i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[j]<arr[min_Index])
            {
                min_Index = j;   
            }
        }
        swap(arr[i],arr[min_Index]);
    }
}
int main() {
     int arr[10];
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
    SelectionSort(arr,size);
    cout<<"Displaying Sorted Array"<<endl;
    for(int value:arr){
        cout<<value<<" ";
    }
    cout<<endl;
    return 0;
}

#include <iostream>

using namespace std;
void BubbleSort(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-1; j++)
        {
            if (arr[i]<arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }
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
    BubbleSort(arr,size);
     cout<<"Displaying Sorted Array"<<endl;
    for(int value:arr){
        cout<<value<<" ";
    }
    cout<<endl;
    return 0;
}

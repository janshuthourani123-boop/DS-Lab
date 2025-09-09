#include <iostream>

using namespace std;
void CombSort(int arr[],int size){
    int gap = size;
    float shrink = 1.3;
    bool swapped = true;
    while (gap>1 || swapped)
    {
        if (gap<1)
        {
            gap = 1;
        }
        swapped = false;
        gap = (int)(gap/shrink);
        for (int i = 0; i+gap < size; i++)
        {
            if (arr[i]>arr[i+gap])
            {
             swap(arr[i],arr[i+gap]);
             swapped = true;   
            }
        }
    }
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
    CombSort(arr,size);
    cout<<"Displaying Sorted Array"<<endl;
    for(int value:arr){
        cout<<value<<" ";
    }
    cout<<endl;
    return 0;
}

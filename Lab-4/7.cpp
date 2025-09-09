#include <iostream>

using namespace std;
void ShellSort(int arr[],int size){
    for (int i = size/2; i > 0 ; i/=2)
    {
        for (int j = i; j < size; j++)
        {
            int temp = arr[j];
            int k;
            for (k = j; k>=i && arr[k-i]>temp; k-=i)
            {
                arr[k] = arr[k-i];
            }
            arr[k] = temp;
        }
    }
}
int main() {
     int arr[10] = {3,1,2,5,8,9,6,1,2,68};
      int size = sizeof(arr)/sizeof(arr[0]);
    // for (int i = 0; i < size; i++)
    // {
    //     cout<<"arr["<<i+1<<"]. ";
    //     cin>>arr[i];
    // }
    cout<<"Displaying UnSorted Array"<<endl;
    for(int value:arr){
        cout<<value<<" ";
    }
    cout<<endl;
    ShellSort(arr,size);
    cout<<"Displaying Sorted Array"<<endl;
    for(int value:arr){
        cout<<value<<" ";
    }
    cout<<endl;
    return 0;
}

#include <iostream>

using namespace std;
void resize(int *&arr,int &n,int newN){
    if (newN>=0 && newN<12)
    {
    int* temp = new int[newN];
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[i];
    }   
    for (int i = n; i < newN; i++)
    {
        cout << "Enter expense(resized). ";
        cin>>temp[i];
    }
    delete[] arr;
    arr = temp;
    n = newN;
    }
    else
    {
        cout << "Invalid"<<endl;
    }
    
}
int main() {
    int n;
    cout << "Enter no. of months. ";
    cin>>n;
    int* arr = new int[n];
    if (n>=0 && n<12)
    {
    for (int i = 0; i < n; i++)
    {
       cout << "Enter expense. ";
       cin >> arr[i];   
    }
    resize(arr,n,9);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}
else
{
    cout << "Invalid"<<endl;
}

    return 0;
}

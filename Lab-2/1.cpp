#include <iostream>

using namespace std;
void update(int* arr,int pos,int size,int newValue){
    if (pos>=0 && pos<=size)
    {
        arr[pos] = newValue;
        cout << "Value updated"<<endl;
    }
    else
    {
        cout << " Not found"<<endl;
    } 
}
int main() {
int size;
cout<<"Enter Size. "<<endl;
cin>>size;    
int* arr = new int[size];
for (int i = 0; i < size; i++)
{
    arr[i] = 0;
}
int newValue1;
int pos;
cout << "Enter Pos. ";
cin>>pos;
cout << "Enter new Value. ";
cin >> newValue1;
update(arr,pos,size,newValue1);
cout << "Enter Pos. ";
cin>>pos;
cout << "Enter new Value. ";
cin >> newValue1;
update(arr,pos,size,newValue1);
for (int i = 0; i < size; i++)
{
    cout<<"arr["<<i<<"]. "<<arr[i]<<"  ";
}

    return 0;
}

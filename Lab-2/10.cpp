#include <iostream>

using namespace std;

int main() {
int category;
cout << "Enter no. of category. ";
cin>>category;
int bookN[100];
int** arr = new int*[category];
for (int i = 0; i < category; i++)
{
    arr[i] = new int[i];
    cout << " Enter no. of books. ";
    cin>>bookN[i];
    for (int j = 0; j < bookN[i]; i++)
    {
        cout << "Enter IDs. ";
        cin>>arr[i][j];
    }
}
int id;
cout<<"enter id to search in lib. ";
cin>>id;
for (int i = 0; i < category; i++)
{
    for (int j = 0; j < bookN[i]; j++)
    {
        if (arr[i][j]==id)
        {
            cout<<"found"<<endl;
        }
    }
    cout <<"not found"<<endl;
}
for (int i = 0; i < category; i++)
{
    for (int j = 0; j < bookN[i]; j++)
    {
        cout<<arr[i][j]<<"  ";
    }
    cout<<endl;
}
for (int i = 0; i < category; i++)
{
    delete[] arr[i];
}
delete[] arr;
delete[] bookN; 
    return 0;
}

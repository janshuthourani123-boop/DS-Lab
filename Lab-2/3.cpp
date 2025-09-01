#include <iostream>

using namespace std;

int main() {
    int row;
  cout<<"Enter no. of coures. ";
    cin>> row;
    int col[row];
    int arr[row][100];
    for (int i = 0; i < row; i++)
    {
         cout << " Enter students. ";
        cin>>col[i];
        for (int j = 0; j < col[i]; j++)
        {
            cout << "Enter marks. ";
            cin>>arr[i][j];
        }
    }
    int total = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col[i]; j++)
        {
          cout << arr[i][j]<<" "; 
        }
        cout <<endl;
    }
    cout << "Displaying student's average. "<<endl;  
     for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col[i]; j++)
        {
           total+=arr[i][j];
        }
        int avg = total/col[i];
        cout << avg<<endl;
    }
    return 0;
}

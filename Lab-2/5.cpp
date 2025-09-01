#include <iostream>
using namespace std;
void Add(int** arr1,int** arr2,int row,int col){
    int** arr3 = new int*[row];
    for (int i = 0; i < row; i++)
    {
      arr3[i] = new int[col];   
    }
       for (int  i = 0; i < row; i++)
       {
        for (int j = 0; j < col; j++)
        {
            arr3[i][j] = arr1[i][j]+arr2[i][j];
        }
       }
      for (int i = 0; i < row; i++)
      {
         for (int j = 0; j < col; j++)
         {
            cout << arr3[i][j]<<"  ";
         }
         cout<<endl;
      }
      for (int i = 0; i < row; i++)
      {
        delete[] arr3[i];
      }
      delete[] arr3;
}
void Sub(int** arr1,int** arr2,int row,int col){
    int** arr3 = new int*[row];
    for (int i = 0; i < row; i++)
    {
      arr3[i] = new int[col];   
    }
       for (int  i = 0; i < row; i++)
       {
        for (int j = 0; j < col; j++)
        {
            arr3[i][j] = arr1[i][j]-arr2[i][j];
        }
       }
       for (int i = 0; i < row; i++)
       {
        for (int j = 0; j < col; j++)
        {
            cout<<arr3[i][j]<<"  ";
        }
        cout << endl;
       }
       for (int i = 0; i < row; i++)
      {
        delete[] arr3[i];
      }
      delete[] arr3;
}
using namespace std;
int main() {
    int row,col;
    cout << "Enter Row. ";
    cin>>row;
    cout << "Enter col. ";
    cin>>col;
    int** arr = new int*[row];
    for (int i = 0; i < row; i++)
    {
      arr[i] = new int[col];   
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
         cout << "arr["<<i+1<<"]["<<j+1<<"]. ";
         cin>>arr[i][j]; 
        }
        cout<<endl;
    }
    cout << "Displaying Matrix 1"<<endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
     int row1,col1;
    cout << "Enter Row. ";
    cin>>row1;
    cout << "Enter col. ";
    cin>>col1;
     int** arr1 = new int*[row1];
    for (int i = 0; i < row1; i++)
    {
      arr1[i] = new int[col1];   
    }
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
         cout << "arr["<<i+1<<"]["<<j+1<<"]. ";
         cin>>arr1[i][j]; 
        }
        cout<<endl;
    }
    cout << "Displaying matrix 2"<<endl;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cout<<arr1[i][j]<<"  ";
        }
        cout<<endl;
    }
    if (row1 == row && col == col1)
    {
      cout << "Displaying  matrix after addition..."<<endl;
       Add(arr,arr1,row,col);
      cout<< "Displaying mtrix after subtraction..."<<endl;
      Sub(arr,arr1,row,col);
    }
    else
    {
      cout<<"Invalid"<<endl;
    }
    return 0;
}

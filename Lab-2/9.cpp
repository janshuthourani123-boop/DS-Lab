#include <iostream>

using namespace std;

int main() {
    int row,col;
    cout << "Enter Row. ";
    cin>>row;
    cout<<"enter col. ";
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
            cout << "Arr["<<i+1<<"]["<<j+1<<"]. ";
            cin >>arr[i][j];
        }
    }
     for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
           if (arr[i][j]!=0)
           {
            cout << i << " " << j << " " <<arr[i][j] << endl;
           }
           else
           {
            cout << "not a sparse value"<<endl;
           }
        }
    }
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}

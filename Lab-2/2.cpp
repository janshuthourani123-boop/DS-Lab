#include <iostream>

using namespace std;
void Update(int* arr[],int row,int col,int Pr,int Pc,int newValue=1){
    if ((Pr>=0 && Pr<row) && (Pc>=0 && Pc<col))
    {
        arr[Pr][Pc] = newValue;
        cout << "Value Update"<<endl; 
    }
    else
    {
        cout << "not found"<<endl;
    } 
}
int main() {
    int row,col;
    cout<<"Enter rows. ";
    cin>>row;
    cout<<"Enter col. ";
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
        arr[i][j] = 0;
     }
   } 
   int Ur,Uc;
   cout << "Enter Upadated Row. ";
   cin >> Ur;
   cout << "Enter Updated Columns. ";
   cin >> Uc;
   Update(arr,row,col,Ur,Uc);
   cout << "Enter Upadated Row. ";
   cin >> Ur;
   cout << "Enter Updated Columns. ";
   cin >> Uc;
   Update(arr,row,col,Ur,Uc);
   cout << "Enter Upadated Row. ";
   cin >> Ur;
   cout << "Enter Updated Columns. ";
   cin >> Uc;
   Update(arr,row,col, Ur,Uc);
   for (int i = 0; i < row; i++)
   {
     for (int j = 0; j < col; j++)
     {
        cout << arr[i][j] << "  ";
     }
     cout<<endl;
   }
   for (int i = 0; i < row; i++)
   {
     delete[] arr[i];
   }
   delete[] arr;
    return 0;
}

#include <iostream>

using namespace std;

int main() {
    int day,timeN;
    cout << "Enter Row. ";
    cin >> day;
    cout << "Enter Col. ";
    cin >> timeN;
    int** arr = new int*[day];
    for (int i = 0; i < day; i++)
    {
        arr[i] = new int[timeN];
    }
     for (int i = 0; i < day; i++)
     {
       for (int j = 0; j < timeN; j++)
       {
         cout <<"arr["<<i+1<<"]["<<j+1<<"]. ";
         cin >> arr[i][j]; 
       }
     }
    int hotest = 0;
    int coldest = arr[0][0];
    int high = 0;
    int low = 0;
    for (int i = 0; i < day; i++)
    {
        for (int j = 0; j < timeN; j++)
        {
             if (hotest<= arr[i][j])
            {
               high = i;
            }
            if (coldest >= arr[i][j])
            {
                low = i;
            }  
        }   
    }
     cout << "Hottest. "<<high<<endl;
     cout << "Coldest. "<<low<<endl;
     
    return 0;
}

#include <iostream>

using namespace std;

int main() {
    int dep;
    cout << "Enter no. of departments. ";
    cin >> dep;
    int emp[dep];
    int salary[dep][100];
    for (int i = 0; i < dep; i++)
    {
        cout << "Enter no. of employees. ";
        cin >> emp[i];
        for (int j = 0; j < emp[i]; j++)
        {
            cout << "Enter salary. ";
            cin >> salary[i][j];
        }
    }
    int highest[100] = {0};
    int total[100] = {0};
    for (int i = 0; i < dep; i++)
    {
        for (int j = 0; j < emp[i]; j++)
        {
        total[i]+=salary[i][j];
         if (highest[i]<=salary[i][j])
         {
            highest[i] = salary[i][j]; 
         }
        }
         int avg = total[i]/emp[i];
        cout <<"average. "<<avg << endl;
    }
    cout << "Displaying highest salary in each department"<<endl;
    for (int i = 0; i < dep; i++)
    {
        cout << highest[i]<<endl;
    }
    
    
    return 0;
}

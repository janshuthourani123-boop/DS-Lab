#include <iostream>

using namespace std;
class SafeArray{
    int *marks;
    public:
    SafeArray(){
        marks = new int(0);
    }
    void SetValue(int value){
        if (marks!=nullptr)
        {
            *marks = value;
        }
    }
    int getValue(){
        if (marks!=nullptr)
        {
            return *marks;
        }
    }
    void releasValue(){
        if (marks!=nullptr)
        {
            delete marks;
        }
    }
    ~SafeArray(){
        delete marks;
    }
};
int main() {
  int arr[5] = {3,1,2,5,8};
  int size = sizeof(arr)/sizeof(arr[0]);
  SafeArray s[size];
  for (int i = 0; i < size; i++)
  {
     s[i].SetValue(arr[i]);
  }
  for (int i = 0; i < size; i++)
  {
    cout<< s[i].getValue()<<"  ";
  }
  for (int i = 0; i < size; i++)
  {
     s[i].releasValue();
  }
  
    return 0;
}

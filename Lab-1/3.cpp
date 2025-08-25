#include <iostream>

using namespace std;

class Box{
    int* size;
    public:
    Box(int s){
     size = new int(s);
    }
    Box(Box& other){
        size = *(&other.size);
    }
    Box& operator=(Box& b){
        size = b.size;
    }
    void Display(){
        cout<<*size<<endl;
    }
    ~Box(){
        delete size;
    }
};
int main() {
  Box b(46);
  b.Display();
  Box b1 = b;
  b1.Display();
    return 0;
}

#include <iostream>

using namespace std;

class Exam{
    string* name;
    string *date;
    int* score;
    public:
    Exam(string n,string d,int s){
        name = new string(n);
        date = new string(d);
        score = new int(s);
    }
    void setName(string n){
        delete name;
        name = new string(n);
    }
    void setDate(string d){
        delete date;
        date = new string(d);
    }
    void setScore(int s){
        delete score;
        score = new int(s);
    }
    void Display(){
        cout<<"Name: "<<*name<<endl;
        cout<<"Date: "<<*date<<endl;
        cout<<"Score: "<<*score<<endl;
    }
    ~Exam(){
        delete name;
        delete date;
        delete score;
    }
};
int main() {
    Exam e1("Jiyanshu","29-09-2001",25);
    e1.setName("Jivan");
    e1.Display();
    e1.setName("Jivan");
    e1.Display();
    Exam e2("Nelash","29-28-2000",55);
    e2.Display();
    e2.setDate("29-09-2004");
    e2.Display();
    Exam e3 = e2;
    e3.Display();
    e3.setScore(65);
    e3.Display();
    return 0;
}

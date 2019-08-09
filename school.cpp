#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
    protected:
        string name;
        int age;

    public:
        
        virtual void getdata(){cout << "something is wrong" << endl;}
        virtual void putdata(){cout << "something is wrong" << endl;}

};
class Student:public Person{
    private:
        int marks[6];
        int sum = 0;
        static int sid;
        int cur_id;
    public:
        Student(){
            this -> cur_id = sid;
            sid++;
        }
        void getdata(){
            cin >> name;
            cin >> age;
            for(short i = 0; i < 6; i++)
            {
                int x;
                cin >> x;
                sum += x;
                marks[i] = x;
            }
        }
        void putdata(){
            cout << name << " " << age << " " << sum << " " << cur_id << endl;
        }
};
int Student::sid = 1;

class Professor:public Person{
    private: 
        int publications;
        static int pid;
        int cur_id;
    public:
        Professor(string name, int age, int publications){this-> cur_id = ++pid;}
        void getdata(){
            cin >> name;
            cin >> age;
            cin >> publications;
        }
        void putdata(){
            cout << name <<" " << age << " " << publications << " " << cur_id << endl;
        }
};
int Professor::pid =0;
int main(){
    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
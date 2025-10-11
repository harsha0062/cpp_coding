#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Teacher{
    private:
        double salary;
    public:
            string name;
            string dept;
            string subj;
        void changedept(string newdept){
            dept=newdept;
        }
        void setsalary(double s){
            salary=s;
        }
        double getsalary(){
            return salary;
        }
};
class Account{
    private:
        double balance;
        // string password;
    public:
        string accountid;
        string password;
};
int main(){
    Teacher t1;
    t1.name="harsha";
    t1.dept="cse";
    t1.subj="maths";
    t1.setsalary(23000);
    cout<<t1.name<<endl;
    cout<<t1.dept<<endl; 
    cout<<t1.subj<<endl;
    cout<<t1.getsalary()<<endl;


}
#include  <iostream>
#include    <string>
#include    <vector>
#include    <limits>
#define      el '\n'
using namespace std;
class fact
{
    string name;
    int     age;
    int  salary;
    char gender;
public:
    fact(string n,int a,int s,char g)
    {
        name   = n;
        age    = a;
        salary = s;
        gender = g;
    }
    static void Enter_display()
    {
        cout <<       "Enter your choice:\n";
        cout <<      "1) Add new employee\n";
        cout <<   "2) Print all employees\n";
        cout <<         "3) Delete by age\n";
        cout << "4) Update salary by name\n";
    }
    void choice_2()
    {
        cout << name  << ' ';
        cout << age   << ' ';
        cout << salary<< ' ';
        cout << gender<<  el;
    }
    int choice_3()
    {
        return age;
    }
    string choice_4()
    {
        return name;
    }
    void change (int newsal)
    {
        salary = newsal;
    }
};
void ifskep(int a , int b , bool&x)
{
    if (a == 0 || b == 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nTry again please.\n\n";
        x = true;
    }
    else return;
}
int main()
{
    vector<fact>emp;
    while (true)
    {
        fact::Enter_display();
        int          o;
        cin >>       o;
        bool x = false;
        if (o == 1)
        {
            string n;
            int a , s;
            char g;
            cout << "Enter name: "        ;
            cin >> n;
            cout << "Enter age: "         ;
            cin >> a;
            cout << "Enter salary: "      ;
            cin >> s;
            cout << "Enter gender (M/F): ";
            cin >> g;
            ifskep(a , s , x);
            if (x) continue;
            emp.push_back(fact(n,a,s,g));
        }
        else if (o == 2)
        {
            cout <<"********************\n";
            for (auto&it : emp)
            {
                it.choice_2();
            }
            cout <<"********************\n";
        }
        else if (o == 3)
        {
            cout << "Enter start and end age\n";
            int st   ,   en;
            cin >> st >> en;
            ifskep(st , en , x);
            if (x) continue;
            for (int i = 0; i < emp.size();i++)
            {
                if (emp[i].choice_3() >= st && emp[i].choice_3() <= en)
                {
                    emp.erase(emp.begin() + i);
                    i--;
                }
            }
        }
        else if (o == 4)
        {
            cout << "Enter the name and salary\n";
            string   name; cin >>   name;
            int    salary; cin >> salary;
            ifskep(salary , 1 , x);
            if (x) continue;
            for (int i = 0; i < emp.size(); i++)
            {
                if (emp[i].choice_4() == name)
                {
                    emp[i].change(salary);
                    break;
                }
            }
        }
        ifskep(o , 1 , x);
    }
}

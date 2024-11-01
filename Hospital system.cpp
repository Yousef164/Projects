#include  <iostream>
#include <algorithm>
#include    <vector>
#include    <string>
#include    <limits>
#define    el  '\n'
using namespace std;
class hos{
    int    spec;
    string name;
    bool statis;
public:
    hos() = default;
    hos(int s , string n , bool t):spec(s) , name(n) , statis(t){}
    static void display_menu()
    {
        cout <<    "Enter your choice:\n";
        cout <<    "1) Add new patient\n";
        cout << "2) Print all payients\n";
        cout <<   "3) Get next patient\n";
        cout <<               "4) Exit\n";
    }
    string get_name()
    {
        return name;
    }
    bool get_statis() const
    {
        return statis;
    }
    void choice_2()
    {
        cout << name << ' ' <<(statis ? "urgent" : "regular");
    }
};
bool comper(const hos& a , const hos& b)
{
    return a.get_statis() > b.get_statis();
}
void print(int i , int size)
{
    cout << "******************************\n";
    cout <<               "There are " << size;
    cout << " patients in specialization "<< i;
    cout << el;
}
void check_1 (int s , string n , bool t , vector<vector<hos>>&a)
{
    if (a[s].size() < 5)
    {   
        a[s].push_back (hos (s , n , t));
        sort(a[s].begin(), a[s].end(), comper);
    }
    else 
    {
        cout << "Sorry we can't add more patients for this specialization\n\n";
    }
}
void check_2(vector<vector<hos>>&a)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (!a[i].empty())
        {
            print (i, a[i].size());
            for (auto& patient : a[i])
            {
                patient.choice_2();
                cout << el;
            }
            cout << el << el;
        }
    }
}
void check_3 (int x , vector<vector<hos>>&a)
{
    if (a[x].empty())
    {
        cout << "No patients at the moment.\n\n";
    }
    else
    {
        cout << a[x][0].get_name();
        cout << " please go with the Dr\n\n";
        for (int i = 0; i < a[x].size()-1; i++){
            a[x][i] = a[x][i + 1];
        }
        a[x].pop_back();
    }
}
void skep() 
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nTry again please.\n\n";
}
void ifskep(int a , int b , bool&x)
{
    if (a == 0 || b == 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nTry again please.\n\n";
        x = true;
    }
    else return;
}
int main()
{
    vector<vector<hos>> a(21);
    while(true){
        hos::display_menu();
        bool x = false;
        int          o;
        cin >>       o;
        if (o == 1)
        {
            cout << "Enter specialization, name, statis(1/0) :\n";
            int    s;     cin >> s;
            string n;     cin >> n;
            char   t;     cin >> t;
            if   (t == '1' || t == '0')
            {
                bool f = t - '0';
                ifskep       (s, 1, x);
                if(x)         continue;
                check_1(s, n, f, a);
                cout << el;
            }
            else
            {
                skep();
                continue;
            }
        }
        else if (o == 2)
        {
            check_2(a);
            cout << el;
        }
        else if (o == 3)
        {
            cout << "Enter specialization : ";
            int y;    cin >> y;
            ifskep   (y, 1, x);
            if(x)     continue;
            check_3     (y, a);
        }
        else if (o == 4)
            break;
        ifskep (o, 1, x);
    }
    return 0;
}

#include <iostream>
using namespace std;

class Student
{
    string name,class_name,dob,blood_group,address;
    int roll_no,license_num,division;
    long long ph_num;

    public:
    Student()
    {
        roll_no = 0;
        name = "";
        class_name = "";
        dob = "";
        blood_group = "";
        address = "";
        ph_num = 0;
        division = 0;
        license_num = 0;
    }

    Student(Student &obj)
    {                  
        this->name = obj.name;                
        this->roll_no = obj.roll_no;
        this->class_name = obj.class_name;
        this->division = obj.division;
        this->dob = obj.dob;
        this->blood_group = obj.blood_group;
        this->address = obj.address;
        this->ph_num = obj.ph_num;
        this->license_num = obj.license_num;
        cout << "Copy constructor called!" <<endl;
    }

    ~Student()
    {
        cout << endl;
        cout << "Student " << name << " info is destroyed" << endl;
    }

    friend class display;
    friend class input;

    static void func()
    {
        cout << "Object of student created!" << endl;
    }

};

class display
{
public:
    inline void show(Student &s)
    {
        cout << "\nThe details of the student are:";
        cout << "\nRoll Number                   :" << s.roll_no;
        cout << "\nName                          :" << s.name;
        cout << "\nClass                         :" << s.class_name;
        cout << "\nDivision                      :" << s.division;
        cout << "\nDate of Birth                 :" << s.dob;
        cout << "\nBlood Group                   :" << s.blood_group;
        cout << "\nContact Address               :" << s.address;
        cout << "\nTelephone Number              :" << s.ph_num;
        cout << "\nDriving License No            :" << s.license_num << endl;
    }
};

class input
{
public:
    inline void getdata(Student &s)
    {
        cout << "Enter details of the student:";
        do
        {
            try
            {
                cout << "\nRoll number: ";
                cin >> s.roll_no;
                if (s.roll_no < 0)
                {
                    throw s.roll_no;
                }
            }
            catch(int roll_no)
            {
                cout<<"Roll number should be positive!\n";
            }
        } while(s.roll_no < 0);
        cout << "Name: ";
        cin.ignore();
        getline(cin,s.name);
        cout << "Class: ";
        cin >> s.class_name;
        cout << "Division: ";
        cin >> s.division;
        cout << "Date of Birth: ";
        cin >> s.dob;
        cout << "Blood Group: ";
        cin >> s.blood_group;
        cout << "Contact Address: ";
        cin.ignore();
        getline(cin,s.address);
        cout << "Telephone Number: ";
        cin >> s.ph_num;
        cout << "Driving License No: ";
        cin >> s.license_num;
    }
};

int main(){
    int total, i;
    cout << "Enter total no. of students: ";
    cin >> total;
    Student* a = new Student[total];
    input in;
    display out;
    for(i = 0; i < total; i++)
    {
        in.getdata(a[i]);
        Student::func();
    }

    for(i = 0; i < total; i++)
    {
        out.show(a[i]);
    }

    Student b = a[0];
    out.show(b);

    delete [] a;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Person {
    public:
        string mName; 
        unsigned int mAge;
        double mSalary;

        const bool operator == (const Person &obj) {
            if (mName == obj.mName && mAge == obj.mAge && mSalary == obj.mSalary)
                return 1;
            return 0;
        }

        const bool operator < (const Person &obj) {
            if (mName < obj.mName)
                return 1;
            return 0;
        }

        Person() {
            mName = "";
            mAge = 0;
            mSalary = 0;
        }

        Person(string name, unsigned int age, double salary) {
            mName = name;
            mAge = age;
            mSalary = salary;
        }

};

class Building {
    protected:
        string mBuildingName;
        string mType;
        Person mCoordinator;
        vector<Person> mEmployees;
        vector<Person> mCitizens;
    
    public:
        virtual void add(const Person obj) = 0;
        virtual void remove(const Person obj) = 0;
        
        virtual Building* operator + (const Person &obj) = 0;
        virtual Building* operator - () {return nullptr;}
        virtual Building* operator - (const Person &obj) {return nullptr;}

        const string getBuildingName() {return mBuildingName;}
        const string getType() {return mType;}
        const unsigned int getEmployeesSize() {return mEmployees.size();}
        const unsigned int getCitizensSize() {return mCitizens.size();}

        const Person getEmployee(unsigned int idx) {return mEmployees[idx];}
        const Person getCitizen(unsigned int idx) {return mCitizens[idx];}

        const Person getCoordinator() {return mCoordinator;}

        Building(string name, string type) {
            mBuildingName = name;
            mType = type;
        }
};

class CityHall : protected Building {
    public:
        // Person* operator + (const Person obj) {
        //     if (mCoordinator == Person("",0,0))
        //         mCoordinator = obj;
        //     return mCoordinator;
        // }

        void print() {
            cout << mBuildingName << " " << mType;
        }


        CityHall(string name): Building(name, "CityHall") {
            mCitizens.clear();
            mCoordinator = Person();
        }
};


int main() {
    Person p1("Marcel", 40, 5000);
    Person p2("George", 35, 6500);
    
    CityHall ch1("sector2");


    return 0;
}
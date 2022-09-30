#include <bits/stdc++.h>
using namespace std;

class Person {
    public:
        string mName; 
        unsigned int mAge;
        double mSalary;

        const bool operator == (const Person obj) {
            if (mName == obj.mName && mAge == obj.mAge && mSalary == obj.mSalary)
                return 1;
            return 0;
        }

        const bool operator < (const Person obj) {
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

ostream& operator<<(ostream& output, const Person obj) {
    cout << obj.mName << " " << obj.mAge << " " << obj.mSalary;
    return output;
}

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
        
        virtual Building* operator + (const Person obj) = 0;
        virtual Building* operator - () {return nullptr;}
        virtual Building* operator - (const Person obj) {return nullptr;}

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
        CityHall* operator + (const Person obj) {
            if (mCoordinator == Person("", 0, 0))
                mCoordinator = obj;

            return this;
        }

        CityHall* operator - () {
            mCoordinator = Person("", 0, 0);

            return this;
        }

        
        void add(Person obj) {
            mCitizens.push_back(obj);
        }

        void remove(Person obj) {
            mCitizens.erase(std::remove(mCitizens.begin(), mCitizens.end(), obj), mCitizens.end());
        }

        void print() {
            cout << mBuildingName << " " << mType << ' ';
            cout << mCoordinator;
            cout << '\n';
            
            for (auto i = mCitizens.begin(); i != mCitizens.end(); i++) cout << *i << "\n";
        }


        CityHall(string name): Building(name, "CityHall") {
            mCitizens.clear();
            mCoordinator = Person();
        }
};

class Hospital : protected Building {
    public:
        Hospital* operator + (const Person obj) {
            mEmployees.push_back(obj);

            return this;
        }

        Hospital* operator - (const Person obj) {
            mEmployees.erase(std::remove(mEmployees.begin(), mEmployees.end(), obj), mEmployees.end());

            return this;
        }

        void add(const Person obj) {
            mCitizens.push_back(obj);
        }

        void remove(const Person obj) {
            mCitizens.erase(std::remove(mCitizens.begin(), mCitizens.end(), obj), mCitizens.end());
        }
 
        Hospital(string name) : Building(name, "Hospital") {
            mCitizens.clear();
            mEmployees.clear();
        }
};

class PoliceStation : protected Building {
    public:
        PoliceStation* operator + (const Person obj) {
            mEmployees.push_back(obj);

            return this;
        }

        PoliceStation* operator - (const Person obj) {
            mEmployees.erase(std::remove(mEmployees.begin(), mEmployees.end(), obj), mEmployees.end());

            return this;
        }

        void add(const Person obj) {
            mCitizens.push_back(obj);
        }

        void remove(const Person obj) {
            mCitizens.erase(std::remove(mCitizens.begin(), mCitizens.end(), obj), mCitizens.end());
        }

        PoliceStation(string name) : Building(name, "PoliceStation") {
            mCitizens.clear();
            mEmployees.clear();
        }
};

class House : protected Building {
    private:
        unsigned int mMaxNumber;
    public:
        House* operator + (const Person obj) {
            if (mCoordinator == Person("", 0, 0)) {
                mCoordinator = obj;
                add(obj);
            }
            return this;
        }

        House* operator - () {
            remove(mCoordinator);
            mCoordinator = Person("", 0, 0);
            return this;
        }

        void add(const Person obj) {
            if (mCitizens.size() < mMaxNumber)
                mCitizens.push_back(obj);
        }

        void remove(const Person obj) {
            if (obj.mAge >= 18)
                mCitizens.erase(std::remove(mCitizens.begin(), mCitizens.end(), obj), mCitizens.end());
        }

        House(string name, unsigned int maxnumber) : Building(name, "House") {
            mMaxNumber = maxnumber;
            mCitizens.clear();
            mCoordinator = Person();
        }
};

class Block : protected Building {
    private:
        unsigned int mMaxNumberPerFloor;
    public:
        Block* operator + (const Person obj) {
            if (mCoordinator == Person("", 0, 0)) {
                mCoordinator = obj;
            }

            return this;
        }

        Block* operator - () {
            mCoordinator = Person("", 0, 0);
            return this;
        }

        // helper for add function
        void insert_in_vector(vector<Person> vect, const Person obj) {
            for(auto i = vect.begin(); i != vect.end(); i++) {
                if (*i == Person("", 0, 0)) {
                    *i = obj;
                    break;
                }
            }
        }

        void add(const Person obj) {
            if (mCitizens.size() < mMaxNumberPerFloor) {
                insert_in_vector(mCitizens, obj);
            }
        }


        //helper for remove function
        void remove_in_vector(vector<Person> vect, const Person obj) {
            for (auto i = vect.begin(); i != vect.end(); i++) {
                if (*i == obj) {
                    *i = Person("", 0, 0);
                    break;
                }
            }
        }

        void remove(const Person obj) {
            if (obj.mAge >= 18) {
                remove_in_vector(mCitizens, obj);
            }
        }

        Block (string name, unsigned int floors, unsigned int maxperfloor) : Building(name, "Block") {
            mMaxNumberPerFloor = maxperfloor;
            mCitizens.clear();
            mCoordinator = Person("", 0, 0);
            
            for(int i = 0; i < floors * mMaxNumberPerFloor; i++)
                mCitizens.push_back(Person("", 0, 0));
        }
};

int main() {
    Person p1("Aaaa", 40, 5000);
    Person p2("Bbbb", 35, 6500);
    Person p3("Cccc", 60, 8500);
    Person p4("Dddd", 70, 10090);

    // if (p1 < p2) {
    //     cout << "DA";
    // }

    CityHall ch1("sector2");

    ch1.add(p1);
    ch1.add(p2);
    ch1.add(p3);
    ch1 + p4;

    ch1.print();

    ch1.remove(p2);

    -ch1;

    ch1.print();



    return 0;
}
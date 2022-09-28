#include <bits/stdc++.h>
using namespace std;

class Person {
    public:
        string mName; 
        unsigned int mAge;
        double mSalary;

        const bool operator == (Person &obj) {
            if (mName == obj.mName && mAge == obj.mAge && mSalary == obj.mSalary)
                return 1;
            return 0;
        }

        const bool operator < (Person &obj) {
            if (mName < obj.mName)
                return 1;
            return 0;
        }

        Person() {
            mName = "";
            mAge = 0;
            mSalary = 0;
        }

        Person(string x, unsigned int y, double z) {
            mName = x;
            mAge = y;
            mSalary = z;
        }

};


int main() {




    return 0;
}
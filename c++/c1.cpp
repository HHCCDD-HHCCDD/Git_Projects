#include<iostream>

class Date{
    public:
        void printDate(){};
        void setDay(int d){};
        void setMonth(int m){};
        void setYear(int y){};
    private:
        int day, month, year;
};

int main()
{
    Date testDay;
    testDay.setDay(5);
    testDay.setMonth(10);
    testDay.setYear(2003);
    testDay.printDate();
    return 0;
}
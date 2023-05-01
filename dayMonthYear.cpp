#include<stdio.h>
#include <ctime>
class dayMonthYear{
    private:
        int day;
        int month;
        int year;
    public:
        dayMonthYear(int day, int month, int year);
        void calcAge();
        void checkHoliday();
};

dayMonthYear::dayMonthYear(int day, int month, int year){
    this->day = day;
    this->month = month;
    this->year =year;
}

void dayMonthYear::calcAge(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int currentYear = 1900 + ltm->tm_year;
    int currentMonth = 1 + ltm->tm_mon;
    int currentDay = ltm->tm_mday;
    int age;
    age = currentYear - this->year;
    if(currentMonth < this->month ||  currentMonth == this->month && currentDay < this->day) age -= 1;
    printf("Age: %d\n",age);
}
void dayMonthYear::checkHoliday(){
    if(this->day == 1 && this->month == 1 || 
    this->day == 30 && this->month == 4 ||
    this->day == 1 && this->month == 5 ||
    this->month == 2 && this->month == 9) printf("It's holiday\n");
    else printf("It isn't holiday\n");
}
int main(){
    dayMonthYear Hung(24,9,2002);
    Hung.calcAge();
    Hung.checkHoliday();
    return 0;
}
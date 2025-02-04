#include <iostream>

using namespace std;

bool isLeap(int year){
    bool leap = false;
    if (year % 4 == 0){
        if (year % 100 == 0){
            if (year % 400 == 0){
                leap = true;
            }
        }
        else{
            leap = true;
        }
    }
    return leap;
}

int dateCal(int year, int month, int day){
    int date = 0;
    for (int i = 1; i < year; i++){
        date += 365;
        if (isLeap(i)){
            date += 1;
        }
    }
    for (int i = 1; i < month; i++){
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){
            date += 31;
        }
        else if (i == 2){
            date += 28;
            if (isLeap(year)){
                date += 1;
            }
        }
        else{
            date += 30;
        }
    }
    return date+day;
}

int main(){
    int tYear, tMonth, tDay;
    int dYear, dMonth, dDay;

    cin >> tYear >> tMonth >> tDay;
    cin >> dYear >> dMonth >> dDay;

    int x = dateCal(dYear, dMonth, dDay) - dateCal(tYear, tMonth, tDay);
    if (dYear > tYear+1000 || (dYear == tYear+1000 && dMonth > tMonth) || 
    (dYear == tYear+1000 && dMonth == tMonth && dDay >= tDay)){
        cout << "gg";
    }
    else{
        cout << "D-" << dateCal(dYear, dMonth, dDay) - dateCal(tYear, tMonth, tDay);
    }

}
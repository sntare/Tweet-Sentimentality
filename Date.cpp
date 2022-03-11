//
// Created by Steve Ntare on 7/7/2021.
//

#include "Date.h"
#include <cctype>



Date::Date() {
    month = nullptr;
    dateOfMonth = nullptr;
    time = nullptr;
    year = nullptr;
}

Date::Date(const Date& in) {
    month = new char[strlen(in.month) + 1 ];
    strcpy(month, in.month);
    dateOfMonth = new char[strlen(in.dateOfMonth) + 1 ];
    strcpy(dateOfMonth, in.dateOfMonth);
    time = new char[strlen(in.time) + 1 ];
    strcpy(time, in.time);
    year = new char[strlen(in.year) + 1 ];
    strcpy(year, in.year);
}

Date &Date::operator=(const Date& in) {
    if (month!= nullptr)
        delete[] month;
    if (in.month != nullptr){
        month = new char[strlen(in.month) + 1 ];
        strcpy(month, in.month);
    }


    if (dateOfMonth!= nullptr)
        delete[] dateOfMonth;

    if (in.dateOfMonth != nullptr){
        dateOfMonth = new char[strlen(in.dateOfMonth) + 1 ];
        strcpy(dateOfMonth, in.dateOfMonth);
    }
    if (time != nullptr)
        delete[] time;
    if (in.time != nullptr){
        time = new char[strlen(in.time) + 1 ];
        strcpy(time, in.time);
    }
    if (year!= nullptr)
        delete[] year;
    if (in.year != nullptr){
        year = new char[strlen(in.year) + 1 ];
        strcpy(year, in.year);
    }

}


Date::Date(char* in, char* in2, char* in3, char* in4) {


    month = new char[strlen(in) + 1 ];
    strcpy(month, in);
    dateOfMonth = new char[strlen(in2) + 1 ];
    strcpy(dateOfMonth, in2);
    time = new char[strlen(in3) + 1 ];
    strcpy(time, in3);
    year = new char[strlen(in4) + 1 ];
    strcpy(year, in4);

}

Date::~Date() {
    if(month != nullptr)
        delete[] month;
    if(dateOfMonth != nullptr)
        delete[] dateOfMonth;
    if(time != nullptr)
        delete[] time;
    if(year != nullptr)
        delete[] year;

}


int Date::dateInt() const{
    char numericalMonth[2];
    int numericalDateOfMonth;
    int numericalTime;
    int numericalYear;

    if(isdigit(month[0])){
        strcpy(numericalMonth, month);
    }else {
        if (strcmp(month, "Jan") == 0) {
            strcpy(numericalMonth, "01");
        } else if (strcmp(month, "Feb") == 0) {
            strcpy(numericalMonth, "02");
        } else if (strcmp(month, "Mar") == 0) {
            strcpy(numericalMonth, "03");
        } else if (strcmp(month, "Apr") == 0) {
            strcpy(numericalMonth, "04");
        } else if (strcmp(month, "May") == 0) {
            strcpy(numericalMonth, "05");
        } else if (strcmp(month, "Jun") == 0) {
            strcpy(numericalMonth, "06");
        } else if (strcmp(month, "Jul") == 0) {
            strcpy(numericalMonth, "07");
        } else if (strcmp(month, "Aug") == 0) {
            strcpy(numericalMonth, "08");
        } else if (strcmp(month, "Sept") == 0) {
            strcpy(numericalMonth, "09");
        } else if (strcmp(month,"Oct") == 0) {
            strcpy(numericalMonth, "10");
        } else if (strcmp(month, "Nov") == 0) {
            strcpy(numericalMonth, "11");
        } else if (strcmp(month, "Dec") == 0) {
            strcpy(numericalMonth, "12");
        }
    }
    char numberString [100];
    strcpy(numberString, year);
    strcat(numberString, numericalMonth);
    strcat(numberString, dateOfMonth);
    strcat(numberString, time);
    int date = atoi(numberString);
    return date;

//    char* numberString = strcat(year, numericalMonth);
//    numberString = strcat(numberString, dateOfMonth);
//    numberString = strcat(numberString, time);
//    int date = atoi(numberString);
//    return date;


}






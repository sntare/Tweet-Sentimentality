//
// Created by Steve Ntare on 7/7/2021.
//

#ifndef INC_21SU_PA02_TEMPLATE_DATE_H
#define INC_21SU_PA02_TEMPLATE_DATE_H
#include "DSVector.h"
#include "DSString.h"
class Date {
private:
    char* month;
    char* dateOfMonth;
    char* time;
    char* year;
public:
    Date();
    Date(char*, char*, char*, char*);
    Date(const Date&);
    Date& operator=(const Date&);
    ~Date();
    int dateInt() const;
    char* getMonth(){return month;}
    char* getDateOfMonth(){return dateOfMonth;}
    char* getTime(){return time;}
    char* getYear(){return year;}
    bool operator <= (const Date& date){
        if(dateInt() <= date.dateInt()){
            return true;
        }
        return false;
    }

};


#endif //INC_21SU_PA02_TEMPLATE_DATE_H

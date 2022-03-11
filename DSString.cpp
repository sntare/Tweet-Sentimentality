//
// Created by mark on 6/2/2021.
//

#include "DSString.h"
#include <cstring>
#include <iostream>
using namespace std;
//constructors
DSString ::DSString() {
    const char* ran = "";
    data = new char [strlen(ran)+1];
    strcpy(data, ran);
}

DSString::DSString(const DSString& ran) {
    data = new char [strlen(ran.data) + 1];
    strcpy(data, ran.data);
}

DSString::DSString(const char* ran) {
    if (ran != nullptr){
        data = new char [strlen(ran) + 1];
        strcpy(data, ran);

    }else{
        data = new char [strlen(ran) + 1];
        strcpy (data, "");
    }
}
//destructor
DSString ::~DSString() {
    if(data != nullptr)
        delete[] data;
}
//functions for overloaded assignemnt operators
DSString& DSString::operator=(const DSString& ran) {
    if (data != nullptr)
        delete [] data;
    if(ran.data != nullptr){
        data = new char [strlen(ran.data)+ 1];
        for(int i = 0; i < strlen(ran.data); i++){
            data[i] = ran.data[i];

        }
        data[strlen(ran.data)] = '\0';

    }
    return *this;
}
DSString& DSString::operator=(const char* ran) {
    if (data != nullptr)
        delete[] data;
    if(ran != nullptr){
        data = new char [strlen(ran)+1];
        for(int i = 0; i<strlen(ran); i++){
            data [i] = ran [i];

        }
        data[strlen(ran)] = '\0';

    }
    return *this;
}
//functions for standard relational operators
bool DSString::operator==(const DSString& ran) {
    if(ran.data != nullptr){
        int answer = strcmp(data, ran.data);
        if(answer == 0)
            return true;
    }
    return false;
}

bool DSString::operator==(const char* ran) {
    if(ran!= nullptr){
        int answer = strcmp(data, ran);
        if(answer == 0)
            return true;
    }
    return false;
}
//functions for overloaded non-modifying string concat
DSString DSString::operator+(const DSString& ran) {
    int length = strlen(data) + strlen(ran.data) + 1;
    DSString temp = new char [length];
    strcpy(temp.data, data);
    strcat(temp.data, ran.data);
    return temp;
}

DSString DSString::operator+(const char* ran) {
    int length = strlen(data) + strlen(ran) + 1;
    DSString temp = new char [length];
    strcpy(temp.data, data);
    strcat(temp.data, ran);
    return temp;
}
//functions for relational operators
bool DSString::operator<(const DSString& ran)const {
    if(ran.data != nullptr){
        int answer = strcmp(data, ran.data);
        if(answer>0)
            return false;
    }
    return true;
}

bool DSString::operator<(const char* ran)const {
    if(ran != nullptr){
        int answer = strcmp(data, ran);
        if(answer>0)
            return false;
    }
    return true;}


bool DSString::operator>(const DSString& ran) {
    if(ran.data != nullptr){
        int answer = strcmp(data, ran.data);
        if(answer>0)
            return true;
    }
    return false;
}

bool DSString::operator>(const char* ran) {
    if(ran != nullptr){
        int answer = strcmp(data, ran);
        if(answer>0)
            return true;
    }
    return false;
}
//function for subscript operator
char &DSString::operator[](const int num) {

    return data[num];
}
//funciton that returns number of characters in string
int DSString::getLength() {
    int length = 0;
    if(data != nullptr){
        length = strlen(data);

    }
    return length;
}
//function that returns string object which contains sequence of characters from this string object
DSString DSString::substring(int start, int numChars) {
    DSString newString;
    newString.data = new char[numChars + 1];
    for(int i =0; i < numChars; i++){
        newString.data[i] = data[start + i];
    }
    return newString;
}
//functions with overloaded stream insertion operator for printing
std::ostream &operator<<(std::ostream& out, const DSString& line) {
    out << line.data;
    return out;
}
//function that returns null-terminated c-string holding contents of this object
char *DSString::c_str() {
    return data;
}
//setter for data
void DSString::setData( char* ran) {
    this->data = ran;

}





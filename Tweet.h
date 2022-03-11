//
// Created by Steve Ntare on 6/14/2021.
//

#ifndef INC_21SU_PA02_TEMPLATE_TWEET_H
#define INC_21SU_PA02_TEMPLATE_TWEET_H

#define __USE_XOPEN
#include <time.h>
#include "Date.h"
#include "DSString.h"
#include <ctime>

#include "DSVector.h"

using namespace std;
class Tweet {
private:
    //all private variables that will be needed
    DSString text;
    Date date;
    DSVector<DSString> words;
    DSVector<DSString> hashtags;
    DSString userName;
    DSString month;
    DSString dateOfMonth;
    DSString time;
    DSString year;


public:
    //function declarations with constructors
    Tweet();
    Tweet(Date, DSString, DSString);
    DSString GetText();
    void SetText(DSString);
    Date GetDate();
    DSVector<DSString>& getWords(){return words;}
    void Tokenize(char*);
    void TokenizeHashtags(char*);
    void parseDate();
    bool operator<= (const Tweet& tweet){
        if(date <= tweet.date){
            return true;
        }
        return false;

    }
    void Print(){
        cout << date.getMonth() << "/" << date.getDateOfMonth() << "/" << date.getYear() << " " << text << endl;
    }
};


#endif //INC_21SU_PA02_TEMPLATE_TWEET_H

//
// Created by Steve Ntare on 6/3/2021.
//

#ifndef PA01_SENTIMENT_TWEET_H
#define PA01_SENTIMENT_TWEET_H
#include <vector>
#include "DSString.h"
using namespace std;
class Tweet {
private:
    //all private variables that will be needed
    DSString text;
    DSString sentVal;
    vector<DSString> words;
    DSString id;

public:
    //function declarations with constructors
    Tweet(DSString, DSString, DSString);
    Tweet(DSString);
    Tweet(DSString, DSString);
    DSString GetText();
    void SetText(DSString);
    DSString GetSentVal();
    void SetSentVal(DSString);
    DSString GetID();
    void SetID(DSString);
    void Print();
    vector<DSString>& getWords(){return words;}
    void Tokenize(char*);


};


#endif //PA01_SENTIMENT_TWEET_H

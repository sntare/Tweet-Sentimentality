//
// Created by Steve Ntare on 6/3/2021.
//

#include "Tweets.h"
#include "DSString.h"

using namespace std;
//constructors
Tweet::Tweet(DSString in, DSString in2, DSString in3) {
    id = in;
    text = in2;
    sentVal = in3;
}

Tweet::Tweet(DSString in, DSString in2) {
    id = in;
    text = in2;
}

Tweet::Tweet(DSString in) {
    id = in;
}

//getters and setters
DSString Tweet::GetText(){
    return text;
}
void Tweet::SetText(DSString in){
    text = in;
}
DSString Tweet::GetID() {
    return id;
}

void Tweet::SetID(DSString in) {
    id = in;
}
DSString Tweet::GetSentVal(){
    return sentVal;
}
void Tweet::SetSentVal(DSString in2){
    sentVal = in2;
}
void Tweet::Print(){
    cout << sentVal << endl;
    cout << text << endl;
}
//tokenize function that goes separates words individually from tweets
void Tweet::Tokenize(char* fed){


    char word[100];
    int counter = 0;
    for (int i=0; i<strlen(fed); i++){
        if (fed[i] == ' '){
            word[counter] = '\0';
            DSString def = word;
            words.push_back(def);
            counter = 0;
        }else{
            word[counter] = fed[i];
            counter++;

        }

    }


}





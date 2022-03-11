//
// Created by Steve Ntare on 6/14/2021.
//

#include "Tweet.h"

using namespace std;
//constructors
Tweet::Tweet() {

}
Tweet::Tweet(Date in, DSString in1, DSString in2) {
    date = in;
    userName = in1;
    text = in2;
}

//getters and setters
DSString Tweet::GetText(){
    return text;
}
void Tweet::SetText(DSString in){
    text = in;
}






//tokenize function that goes separates words individually from tweets
void Tweet::Tokenize(char* fed){


    char word[300];
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

void Tweet::parseDate() {

}

void Tweet::TokenizeHashtags(char* def) {
    char hashtag[300];
    bool ishashtag;
    int counter = 0;
    for (int i=0; i<strlen(def); i++){
        if (ishashtag){
            hashtag [counter] = def[i];
            if(def[i]==' '){
                ishashtag = false;
                hashtag [counter] = '\0';
                hashtags.push_back(hashtag);
                counter = 0;
            }
            counter ++;
        }
        if (def[i] == '#'){
            ishashtag = true;
        }

    }
}

Date Tweet::GetDate() {
    return date;
}




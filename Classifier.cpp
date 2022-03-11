//
// Created by Steve Ntare on 6/6/2021.
//

#include "Classifier.h"
#include "Tweets.h"
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <fstream>
//constructor
Classifier::Classifier() {

}

Classifier::Classifier(char** fileNames) {
    //call open file function for the files and read them in
   ifstream trainFile = openFile(fileNames[1]);
   readTrainingFile(trainFile);
   ifstream testFile = openFile(fileNames[2]);
   readTestFile(testFile);
   //create maps with the test tweet vector that's now been populated
   CreateMaps(testTweets);
   ifstream sentFile = openFile(fileNames[3]);
   readSentimentFile(sentFile);
   //call the functions that make sentiments for the test tweets and check if
   //they're the same as the real sentiments
   predictSentiments();
   checkSentiments();
   //print the resulting percentage of what's right and the wrong id's in the output file
   ofstream outFS = openOutputFile(fileNames[4]);
   outputData(outFS);


}
//destructor
Classifier::~Classifier() {
    positiveWords.clear();
    negativeWords.clear();
    wrongIDs.clear();
}
//getters and setters
vector<Tweet> Classifier::getTestTweets() {
    return testTweets;
}

vector<Tweet> Classifier::getTrainingTweets() {
    return trainingTweets;
}

vector<DSString> Classifier::getWrongIDs() {
    return wrongIDs;
}

void Classifier::setAccuracy(double acc) {
    accuracy = acc;
}

double Classifier::getAccuracy() {
    return accuracy;
}

map<DSString, int> &Classifier::getPosMap() {
    return positiveWords;
}

map<DSString, int> &Classifier::getNegMap() {
    return negativeWords;
}

map<DSString, int> &Classifier::getTweetIDs() {
    return tweetIDs;
}
//read training file function that also calls the tokenize function and
//populates the training tweets vector
void Classifier::readTrainingFile(ifstream& file){
    char sentimentValue[500];
    char tweet[500];
    char id[500];
    char other[500];
    file.getline(other, 500);
    file.getline(sentimentValue, 500, ',');
    int i = 0;
    while(!file.eof()){
        file.getline(id, 500 , ',');
        file.getline(other, 500 , ',');
        file.getline(other, 500 , ',');
        file.getline(other, 500 , ',');
        file.getline(tweet, 500 );


        Tweet trainingObject (id, tweet, sentimentValue);
        trainingObject.Tokenize(trainingObject.GetText().c_str());
        trainingTweets.push_back(trainingObject);


        file.getline(sentimentValue, 500, ',');
        i++;
    }

    file.close();
}
//read test file function that populates the test tweets vector
void Classifier::readTestFile(ifstream& file) {
    char id[500];
    char tweet[500];
    char other[500];
    file.getline(other, 500);
    file.getline(id, 500, ',');
    int i = 0;
    while(!file.eof()){
//       cout << "Sentiment value: " << sentimentValue << endl;
        file.getline(other, 500 , ',');
        file.getline(other, 500 , ',');
        file.getline(other, 500 , ',');
        file.getline(tweet, 500 );

//       cout << "Tweet: " << tweet << endl;

        Tweet testObject (id, tweet);
        testObject.Tokenize(testObject.GetText().c_str());
        testTweets.push_back(testObject);

        file.getline(id, 500, ',');
        i++;
    }
//    for(int i = 0; i<testTweets.size(); i++){
//        cout << testTweets.at(i).GetSentVal()  << endl;
//    }
    file.close();
}


//read sentiment file function that pushes back the real sentiments into the actual sentiments list
//vector after reading in the file
void Classifier::readSentimentFile(ifstream& file) {
    char sentimentValue[500];
    char id[500];
    char other[500];
    file.getline(other, 500);
    file.getline(sentimentValue, 500, ',');
    int i = 0;
    while(!file.eof()){
        file.getline(id, 500 );

        Tweet sentimentFileObject (id);
        sentimentFileObject.SetSentVal(sentimentValue);
        actualSentimentList.push_back(sentimentFileObject);


        file.getline(sentimentValue, 500, ',');
        i++;
    }
//    for (int j = 0; j < actualSentimentList.size(); ++j) {
//        cout << actualSentimentList.at(j).GetID() << endl;
//    }
    file.close();
}

//predict sentiments function that applies logic for predicting the test tweets sentiments then pushes
//the predicted sentiments back into the predicted values list vector
void Classifier::predictSentiments() {
    DSString words;
    for (int i = 0; i<testTweets.size(); i++){
        int senti = 0;
        for (int j = 0; j<testTweets[i].getWords().size(); j++){
            words = testTweets[i].getWords().at(j);
            map<DSString, int>::iterator posItr = positiveWords.find(words);
            map<DSString, int>::iterator negItr = negativeWords.find(words);
            int bink = posItr->second - negItr->second;
            senti += bink;
        }
        DSString sentiStr;
        if(senti>=0){
            sentiStr = "4";
        }else{
            sentiStr = "0";
        }
        Tweet newTweet = testTweets.at(i);
        newTweet.SetSentVal(sentiStr);
        predictedValuesList.push_back(newTweet);

    }
//    for(int i = 0; i<predictedValuesList.size(); i++){
//        cout << predictedValuesList.at(i).GetSentVal() << endl;
//    }
}
//check sentiments function that checks to see if the predicted sentiments match with the actual sentiments
void Classifier::checkSentiments() {
    int count = 0;
    for(int i = 0; i<predictedValuesList.size(); i++){
        if(predictedValuesList.at(i).GetSentVal() == actualSentimentList.at(i).GetSentVal()){
            count++;
        }else{
            wrongIDs.push_back(predictedValuesList.at(i).GetID());
        }
    }
    cout << predictedValuesList.size() << endl;
    cout << count << endl;
    accuracy = ((double)count)/predictedValuesList.size();

}
//function that prints the data into the output file
void Classifier::outputData(ofstream& file) {
    file << fixed << setprecision(3) << accuracy << endl;

    for(int i = 0; i<wrongIDs.size() ; i++ ){
        file << wrongIDs.at(i) << endl;
    }
    file.close();
}

//function that opens the file arguments
ifstream Classifier::openFile(char* fileName){
    ifstream networkFile;
    networkFile.open(fileName);
    if(networkFile.is_open()){
        cout << "File opened." << endl;
    } else {
        cout << "File " << fileName <<" couldn't open" << endl;
    }
    return networkFile;
}

//function that opens the output file
ofstream Classifier::openOutputFile(char* fileName){
    ofstream networkFile;
    networkFile.open(fileName);
    if(networkFile.is_open()){
        cout << "Output file opened." << endl;
    }else{
        cout << "Output file couldn't open" << endl;
    }
    return networkFile;
}

//function that populates the maps with positive and negative words
void Classifier::PopulateMap(Tweet& tweet, map<DSString, int>& dictionary) {
    map<DSString, int>::iterator itr;
    vector<DSString> words = tweet.getWords();
    for(int i = 0; i < words.size(); i++){
        DSString current_word = words[i];
        itr = dictionary.find(words[i]);
        if(itr == dictionary.end()){
            dictionary[words[i]] = 1;
        }else{
            dictionary[words[i]] ++;
        }
    }
//    for(itr = dictionary.begin(); itr != dictionary.end(); ++itr){
//        cout << itr->first<<" "<< itr->second << endl;
//    }
}
//function that creates the maps used to store positive and negative words
void Classifier::CreateMaps(vector<Tweet>& tweets) {
    for(int i = 0; i<tweets.size(); i++){
        Tweet tweet = tweets[i];
        if(tweet.GetSentVal() == 0){
            PopulateMap(tweet, negativeWords);
        }else{
            PopulateMap(tweet, positiveWords);
        }
    }
//    map<DSString, int>::iterator itr;
//    for(itr = positiveWords.begin(); itr != positiveWords.end(); ++itr){
//        cout << itr->first<<" "<< itr->second << endl;
//    }

}


//void Classifier::printMaps() {
//    map<DSString, int>::iterator itr;
//    for(itr = positiveWords.begin(); itr != positiveWords.end(); ++itr){
//        cout << itr->first<<" "<< itr->second << endl;
//    }
//}














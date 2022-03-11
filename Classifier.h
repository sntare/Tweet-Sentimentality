//
// Created by Steve Ntare on 6/6/2021.
//

#ifndef PA01_SENTIMENT_CLASSIFIER_H
#define PA01_SENTIMENT_CLASSIFIER_H
#include <iostream>
#include "DSString.h"
#include <map>
#include "Tweets.h"
#include <vector>
using namespace std;

class Classifier {
private:
    //all private variables that will be needed
    map<DSString, int> positiveWords;
    map<DSString, int> negativeWords;
    map<DSString, int> tweetIDs;


    vector<Tweet> predictedValuesList;
    vector<Tweet> actualSentimentList;

    vector<Tweet> testTweets;
    vector<Tweet> trainingTweets;
    vector<DSString> wrongIDs;

    double accuracy = 0;

public:
    //constructors and destructor
    Classifier();
    Classifier(char**);
    ~Classifier();

    //vectors and map declarations with map getters and setters
    vector<Tweet> getTestTweets();
    vector<Tweet> getTrainingTweets();
    vector<DSString> getWrongIDs();
    map<DSString, int>& getPosMap();
    map<DSString, int>& getNegMap();
    map<DSString, int>& getTweetIDs();

    //function declarations

    void setAccuracy(double);
    double getAccuracy();
    void readTestFile(ifstream&);
    void CreateMaps(vector<Tweet>&);
    void PopulateMap(Tweet&, map<DSString, int>&);
    void predictSentiments();
    void checkSentiments();
    void outputData(ofstream&);
    ifstream openFile(char*);
    void readTrainingFile(ifstream&);
    void readSentimentFile(ifstream&);
//    void printMaps();


    ofstream openOutputFile(char *fileName);
};


#endif //PA01_SENTIMENT_CLASSIFIER_H

//
// Created by Steve Ntare on 6/15/2021.
//


#include "Sort.h"
#include "Tweet.h"
#include <iostream>
#include <iomanip>
#include <map>
#include <time.h>
#include "DSVector.h"
#include "Date.h"
#include <fstream>
//constructor
Sort::Sort() {

}

Sort::Sort(char** args) {
    //call open file function for the files and read them in
    cout << "First Print: " << args[1] << " " << args[2] << " " << args[3]<< " " <<
    args[4] << " "  << args[5] << " " << args[6] << " " << args[7] << endl;
    if (strcmp(args[1], "-f")==0){
        ifstream testFile = openFile(args[2]);
        cout << "before reading training file" << endl;
        readTrainingFile(testFile);
        cout << "after reading training file" << endl;
    }
    if (strcmp(args[3], "-r")==0){
        cout << "before sorting by date" << endl;
        sortByDate(args[4], args[5]);
        cout << "after sorting by date" << endl;
    }
    if (strcmp(args[6], "-o")==0){
        cout << "before opening output file" << endl;
        ofstream outFS = openOutputFile(args [7]);
        cout << "after opening output file" << endl;
        outputData(outFS);
        cout << "after outputting data" << endl;

//        cout << args[4] << args[5] << endl;
    }
//    ifstream testFile = openFile(fileNames[1]);
//    readTrainingFile(testFile);

    //call the functions that make sentiments for the test tweets and check if
    //they're the same as the real sentiments

    //print the resulting percentage of what's right and the wrong id's in the output file
//    ofstream outFS = openOutputFile(args[7]);
//    outputData(outFS);


}
//destructor
Sort::~Sort() {

}
//getters and setters
DSVector<Tweet> Sort::getTweets() {
    return tweets;
}


//read test file function that populates the test tweets vector
void Sort::readTrainingFile(ifstream& file){
    char tweet[500];
    char userName[500];
    char month[500];
    char dateOfMonth[500];
    char time[500];
    char year[500];
    char other[500];
    file.getline(other, 500);
    file.getline(other, 500, ',');
    int i = 0;
    while(!file.eof()){
        file.getline(other, 500 , ',');
        file.getline(other, 500 , ' ');
        file.getline(month, 500 , ' ');
        file.getline(dateOfMonth, 500 , ' ');
        file.getline(time, 500 , ' ');
        char* hour;
        char* min;
        char* sec;
        hour = strtok(time, ":");
        min = strtok(nullptr, ":");
        sec = strtok(nullptr, ":");
        char timeWithoutColon[500];
        strcpy(timeWithoutColon, hour);
        strcat(timeWithoutColon, min);
        strcat(timeWithoutColon, sec);
        file.getline(other, 500 , ' ');
        file.getline(year, 500 , ',');
        file.getline(other, 500 , ',');
        file.getline(userName, 500 , ',');
        file.getline(tweet, 500 );

        Date dateObject(month, dateOfMonth, timeWithoutColon, year);
        Tweet tweetObject (dateObject, userName, tweet);
        tweetObject.parseDate();
        tweetObject.Tokenize(tweetObject.GetText().c_str());
        tweetObject.TokenizeHashtags(tweetObject.GetText().c_str());
        tweets.push_back(tweetObject);





        file.getline(other, 500, ',');
        i++;
    }

    file.close();

    cout << "Finished reading file" << endl;

}

void Sort::sortByDate (char*& startDate, char*& endDate){
    char* sd_year;
    char* sd_month;
    char* sd_dateOfMonth;
    char* sd_time = "000000";
    sd_year = strtok(startDate, "/");
    sd_month = strtok(nullptr, "/");
    sd_dateOfMonth = strtok(nullptr, "/");
    Date sd_Date(sd_month, sd_dateOfMonth, sd_time, sd_year);



    char* ed_year;
    char* ed_month;
    char* ed_dateOfMonth;
    char* ed_time = "000000";
    ed_year = strtok(endDate, "/");
    ed_month = strtok(nullptr, "/");
    ed_dateOfMonth = strtok(nullptr, "/");
    Date ed_Date(ed_month, ed_dateOfMonth, ed_time, ed_year);


    for(int i = 0; i<tweets.getSize(); i++) {
        Tweet cur_tweet = tweets[i];
        if(cur_tweet.GetDate().dateInt()>= sd_Date.dateInt() && cur_tweet.GetDate().dateInt()<= ed_Date.dateInt()){
            results.push_back(cur_tweet);
        }
    }
    int n = results.getSize();
    results.quickSort(results, 0, n-1);
    cout << "Finished sorting" << endl;
//    for (int i = 0; i<results.getSize(); i++){
//        results[i].print();
//    }


}



//function that prints the data into the output file
void Sort::outputData(ofstream& file) {
    for(int i = 0; i<results.getSize(); i++){
        file << results[i].GetDate().getMonth() << "/" << results[i].GetDate().getDateOfMonth() << "/" << results[i].GetDate().getYear() << "  " << results[i].GetText() << endl;

    }
    file.close();
    cout << "file closed" << endl;
}

//function that opens the file arguments
ifstream Sort::openFile(char* fileName){
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
ofstream Sort::openOutputFile(char* fileName){
    ofstream networkFile;
    networkFile.open(fileName);
    if(networkFile.is_open()){
        cout << "Output file opened." << endl;
    }else{
        cout << "Output file couldn't open" << endl;
    }
    return networkFile;
}


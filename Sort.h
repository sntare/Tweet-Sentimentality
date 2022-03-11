//
// Created by Steve Ntare on 6/15/2021.
//

#ifndef INC_21SU_PA02_TEMPLATE_SORT_H
#define INC_21SU_PA02_TEMPLATE_SORT_H
#include <iostream>
#include "DSString.h"
#include "Tweet.h"
#include "DSVector.h"
#include <ctime>

using namespace std;

class Sort {
private:
    //all private variables that will be needed

    DSVector<Tweet> tweets;
    DSVector<Tweet> results;



public:
    //constructors and destructor
    Sort();
    Sort(char**);
    ~Sort();


    DSVector<Tweet> getTweets();

    //function declarations


    void readTrainingFile(ifstream&);

    void outputData(ofstream&);
    ifstream openFile(char*);
    void sortByDate (char*&, char*&);



    ofstream openOutputFile(char *fileName);

    int partition(int *, int, int );
};





#endif //INC_21SU_PA02_TEMPLATE_SORT_H

//
// Created by Sulav on 2/2/2020.
//
#include "pch.h"

#ifndef QUANTLABS_SULAV_ADHIKARI_FILEHANDLER_H
#define QUANTLABS_SULAV_ADHIKARI_FILEHANDLER_H

/*
 * File Handler opens input file and reads number of lines in batches. This is done so that
 * large file unable to fit in memory at once can be loaded in chunks. Batches here is defined by number of
 * lines read from file. Batch Size is 1000 lines by default. This can be defined during construction.
 * Client of this class is unaware of the batching. Client interacts with FileHandler through hasNext() and getNextLine()
 * which check if any new line is remaining in file and returns it respectively.
 * */
class FileHandler {

private:
    std::fstream handle;                    // File Handler
    int totalBatchSize;                     // BatchSize in number of lines
    int currentIterator;                    // line number in current batch
    int batchSize;                          // number of lines in current batch
    std::vector<std::string> buffer;        // buffer to store lines read from file

    /*When current buffer is exhausted, read next batch of lines from file*/
    void loadNextBatch();

public:
    FileHandler(int BATCHSIZE = 1000);

    /*Open file to be read*/
    int loadInputFile(std::string filename);

    /*Check if new line is available in file*/
    bool hasNext();

    /*read the next line from file*/
    std::string getNextLine();

    /*destructor*/
    ~FileHandler();
};


#endif //QUANTLABS_SULAV_ADHIKARI_FILEHANDLER_H

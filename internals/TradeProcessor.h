//
// Created by Sulav on 2/2/2020.
//

#include "TradeResult.h"
#include "Trade.h"
#include "FileHandler.h"
#include "pch.h"

#ifndef QUANTLABS_SULAV_ADHIKARI_TRADEPROCESSOR_H
#define QUANTLABS_SULAV_ADHIKARI_TRADEPROCESSOR_H

/*
 * Trade Processor takes the stream of Trade data, processes them and generates output.
*/
class TradeProcessor {
private:
    FileHandler* handler;
    std::map<std::string, TradeResult*> records;

public:
    TradeProcessor(std::string inputFileName);

    /*
     Run through the trade data and calculate output
    */
    void ProcessTrades();


    void generateOutputToFile(std::string outputFileName = "./output.csv");

    /*
        free memory
    */
    ~TradeProcessor();
};

#endif //QUANTLABS_SULAV_ADHIKARI_TRADEPROCESSOR_H

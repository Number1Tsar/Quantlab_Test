//
// Created by Sulav on 2/2/2020.
//
#include <string>
#include "Trade.h"
#ifndef QUANTLABS_SULAV_ADHIKARI_TRADERESULT_H
#define QUANTLABS_SULAV_ADHIKARI_TRADERESULT_H


class TradeResult {

private:
    std::string symbol;
    unsigned long long maxTimeGap;
    unsigned long volume;
    unsigned int weightedPrice;
    unsigned int maxPrice;
    unsigned long long lastTimeStamp;

public:
    /*constructor takes in symbol name*/
    TradeResult(std::string symbol);

    /*updates the trade statuses according to new trade*/
    void updateStats(const Trade& trade);

    /*Converts to string for writing to file*/
    std::string toString();
};


#endif //QUANTLABS_SULAV_ADHIKARI_TRADERESULT_H

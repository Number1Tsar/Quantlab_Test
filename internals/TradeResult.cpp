//
// Created by Sulav on 2/2/2020.
//

#include "TradeResult.h"
#include "pch.h"

TradeResult::TradeResult(std::string symbol)
{
    this->symbol = symbol;
    maxTimeGap = 0;
    volume = 0;
    weightedPrice = 0;
    maxPrice = 0;
    lastTimeStamp = 0;
}

void TradeResult::updateStats(const Trade &trade)
{
    /*First Data*/
    if (lastTimeStamp == 0)
    {
        volume += trade.quantity;
        weightedPrice = trade.price;
        maxPrice = trade.price;
    }
    else
    {
        weightedPrice = round((this->volume*this->weightedPrice + trade.quantity*trade.price) / (this->volume + trade.quantity));
        volume += trade.quantity;
        maxPrice = std::max(maxPrice, trade.price);
        maxTimeGap = std::max(maxTimeGap, trade.timestamp - lastTimeStamp);
    }
    lastTimeStamp = trade.timestamp;
}

std::string TradeResult::toString()
{
    std::string result;
    const std::string delimiter = ",";
    result = symbol + delimiter +
             std::to_string(maxTimeGap) + delimiter +
             std::to_string(volume) + delimiter +
             std::to_string(weightedPrice) + delimiter +
             std::to_string(maxPrice);
    return result;
}
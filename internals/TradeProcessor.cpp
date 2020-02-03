//
// Created by Sulav on 2/2/2020.
//

#include "TradeProcessor.h"

TradeProcessor::TradeProcessor(std::string inputFileName)
{
    handler = new FileHandler();
    handler->loadInputFile(inputFileName);
}

void TradeProcessor::ProcessTrades()
{
    while (handler->hasNext())
    {
        std::string nextLine = handler->getNextLine();
        Trade newTrade(nextLine);
        if (records.find(newTrade.symbol) == records.end())
        {
            records[newTrade.symbol] = new TradeResult(newTrade.symbol);
        }
        records[newTrade.symbol]->updateStats(newTrade);
    }
}

void TradeProcessor::generateOutputToFile(std::string outputFileName)
{
    std::fstream outputFileHandler(outputFileName, std::fstream::out);
    for (auto it = records.begin(); it != records.end(); it++)
    {
        outputFileHandler << it->second->toString()<<std::endl;
    }
}

TradeProcessor::~TradeProcessor()
{
    for(auto it = records.begin();it!=records.end();it++)
    {
        delete it->second;
    }
}
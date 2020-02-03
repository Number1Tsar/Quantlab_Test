//
// Created by Sulav on 2/2/2020.
//
#include "pch.h"
#ifndef QUANTLABS_SULAV_ADHIKARI_TRADE_H
#define QUANTLABS_SULAV_ADHIKARI_TRADE_H


class Trade{
public:

    unsigned long long timestamp;
    std::string symbol;
    unsigned int quantity;
    unsigned int price;

    Trade(std::string line);
};


#endif //QUANTLABS_SULAV_ADHIKARI_TRADE_H

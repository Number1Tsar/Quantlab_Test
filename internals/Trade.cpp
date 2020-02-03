//
// Created by Sulav on 2/2/2020.
//

#include "Trade.h"
#include "utils.h"

Trade::Trade(std::string line)
{
    auto tokens = split(line, ",");
    timestamp = stoull(tokens[0]);
    symbol = tokens[1];
    quantity = stoi(tokens[2]);
    price = stoi(tokens[3]);
}
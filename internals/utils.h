//
// Created by Sulav on 2/2/2020.
//
#include <vector>
#include <string>

#ifndef QUANTLABS_SULAV_ADHIKARI_UTILS_H
#define QUANTLABS_SULAV_ADHIKARI_UTILS_H

/*
 * Split the line from CSV file into individual tokens
*/
std::vector<std::string> split(const std::string& line, const std::string& delimiter)
{
    int index = 0;
    std::vector<std::string> tokens;
    while (index < line.size())
    {
        auto pos = line.find(delimiter, index);
        std::string token;
        if (pos == std::string::npos)
        {
            token = line.substr(index);
            index = line.size();
        }
        else
        {
            token = line.substr(index, pos - index);
            index = pos + 1;
        }
        tokens.push_back(token);
    }
    return tokens;
}

#endif //QUANTLABS_SULAV_ADHIKARI_UTILS_H

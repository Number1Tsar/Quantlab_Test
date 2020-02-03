//
// Created by Sulav on 2/2/2020.
//

#include "FileHandler.h"

FileHandler::FileHandler(int BATCHSIZE)
{
    totalBatchSize = BATCHSIZE;
    currentIterator = 0;
    batchSize = 0;
    buffer.resize(BATCHSIZE);
}

int FileHandler::loadInputFile(std::string filename)
{
    handle.open(filename, std::fstream::in);
    if (handle.fail())
    {
        printf("Unable to open file\n");
        exit(1);
    }
    if(handle.peek() == std::fstream::traits_type::eof())
    {
        printf("Input file is Empty\n");
        exit(1);
    }
    return 1;
}

bool FileHandler::hasNext()
{
    return (currentIterator < batchSize || !handle.eof());
}

std::string FileHandler::getNextLine()
{
    if (currentIterator >= batchSize) loadNextBatch();
    return buffer[currentIterator++];
}

FileHandler::~FileHandler()
{
    handle.close();
}

void FileHandler::loadNextBatch()
{
    int lineNumber = 0;
    std::string line;
    for (; lineNumber < totalBatchSize && getline(handle, line); lineNumber++)
    {
        buffer[lineNumber] = line;
    }
    batchSize = lineNumber;
    currentIterator = 0;
}
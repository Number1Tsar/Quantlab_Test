#include "internals/TradeProcessor.h"
#include "internals/pch.h"
#include <ctime>


/*
    First command line argument is input file location.
    Second command line argument (optional) is output file location. default output filename is "output.csv"
*/
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Invalid command. Please provide command in following way. Ouput File argument is optional\n");
        printf("./out <inputfile name> <outputfile name>");
        exit(1);
    }
    std::string inputFileName = argv[1];
    std::string outputFileName = "./output.csv";
    if(argc > 2) outputFileName = argv[2];
    const clock_t startTime = clock();
    TradeProcessor processor(inputFileName);
    processor.ProcessTrades();
    processor.generateOutputToFile(outputFileName);
    auto timeTaken = float(clock() - startTime) / CLOCKS_PER_SEC;
    printf("Total time taken: %f\n", timeTaken);
    return 0;
}
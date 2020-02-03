#include "internals/TradeProcessor.h"
#include <ctime>

int main()
{
    const clock_t startTime = clock();
    TradeProcessor processor("C:\\\\Users\\Sulav\\CLionProjects\\Quantlabs_Sulav_Adhikari\\input.csv");
    processor.ProcessTrades();
    processor.generateOutputToFile("C:\\\\Users\\Sulav\\CLionProjects\\Quantlabs_Sulav_Adhikari\\results\\output_dummy.csv");
    auto timeTaken = float(clock() - startTime) / CLOCKS_PER_SEC;
    printf("Total time taken: %f\n", timeTaken);
    return 0;
}
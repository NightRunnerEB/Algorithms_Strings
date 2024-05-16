#ifndef STRINGGENERATOR_H
#define STRINGGENERATOR_H

#include <string>
#include <vector>

class StringGenerator {
private:
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#%:;^&*()-";

public:
    std::string generateRandomString(int length);
    std::vector<std::string> generateRandomArray(int size);
    std::vector<std::string> generateSortedArray(int size);
    std::vector<std::string> generateAlmostSortedArray(int size, int num_swaps);
};

#endif // STRINGGENERATOR_H

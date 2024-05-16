#include "StringGenerator.h"
#include <algorithm>
#include <random>

std::string StringGenerator::generateRandomString(int length) {
    std::string result;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, alphabet.size() - 1);

    for (int i = 0; i < length; ++i) {
        result += alphabet[dis(gen)];
    }

    return result;
}

std::vector<std::string> StringGenerator::generateRandomArray(int size) {
    std::vector<std::string> array;
    for (int i = 0; i < size; ++i) {
        int length = rand() % 191 + 10;
        array.push_back(generateRandomString(length));
    }
    return array;
}

std::vector<std::string> StringGenerator::generateSortedArray(int size) {
    auto array = generateRandomArray(size);
    std::sort(array.begin(), array.end(), std::greater<std::string>());
    return array;
}

std::vector<std::string> StringGenerator::generateAlmostSortedArray(int size, int num_swaps) {
    auto array = generateSortedArray(size);
    for (int i = 0; i < num_swaps; ++i) {
        int index1 = rand() % size;
        int index2 = rand() % size;
        std::swap(array[index1], array[index2]);
    }
    return array;
}

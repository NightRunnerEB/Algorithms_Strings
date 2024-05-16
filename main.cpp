#include <iostream>
#include <vector>
#include "StringGenerator.h"
#include "SortBenchmark.h"

int main() {
    StringGenerator generator;

    // Генерация неотсортированного массива
    std::vector<std::string> unsortedArray = generator.generateRandomArray(3000);

    // Генерация отсортированного массива
    std::vector<std::string> sortedArray = generator.generateSortedArray(3000);

    // UNSORTED ARRAY
    for(int i = 100; i < 3001; i += 100) {
        std::vector<std::string> tempArray(unsortedArray.begin(), unsortedArray.begin() + i);
        SortBenchmark::runTernaryStringQuickSort(tempArray, "STRING_QUICKSORT_UNSORTED.csv");
    }

    for(int i = 100; i < 3001; i += 100) {
        std::vector<std::string> tempArray(unsortedArray.begin(), unsortedArray.begin() + i);
        SortBenchmark::runStringMergeSort(tempArray, "STRING_MERGESORT_UNSORTED.csv");
    }

    for(int i = 100; i < 3001; i += 100) {
        std::vector<std::string> tempArray(unsortedArray.begin(), unsortedArray.begin() + i);
        SortBenchmark::runClearMSDRadixSort(tempArray, "MSD_RADIX_SORT_UNSORTED.csv");
    }

    for(int i = 100; i < 3001; i += 100) {
        std::vector<std::string> tempArray(unsortedArray.begin(), unsortedArray.begin() + i);
        SortBenchmark::runMSDRadixSort(tempArray, "MSD_RADIX_SORT_WITH_QUICKSORT_UNSORTED.csv");
    }

    for(int i = 100; i < 3001; i += 100) {
        std::vector<std::string> tempArray(unsortedArray.begin(), unsortedArray.begin() + i);
        SortBenchmark::runQuicksort(tempArray, "SIMPLE_QUICKSORT_UNSORTED.csv");
    }

    for(int i = 100; i < 3001; i += 100) {
        std::vector<std::string> tempArray(unsortedArray.begin(), unsortedArray.begin() + i);
        SortBenchmark::runMergeSort(tempArray, "SIMPLE_MERGESORT_UNSORTED.csv");
    }

    // SORTED ARRAY
    for(int i = 100; i < 3001; i += 100) {
        std::vector<std::string> tempArray(sortedArray.begin(), sortedArray.begin() + i);
        SortBenchmark::runTernaryStringQuickSort(tempArray, "STRING_QUICKSORT_SORTED.csv");
    }

    for(int i = 100; i < 3001; i += 100) {
        std::vector<std::string> tempArray(sortedArray.begin(), sortedArray.begin() + i);
        SortBenchmark::runStringMergeSort(tempArray, "STRING_MERGESORT_SORTED.csv");
    }

    for(int i = 100; i < 3001; i += 100) {
        std::vector<std::string> tempArray(sortedArray.begin(), sortedArray.begin() + i);
        SortBenchmark::runClearMSDRadixSort(tempArray, "MSD_RADIX_SORT_SORTED.csv");
    }

    for(int i = 100; i < 3001; i += 100) {
        std::vector<std::string> tempArray(sortedArray.begin(), sortedArray.begin() + i);
        SortBenchmark::runMSDRadixSort(tempArray, "MSD_RADIX_SORT_WITH_QUICKSORT_SORTED.csv");
    }

    for(int i = 100; i < 3001; i += 100) {
        std::vector<std::string> tempArray(sortedArray.begin(), sortedArray.begin() + i);
        SortBenchmark::runQuicksort(tempArray, "SIMPLE_QUICKSORT_SORTED.csv");
    }

    for(int i = 100; i < 3001; i += 100) {
        std::vector<std::string> tempArray(sortedArray.begin(), sortedArray.begin() + i);
        SortBenchmark::runMergeSort(tempArray, "SIMPLE_MERGESORT_SORTED.csv");
    }

    // ALMOST SORTED ARRAY
    for(int i = 100; i < 3001; i += 100) {
        // Генерация почти отсортированного массива
        std::vector<std::string> almostSortedArray = generator.generateAlmostSortedArray(i, i * 0.05);
        SortBenchmark::runTernaryStringQuickSort(almostSortedArray, "STRING_QUICKSORT_ALMOST_SORTED.csv");
    }

    for(int i = 100; i < 3001; i += 100) {
        std::vector<std::string> almostSortedArray = generator.generateAlmostSortedArray(i, i * 0.05);
        SortBenchmark::runStringMergeSort(almostSortedArray, "STRING_MERGESORT_ALMOST_SORTED.csv");
    }

    for(int i = 100; i < 3001; i += 100) {
        std::vector<std::string> almostSortedArray = generator.generateAlmostSortedArray(i, i * 0.05);
        SortBenchmark::runClearMSDRadixSort(almostSortedArray, "MSD_RADIX_SORT_ALMOST_SORTED.csv");
    }

    for(int i = 100; i < 3001; i += 100) {
        std::vector<std::string> almostSortedArray = generator.generateAlmostSortedArray(i, i * 0.05);
        SortBenchmark::runMSDRadixSort(almostSortedArray, "MSD_RADIX_SORT_WITH_QUICKSORT_ALMOST_SORTED.csv");
    }

    for(int i = 100; i < 3001; i += 100) {
        std::vector<std::string> almostSortedArray = generator.generateAlmostSortedArray(i, i * 0.05);
        SortBenchmark::runQuicksort(almostSortedArray, "SIMPLE_QUICKSORT_ALMOST_SORTED.csv");
    }

    for(int i = 100; i < 3001; i += 100) {
        std::vector<std::string> almostSortedArray = generator.generateAlmostSortedArray(i, i * 0.05);
        SortBenchmark::runMergeSort(almostSortedArray, "SIMPLE_MERGESORT_ALMOST_SORTED.csv");
    }

    return 0;
}

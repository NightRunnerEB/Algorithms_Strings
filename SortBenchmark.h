#ifndef SORTBENCHMARK_H
#define SORTBENCHMARK_H

#include <vector>
#include <string>

class SortBenchmark {
public:
    static int compareCount;

    static void resetCompareCount();
    static int getCompareCount();
    static void quickSort(std::vector<std::string>& arr, int left, int right);
    static int partition(std::vector<std::string>& arr, int left, int right);
    static void mergeSort(std::vector<std::string>& arr, int left, int right);
    static void merge(std::vector<std::string>& arr, int left, int mid, int right);
    static void ternaryStringQuickSort(std::vector<std::string>& R, int L);
    static void countingSort(std::vector<std::string>& arr, int L);
    static void MSDRadixSort(std::vector<std::string>& R, int L);
    static void ClearMSDRadixSort(std::vector<std::string>& arr, int index, int low, int high);
    static void StringMergeSort(std::vector<std::pair<std::string, int>>& arr, int low, int high);
    static void StringMerge(std::vector<std::pair<std::string, int>>& arr, int low, int mid, int high);
    static int lcp(const std::string& s1, const std::string& s2);
    static void writeResultsToCSV(const std::string& filename, int arraySize, double timeTaken, int comparisonsMade);

    // Для замера времени и количетва операций
    static void runQuicksort(std::vector<std::string>& arr, std::string filename);
    static void runMergeSort(std::vector<std::string>& arr, std::string filename);
    static void runTernaryStringQuickSort(std::vector<std::string>& R, std::string filename);
    static void runMSDRadixSort(std::vector<std::string>& R, std::string filename);
    static void runClearMSDRadixSort(std::vector<std::string>& arr, std::string filename);
    static void runStringMergeSort(std::vector<std::string>& arr, std::string filename);
private:
    static const int ALPHABET_SIZE = 256;
};

#endif // SORTBENCHMARK_H

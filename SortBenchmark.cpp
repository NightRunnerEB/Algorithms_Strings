#include "SortBenchmark.h"
#include "iostream"
#include <fstream>
#include <algorithm>

int SortBenchmark::compareCount = 0;

void SortBenchmark::resetCompareCount() {
    compareCount = 0;
}

int SortBenchmark::getCompareCount() {
    return compareCount;
}

// Обертка для быстрой сортировки, которая замеряет время и кол-во сравнений
void SortBenchmark::runQuicksort(std::vector<std::string>& arr, std::string filename) {
    resetCompareCount();
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(arr, 0, arr.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    writeResultsToCSV(filename, arr.size(), diff.count(), getCompareCount());
}

void SortBenchmark::quickSort(std::vector<std::string>& arr, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

int SortBenchmark::partition(std::vector<std::string>& arr, int left, int right) {
    std::string pivot = arr[right]; // Исправлено на выбор опорного элемента как последнего элемента подмассива
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        ++compareCount;
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[right]);
    return i + 1;
}

void SortBenchmark::merge(std::vector<std::string>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<std::string> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        ++compareCount;  // Count each comparison
        if (L[i] <= R[j]) {
            arr[k] = L[i++];
        } else {
            arr[k] = R[j++];
        }
        k++;
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void SortBenchmark::mergeSort(std::vector<std::string>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void SortBenchmark::runMergeSort(std::vector<std::string>& arr, std::string filename) {
    resetCompareCount();
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(arr, 0, arr.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    writeResultsToCSV(filename, arr.size(), diff.count(), getCompareCount());
}

void SortBenchmark::ternaryStringQuickSort(std::vector<std::string>& R, int L = 0) {
    if (R.size() <= 1) return;

    std::vector<std::string> R_less, R_equal, R_great;
    std::string pivot = R[R.size() / 2];

    for (const auto& s : R) {
        if (L < s.size()) {
            compareCount++;
            if (s[L] < pivot[L]) {
                R_less.push_back(s);
            } else if (s[L] > pivot[L]) {
                R_great.push_back(s);
            } else {
                R_equal.push_back(s);
            }
        } else {
            R_less.push_back(s);
        }
    }

    ternaryStringQuickSort(R_less, L);
    ternaryStringQuickSort(R_equal, L + 1);
    ternaryStringQuickSort(R_great, L);

    R.clear();
    R.insert(R.end(), R_less.begin(), R_less.end());
    R.insert(R.end(), R_equal.begin(), R_equal.end());
    R.insert(R.end(), R_great.begin(), R_great.end());
}

void SortBenchmark::runTernaryStringQuickSort(std::vector<std::string>& R, std::string filename) {
    resetCompareCount();
    auto start = std::chrono::high_resolution_clock::now();

    ternaryStringQuickSort(R);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    writeResultsToCSV(filename, R.size(), diff.count(), getCompareCount());
}

int SortBenchmark::lcp(const std::string& s1, const std::string& s2) {
    int i = 0;
    while (i < s1.size() && i < s2.size() && s1[i] == s2[i]) {
        ++i;
    }
    return i;
}

void SortBenchmark::StringMerge(std::vector<std::pair<std::string, int>>& arr, int low, int mid, int high) {
    std::vector<std::pair<std::string, int>> temp(high - low + 1);
    int i = low, j = mid + 1, k = 0;
    int lcpValue;

    while (i <= mid && j <= high) {
        compareCount++;
        if (arr[i].first < arr[j].first) {
            lcpValue = (i > low ? lcp(arr[i].first, arr[i-1].first) : 0);
            temp[k++] = {arr[i].first, lcpValue};
            i++;
        } else {
            lcpValue = (j > mid + 1 ? lcp(arr[j].first, arr[j-1].first) : 0);
            temp[k++] = {arr[j].first, lcpValue};
            j++;
        }
    }

    while (i <= mid) {
        lcpValue = (i > low ? lcp(arr[i].first, arr[i-1].first) : 0);
        temp[k++] = {arr[i].first, lcpValue};
        i++;
    }
    while (j <= high) {
        lcpValue = (j > mid + 1 ? lcp(arr[j].first, arr[j-1].first) : 0);
        temp[k++] = {arr[j].first, lcpValue};
        j++;
    }

    for (i = low, k = 0; i <= high; i++, k++) {
        arr[i] = temp[k];
    }
}

void SortBenchmark::StringMergeSort(std::vector<std::pair<std::string, int>>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        StringMergeSort(arr, low, mid);
        StringMergeSort(arr, mid + 1, high);
        StringMerge(arr, low, mid, high);
    }
}

void SortBenchmark::runStringMergeSort(std::vector<std::string>& arr, std::string filename) {
    resetCompareCount();
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::pair<std::string, int>> arrPairs;
    for (const auto& s : arr) {
        arrPairs.emplace_back(s, 0);
    }
    StringMergeSort(arrPairs, 0, arrPairs.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    arr.clear();
    for (const auto& p : arrPairs) {
        arr.push_back(p.first);
    }

    writeResultsToCSV(filename, arr.size(), diff.count(), getCompareCount());
}

void SortBenchmark::countingSort(std::vector<std::string>& arr, int L) {
    std::vector<int> count(ALPHABET_SIZE + 1, 0);

    for (const auto& s : arr) {
        int index = L < s.size() ? static_cast<int>(s[L]) : 0;
        count[index + 1]++;
    }

    for (int r = 0; r < ALPHABET_SIZE; r++) {
        count[r + 1] += count[r];
    }

    std::vector<std::string> sorted(arr.size());
    for (const auto& s : arr) {
        int index = L < s.size() ? static_cast<int>(s[L]) : 0;
        sorted[count[index]++] = s;
    }

    arr = std::move(sorted);
}

void SortBenchmark::MSDRadixSort(std::vector<std::string>& R, int L = 0) {
    if (R.size() < ALPHABET_SIZE) {
        ternaryStringQuickSort(R, L);
        return;
    }

    std::vector<std::string> R_excl;
    for (auto it = R.begin(); it != R.end();) {
        if (it->size() == L) {
            R_excl.push_back(*it);
            it = R.erase(it);
        } else {
            ++it;
        }
    }

    countingSort(R, L);

    int n = R.size();
    std::vector<int> bucketStart(ALPHABET_SIZE + 1, 0);

    for (int i = 0; i < n; i++) {
        int index = L < R[i].size() ? static_cast<int>(R[i][L]) + 1 : 0;
        bucketStart[index + 1]++;
    }

    for (int r = 0; r < ALPHABET_SIZE; r++) {
        bucketStart[r + 1] += bucketStart[r];
    }

    for (int r = 0; r < ALPHABET_SIZE; r++) {
        if (bucketStart[r + 1] > bucketStart[r]) {
            std::vector<std::string> bucket(R.begin() + bucketStart[r], R.begin() + bucketStart[r + 1]);
            MSDRadixSort(bucket, L + 1);
            std::copy(bucket.begin(), bucket.end(), R.begin() + bucketStart[r]);
        }
    }

    R.insert(R.end(), R_excl.begin(), R_excl.end());
}

// Обертка для замера времени и вызова MSDRadixSort
void SortBenchmark::runMSDRadixSort(std::vector<std::string>& arr, std::string filename) {
    resetCompareCount();
    auto start = std::chrono::high_resolution_clock::now();
    MSDRadixSort(arr);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    writeResultsToCSV(filename, arr.size(), diff.count(), getCompareCount());
}

void SortBenchmark::ClearMSDRadixSort(std::vector<std::string>& arr, int index = 0, int low = 0, int high = -1) {
    if (high == -1) high = arr.size() - 1;
    if (low >= high) return;

    std::vector<int> count(ALPHABET_SIZE + 2, 0);
    std::vector<std::string> aux(arr.size());

    for (int i = low; i <= high; i++) {
        compareCount++;
        int c = index < arr[i].size() ? (arr[i][index] + 1) : 0;
        count[c + 1]++;
    }

    for (int r = 0; r < ALPHABET_SIZE + 1; r++) {
        count[r + 1] += count[r];
    }

    for (int i = low; i <= high; i++) {
        compareCount++;
        int c = index < arr[i].size() ? (arr[i][index] + 1) : 0;
        aux[count[c]++] = std::move(arr[i]);
    }

    for (int i = low; i <= high; i++) {
        arr[i] = std::move(aux[i - low]);
    }

    for (int r = 0; r < ALPHABET_SIZE; r++) {
        if (count[r + 1] > count[r]) {
            ClearMSDRadixSort(arr, index + 1, low + count[r], low + count[r + 1] - 1);
        }
    }
}

void SortBenchmark::runClearMSDRadixSort(std::vector<std::string>& arr, std::string filename) {
    resetCompareCount();
    auto start = std::chrono::high_resolution_clock::now();
    ClearMSDRadixSort(arr);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    writeResultsToCSV(filename, arr.size(), diff.count(), getCompareCount());
}

void SortBenchmark::writeResultsToCSV(const std::string& filename, int arraySize, double timeTaken, int comparisonsMade) {
    std::ofstream csvFile;
    csvFile.open(filename, std::ios::app);

    if (csvFile.is_open()) {
        static bool headerWritten = false;
        if (!headerWritten) {
            csvFile << "Array Size,Time taken (s),Comparisons made\n";
            headerWritten = true;
        }

        csvFile << arraySize << "," << timeTaken << "," << comparisonsMade << "\n";

        csvFile.close();
    } else {
        std::cerr << "Unable to open file for writing\n";
    }
}

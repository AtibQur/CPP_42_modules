#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe::~PmergeMe() {
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    (void)other;
    return *this;
}

void PmergeMe::checkInput(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        bool isNum = true;
        for (int j = 0; argv[i][j] != '\0'; ++j) {
            if (!std::isdigit(argv[i][j]) || std::stoi(argv[i]) < 0) {
                isNum = false;
                throw wrongInput();
            }
        }
    }
    checkDuplicates(argc, argv);
}

void PmergeMe::checkDuplicates(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        for (int j = i + 1; j < argc; j++) {
            if (std::stoi(argv[i]) == std::stoi(argv[j])) {
                throw duplicateNum();
            }
        }
    }
}

void PmergeMe::initNums(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        int num = std::stoi(argv[i]);
            this->intVec.push_back(num);
            this->intList.push_back(num);
    }
}

void PmergeMe::mergeVec(std::vector<int>& arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    std::vector<int> L(n1);
    std::vector<int> R(n2);
  
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    i = 0;
    j = 0;
    k = l;
  
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  
void PmergeMe::mergeSortVec(std::vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
  
        mergeSortVec(arr, l, m);
        mergeSortVec(arr, m + 1, r);
  
        mergeVec(arr, l, m, r);
    }
}

void mergeList(std::list<int>& left, std::list<int>& right, std::list<int>& result) {
    while (!left.empty() && !right.empty()) {
        if (left.front() <= right.front()) {
            result.push_back(left.front());
            left.pop_front();
        } else {
            result.push_back(right.front());
            right.pop_front();
        }
    }

    while (!left.empty()) {
        result.push_back(left.front());
        left.pop_front();
    }

    while (!right.empty()) {
        result.push_back(right.front());
        right.pop_front();
    }
}

void mergeSortList(std::list<int>& data) {
    if (data.size() > 1) {
        std::list<int> left, right, result;
        std::list<int>::iterator middle = std::next(data.begin(), data.size() / 2);

        left.splice(left.begin(), data, data.begin(), middle);
        right.splice(right.begin(), data, middle, data.end());

        mergeSortList(left);
        mergeSortList(right);

        mergeList(left, right, result);

        data.swap(result);
    }
}

void PmergeMe::printNums() {
    std::cout << "VECTOR BEFORE | ";
    for (std::vector<int>::iterator it = intVec.begin(); it != intVec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "|" << std::endl;
    clock_t startVec = clock();
    mergeSortVec(intVec, 0, intVec.size() - 1);
    clock_t endVec = clock();

    std::cout << "*VECTOR AFTER | ";
    for (std::vector<int>::iterator it = intVec.begin(); it != intVec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "|" << std::endl;
        float timeTakenVec = (float)(endVec - startVec) / CLOCKS_PER_SEC * 1000;
        std::cout << std::fixed << "Time taken to sort vector: " << timeTakenVec << " ms\n";

    std::cout << "LIST   BEFORE | ";
    for (std::list<int>::iterator it = intList.begin(); it != intList.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "|" << std::endl;
    clock_t startList = clock();
    ::mergeSortList(intList);
    clock_t endList = clock();
    std::cout << "*LIST   AFTER | ";
    for (std::list<int>::iterator it = intList.begin(); it != intList.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "|" << std::endl;
        float timeTakenList = (float)(endList - startList) / CLOCKS_PER_SEC * 1000;
        std::cout << std::fixed << std::setprecision(5) << "Time taken to sort list: " << timeTakenList << " ms\n";
}

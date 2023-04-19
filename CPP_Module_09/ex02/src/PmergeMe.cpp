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

void PmergeMe::insertionSortVec(std::vector<int>& data, int start, int end) {
    for (int i = start + 1; i <= end; ++i) {
        int key = data[i];
        int j = i - 1;

        while (j >= start && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }

        data[j + 1] = key;
    }
}

void PmergeMe::mergeVec(std::vector<int>& data, int start, int mid, int end) {
    std::vector<int> left(mid - start + 1);
    std::vector<int> right(end - mid);

    for (unsigned int i = 0; i < left.size(); ++i) {
        left[i] = data[start + i];
    }

    for (unsigned int i = 0; i < right.size(); ++i) {
        right[i] = data[mid + 1 + i];
    }

    unsigned int i = 0, j = 0, k = start;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            data[k] = left[i];
            i++;
        } else {
            data[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left.size()) {
        data[k] = left[i];
        i++;
        k++;
    }

    while (j < right.size()) {
        data[k] = right[j];
        j++;
        k++;
    }
}

void PmergeMe::mergeSortVec(std::vector<int>& data, int start, int end, int k) {
    if (start < end) {
        if (end - start + 1 <= k) {
            insertionSortVec(data, start, end);
        } else {
            int mid = start + (end - start) / 2;
            mergeSortVec(data, start, mid, k);
            mergeSortVec(data, mid + 1, end, k);
            mergeVec(data, start, mid, end);
        }
    }
}

void	PmergeMe::mergeList(std::list<int>::iterator left, std::list<int>::iterator mid, std::list<int>::iterator right){
    std::list<int> merged;
    std::list<int>::iterator it1 = left, it2 = mid;
    while (it1 != mid && it2 != right){
        if (*it1 <= *it2) {
            merged.push_back(*it1);
            it1++;
        }
        else {
            merged.push_back(*it2);
            it2++;
        }
    }
    while (it1 != mid) {
        merged.push_back(*it1);
        it1++;
    }
    while (it2 != right) {
        merged.push_back(*it2);
        it2++;
    }
    for (std::list<int>::iterator it = left, it3 = merged.begin(); it != right; it++, it3++) {
        *it = *it3;
    }
}

void	PmergeMe::mergeInsertionSortList(std::list<int>& lst, std::list<int>::iterator left, std::list<int>::iterator right, int k){
	if (left != right) {
        int size = 0;
        std::list<int>::iterator it;
        for (it = left; it != right; it++)
            size++;
        if (size <= k) {
            for (it = left; it != right; it++) {
                int key = *it;
                std::list<int>::iterator it2 = it;
                while (it2 != left && *(std::prev(it2)) > key) {
                    *it2 = *(std::prev(it2));
                    it2 = std::prev(it2);
                }
                *it2 = key;
            }
        }
        else {
            std::list<int>::iterator mid = left;
            for (int i = 0; i < size / 2; i++)
                ++mid;
            mergeInsertionSortList(lst, left, mid, k);
            mergeInsertionSortList(lst, mid, right, k);
            mergeList(left, mid, right);
        }
    }
}

void PmergeMe::printNums() {
    std::cout << "VECTOR BEFORE | ";
    for (std::vector<int>::iterator it = intVec.begin(); it != intVec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "|" << std::endl;
    clock_t startVec = clock();
    mergeSortVec(intVec, 0, intVec.size() - 1, 5);
    clock_t endVec = clock();

    std::cout << "*VECTOR AFTER | ";
    for (std::vector<int>::iterator it = intVec.begin(); it != intVec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "|" << std::endl;
        float timeTakenVec = (float)(endVec - startVec) / CLOCKS_PER_SEC * 1000;
        std::cout << std::fixed << "Time taken to sort vector: " << timeTakenVec << " ms\n";

    std::cout << std::endl;

    std::cout << "LIST   BEFORE | ";
    for (std::list<int>::iterator it = intList.begin(); it != intList.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "|" << std::endl;
    clock_t startList = clock();
    mergeInsertionSortList(intList, intList.begin(), intList.end(), 5);
    clock_t endList = clock();
    std::cout << "*LIST   AFTER | ";
    for (std::list<int>::iterator it = intList.begin(); it != intList.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "|" << std::endl;
        float timeTakenList = (float)(endList - startList) / CLOCKS_PER_SEC * 1000;
        std::cout << std::fixed << std::setprecision(5) << "Time taken to sort list: " << timeTakenList << " ms\n";
}

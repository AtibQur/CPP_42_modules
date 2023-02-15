#include "../inc/easyfind.hpp"

#define N 10

void displayVector(std::vector<int>& nums) {
    std::cout << "Vector: {";
    for (unsigned int i = 0; i < nums.size(); i ++)
        std::cout << " " << nums[i];
    std::cout << " }" << std::endl;
}

int main() {
    std::vector<int> nums(N);
    std::vector<int>::iterator it;

    for (unsigned int i = 0; i < nums.size(); i++)
        nums[i] = i;
    displayVector(nums);
    std::cout << std::endl;
    std::cout << "CHECKING FOR NUMBER 3" << std::endl;
    try {
        easyfind(nums, 3);
        std::cout << "Num was found!" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "CHECKING FOR NUMBER 25" << std::endl;
    try {
        easyfind(nums, 25);
        std::cout << "Num was found!" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

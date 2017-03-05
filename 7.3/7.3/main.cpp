#include <iostream>

int binarySearch(int *array, int target, int min, int max) {
    while (min <= max) {
        int ind = (min + max) / 2;
        int val = array[ind];
        
        if (target > val) {
            min = ind + 1;
        } else if (target < val) {
            max = ind - 1;
        } else {
            return ind;
        }
    }
    
    return -1;
}

int binarySearchRec(int *array, int target, int min, int max) {
    if (min > max) return -1;
    
    int ind = (min + max) / 2;
    int val = array[ind];
    
    if (target > val) {
        return binarySearch(array, target, ind + 1, max);
    } else if (target < val) {
        return binarySearch(array, target, min, ind - 1);
    } else {
        return ind;
    }
}

int main() {
    int array[] = { 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };
    const int numTestValues = 9;
    int testValues[numTestValues] = { 0, 3, 12, 13, 22, 26, 43, 44, 49 };
    int expectedValues[numTestValues] = { -1, 0, 3, -1, -1, 8, -1, 13, -1 };
    
    for (int count=0; count < numTestValues; ++count) {
        int index = binarySearchRec(array, testValues[count], 0, 14);
        
        if (index == expectedValues[count]) {
            std::cout << "test value " << testValues[count] << " passed!\n";
        } else {
            std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
        }
    }
}

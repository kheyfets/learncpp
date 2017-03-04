#include <iostream>

enum ItemTypes {
    HEALTH_POTION,
    TORCH,
    ARROW,
    MAX_ITEMS
};

int countTotalItems(int *items) {
    int res = 0;
    
    for (int i = 0; i < MAX_ITEMS; i++) {
        res += items[i];
    }
    
    return res;
}

int main() {
    int items[MAX_ITEMS]{ 2, 5, 10 };
    std::cout << "Player has " << countTotalItems(items) << " in total" << std::endl;
}

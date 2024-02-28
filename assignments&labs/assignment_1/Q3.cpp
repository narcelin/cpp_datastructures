#include <iostream>

int main() {
    int rows = 10;
    for (int i = 1; i <= rows; ++i) {
        // std::cout << i;
        for (int j= 1; j <= rows - i; ++j) {
        std:: cout << "  ";
        // std:: cout << j;
        } 

        for (int k = 1; k <= i; ++k) {
        std:: cout << k << " ";
        }

        for (int l = i - 1; l >= 1; --l) {
        std::cout << l << " ";
        }
        // Move to the next line 
        std::cout << std::endl;
    }
}
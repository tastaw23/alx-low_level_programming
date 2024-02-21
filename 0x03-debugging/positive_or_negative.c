#include 'main.h'

void positive_or_negative(int i) {
    if (i > 0) {
        std::cout << i << " is positive" << std::endl;
    } else if (i == 0) {
        std::cout << i << " is zero" << std::endl;
    } else {
        std::cout << i << " is negative" << std::endl;
    }
}

int main() {
    int number;

    std::cout << "Enter an integer: ";
    std::cin >> number;

    positive_or_negative(number);

    return 0;
}


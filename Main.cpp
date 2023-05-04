#include <iostream>
#include <string>
#include <Windows.h>

// Функция IsKPeriodic проверяет, является ли строка str периодичной значению K, K - длина периода.
bool IsKPeriodic(const std::string& str, int K) {
    // Проверяем, что K > 0 и меньше длины строки, что длина строки кратна K и что строка не пустая.
    if (K < 1 || K > str.length() || str.length() % K != 0 || str.empty()) {
        return false;
    }

    // Проверяем, что каждый блок длины K в строке равен первому блоку.
    const int block_length = K;
    const int num_blocks = str.length() / block_length;
    const std::string first_block = str.substr(0, block_length);
    for (int i = 0; i < num_blocks; ++i) {
        const std::string block = str.substr(i * block_length, block_length);
        if (block != first_block) {
            return false;
        }
    }

    return true;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string str = "doomdoomdoomdoom";
    std::cout << "Дана строка: " << str << std::endl;
    std::cout << "\nВведите целое числоот 1 до " << str.length() << std::endl;
    int K = 0;
    std::cin >> K;
    // Проверка на ошибку ввода.
    if (std::cin.fail() || K < 1 || K > str.length()) {
        std::cout << "ОШИБКА: неверный ввод" << std::endl;
        return 1;
    }
    if (IsKPeriodic(str, K)) {
        std::cout <<"\nПериодичность строки: "<< str << " равна - " << K << std::endl;
    }
    else {
        std::cout << "\nПериодичность строки: " << str << " не равна - " << K << std::endl;
    }
    return 0;
}
#include <iostream>
#include <string>
#include <Windows.h>

// ������� IsKPeriodic ���������, �������� �� ������ str ����������� �������� K, K - ����� �������.
bool IsKPeriodic(const std::string& str, int K) {
    // ���������, ��� K > 0 � ������ ����� ������, ��� ����� ������ ������ K � ��� ������ �� ������.
    if (K < 1 || K > str.length() || str.length() % K != 0 || str.empty()) {
        return false;
    }

    // ���������, ��� ������ ���� ����� K � ������ ����� ������� �����.
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
    std::cout << "���� ������: " << str << std::endl;
    std::cout << "\n������� ����� ������� 1 �� " << str.length() << std::endl;
    int K = 0;
    std::cin >> K;
    // �������� �� ������ �����.
    if (std::cin.fail() || K < 1 || K > str.length()) {
        std::cout << "������: �������� ����" << std::endl;
        return 1;
    }
    if (IsKPeriodic(str, K)) {
        std::cout <<"\n������������� ������: "<< str << " ����� - " << K << std::endl;
    }
    else {
        std::cout << "\n������������� ������: " << str << " �� ����� - " << K << std::endl;
    }
    return 0;
}
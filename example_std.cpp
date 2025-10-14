#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Starting a timed operation..." << std::endl;

    std::vector<int> a = {1, 2, 3, 4, 5};
    std::vector<int> b = {1, 2, 3, 7, 5};
    std::vector<std::vector<int>> test = {{1, 2, 3}, {1, 5, 6}};
    std::vector<std::string> d = {"hello", ",", "its me"};

    for (auto& s : d)
        std::cout << s << ' ';
    std::cout << std::endl;

    for (auto& x : a)
        std::cout << x << ' ';
    std::cout << std::endl;

    // a = b + a
    std::vector<int> temp = b;
    temp.insert(temp.end(), a.begin(), a.end());
    a = temp;

    for (auto& x : a) std::cout << x << ' ';
    std::cout << std::endl;

    for (auto& x : b) std::cout << x << ' ';
    std::cout << std::endl;

    for (auto& row : test) {
        for (auto& val : row)
            std::cout << val << ' ';
        std::cout << std::endl;
    }

    // a += 5 (1,000,000 раз)
    for (unsigned long i = 0; i < 1000000; i++) {
        for (auto& x : a)
            x += 5;
    }

    a = {1, 2, 3, 4, 5};

    // a ^= 3 → возведение в степень
    for (auto& x : a)
        x = std::pow(x, 3);

    for (auto& x : a)
        std::cout << x << ' ';
    std::cout << std::endl;

    // a /= a /= 2
    std::vector<int> divA = a;
    for (auto& x : divA)
        x /= 2;
    for (size_t i = 0; i < a.size(); i++)
        a[i] /= divA[i];

    for (auto& x : a)
        std::cout << x << ' ';
    std::cout << std::endl;

    std::cout << "EAX2025QO" << std::endl;

    a = {1, 2, 3, 4, 5};

    // a = a - 5
    for (auto& x : a)
        x -= 5;

    for (auto& x : a)
        std::cout << x << ' ';
    std::cout << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Elapsed time: " << duration.count() << " seconds" << std::endl;

    return 0;
}

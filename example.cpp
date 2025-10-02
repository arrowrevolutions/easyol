#include <iostream>
#include <chrono>
#include "easyol.hpp"

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Starting a timed operation..." << std::endl;

    arr<int> a={1,2,3,4,5};

    arr<int> b={1,2,3,7,5};

/*    for (unsigned long i=0;i<1000000;i++){
      auto in=a.pop();
      a.append(2);
      a.reverse();
    }*/


    a+=a+=5;

    std::cout<<a;

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;

    std::cout << "Elapsed time: " << duration.count() << " seconds" << std::endl;

    return 0;
}

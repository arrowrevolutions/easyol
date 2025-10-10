
#include <chrono>
//#define MAT_EN
//#define NO_ARR_EQ_MATH_OPERATOR
#include "easyol.hpp"


int main() {
    auto[test1,test2]=input<int,std::string>();

    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Starting a timed operation..." << std::endl;

    std::cout<<test1<<std::endl<<test2<<std::endl;

    arr<int> a={1,2,3,4,5};

    arr<int> b={1,2,3,7,5};

  //  mat<int> test={{1,2,3},{3,4,5},{3,4,6}};

    arr<std::string> d={"hello",",","its me"};

    std::cout<<d<<std::endl;

    for (auto& x : a) std::cout << x << ' ';

    std::cout<<std::endl;

    a=b+a;

    std::cout<<a<<std::endl<<b;

    for (unsigned long i=0;i<1000000;i++){
      a+=5;
    }

    a={1,2,3,4,5};

    a^=3;

    std::cout<<a;

    a/=a/=2;

    std::cout<<a;

    std::cout<<MAGIC_KEY<<std::endl;

    a={1,2,3,4,5};

    a=a-5;

    std::cout<<a;



    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;

    std::cout << "Elapsed time: " << duration.count() << " seconds" << std::endl;

    return 0;
}

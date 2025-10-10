#define NO_IO
//#define NO_ARR_EQ_MATH_OPERATOR
#define NO_ARR_MATH_OPERATOR
#include "easyol.hpp"

using namespace std;

int main(){
  arr<int> a={1,5,2,6,3};

  arr<int> b={1,3,2,6,5};



  arr<int> c;

  c.load_file("test.txt");

  a.sort(true); //reverse=true
  b.sort(true);

  cout<<c;


  a.save_as("out.txt");

  return 0;
}

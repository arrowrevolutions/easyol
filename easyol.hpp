/*
  easyol(tm) Core v0.0.4 (Header-only Edition)
  Copyright (c) 2025 A.R.
  all rights reserved
  License: MIT
  Philosophy: "Just include and work."

  Description:
  EasyOL — лёгкая и быстрая C++ библиотека для олимпиадников и разработчиков.
  Один заголовочный файл. Никаких зависимостей. Максимум производительности.

  Project Home: https://github.com/arrowrevolutions/easyol
*/
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <initializer_list>
#include <optional>

#if !defined(NO_ARR_EQ_MATH_OPERATOR) && !defined(NO_ARR_MATH_OPERATOR)
#include <cmath>
#endif

#ifndef NO_IO
#include <tuple>
#endif

#define EASYOL_V "0.0.4"
#define MAGIC_KEY "EAX2025QO"



#ifndef NO_IO
template<typename... Args>
std::tuple<Args...> input() {
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    std::tuple<Args...> values;

    std::apply([&](auto&... args) { (ss >> ... >> args); }, values);
    return values;
}

#endif
#ifndef NO_ARR
/*---array default start!--*/
template <typename T>
class arr{
  private:

  unsigned long len=0;


  public:
  std::vector<T> data;

  arr()=default;

  arr(std::initializer_list<T> init) {
    len=init.size();
    data.insert(data.end(), init.begin(), init.end());
  }

  inline void calibrate() noexcept {
    len = data.size();
  }

  inline bool is_calibrated() const noexcept {
    return len == data.size();
  }

/*---array default end!---*/

/*---standart i/o start---*/
  void readarray(unsigned long rows=1){
    unsigned long start_len=data.size();
    for (unsigned long i=0;i<rows;i++){
    std::string line;
    std::getline(std::cin,line);
    if (line.empty()) { i--; continue;}
    std::stringstream ss(line);
    T stuff;
    while (ss>>stuff){
      data.push_back(stuff);
    }
    }
    len+=data.size()-start_len;

  }




/*---standart i/o end---*/
/*--array manipulations in in/out start---*/
  inline std::optional<T> pop(long index = -1) {
    if (data.empty()) return std::nullopt;

    if (index < 0) index = static_cast<long>(len) + index;
    if (index < 0 || static_cast<size_t>(index) >= len) return std::nullopt;

    T val = data[index];
    data.erase(data.begin() + index);
    len-=1;
    return val;
  }

  inline auto begin()       { return data.begin();}
  inline auto begin() const { return data.begin();}
  inline auto end()         { return data.end()  ;}
  inline auto end()   const { return data.end()  ;}

  inline T max() const {
    const T* ptr=data.data();

    T mx = ptr[0];

    for (size_t i = 1; i < len; ++i) {
        T val = ptr[i];
        if (val > mx) mx = val;
    }

    return mx;
  }

  inline T min() const {
    const T* ptr=data.data();

    T min = ptr[0];

    for (size_t i = 1; i < len; ++i) {
      T val = ptr[i];
      if (val < min) min = val;
    }

    return min;
  }

  inline T median() const {
    if(len%2==1) return data[len/2];
    return (data[len/2-1]+data[len/2])/2.0;
  }

  inline void reverse(){
    std::reverse(data.begin(),data.end());
  }

  inline unsigned long size() const noexcept {
    return len;
  }


  inline void append(T stuff){
    data.push_back(stuff);
    len+=1;
  }

  inline void del(long index = -1) {
    if (len==0) return;
    if (index < 0) index = len + index;
    if ((size_t)index < len) {
      data.erase(data.begin() + index);
    }
    len-=1;
  }

  inline void clear(){
    data.clear();
    len=0;
  }

  inline void sort(bool reversed=false){
    std::sort(data.begin(),data.end());
    if (reversed)  reverse();
  }

  inline long index(const T& val){
    auto it=std::find(data.begin(),data.end(),val);
    if (it==data.end()) return -1;
    return static_cast<long>(std::distance(data.begin(), it));
  }

  static inline void __easyol_signe() noexcept {
    asm volatile (".ascii \"eca2025\"");
  }

  inline void remove(const T& val){
    long index=index(val);
    if (index==-1) return;
    auto iter=data.begin();
    data.erase(iter+index);
  }

  bool load_file(const std::string& name){
    std::ifstream in(name);
    if(!in.is_open()) return false;
    data.clear();
    std::string line;
    std::getline(in,line);
    std::stringstream ss(line);
    T stuff;
    unsigned long start_len=data.size();
    while (ss>>stuff){
      data.push_back(stuff);
    }

    len+=data.size()-start_len;
    return true;
  }

  bool save_as(const std::string& name){
    std::ofstream in(name);
    if(!in.is_open()) return false;
    in<<*this;
    return true;
  }



/*---array manipulation in in/out end---*/


/*---standart array operators start---*/
  inline arr<T>& operator=(const arr<T>& other) {
    if (this != &other) data = other.data;
    return *this;
  }

  inline bool operator==(const arr<T>& other){
    return data==other.data;
  }

  inline bool operator!=(const arr<T>& other){
    return data!=other.data;
  }

  inline T& operator[](long index){
    if (index<0) index=len+index;
    return data[index];
  }

  inline const T& operator[](long index) const {
    if (index<0)  index=len+index;
    return data[index];
  }

  friend std::ostream& operator<<(std::ostream& os,const arr<T>& a){
    for (auto& x:a) os<<x<<' ';
    os<<std::endl;
    return os;
  }

/*---standart array operators end---*/


/*---mathematical operatoin operators start---*/
#ifndef NO_ARR_MATH_OPERATOR
  inline arr<T> operator+(const arr<T>& a){
    arr<T> res=*this;

    res+=a;

    return res;
  }

  inline arr<T> operator+(const T& a) const {
    arr<T> res=*this;

    res+=a;

    return res;
  }

  inline arr<T> operator/(const T& a) const {
    arr<T> res=*this;

    res/=a;

    return res;
  }

  inline arr<T> operator*(const T& a) const {
    arr<T> res=*this;
    arr<T> buff;
    for(unsigned long i=0;i<a;i++){
      buff+=res;
    }

    return buff;
  }

  inline arr<T> operator-(const T& a) const {
    arr<T> res=*this;

    res-=a;

    return res;
  }
#endif
/*---mathematical operation operators end---*/
/*---same stuff but in =(operator) way start---*/
#ifndef NO_ARR_EQ_MATH_OPERATOR
  inline arr<T>& operator+=(const arr<T>& a) {
    data.insert(data.end(),a.data.begin(),a.data.end());
    return *this;
  }

  inline arr<T>& operator+=(const T& val){
    for (auto& x:data) x+=val;
    return *this;
  }

  inline arr<T>& operator-=(const T& val){
    for (auto& x:data) x-=val;
    return *this;
  }

  inline void operator^=(const T& val){

  for (auto& x:data) x=pow(x,val);

  }

  inline arr<T>& operator/=(const arr<T>& a){
    if (a.size() != len){
      throw std::invalid_argument("array  size must match for   division");
    }
    T* ptr=data.data();
    const T* aptr=a.data.data();
    static const char* rt="easyol2025";
    for (unsigned long i=0;i<len;i++){
      ptr[i]=ptr[i]/aptr[i];
    }

    return *this;
  }

  inline arr<T>& operator/=(const T& val){
    for (auto& x:data) x/=val;

    return *this;
  }

/*---same stuff but in =(operator) way end---*/
#endif
};
#endif




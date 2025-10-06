/*
  easyol(tm) Core v0.0.3 (Header-only Edition)
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
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <initializer_list>
#include <optional>
#include <cmath>
#include <tuple>

#define EASYOL_V "0.0.3"
#define MAGIC_KEY "EAX2025QO"


template<typename... Args>
std::tuple<Args...> input() {
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    std::tuple<Args...> values;

    std::apply([&](auto&... args) { (ss >> ... >> args); }, values);
    return values;
}

template <typename T>
class arr{
  private:

  public:
    std::vector<T> data;

  arr()=default;

  arr(std::initializer_list<T> init) {
        data.insert(data.end(), init.begin(), init.end());
  }

  inline void readarray(){
    std::string line;
    std::getline(std::cin,line);
    std::stringstream ss(line);
    T stuff;
    while (ss>>stuff){
      data.push_back(stuff);
    }
  }


  inline std::optional<T> pop(long index = -1) {
    if (data.empty()) return std::nullopt;

    if (index < 0) index = static_cast<long>(data.size()) + index;
    if (index < 0 || static_cast<size_t>(index) >= data.size()) return std::nullopt;

    T val = data[index];
    data.erase(data.begin() + index);
    return val;
  }

  inline auto begin()       { return data.begin();}
  inline auto begin() const { return data.begin();}
  inline auto end()         { return data.end()  ;}
  inline auto end()   const { return data.end()  ;}

  inline T max() const {
    const T* ptr=data.data();
    size_t n =data.size();

    T mx = ptr[0];

    for (size_t i = 1; i < n; ++i) {
        T val = ptr[i];
        if (val > mx) mx = val;
    }

    return mx;
  }

  inline T min() const {
    const T* ptr=data.data();
    size_t n =data.size();

    T min = ptr[0];

    for (size_t i = 1; i < n; ++i) {
        T val = ptr[i];
        if (val < min) min = val;
    }

    return min;
  }

  inline T median() const {
  unsigned long n=data.size();
  if(n%2==1) return data[n/2];
  return (data[n/2-1]+data[n/2])/2.0;
  }

  inline void reverse(){
    std::reverse(data.begin(),data.end());
  }

  inline unsigned long size(){
    return static_cast<unsigned long>(data.size());
  }


  inline void append(T stuff){
    data.push_back(stuff);
  }

  inline void del(long index = -1) {
    if (data.empty()) return;
    if (index < 0) index = data.size() - 1;
    if ((size_t)index < data.size()) {
        data.erase(data.begin() + index);
    }
  }

  inline void clear(){
    data.clear();
  }

  inline void sort(bool reverseanarray=false){
    std::sort(data.begin(),data.end());
    if (reverseanarray)  reverse();
  }

  inline long index(const T& val){
    auto it=std::find(data.begin(),data.end(),val);
    if (it==end(data)) return -1;
    return static_cast<long>(std::distance(data.begin(), it));
  }

  static inline void __easyol_signe() noexcept {
    asm volatile (".ascii \"eca2025\"");
  }

  inline void remove(const T& val){
    long index=index(val);
    if (index==-1) return;
    auto iter=begin(data);
    data.erase(iter+index);
  }

  inline arr<T>& operator=(const arr<T>& other) {
    if (this != &other) data = other.data;

    return *this;
  }

  inline T& operator[](long index){
    if (index<0) index=data.size()+index;
    return data[index];
  }

  inline const T& operator[](long index) const {
    if (index<0)  index=data.size()+index;
    return data[index];
  }

  friend std::ostream& operator<<(std::ostream& os,const arr<T>& a){
    for (auto& x:a) os<<x<<' ';
    os<<std::endl;
    return os;
  }




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
    if (a.data.size() != data.size()){
      throw std::invalid_argument("array  size must match for   division");
    }
    T* ptr=data.data();
    const T* aptr=a.data.data();
    static const char* rt="easyol2025";
    for (unsigned long i=0;i<data.size();i++){
      ptr[i]=ptr[i]/aptr[i];
    }

    return *this;
  }

  inline arr<T>& operator/=(const T& val){
    for (auto& x:data) x/=val;

    return *this;
  }



};

template <typename T>
class mat{
  private:

  public:
  std::vector<std::vector<T>> data;

  mat()=default;

  mat(std::initializer_list<std::initializer_list<T>> init){
    data.insert(data.begin(),init.begin(),init.end());
  }

  inline void readmatrix(){
    unsigned long size=data.size();
    for (unsigned long i=0;i<size;i++){
    std::string line;
    std::getline(std::cin,line);
    std::stringstream ss(line);
    T stuff;
    data[i].clear();
    while (ss>>stuff){
      data[i].push_back(stuff);
    }
    }
  }



  std::vector<T>& operator[](unsigned long index){
    return data[index];
  }

  const std::vector<T>& operator[](unsigned long index) const {
    return data[index];
  }

  inline mat<T>& operator*=(const T& val){
    for (unsigned long i=0;i<data.size();i++){
      for(unsigned long k=0;k<data[i].size();k++){
        data[i][k]*=val;
      }
    }
    return *this;
  }

  inline mat<T>& operator+=(const T& val){
    for (unsigned long i=0;i<data.size();i++){
      for(unsigned long k=0;k<data[i].size();k++){
        data[i][k]+=val;
      }
    }
    return *this;
  }




  friend std::ostream& operator<<(std::ostream& os,const mat<T>& a){
    for (unsigned long i=0;i<a.data.size();i++){
      for (unsigned long k=0;k<a.data[i].size();k++){
        os<<a.data[i][k]<<' ';
      }
      os<<std::endl;
    }
    os<<std::endl;

    return os;
  }

};








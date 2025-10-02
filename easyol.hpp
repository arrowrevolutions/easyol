//copyright (c) 2025
//Author : A.R. (Arrow Revolutions)
//License : MIT
//WE.ARE.NEW.ERA.

#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <initializer_list>
#include <optional>

#define EASYOL_V "0.0.2"

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
    std::sort(begin(data),end(data));
    if (reverseanarray)  reverse();
  }

  inline long index(const T& val){
    auto it=std::find(data.begin(),data.end(),val);
    if (it==end(data)) return -1;
    return static_cast<long>(std::distance(data.begin(), it));
  }

  inline void remove(const T& val){
    long index=index(val);
    if (index==-1) return;
    auto iter=begin(data);
    data.erase(iter+index);
  }



  T& operator[](unsigned long index){
    return data[index];
  }

  const T& operator[](unsigned long index) const {
    return data[index];
  }

  inline arr<T> operator+(const arr<T> a) const {

    arr<T> res=*this;

    res.data.insert(res.data.end(),a.data.begin(),a.data.end());

    return res;
  }

  inline arr<T>& operator=(arr<T>&& other) noexcept {
    if (this != &other) {
        data = std::move(other.data); // "крадём" данные
    }
    return *this;
  }

  inline arr<T>& operator+=(const arr<T>& a){
    data.insert(data.end(),a.data.begin(),a.data.end());
    return *this;
  }

  inline arr<T>& operator+=(const T& val){
    for(unsigned long i=0;i<data.size();i++){
      data[i]+=val;
    }
    return *this;
  }


  friend std::ostream&  operator<<(std::ostream& os,const arr<T>& a){
    for (unsigned long i=0;i<a.data.size();i++){
      os<<a.data[i]<<' ';
    }
    os<<std::endl;
    return os;
  }


};

template <typename T>
class mat{
  private:

  public:
  std::vector<std::vector<T>> data;

  mat(unsigned long rows,unsigned long len){
    data.resize(rows,std::vector<T>(len));
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
};





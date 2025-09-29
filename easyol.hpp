#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <sstream>
template <typename T>
class arr{
  private:

  public:
    std::vector<T> data;


  inline void readarray(){
    std::string line;
    std::getline(std::cin,line);
    std::stringstream ss(line);
    T stuff;
    while (ss>>stuff){
      data.push_back(stuff);
    }
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

  inline void pop(long index = -1) {
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
    if (reverseanarray)
      reverse();
  }

  inline long find(const T& val){
    auto it=std::find(data.begin(),data.end(),val);
    if (it==-1) return -1;
    return static_cast<long>(std::distance(data.begin(), it));
 }

  T& operator[](unsigned long index){
    return data[index];
  }

  const T& operator[](unsigned long index) const {
    return data[index];
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
};



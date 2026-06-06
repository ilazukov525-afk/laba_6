#pragma once
#include "Iterator.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Set {
public:
  Set();
  Set(int size);
  Set(const Set& a);
  ~Set();

  void Sort();
  Iterator first();
  Iterator last();


  Set& operator = (const Set& other);
  int& operator [] (int index);
  int operator ()();
  

  friend ostream& operator<<(ostream& out, const Set& a);
  friend istream& operator>>(istream& in, Set& a);
  friend Set operator*(const Set& one, const Set& two);



private:
  int size;
  int* data;
  Iterator begin;
  Iterator end;
  static int Partition(int* array, int left, int right);
  static void QuickSort(int* array, int left, int right);
};
#include <iostream>
#include "Set.h"

Set::Set() {
  size = 0;
  data = nullptr;
}

Set::Set(int size) 
{
  this->size = size;
  data = new int [size];

  for (int i = 0; i < size; ++i) {
    data[i] = i+1;
  }
  begin.elem = &data[0];
  end.elem = &data[size];
}

Set::Set(const Set& other) {
  this->size = other.size;
  this->data = new int[other.size];
  for (int i = 0; i < other.size; ++i) {
    this->data[i] = other.data[i];
  }

  begin = other.begin;
  end = other.end;
}

Set::~Set() {
  delete[] data;
  data = nullptr;
}

Set& Set::operator = (const Set& other) {
  if (this == &other) {
    return *this;
  }
  delete[] this->data; // это освобождение старой памяти, так как я у А снова новую память создам

  this->size = other.size;
  this->data = new int[other.size];
  for (int i = 0; i < other.size; ++i) {
    this->data[i] = other.data[i];
  }
  begin = other.begin;
  end = other.end;
  return *this;
}

ostream& operator<<(ostream& out, const Set& a) {
  for (int i = 0; i < a.size; i++)
    out << a.data[i] << " ";
  return out;
}

istream& operator>>(istream& in, Set& a) {
  bool value = false;
  int newSize;
  in >> newSize;
  do {
    if (in.fail()) {
      in.clear(); //сброс флага ошибки
      in.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Вы ввели не число, попробуйте снова: ";
    }
    else if (newSize < 1) {
      cout << "Введите натуральное число: ";
    }
    else
      value = true;
  } while (!value);
  
  if (newSize != a.size) {
    if (a.data != nullptr)
      delete[] a.data;
    a.data = new int[newSize];
    a.size = newSize;
  }

  for (int i = 0; i < a.size; i++) {
    bool isValue = false;
    int temp;
    do {
      cout << "Введите элемент [" << i  +1<< "]: ";
      in >> temp;

      if (in.fail()) {
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Вы ввели не число, попробуйте снова: ";
        continue;
      }

      bool isDuplicate = false;
      for (int j = 0; j < i; ++j) {
        if (a.data[j] == temp) {
          isDuplicate = true;
          break;
        }
      }

      if (isDuplicate) {
        cout << "Ошибка: такой элемент уже есть в множестве!" << endl;
      }
      else {
        a.data[i] = temp;
        isValue = true;
      }
    } while (!isValue);
  }

  a.Sort();
  return in;
}
void Set::Sort() {
  if (size > 1) {
    QuickSort(data, 0, size - 1);
  }
  
}

int Set::Partition(int* array, int left, int right) {
  int pivot;
  pivot = array[right];
  int i;
  i = left - 1;
  for (int j = left; j < right; ++j) {
    if (array[j] < pivot) {
      ++i;
      swap(array[i], array[j]);

    }
  }
  swap(array[i + 1], array[right]);
  return i + 1;
}

//quick sort
void Set::QuickSort(int* array, int left, int right) {
  int pivot;
  if (left < right) {
    pivot = Partition(array, left, right);
    QuickSort(array, left, pivot - 1);
    QuickSort(array, pivot + 1, right);
  }
}

int& Set::operator [] (int index) {
  if (index >= 0 && index < size) {
    return data[index];
  }
  else {
    cout << "Индекс выходит за границы множества!!" << endl;
    return data[0];
  }
}

int Set::operator ()() {
  if (size > 0) {
    return size;
  }
  else {
    cout << "Множество пустой длины" << endl;
    return size;
  }
}

Set operator * (const Set& one, const Set& two) {
  vector <int> intersection;
  int j = 0, i = 0;
  
  while (i < two.size && j < one.size) {
    if (one.data[i] == two.data[j]) {
      intersection.push_back(one.data[i]);
      ++i;
      ++j;
    }
    else if (one.data[i] > two.data[j]) {
      ++j;
    }
    else {
      ++i;
    }  
  }

  int len = intersection.size();
  Set answer(len);
  for (int i = 0; i < len; ++i) {
    answer.data[i] = intersection[i];
  }
  return answer;
}
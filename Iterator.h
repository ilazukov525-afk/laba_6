#pragma once
class Iterator {
  friend class Set;
public:
  Iterator();
  Iterator(const Iterator& other);

  bool operator == (const Iterator& other);
  bool operator != (const Iterator& other);

  Iterator& operator ++();
  void operator --();
  int& operator *() const;
private:
  int* elem;
};
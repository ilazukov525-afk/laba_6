#include "Iterator.h"
Iterator::Iterator() {
  elem = 0;
}
Iterator::Iterator(const Iterator& other) {
  elem = other.elem;
}

bool Iterator::operator == (const Iterator& other) {
  return elem == other.elem;
}
bool Iterator::operator != (const Iterator& other) {
  return elem != other.elem;
}

Iterator& Iterator::operator ++() {
  ++elem;
  return *this;
}
void Iterator::operator --() {
  --elem;
}
int& Iterator::operator *() const {
  return *elem;
}
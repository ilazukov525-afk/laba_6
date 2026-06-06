#include <iostream>
#include <limits>
#include "Set.h"
using namespace std;

void PrintMenu1() {
  cout << "\n=== Создание множества ===" << endl;
  cout << "1 - Заполнить числами от 1 до N" << endl;
  cout << "2 - Ввести элементы вручную" << endl;
  cout << "\nВаш выбор: ";
}


int ReadChoice(int maxChoice) {
  int choice;
  bool valid = false;
  do {
    cin >> choice;
    if (cin.fail()) {
      cin.clear(); //сброс флага ошибки
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Вы ввели не число, попробуйте снова: ";
    }
    else if (choice < 1 || choice > maxChoice) {
      cout << "Неверное число. Введите число от 1 до " << maxChoice << ": ";
    }
    else {
      valid = true;
    }
  } while (valid == false);
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return choice;
}

Set* DoCase1(Set* a) {
  std::cout << "\033[2J\033[1;1H" << std::flush; //это очищает весь экран консоли (посмотрел в нейронке)
  cout << "Отлично, создастся множество чисел от 1 до N. \nВведите число до 20. Ваше число: ";
  int size = ReadChoice(20);
  a = new Set(size);
  cout << "Ваше множество" << endl;
  cout << *a << endl;
  return a;

}

Set* DoCase2(Set* a) {
  std::cout << "\033[2J\033[1;1H" << std::flush;
  cout << "Отлично, вы введете элементы вручную\n Введите число до 20. Ваше число: ";
  a = new Set(0);
  cin >> *a;
  cout << "Ваше множество" << endl;
  cout << *a << endl;
  return a;
}

int main()
{
  setlocale(LC_ALL, "RU");
  cout << "Здравствуйте! Программа для работы со множествами." << endl;
  int choice;

  PrintMenu1();
  choice = ReadChoice(2);

  Set* a = nullptr;
  switch (choice) {
  case 1:
    a = DoCase1(a);
    break;
  case 2:
    a = DoCase2(a);
      break;
  }

  if (a != nullptr) {
    Set b = *a;  
    cout << b;   
    delete a;    
    a = nullptr;
  }
  else {
    cout << "Множество не создано!";
  }

  
}
 
#include <iostream>  // для std::cin, std::cout
#include <string>    // для std::string

int
main()
{
  std::string name;  // переменная для хранения имени пользователя
  std::cout << "Enter your name: ";  // запрос имени
  std::cin >> name;                  // чтение имени из стандартного ввода
  std::cout << "Hello world from " << name << std::endl;  // приветствие
  return 0;
}

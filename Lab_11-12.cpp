// 12. Створити лінійний односпрямований список з цілих чисел.
// Видалити зі списку кожний елемент, який є кратний трьом.
// Додати до списку число 88 після кожної пари рівних чисел
//

#include <iostream>
#include <forward_list>
#include <iomanip> 
#include <windows.h> 
using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    forward_list<int> numberList = { 1, 42, 71, 12, 14, 8, 8, 52, 9, 11, 21, 17 };

    cout << "Список цілих чисел: ";
    for (int number : numberList) {
        cout << number << " ";
    }
    cout << endl;
    // Видалення елементів, кратних трьом
    auto prev = numberList.before_begin(); 
    auto it = numberList.begin();          
    while (it != numberList.end()) {
        if (*it % 3 == 0) { 
            it = numberList.erase_after(prev); 
        }
        else {
            prev = it; 
            ++it;      
        }
    }

    // Додавання 88 після кожної пари рівних чисел
    it = numberList.begin();
    while (it != numberList.end()) {
        auto nextIt = it; 
        ++nextIt;         
        if (nextIt != numberList.end() && *it == *nextIt) { 
            it = numberList.insert_after(nextIt, 88);
            ++it;  
        }
        ++it; 
    }

    cout << "Оновлений список: ";
    for (int number : numberList) {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}
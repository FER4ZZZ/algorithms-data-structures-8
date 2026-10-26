// Задача 1
#include <iostream>

// Функция быстрого возведения base в степень exp.
// Работает за счёт двоичного представления степени:
//   a^n = произведение a^(2^i) для всех i, где i-й бит n равен 1.
long long fastPowIter(long long base, long long exp) {
    long long result = 1;              // нейтральный элемент умножения

    while (exp > 0) {                  // пока не обработали все биты степени
        if (exp & 1) {                 // если младший бит степени равен 1...
            result *= base;            // ...домножаем результат на текущее основание
        }
        base *= base;                  // возводим основание в квадрат: base = base^2
        exp >>= 1;                     // сдвигаем степень вправо (делим на 2)
    }

    return result;                     // итоговое значение base^exp
}

int main() {
    long long a, n;
    std::cout << "Введите основание и степень: ";
    std::cin >> a >> n;

    // Пример из условия: 10^12 = 1000000000000
    std::cout << a << "^" << n << " = " << fastPowIter(a, n) << "\n";


    return 0;
}

// Задача 2
#include <iostream>

// Рекурсивный НОД: gcd(a, b) = gcd(b, a % b), база — gcd(a, 0) = a.
long long gcdMod(long long a, long long b) {
    if (b == 0) {              // база рекурсии: одно из чисел стало нулём
        return a;              // тогда НОД — это второе (ненулевое) число
    }
    return gcdMod(b, a % b);   // шаг Евклида: заменяем пару (a, b) на (b, a % b)
}

int main() {
    long long a, b;
    std::cin >> a >> b;                       // вводим два натуральных числа
    std::cout << gcdMod(a, b) << "\n";        // выводим их НОД
    return 0;
}

// Задача 2.1
#include <iostream>

// Рекурсивный НОД через вычитание.
long long gcdSub(long long a, long long b) {
    if (a == b) {              // база: числа равны — это и есть НОД
        return a;
    }
    if (a > b) {               // уменьшаем большее число
        return gcdSub(a - b, b);
    } else {                   // (b > a) — уменьшаем b
        return gcdSub(a, b - a);
    }
}

int main() {
    long long a, b;
    std::cin >> a >> b;                       // вводим два натуральных числа
    std::cout << gcdSub(a, b) << "\n";        // выводим их НОД
    return 0;
}

// Задача 3
#include <iostream>

// Функция печатает последовательность перекладываний,
// чтобы переместить n ингредиентов со стержня 'from' на 'to',
// используя 'aux' как вспомогательный.
//
// Идея:
//   1) Перекладываем верхние n-1 ингредиентов с from на aux (рекурсивно).
//   2) Перекладываем самый большой (n-й) ингредиент с from на to.
//   3) Перекладываем n-1 ингредиентов с aux на to (рекурсивно).
void hanoi(int n, int from, int to, int aux) {
    if (n == 0) {                            // база рекурсии: нечего перекладывать
        return;
    }
    hanoi(n - 1, from, aux, to);             // шаг 1: n-1 ингредиентов на вспомогательную
    std::cout << "Ingredient " << n
              << " move from " << from
              << " to " << to << "\n";       // шаг 2: самый большой — на целевую
    hanoi(n - 1, aux, to, from);             // шаг 3: n-1 ингредиентов с вспомогательной на целевую
}

int main() {
    int n;
    std::cin >> n;                           // количество ингредиентов
    // Все ингредиенты лежат на салфетке 1, нужно переложить на салфетку 3
    hanoi(n, 1, 3, 2);
    return 0;
}
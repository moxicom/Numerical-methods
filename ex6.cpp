#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

double f(double x) {
    return sin(x) / (1 + cos(x));
}

double integralRectangles(int n) {
    double a = 0;
    double b = M_PI / 2;
    double result = 0;
    double h = (b - a) / n;

    for (int i = 0; i < n; ++i) {
        result += f(a) * h;
        a += h;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "ru");

    int n = 4;
    int repeat_amount;
    double integral;
    double exact_integral;
    double prev_inaccuracy;


    cout << "Input repeat amount: ";
    cin >> repeat_amount;
    cout << "Input n: ";
    cin >> n;

    cout << "----------------------------\n";

    exact_integral = log(2); // !!!!!!!!!!!!!!!!!!! У ТЕБЯ ЗДЕСЬ ДОЛЖНО БЫТЬ СВОЕ ЗНАЧЕНИЕ -- ТОЧНЫЙ ОТВЕТ НА ФУНКЦИЮ, КОТОРЫЙ В ОНЛАЙН КАЛЬКУЛЯТОРЕ НАЙТИ
                            // !!!!!!!!!!!!!!!!!!!! ТАК ВО ВСЕХ ЗАДАНИЯХ № 6 - 8

    for (int i = 0; i < repeat_amount; ++i) {
        integral = integralRectangles(n);
        cout << "n = " << n << endl; 
        cout << setw(22) << "integral rectangles = " << integral << endl;
        cout << setw(22) << "exact integral = " << exact_integral << endl;
        cout << setw(22) << "inaccuracy = " << exact_integral - integral << endl;
        if (i != 0) {
            cout << setw(30) << "prev_integral / integral = " << prev_inaccuracy /
                (exact_integral - integral) << endl;
        }
        cout << "----------------------------\n";
        n *= 2;
        prev_inaccuracy = exact_integral - integral;
    }
    return 0;
}

// Я ТАК НАХОДИЛ:
// Точное значение интеграла от sin(x) / (1 + cos(x)) на отрезке[0, pi / 2] равно log(2).Чтобы увидеть, почему это так, можно выполнить следующие действия :
//
//  1. Выразить функцию sin(x) / (1 + cos(x)) через тангенс половинного угла : sin(x) / (1 + cos(x)) = 2tan(x / 2)
//  2. Вычислить интеграл 2tan(x / 2)dx на отрезке[0, pi / 2](этот интеграл уже известен и равен log(2)).
//  3. делать вывод, что интеграл sin(x) / (1 + cos(x))dx на отрезке[0, pi / 2] равен ln(2).


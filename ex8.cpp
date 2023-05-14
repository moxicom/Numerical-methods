#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

long double f(long double x) {
    return sin(x) / (1 + cos(x));
}

long double simpsonMethod(int n) {
    long double a = 0;
    long double b = M_PI / 2;
    long double result = 0;
    long double h = (b - a) / n;

    for (int i = 0; i < (n / 2); ++i) {
        result += h * (f(a) + 4 * f(a + h) + f(a + 2 * h)) / 3;
        a += 2 * h;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "ru");

    int n = 4;
    int repeat_amount;
    long double integral;
    long double prev_inaccuracy;
    long double exact_integral;


    cout << "Input repeat amount: ";
    cin >> repeat_amount;
    cout << "Input n: ";
    cin >> n;

    cout << "----------------------------\n";

    exact_integral = log(2);

    for (int i = 0; i < repeat_amount; ++i) {
        integral = simpsonMethod(n);

        cout << "n = " << n << endl;
        cout << setw(30) << "integral Simpson = " << integral << endl;
        cout << setw(30) << "exact integral = " << exact_integral << endl;
        cout << setw(30) << "inaccuracy = " << exact_integral - integral << endl;

        if (i != 0) {
            cout << setw(30) << "prev_integral / integral = " << prev_inaccuracy / (exact_integral - integral) << endl;
        }

        cout << "----------------------------\n";

        n *= 2;
        prev_inaccuracy = exact_integral - integral;
    }
    return 0;
}


// Точное значение интеграла от sin(x) / (1 + cos(x)) на отрезке[0, pi / 2] равно log(2).Чтобы увидеть, почему это так, можно выполнить следующие действия :
//
//  1. Выразить функцию sin(x) / (1 + cos(x)) через тангенс половинного угла : sin(x) / (1 + cos(x)) = 2tan(x / 2)
//  2. Вычислить интеграл 2tan(x / 2)dx на отрезке[0, pi / 2](этот интеграл уже известен и равен ln(2)).
//  3. делать вывод, что интеграл sin(x) / (1 + cos(x))dx на отрезке[0, pi / 2] равен log(2).
#include <iostream>
#include <cmath>


double f(double &x) {
	return 3 * x - cos(x) - 1;
}


double f_2(double& x) {
	return (1 + cos(x)) / 3; // выражаешь x (норин вроде просит по-дургому это выражать)
}


void dichotomy(double &a, double &b, double &accuracy){
	if (f(a) > 0 && f(b) > 0 || f(a) < 0 && f(b) < 0) {
		std::cout << "Нет корней\n";
		return;
	}
	double c;
	int amount = 0;
	if (f(a) * f(b) > 0)
	{
		std::cout << "Нет корней на данном отрезке" << std::endl;
		return;
	}
	do
	{	
		amount++;
		c = (a + b) / 2;
		if (f(a) * f(c) < 0) {
			b = c;
			continue;
		}
		a = c;
		
	} while (fabs(b - a) > accuracy);

	std::cout << "МЕТОД ДЕЛЕНИЯ ОТРЕЗКА ПОПОЛАМ (дихотомии)" << std::endl;
	std::cout << "Amount of iterations: " << amount << std::endl;
	std::cout << "Root: " << c << std::endl;
}


void iteration(double& x, double& accuracy){
	int amount = 0;
	double x1 = 100;
	while (fabs(x1 - x) > accuracy){
		amount++;
		x1 = x;
		x = f_2(x);	
	}

	std::cout << "МЕТОД ПРОСТЫХ ИТЕРАЦИЙ" << std::endl;
	std::cout << "Amount of iterations: " << amount << std::endl;
	std::cout << "Root: " << x << std::endl;
}


int main()
{	
	setlocale(LC_ALL, "ru");
	double a, b, accuracy, x0;
	std::cout << "Введите a, b, x0, accuracy" << std::endl;
	std::cin >> a >> b >> x0 >> accuracy;
	dichotomy(a, b, accuracy);
	iteration(x0, accuracy);
	return 0;
}

#include <iostream>
#include <cmath>

double f(const double &x) {
	return 3 * x - cos(x) - 1; // функция
}

double derivative(double &x) {
	return sin(x) + 3; // производная функции
}

void methodNewton(){
	double x, x0, accuracy;
	int count{};
	std::cout << "-------NEWTON's METHOD-------\ninput x, accuracy: ";
	std::cin >> x >> accuracy;
	do
	{
		x0 = x;
		x = x0 - f(x0) / derivative(x0);
		count++;
	} while  (fabs(x - x0) > accuracy);
	
	std::cout << "Root: " << x << std::endl;
	std::cout << "Amount of iterations: " << count << std::endl;
	return;
	
}

void methodSecant() { // метод хорд
	double x0, x1, accuracy;
	int count{};

	std::cout << "-------SECANT METHOD-------\ninput x0, x1, accuracy: ";
	std::cin >> x0 >> x1 >> accuracy;

	while (x0 < 0 && derivative(x0) < 0 || x0 > 0 && derivative(x0) > 0){
		std::cout << derivative(x0) <<"there is no root" << std::endl;
		std::cin >> x0 >> x1;
	}

	double x2 = x0 - f(x0) * (x1 - x0) / (f(x1) - f(x0));

	do {
		if (f(x2) * f(x1) < 0) {
			x0 = x2;
			x2 = x0 - f(x0) * (x1 - x0) / (f(x1) - f(x0));
		}
		else {
			x1 = x2;
			x2 = x0 - f(x0) * (x1 - x0) / (f(x1) - f(x0));
		}
		count++;
	} while (fabs(x2 - x1) > accuracy);
	
	std::cout << "Root: " << x2 << std::endl << "Amount of iterations: "
		<< count << std::endl;
}

int main()
{
	methodNewton();
	methodSecant();
	return 0;
}
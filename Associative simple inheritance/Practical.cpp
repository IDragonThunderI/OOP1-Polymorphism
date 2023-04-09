
// Наследование, ассоциация и зависимость

#include <iostream>
#include <cmath>
#include <typeinfo>

using namespace std;

const long double PI = 4.0 * atan(1.0);

class Circle
{
private:
	double r;
	const int id;

protected:
	const double lenght() const { return 2.0 * PI * r; }
	const double area() const { return PI * pow(r, 2.0); }

public:
	static int countCrl;

	Circle() : id(countCrl++) { r = 10.0; }
	Circle(double r) : id(countCrl++) { setRadius(r); }

	const double getRadius() const { return r; }
	void setRadius(double r) { this->r = r; }

	void show() const
	{
		cout << "\nРадиус: " << getRadius();
		cout << "\nДлина окружности: " << lenght();
		cout << "\nПлощадь: " << area() << "\n\n";
	}

	void classInfo() const
	{
		string name = typeid(*this).name();
		cout << "Объект: " << name.erase(0, 6) << id;
	}
};

int Circle::countCrl = 0;

class Square
{
private:
	double x;
	const int id;

protected:
	const double diagonal() const { return sqrt(2.0 * pow(x, 2.0)); }
	const double perimetr() const { return 4.0 * x; }
	const double area() const { return pow(x, 2.0); }

public:
	static int countSqr;

	Square() : id(countSqr++) { x = 10.0; }
	Square(double x) : id(countSqr++) { setSide(x); }

	const double getSide() const { return x; }
	void setSide(double x) { this->x = x; }
	void changeSideOnInscribedCrl(const Circle& crl) { x = 2.0 * crl.getRadius(); } // Изменить сторону по описанной окружности

	void show() const
	{
		cout << "\nСторона: " << getSide();
		cout << "\nДиагональ: " << diagonal();
		cout << "\nПериметр: " << perimetr();
		cout << "\nПлощадь: " << area() << "\n\n";
	}

	void classInfo() const
	{
		string name = typeid(*this).name();
		cout << "Объект: " << name.erase(0, 6) << id;
	}
};

int Square::countSqr = 0;

class Sphere : public Circle
{
private:
	const int id;

protected:
	const double area() const { return 4.0 * PI * pow(getRadius(), 2.0); }
	const double volume() const { return 4.0 / 3.0 * PI * pow(getRadius(), 3.0); }

public:
	static int countSph;

	Sphere() : id(countSph++) { countCrl--; }
	Sphere(double r) : id(countSph++), Circle(r) { countCrl--; }

	void show() const
	{
		cout << "\nРадиус: " << getRadius();
		cout << "\nДлина экватора: " << lenght();
		cout << "\nПлощадь поверхности: " << area();
		cout << "\nОбъём: " << volume() << "\n\n";
	}

	void classInfo() const
	{
		string name = typeid(*this).name();
		cout << "Объект: " << name.erase(0, 6) << id;
	}
};

int Sphere::countSph = 0;

class Prism : public Square
{
private:
	double h;
	const int id;
	Sphere describedSph; // Ассоциация призмы со сферой

protected:
	const double diagonal() const { return sqrt(pow(Square::diagonal(), 2.0) + pow(h, 2.0)); }
	const double volume() const { return Square::area() * h; }
	const double area() const { return perimetr() * h + 2.0 * Square::area(); }
	const double radiusDiscribedSph() const { return diagonal() / 2.0; }

public:
	static int countPrm;

	Prism() : id(countPrm++) { h = 10; describedSph.setRadius(radiusDiscribedSph()); countSqr--; Sphere::countSph--; }
	Prism(double h, double x) : id(countPrm++), Square(x) { setHeight(h); describedSph.setRadius(radiusDiscribedSph()); countSqr--; Sphere::countSph--; }

	const double getHeight() const { return h; }
	void setHeight(double h) { this->h = h; }

	void show() const
	{
		cout << "\nСторона: " << getSide();
		cout << "\nВысота: " << getHeight();
		cout << "\nДиагональ: " << diagonal();
		cout << "\nПлощадь основания: " << Square::area();
		cout << "\nПлощадь поверхности: " << area();
		cout << "\nОбъём: " << volume();
		cout << "\n\n+ Характеристики описанной сферы: "; // Добавили вывод сведений о сфере
		describedSph.show();
	}

	void classInfo() const
	{
		string name = typeid(*this).name();
		cout << "Объект: " << name.erase(0, 6) << id;
	}
};

int Prism::countPrm = 0;

int main()
{
	system("chcp 1251 > nul");

	Square sqr0;
	sqr0.classInfo();
	sqr0.show();

	cout << "==============================\n\n";

	Square sqr1(1.5);
	sqr1.classInfo();
	sqr1.show();

	cout << "==============================\n\n";

	Prism prm0;
	prm0.classInfo();
	prm0.show();

	cout << "==============================\n\n";
	
	Prism prm1(2.5, 5.0);
	prm1.classInfo();
	prm1.show();

	cout << "==============================\n\n";
	
	Circle crl0;
	crl0.classInfo();
	crl0.show();
	
	cout << "==============================\n\n";

	Circle crl1(5.5);
	crl1.classInfo();
	crl1.show();
	
	cout << "==============================\n\n";

	Sphere sph0;
	sph0.classInfo();
	sph0.show();

	cout << "==============================\n\n";
	
	Sphere sph1(2.0);
	sph1.classInfo();
	sph1.show();

	cout << "==============================\n\n";
	
	Square sqr2;
	sqr2.changeSideOnInscribedCrl(crl1);
	sqr2.classInfo();
	sqr2.show();

	system("pause");
	return 0;
}
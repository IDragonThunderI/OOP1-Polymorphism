#include <iostream>
#include <typeinfo>

using namespace std;

/*==================== КЛАСС ТРАНСПОРТ ===================*/

class Transport
{
private:
	string type; // Тип транспорта (Служебный | Общественный | Гражданский)

public:
	Transport();
	Transport(string type);
	void setData(string type);
	Transport& getData();
	void print();
	void classInfo();
};

Transport::Transport()
{
	type = "Unknown";
}

Transport::Transport(string type)
{
	setData(type);
}

void Transport::setData(string type)
{
	if(type != "")
		this->type = type;
}

Transport& Transport::getData()
{
	return *this;
}

void Transport::print()
{
	cout << "Тип транспорта: " << type << "\n\n";
}

void Transport::classInfo()
{
	string className = typeid(*this).name();
	cout << "Класс: " << className.erase(0, 6) << "\n\n";
}

/*==================== КЛАСС АВТОМОБИЛЬ ====================*/

class Automobile : public Transport
{
private:
	string name;		// Название автомобиля
	string body;		// Кузов
	string driveUnit;	// Привод
	string number;		// Номер автомобиля

public:
	Automobile();
	Automobile(Transport& transport, string name, string body, string driveUnit, string number);
	void setData(string name, string body, string driveUnit, string number);
	Automobile& getData();
	void print();
	void classInfo();
};

Automobile::Automobile()
{
	name = body = driveUnit = number = "Unknown";
}

Automobile::Automobile(Transport& transport, string name, string body, string driveUnit, string number) : Transport::Transport(transport)
{
	setData(name, body, driveUnit, number);
}

void Automobile::setData(string name, string body, string driveUnit, string number)
{
	if(name != "")
		this->name = name;
	if(body != "")
		this->body = body;
	if(driveUnit != "")
		this->driveUnit = driveUnit;
	if(number != "")
		this->number = number;
}

Automobile& Automobile::getData()
{
	return *this;
}

void Automobile::print()
{
	Transport::print();
	cout << "Название автомобиля: " << name;
	cout << "\nКузов: " << body;
	cout << "\nПривод: " << driveUnit;
	cout << "\nНомер автомобиля: " << number << "\n\n";
}

void Automobile::classInfo()
{
	string className = typeid(*this).name();
	cout << "Класс: " << className.erase(0, 6) << "\n\n";
}

/*==================== КЛАСС ВОДИТЕЛЬ ====================*/

class Driver
{
private:
	string fullname;	// ФИО
	string gender;		// Пол
	string birthday;	// Дата рождения
	string phoneNumber;	// Номер телефона

public:
	Driver();
	Driver(string fullname, string gender, string birthday, string phoneNumber);
	void setData(string fullname, string gender, string birthday, string phoneNumber);
	Driver& getData();
	void print();
	void classInfo();

};

Driver::Driver()
{
	fullname = gender = birthday = phoneNumber = "Unknown";
}

Driver::Driver(string fullname, string gender, string birthday, string phoneNumber)
{
	setData(fullname, gender, birthday, phoneNumber);
}

void Driver::setData(string fullname, string gender, string birthday, string phoneNumber)
{
	if(fullname != "")
		this->fullname = fullname;
	if(gender != "")
		this->gender = gender;
	if(birthday != "")
		this->birthday = birthday;
	if(phoneNumber != "")
		this->phoneNumber = phoneNumber;
}

Driver& Driver::getData()
{
	return *this;
}

void Driver::print()
{
	cout << "ФИО: " << fullname;
	cout << "\nПол: " << gender;
	cout << "\nДата рождения: " << birthday;
	cout << "\nНомер телефона: " << phoneNumber << "\n\n";
}

void Driver::classInfo()
{
	string className = typeid(*this).name();
	cout << "Класс: " << className.erase(0, 6) << "\n\n";
}

/*=============== КЛАСС ВОДИТЕЛЬ АВТОМОБИЛЯ ===============*/

class CarDriver : public Automobile, public Driver
{
private:
	string driveExperience;		// Водительский стаж
	string category;			// Категория прав
	string trafficViolations;	// Нарушения ПДД

public:
	CarDriver();
	CarDriver(Driver& driver, Automobile& automobile, string driveExperience, string category, string trafficViolations);
	void setData(string driveExperience, string category, string trafficViolations);
	CarDriver& getData();
	void print();
	void classInfo();

};

CarDriver::CarDriver()
{
	driveExperience = category = trafficViolations = "Unknown";
}

CarDriver::CarDriver(Driver& driver, Automobile& automobile, string driveExperience, string category, string trafficViolations) : Driver::Driver(driver), Automobile::Automobile(automobile)
{
	setData(driveExperience, category, trafficViolations);
}

void CarDriver::setData(string driveExperience, string category, string trafficViolations)
{
	if(driveExperience != "")
		this->driveExperience = driveExperience;
	if(category != "")
		this->category = category;
	if(trafficViolations != "")
		this->trafficViolations = trafficViolations;
}

CarDriver& CarDriver::getData()
{
	return *this;
}

void CarDriver::print()
{
	Driver::print();
	Automobile::print();
	cout << "Водительский стаж: " << driveExperience;
	cout << "\nКатегория прав: " << category;
	cout << "\nНарушения ПДД: " << trafficViolations << "\n\n";
}

void CarDriver::classInfo()
{
	string className = typeid(*this).name();
	cout << "Класс: " << className.erase(0, 6) << "\n\n";
}

/*=============== КЛАСС ВОДИТЕЛЬ СЛУЖЕБНОГО АВТОМОБИЛЯ ===============*/

class ServiceCarDriver : public CarDriver
{
private:
	string company;			// Название компании
	string workExperience;	// Стаж работы
	string salary;			// Зарплата

public:
	ServiceCarDriver();
	ServiceCarDriver(CarDriver& carDriver, string company, string workExperience, string salary);
	void setData(string company, string workExperience, string salary);
	ServiceCarDriver& getData();
	void print();
	void classInfo();
};

ServiceCarDriver::ServiceCarDriver()
{
	company = workExperience = salary = "Unknown";
}

ServiceCarDriver::ServiceCarDriver(CarDriver& carDriver, string company, string workExperience, string salary) : CarDriver::CarDriver(carDriver)
{
	setData(company, workExperience, salary);
}

void ServiceCarDriver::setData(string company, string workExperience, string salary)
{
	if(company != "")
		this->company = company;
	if(workExperience != "")
		this->workExperience = workExperience;
	if(salary != "")
		this->salary = salary;
}

ServiceCarDriver& ServiceCarDriver::getData()
{
	return *this;
}

void ServiceCarDriver::print()
{
	CarDriver::print();
	cout << "Название компании: " << company;
	cout << "\nСтаж работы: " << workExperience;
	cout << "\nЗарплата: " << salary << "\n\n";
}

void ServiceCarDriver::classInfo()
{
	string className = typeid(*this).name();
	cout << "Класс: " << className.erase(0, 6) << "\n\n";
}

/*=============== КЛАСС ВОДИТЕЛЬ ТАКСИ ===============*/

class TaxiDriver : public CarDriver
{
private:
	string company;			// Название компании
	string workExperience;	// Стаж работы
	string rating;			// Рейтинг
	string salary;			// Зарплата

public:
	TaxiDriver();
	TaxiDriver(CarDriver& carDriver, string company, string workExperience, string rating, string salary);
	void setData(string company, string workExperience, string rating, string salary);
	TaxiDriver& getData();
	void print();
	void classInfo();
};

TaxiDriver::TaxiDriver()
{
	company = workExperience = rating = salary = "Unknown";
}

TaxiDriver::TaxiDriver(CarDriver& carDriver, string company, string workExperience, string rating, string salary) : CarDriver::CarDriver(carDriver)
{
	setData(company, workExperience, rating, salary);
}

void TaxiDriver::setData(string company, string workExperience, string rating, string salary)
{
	if(company != "")
		this->company = company;
	if(workExperience != "")
		this->workExperience = workExperience;
	if(rating != "")
		this->rating = rating;
	if(salary != "")
		this->salary = salary;
}

TaxiDriver& TaxiDriver::getData()
{
	return *this;
}

void TaxiDriver::print()
{
	CarDriver::print();
	cout << "Название компании: " << company;
	cout << "\nСтаж работы: " << workExperience;
	cout << "\nРейтинг: " << rating;
	cout << "\nЗарплата: " << salary << "\n\n";
}

void TaxiDriver::classInfo()
{
	string className = typeid(*this).name();
	cout << "Класс: " << className.erase(0, 6) << "\n\n";
}

/*==================== MAIN ====================*/

int main()
{
	system("chcp 1251 > nul");

	Transport transport("Гражданский");
	transport.classInfo();
	transport.print();

	cout << "====================================================\n\n";

	Automobile car(transport.getData(), "Lada Vesta", "Седан", "Задний привод", "Е404РР");
	car.classInfo();
	car.print();

	cout << "====================================================\n\n";

	Driver human("Рекечинский Андрей Алексеевич", "Мужской", "21.11.2003", "88005553535");
	human.classInfo();
	human.print();

	cout << "====================================================\n\n";

	CarDriver driver(human.getData(), car.getData(), "5 лет", "B", "Нет");
	driver.classInfo();
	driver.print();

	cout << "====================================================\n\n";

	driver.Transport::setData("Служебный");
	ServiceCarDriver scd(driver.getData(), "\"ООО\" ВОДОУЧЁТ", "1 год", "30000 Р");
	scd.classInfo();
	scd.print();

	cout << "====================================================\n\n";

	driver.Transport::setData("Общественный");
	TaxiDriver td(driver.getData(), "ТАКСИ-ВЕЗИ", "2.5 года", "8.6/10", "50000 Р");
	td.classInfo();
	td.print();

	system("pause");
	return 0;
}
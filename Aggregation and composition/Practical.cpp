#include <iostream>

using namespace std;

class Notebook
{
private:
	class Note
	{
	private:
		string surname;
		string name;
		string phoneNumber;
		string birthday;

	public:
		Note() { surname = name = phoneNumber = birthday = "Unknown"; }
		void setData(string surname, string name, string phoneNumber, string birthday)
		{
			this->surname = surname;
			this->name = name;
			this->phoneNumber = phoneNumber;
			this->birthday = birthday;
		}

		const string getSurname() const { return surname; }
		const string getName() const { return name; }
		const string getPhoneNumber() const { return phoneNumber; }
		const string getBirthday() const { return birthday; }
	};

	string surnameAndInitials;
	Note* note;
	Note* next;

public:
	Notebook() : next(NULL), note(NULL) { surnameAndInitials = "Unknown U.U."; }
	Notebook(string surnameAndInitials) : next(NULL), note(NULL) { this->surnameAndInitials = surnameAndInitials; }
	void addNote(const string surname, const string name, const string phoneNumber, const string birthday)
	{
		note = new Note;
		note->setData(surname, name, phoneNumber, birthday);
		this->next = note;
	}

	void showNote() const
	{
		cout << "Фамилия: " << note->getSurname();
		cout << "\nИмя: " << note->getName();
		cout << "\nНомер телефона: " << note->getPhoneNumber();
		cout << "\nДата рождения: " << note->getBirthday() << "\n\n";
	}

	void findNumberAndBirthday(const string surname, const string name) const
	{
		if (note->getSurname() == surname && note->getName() == name)
		{
			cout << "Номер телефона: " << note->getPhoneNumber();
			cout << "\nДата рождения: " << note->getBirthday() << "\n\n";
		}
		else
			cout << "\nПоиск не дал результатов." << "\n\n";
	}

	void findBy3DigitsOfNumber(const string digits) const
	{
		if (note->getPhoneNumber().find(digits) != string::npos)
			showNote();
		else
			cout << "\nПоиск не дал результатов." << "\n\n";
	}
};

int main()
{
	system("chcp 1251 > nul");

	Notebook notebookTest;
	Notebook notebookMain("Рекечинский А.А.");



	system("pause");
	return 0;
}
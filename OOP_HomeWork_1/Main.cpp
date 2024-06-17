#include<iostream>
#include<string>

// Домашнее задание 1. Телефонная книга.

class Contact {
	// Конструкторы, методы и деструктор в открытом доступе:
public:
	// Конструктор по умолчанию:
	Contact() : name_{ "noname" }, contact_numbers_{ nullptr }, phone_numbers_{ 0 }, address_ { "noaddress" } 
	{ std::cout << "Default constructor for " << this << '\n'; }	// вывод в консоли для понимания
	// Конструкторы параметрические:
	Contact(std::string name, std::string address) : 
		name_{ name }, contact_numbers_{ nullptr }, phone_numbers_{ 0 }, address_{ address } 
	{ std::cout << "Param constructor for " << this << '\n'; }		// вывод в консоли для понимания
	Contact(std::string name, long long number, std::string address) :
		name_{ name }, contact_numbers_{ new long long[1] { number } }, phone_numbers_{ 1 }, address_{ address } 
	{ std::cout << "Param constructor for " << this << '\n'; }		// вывод в консоли для понимания
	// Деструктор:
	~Contact();
	// Геттеры:
	std::string getName()const { return name_; }
	std::string getAddress()const { return address_; }
	long long getNumber(int index)const { return contact_numbers_[index]; }
	size_t getNumbers()const { return phone_numbers_; }
	// Сеттеры:
	void setName(std::string name) { name_ = name; }
	void addPhone_number(long long number);
	void setAddress(std::string address) { address_ = address; }
	// Методы:
	void print();	

	// Поля класса в приватной зоне:
private:
	std::string name_;
	long long* contact_numbers_;
	size_t phone_numbers_;	
	std::string address_;
};


int main() {
	setlocale(LC_ALL, "RU");
	int n;
	// Создадим объект1 с помощью конструктора по умолчанию:
	Contact person1;
	// Вывод информации в консоль об объекте1:
	person1.print();
	std::cout << "-------------------\n";
	// Присвоим объекту1 имя, его адрес, телефон. Также вывод в консоль:
	person1.setName("Gollum");
	person1.setAddress("Shyre");
	person1.addPhone_number(911);
	person1.print();
	std::cout << "-------------------\n";
	// Создадим объект2 с помощью пераметрического конструктора. Потом добавим ему контактные номера и изменим ему адрес:
	Contact person2 ("Bilbo Baggins", "Shyre");
	person2.addPhone_number(9089110005);	
	person2.print();
	std::cout << "-------------------\n";
	person2.addPhone_number(9021110005);
	person2.setAddress("Mordor");
	person2.print();
	std::cout << "-------------------\n";
	// Создадим объект3 с помощью пераметрического конструктора (в кот. также указан контактный номер телефона):
	Contact person3("Torin Oakshield", 9220001205, "Erebor");
	person3.print();

	return 0;
}

Contact::~Contact(){
	delete[] contact_numbers_;
	std::cout << this << " destructed\n";	// вывод в консоли для понимания
}

void Contact::addPhone_number(long long number){
	if (contact_numbers_ == nullptr) {		
		contact_numbers_ = new long long[1] { number };
		phone_numbers_ = 1;
		std::cout << "Add first number\n";
		return;
	}
	long long* tmp = new long long[phone_numbers_ + 1];
	for (size_t i = 0; i < phone_numbers_; ++i)	{
		tmp[i] = contact_numbers_[i];
	}
	tmp[phone_numbers_] = number;
	delete[] contact_numbers_;
	contact_numbers_ = tmp;
	++phone_numbers_;
	std::cout << "Add next number\n";
}

void Contact::print(){
	std::cout << "Имя контакта - " << getName() << std::endl;
	std::cout << "Адресс контакта - " << getAddress() << std::endl;
	if (contact_numbers_ == nullptr) { return; }
	std::cout << "Кол-во контактов - " << getNumbers() << std::endl;
	for (size_t i = 0; i < phone_numbers_; ++i)	{
		std::cout << "тел.: " << getNumber(i) << std::endl;
	}
}



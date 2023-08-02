#pragma once

class Account
{
	string card_number;
	float amount;

public:

	// Constructors

	Account(string card_number, float amount)
	{
		this->set_card_number(card_number);
		this->set_amount(amount);
	}

	// Set Methods

	void set_card_number(string card_number)
	{
		if (card_number.length() == 12)
			this->card_number = card_number;
		else
			assert(!"Card Number is not correct !!!");
	}

	void set_amount(float amount)
	{
		if (amount > 0)
			this->amount = amount;
		else
			assert(!"Amount is not correct !!!");
	}

	// Get Methods

	inline const string get_card_number() const { return this->card_number; }
	inline float get_amount() const { return this->amount; }
};

class Programmer : public Account
{
	string name;
	int age;
	float salary;

public:

	// Constructor

	Programmer(string name, int age, float salary , string card_number , float amount) : Account(card_number , amount)
	{
		this->set_name(name);
		this->set_age(age);
		this->set_salary(salary);
	}

	// Set Methods

	void set_name(string name)
	{
		if (name.length() >= 3)
			this->name = name;
		else
			assert(!"Name is not correct !!!");
	}

	void set_age(int age)
	{
		if (age >= 18 && age <= 70)
			this->age = age;
		else
			assert(!"Age is not correct !!!");
	}

	void set_salary(float salary)
	{
		if (salary >= 8500)
			this->salary = salary;
		else
			assert(!"Salary is not correct !!!");
	}

	// Get Methods

	inline const string get_name() const { return this->name; }
	inline int get_age() const { return this->age; }
	inline float get_salary() const { return this->salary; }
};
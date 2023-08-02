#pragma once

class Car
{
	int id;
	string model;
	int hp;

protected:

	Car() { this->id = global_id++; }
	Car(string model , int hp)
	{
		this->id = global_id++;
		this->set_model(model);
		this->set_hp(hp);
	}

public:

	// Set Methods

	void set_model(string model)
	{
		if (model.length() >= 2)
			this->model = model;
		else
			assert(!"Model is not correct !!!");
	}

	void set_hp(int hp)
	{
		if (hp >= 20)
			this->hp = hp;
		else
			assert(!"Hp is not correct !!!");
	}

	// Get Methods

	inline string get_model() const { return this->model; }
	inline int get_id() const { return this->id; }
	inline int get_hp() const { return this->hp; }
};

class BMW : public Car
{
	bool xdrive;
	bool M;

public:

	// Constructors

	BMW() : Car() {}
	BMW(string model, int hp, bool xdrive, bool M) : Car(model, hp)
	{
		this->xdrive = xdrive;
		this->M = M;
	}

	// Get Method

	inline bool get_xdrive() const { return this->xdrive; }
	inline bool get_M() const { return this->M; }

	// Cout

	friend ostream& operator << (ostream& os, const BMW& bmw);
};

// Cout

ostream& operator << (ostream& os, const BMW& bmw)
{
	os << "ID: " << bmw.get_id() << endl;
	os << "Marka: BMW" << endl;
	os << "Model: " << bmw.get_model() << endl;
	os << "HP: " << bmw.get_hp() << endl;
	os << "Xdrive: " << (bmw.xdrive ? "Exist" : "Not exist") << endl;
	os << "M: " << (bmw.M ? "M model" : "Not M model") << endl;

	return os;
}

class Mercedes : public Car
{
	bool AMG;

public:

	// Constructors

	Mercedes() : Car() {}
	Mercedes(string model, int hp, bool AMG) : Car(model, hp) { this->AMG = AMG; }

	// Get Method

	inline bool get_AMG() const { return this->AMG; }

	// Cout 

	friend ostream& operator << (ostream& os, const Mercedes& bmw);
};

// Cout 

ostream& operator << (ostream& os, const Mercedes& merc)
{
	os << "ID: " << merc.get_id() << endl;
	os << "Marka: Mercedes" << endl;
	os << "Model: " << merc.get_model() << endl;
	os << "HP: " << merc.get_hp() << endl;
	os << "AMG: " << (merc.AMG ? "Exist" : "Not exist") << endl;

	return os;
}
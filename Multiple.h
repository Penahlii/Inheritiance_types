#pragma once

class MessageText
{
	string text;
	string FromName;
	string Toname;

public:

	// Constructors

	MessageText();
	MessageText(string text, string FromName, string Toname);

	// Set Methods

	void set_text(string text);
	void set_from_name(string FromName);
	void set_to_name(string Toname);

	// Get Methods

	inline const string get_text() const;
	inline const string get_from_name() const;
	inline const string get_to_name() const;

	// Send Message

	void Send_Message();
};

class SMS : virtual public MessageText
{
	string number;

public:

	// Constrcutors

	SMS() : MessageText() {}
	SMS(string text, string FromName, string Toname, string number) : MessageText(text, FromName, Toname)
	{
		this->set_from_name(FromName);
		this->set_number(number);
		this->set_text(text);
		this->set_to_name(Toname);
	}

	// Set Method

	void set_number(string number);

	// Get Method

	inline const string get_number() const;

	// Send Message

	void Send_Message();
};

class Email : virtual public MessageText
{
	string email_adress;

public:

	// Constructors

	Email();
	Email(string text, string FromName, string Toname, string email_adress) : MessageText(text, FromName, Toname) { this->set_email_adress(email_adress); }

	// Set Method

	void set_email_adress(string email_adress);

	// Get Method

	inline const string get_email_adress() const;

	// Send Message

	void Send_Message();
};

class MessageService : public SMS, public Email
{
public:

	// Constructors

	MessageService() : SMS(), Email() {}
	MessageService(string text, string FromName, string Toname, string email_adress, string number) : SMS(text, FromName, Toname, number), Email(text, FromName, Toname, email_adress) {}

	// Send Message

	void Send_Message(int num);
};



// Message Text

// Constructors

MessageText::MessageText() {}

MessageText::MessageText(string text, string FromName, string Toname)
{
	this->set_text(text);
	this->set_from_name(FromName);
	this->set_to_name(Toname);
}

// Set Methods

void MessageText::set_text(string text)
{
	if (text.length() >= 2)
		this->text = text;
	else
		assert(!"Text is not correct !!!");
}

void MessageText::set_from_name(string FromName)
{
	if (FromName.length() >= 3)
		this->FromName = FromName;
	else
		assert(!"Name is not correct !!!");
}

void MessageText::set_to_name(string Toname)
{
	if (Toname.length() >= 3)
		this->Toname = Toname;
	else
		assert(!"Name is not correct !!!");
}

// Get Methods

inline const string MessageText::get_text() const { return this->text; }
inline const string MessageText::get_from_name() const { return this->FromName; }
inline const string MessageText::get_to_name() const { return this->Toname; }

// Send Message

void MessageText::Send_Message() { cout << "From " << this->FromName << " To " << this->Toname << "\n" << this->text << endl; }



// SMS Text  

// Set Method

void SMS::set_number(string number)
{
	if (number.length() >= 7 && number.length() <= 10)
		this->number = number;
	else
		assert(!"Number is not correct !!!");
}

// Get Method

inline const string SMS::get_number() const { return this->number; }

// Send Message

void SMS::Send_Message() { cout << "From " << this->get_from_name() << " To " << this->get_to_name() << " with " << this->number << " number " << "\n" << this->get_text(); }


// Email

// Set Method

void Email::set_email_adress(string email_adress)
{
	if (email_adress.length() >= 7 && email_adress.length() <= 30)
		this->email_adress = email_adress;
	else
		assert(!"Eamil Adress is not correct !!!");
}

// Get Method

inline const string Email::get_email_adress() const { return this->email_adress; }

// Send Message

void Email::Send_Message() { cout << "From " << this->get_from_name() << " To " << this->get_to_name() << " with " << this->email_adress << " email adress " << "\n" << this->get_text(); }


// Message Service

// Send Message

void MessageService::Send_Message(int num)
{
	if (num == 1)
		cout << "From " << this->get_from_name() << " To " << this->get_to_name() << " with " << this->get_number() << " number " << "\n" << this->get_text();
	else if (num == 2)
		cout << "From " << this->get_from_name() << " To " << this->get_to_name() << " with " << this->get_email_adress() << " email adress " << "\n" << this->get_text();
	else if (num == 3)
		cout << "From " << this->get_from_name() << " To " << this->get_to_name() << " with " << this->get_email_adress() << " email adress " << " with " << this->get_number() << " number " << "\n" << this->get_text();
	else
		assert(!"Choice does not exist !!!");
}
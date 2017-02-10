#include <iostream>
class TString
{
	char * Data;
public:
	//  Деструктор
	~TString();


	// Конструктор по умолчанию  
	TString();


	// Конструктор копирования 
	TString(const TString& rhs);


	// Пользовательский конструктор  
	TString(const char * data);


	// Оператор присваивания    
	TString& operator =(const TString& rhs);


	// Оператор +=  
	TString& operator +=(const TString& rhs);


	//  Оператор ==  
	bool operator ==(const TString& rhs) const;


	/// Оператор &lt;   
	bool operator <(const TString& rhs) const;


	// Функция поиска подстроки
	size_t Find(const TString& substr) const;


	// Функция замены букв 
	void Replace(char oldSymbol, char newSymbol);


	// Функция возвращает длину строки 
	size_t Size() const;


	// Функция для определения пуста ли строка 
	bool Empty() const;


	// Оператор [] 
	char operator[](size_t index) const;


	// Оператор [] 
	char& operator[](size_t index);


	// Смотри пример 
	void RTrim(char symbol);


	// Смотри пример 
	void LTrim(char symbol);

	friend std::ostream & operator<<(std::ostream &, const TString &);
};

// Оператор +  
TString operator+(const TString & a, const TString & b);


// Оператор !=
bool operator!=(const TString & a, const TString & b);


// Оператор &gt;
bool operator>(const TString & a, const TString & b);


// Оператор вывода 
std::ostream & operator<<(std::ostream &out, const TString &str);
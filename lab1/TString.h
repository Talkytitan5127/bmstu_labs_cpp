#include <iostream>
class TString
{
	char * Data;
public:
	// <summary> Деструктор </summary>
	~TString();


	// <summary> Конструктор по умолчанию </summary> 
	TString();


	// <summary> конструктор копирования </summary>
	TString(const TString& rhs);


	// <summary> Пользовательский конструктор </summary> 
	TString(const char * data);

	// <summary> Оператор присваивания </summary>    
	TString& operator =(const TString& rhs);


	// <summary> Оператор +=  </summary>
	TString& operator +=(const TString& rhs);


	//  <summary> Оператор == </summary>  
	bool operator ==(const TString& rhs) const;


	/// <summary> Оператор &lt; </summary>   
	bool operator <(const TString& rhs) const;


	// <summary> Функция поиска подстроки </summary>
	size_t Find(const TString& substr) const;


	// <summary> Функция замены букв </summary>
	void Replace(char oldSymbol, char newSymbol);


	// <summary> Функция возвращает длину строки </summary> 
	size_t Size() const;


	// <summary> Функция для определения пуста ли строка </summary>
	bool Empty() const;


	// <summary> Оператор [] </summary> 
	char operator[](size_t index) const;


	// <summary> Оператор [] </summary> 
	char& operator[](size_t index);

	void RTrim(char symbol);
 
	void LTrim(char symbol);

	friend std::ostream & operator<<(std::ostream &, const TString &);
};

//  <summary> Оператор + </summary> 
TString operator+(const TString & a, const TString & b);


// <summary> Оператор != </summary>
bool operator!=(const TString & a, const TString & b);


// <summary> Оператор &gt; </summary>
bool operator>(const TString & a, const TString & b);


// <summary> Оператор вывода </summary>
std::ostream & operator<<(std::ostream &out, const TString &str);

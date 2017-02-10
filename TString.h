#include <iostream>
class TString
{
	char * Data;
public:
	//  ����������
	~TString();


	// ����������� �� ���������  
	TString();


	// ����������� ����������� 
	TString(const TString& rhs);


	// ���������������� �����������  
	TString(const char * data);


	// �������� ������������    
	TString& operator =(const TString& rhs);


	// �������� +=  
	TString& operator +=(const TString& rhs);


	//  �������� ==  
	bool operator ==(const TString& rhs) const;


	/// �������� &lt;   
	bool operator <(const TString& rhs) const;


	// ������� ������ ���������
	size_t Find(const TString& substr) const;


	// ������� ������ ���� 
	void Replace(char oldSymbol, char newSymbol);


	// ������� ���������� ����� ������ 
	size_t Size() const;


	// ������� ��� ����������� ����� �� ������ 
	bool Empty() const;


	// �������� [] 
	char operator[](size_t index) const;


	// �������� [] 
	char& operator[](size_t index);


	// ������ ������ 
	void RTrim(char symbol);


	// ������ ������ 
	void LTrim(char symbol);

	friend std::ostream & operator<<(std::ostream &, const TString &);
};

// �������� +  
TString operator+(const TString & a, const TString & b);


// �������� !=
bool operator!=(const TString & a, const TString & b);


// �������� &gt;
bool operator>(const TString & a, const TString & b);


// �������� ������ 
std::ostream & operator<<(std::ostream &out, const TString &str);
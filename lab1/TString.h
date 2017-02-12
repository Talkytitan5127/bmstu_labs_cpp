#include <iostream>
class TString
{
	char * Data;
public:
	//  Äåñòðóêòîð
	~TString();


	// Êîíñòðóêòîð ïî óìîë÷àíèþ  
	TString();


	// Êîíñòðóêòîð êîïèðîâàíèÿ 
	TString(const TString& rhs);


	// Ïîëüçîâàòåëüñêèé êîíñòðóêòîð  
	TString(const char * data);


	// Îïåðàòîð ïðèñâàèâàíèÿ    
	TString& operator =(const TString& rhs);


	// Îïåðàòîð +=  
	TString& operator +=(const TString& rhs);


	//  Îïåðàòîð ==  
	bool operator ==(const TString& rhs) const;


	/// Îïåðàòîð &lt;   
	bool operator <(const TString& rhs) const;


	// Ôóíêöèÿ ïîèñêà ïîäñòðîêè
	size_t Find(const TString& substr) const;


	// Ôóíêöèÿ çàìåíû áóêâ 
	void Replace(char oldSymbol, char newSymbol);


	// Ôóíêöèÿ âîçâðàùàåò äëèíó ñòðîêè 
	size_t Size() const;


	// Ôóíêöèÿ äëÿ îïðåäåëåíèÿ ïóñòà ëè ñòðîêà 
	bool Empty() const;


	// Îïåðàòîð [] 
	char operator[](size_t index) const;


	// Îïåðàòîð [] 
	char& operator[](size_t index);


	// Ñìîòðè ïðèìåð 
	void RTrim(char symbol);


	// Ñìîòðè ïðèìåð 
	void LTrim(char symbol);

	friend std::ostream & operator<<(std::ostream &, const TString &);
};

// Îïåðàòîð +  
TString operator+(const TString & a, const TString & b);


// Îïåðàòîð !=
bool operator!=(const TString & a, const TString & b);


// Îïåðàòîð &gt;
bool operator>(const TString & a, const TString & b);


// Îïåðàòîð âûâîäà 
std::ostream & operator<<(std::ostream &out, const TString &str);

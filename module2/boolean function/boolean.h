#pragma once
#ifndef __BOOLEAN_FUNCTION_INCLUDED__
#define __BOOLEAN_FUNCTION_INCLUDED__

#include <string>
#include <iostream>
#include <vector>

class boolean_function
{
public:
	using value_type = bool;
	using size_type = size_t;
	using reference = std::vector<value_type>::reference;
	using const_reference = std::vector<value_type>::const_reference;

	using iterator = std::vector<value_type>::iterator;
	using const_iterator = std::vector<value_type>::const_iterator;

private:
	std::vector<value_type> func;

public:

	// возвращает функцию которая равна xn с размерностью dimension
	// пример 1
	// n = 0
	// dimension = 3
	// вернется функция "01010101"
	// пример 2
	// n = 1
	// dimension = 4
	// вернется функция "0011001100110011"
	static boolean_function var(size_t n, size_t dimension)
	{
		
		int len = pow(2, dimension);
		int k = pow(2, n);

		std::vector<value_type> res;
		while (res.size() != len)
		{
			for (int j = 0; j != k; j++)
				res.push_back(0);
			for (int j = 0; j != k; j++)
				res.push_back(1);
		}
		
		boolean_function f(res);
		return f;
	}

	// тождественный ноль "от dimension переменных"
	static boolean_function zero(size_t dimension)
	{
		std::vector<value_type> res;
		int len = pow(2, dimension);
		while (res.size() != len)
		{
			res.push_back(0);
		}
		boolean_function f(res);
		return f;
	}

	// тождественная единица "от dimension переменных"
	static boolean_function one(size_t dimension)
	{
		std::vector<value_type> res;
		int len = pow(2, dimension);
		while (res.size() != len)
		{
			res.push_back(1);
		}
		boolean_function f(res);
		return f;
	}
	
	static boolean_function from_anf(std::vector<value_type> v)
	{
		int len = v.size();
		int** mas = new int*[len];
		for (int i = 0; i < len; i++)
		{
			mas[i] = new int[len];
			for (int j = 0; j < len; j++)
				mas[i][j] = 0;
		}
		
		for (int i = 0; i < len; i++)
		{
			if (v[i] == false)
				mas[0][i] = 0;
			else
				mas[0][i] = 1;
		}

		for (int i = len - 2; i > -1; i--)
		{
			for (int j = 1; j < len - i; j++)
			{
				mas[j][i] = (mas[j - 1][i] + mas[j - 1][i + 1]) % 2;
			}
		}

		std::vector<value_type> res;
		for (int i = 0; i < len; i++)
			res.push_back(mas[i][0]);

		boolean_function f(res);

		for (int i = 0; i < len; i++)
			delete[] mas[i];
		
		return f;
	}
	
	boolean_function() = default;

	// задает фунцию тождественного нуля от n переменных
	boolean_function(size_t n)
	{
		int k = pow(2, n);
		for (int i = 0; i < k; i++)
			func.push_back(0);
	}

	// задает фунцию от n переменных. значение равно value
	// пример
	// пусть value = 14, т.е. 0...00001110 в двоичной системе
	// а n = 3
	// тогда АНФ boolean_function будет равна x + y + xy + zx + zy + zyx
	boolean_function(unsigned long long value, size_type n)
	{
		int i = 0;
		while (value > 0)
		{
			func.push_back(value % 2);
			i++;
			value /= 2;
		}
		int len = pow(2, n);
		for (i; i < len; i++)
		{
			func.push_back(0);
		}
	}
	

	// пусть table = "01110000"
	// тогда АНФ boolean_function будет равна x + y + xy + zx + zy + zyx
	boolean_function(const std::string& table)
	{
		for (int i = 0; i < table.size(); i++)
		{
			if (table[i] == '0')
				func.push_back(false);
			else
				func.push_back(true);
		}
	}

	// пусть table = {true, false, false, true};
	// тогда АНФ boolean_function будет равна x + y + 1
	boolean_function(const std::vector<value_type>& table)
	{
		func = table;
	}
	boolean_function(const std::initializer_list<bool> vars)
	{
		for (auto &v : vars)
		{
			func.push_back(v);
		}
	}

	boolean_function(const boolean_function& table)
	{
		func = table.func;
	}

	boolean_function& operator=(const boolean_function& rhs)
	{
		func = rhs.func;
		return *this;
	}

	// сложение по модулю 2
	// если разное количество переменных - исключение
	boolean_function& operator += (const boolean_function& rhs)
	{
		if (func.size() != rhs.func.size())
			throw std::exception("Lengh error\n");

		for (int i = 0; i < size(); i++)
		{
			func[i] = (func[i] + rhs.func[i]) % 2;
		}
		return *this;
	}

	// конъюнкция
	// если разное количество переменных - исключение
	boolean_function& operator *= (const boolean_function& rhs)
	{
		if (func.size() != rhs.func.size())
			throw std::exception("Lengh error\n");
		for (int i = 0; i < size(); i++)
		{
			func[i] = (func[i] * rhs.func[i]);
		}
		return *this;
	}

	// дизъюнкция
	// если разное количество переменных - исключение
	boolean_function& operator |= (const boolean_function& rhs)
	{
		if (func.size() != rhs.func.size())
			throw std::exception("Lengh error\n");
		for (int i = 0; i < size(); i++)
		{
			if (func[i] == 1 || rhs.func[i] == 1)
				func[i] = 1;
		}
		return *this;
	}

	// побитовое отрицание
	boolean_function operator ~()
	{
		for (int i = 0; i < size(); i++)
		{
			if (func[i] == 1)
				func[i] = 0;
			else
				func[i] = 1;
		}
		return *this;
	}

	// true если функции равны
	//  иначе false
	bool operator == (const boolean_function& v) const
	{
		if (size() != v.size())
		{
			bool fl1 = false;
			bool fl2 = false;
			int i = 0;
			int j = 0;
			while (true)
			{
				if (i >= func.size())
				{
					fl1 = true;
					i = 0;
				}
				if (j >= v.size())
				{
					fl2 = true;
					j = 0;
				}
				if (fl1 && fl2)
					return true;
				if (func[i] != v.func[j])
				{
					return false;
				}
				i++;
				j++;
			}
		}

		bool fl = true;
		for (int i = 0; i < func.size(); i++)
		{
			if (func[i] != v.func[i])
			{
				fl = false;
				break;
			}
		}
		return fl;
	}

	// true если одна функция сравнима и больше или равна rhs
	// false если сравнима и меньше rhs
	// logic_error если фунции не сравнимы
	bool operator >= (const boolean_function& rhs) const
	{
		if (size() != rhs.size())
			throw std::exception("logic_error\n");

		int fl1 = 0;
		int fl2 = 0;
		for (int i = 0; i < size(); i++)
		{
			if (func[i] > rhs.func[i])
				fl1 = 1;
			if (func[i] < rhs.func[i])
				fl2 = 2;
		}
		if (fl1 != 0 && fl2 != 0)
			throw std::exception("logic_error\n");
		else if (fl1 != 0 && fl2 == 0 || fl1 == 0 && fl2 == 0)
			return true;
		else
			return false;

	}

	reference operator[](size_type ind)
	{
		if (size() == 0)
			throw std::exception("out of range\n");
		if (ind < 0 || ind >= size())
			throw std::exception("out of range\n");
		return func[ind];
	}
	const_reference operator[](size_type ind) const
	{
		if (size() == 0)
			throw std::exception("out of range\n");
		if (ind < 0 || ind >= size())
			throw std::exception("out of range\n");
		return func[ind];
	}

	reference at(size_type ind)
	{
		if (size() == 0)
			throw std::exception("out of range\n");
		if (ind < 0 || ind >= size())
			throw std::exception("out of range\n");
		return func[ind];
	}
	const_reference at(size_type ind) const
	{
		if (size() == 0)
			throw std::exception("out of range\n");
		if (ind < 0 || ind >= size())
			throw std::exception("out of range\n");
		return func[ind];
	}

	iterator begin()
	{
		return func.begin();
	}
	iterator end()
	{
		return func.end();
	}

	const_iterator cbegin() const
	{
		return func.cbegin();
	}
	const_iterator cend() const
	{
		return func.cend();
	}

	// длина столбца функции
	size_type size() const throw()
	{
		return func.size();
	}

	// количество переменных
	size_type dimension() const throw()
	{
		int k = 0;
		int len = func.size();
		for (k; len > 1; k++)
			len /= 2;
		return k;
	}

	// возвращает значение функции
	// пусть boolean_function задает функцию f(x, y, z)
	// тогда функция вернет f(vars[0], vars[1], vars[2])
	bool operator()(const std::vector<bool>& vars) const
	{
		std::string num;
		for (int i = 0; i < vars.size(); i++)
		{
			if (vars[i] == false)
				num += "0";
			else
				num += "1";
		}
		int res = 0;
		int k = 0;
		for (int i = num.size() - 1; i > -1; i--)
		{
			res += pow(2, k) * num[i];
			k++;
		}
		return func[res];
	}
	bool operator()(const std::initializer_list<bool> vars) const
	{
		std::string num;
		for (auto &v : vars)
		{
			if (v == false)
				num += "0";
			else
				num += "1";
		}
		int res = 0;
		int k = 0;
		for (int i = num.size() - 1; i > -1; i--)
		{
			if (num[i] == '1')
				res += pow(2, k);
			k++;
		}
		return func[res];
	}


	// T(x1, x2, ..., xN) - текущая функция
	// operator вернет новую функцию, которая равна композиции G = T(fs[0], fs[1], ..., fs[N-1])
	boolean_function operator()(const std::vector<boolean_function>& fs) const
  {
		std::vector<value_type> res;
		std::vector<boolean_function> f;

		int s = 0;
		for (int i = 0; i < fs.size(); i++)
		{
			if (fs[i].size() > s)
				s = fs[i].size();
			f.push_back(fs[i]);
		}

		int len = fs.size();
		int** mas = new int*[s];
		for (int i = 0; i < s; i++)
		{
			mas[i] = new int[len];
		}

		int k = 0;
		int it = 0;
		while (it < f.size())
		{
			for (int i = 0; i < len; i++)
			{
				for (int j = 0; j < s; j++)
				{
					if (j >= f[it].size())
						mas[j][i] = 0;
					else
						mas[j][i] = f[it][j];
				}
				it++;
			}
		}

		for (int i = 0; i < s; i++)
		{
			int ch = 0;
			int st = 0;
			for (int j = len - 1; j > -1; j--)
			{
				ch = ch + pow(2, st)*mas[i][j];
				st++;
			}
			res.push_back(func[ch]);
		}

		boolean_function result(res);
		return result;
	}
	boolean_function operator()(const std::initializer_list<boolean_function> vars) const
	{
		std::vector<value_type> res;
		std::vector<boolean_function> f;
		
		int s = 0;
		for (auto &v : vars)
		{
			if (v.size() > s)
				s = v.size();
			f.push_back(v);
		}
		
		int len = vars.size();
		int** mas = new int*[s];
		for (int i = 0; i < s; i++)
		{
			mas[i] = new int[len];
		}

		int k = 0;
		int it = 0;
		while (it < f.size())
		{
			for (int i = 0; i < len; i++)
			{
				for (int j = 0; j < s; j++)
				{
					if (j >= f[it].size())
						mas[j][i] = 0;
					else
						mas[j][i] = f[it][j];
				}
				it++;
			}
		}

		for (int i = 0; i < s; i++)
		{
			int ch = 0;
			int st = 0;
			for (int j = len - 1; j > -1; j--)
			{
				ch = ch + pow(2, st)*mas[i][j];
				st++;
			}
			res.push_back(func[ch]);
		}

		boolean_function result(res);
		return result;
	}
	
	bool is_monotone() const
	{
		if (size() == 0)
			throw std::exception("empty\n");
		
		if (size() == 1)
			return true;

		int len = func.size();
		bool fl = true;
		for (int i = 0; i < len - 1; i++)
		{
			if (func[i] > func[i + 1])
			{
				fl = false;
				break;
			}
		}
		return fl;
	}
	bool is_symmetric() const
	{
		std::vector<value_type> res;
		for (int i = func.size() - 1; i > -1; i--)
		{
			if (func[i] == 1)
				res.push_back(0);
			else
				res.push_back(1);
		}

		if (res != func)
			return false;
		else
			return true;

	}
	bool is_linear() const
	{
		std::vector<value_type> f = anf();
		bool fl = true;
		int k;
		int ch;
		for (int i = 0; i < f.size(); i++)
		{
			k = 0;
			ch = i;
			while (ch > 0)
			{
				k += ch % 2;
				ch /= 2;
			}
			if (k != 1 && i != 0)
			{
				if (f[i] != 0)
				{
					fl = false;
					break;
				}
			}
		}
		return fl;
	}
	bool is_T1() const
	{
		return (func[func.size()-1] == 1);
	}
	bool is_T0() const
	{
		return (func[0] == 0);
	}
	bool is_balanced() const //равновесная ли
	{
		int len = size();
		if (len == 0)
			return false;

		int k = weight();
		if (k != len / 2)
			return false;
		else
			return true;

	}
	size_t weight() const
	{
		int k = 0;
		for (int i = 0; i < size(); i++)
		{
			if (func[i])
				k++;
		}
		return k;
	}

	bool is_functionally_complete_system() const
	{
		bool fT0 = is_T0();
		bool fT1 = is_T1();
		bool s = is_symmetric();
		bool l = is_linear();
		bool m = is_monotone();
		if (fT0 == false && fT1 == false && s == false && l == false && m == false)
			return true;
		else
			return false;
		
	}

	// Возвращает АНФ функции
	std::vector<value_type> anf() const
	{
		const int len = func.size();
		std::vector<value_type> f;
		
		int** mas = new int*[len];
		for (int i = 0; i < len; i++)
		{
			mas[i] = new int[len];
			for (int j = 0; j < len; j++)
				mas[i][j] = 0;
		}
		
		for (int i = 0; i < len; i++)
			mas[i][0] = func[i];
		
		for (int i = 1; i < len; i++)
		{
			for (int j = 0; j < len - i; j++)
			{
				mas[j][i] = (mas[j][i - 1] + mas[j + 1][i - 1]) % 2;
			}
		}
		
		for (int i = 0; i < len; i++)
			f.push_back(mas[0][i]);
		
		for (int i = 0; i < len; i++)
			delete[] mas[i];
		
		return f;
	}
};

// пусть boolean_function представляет из себя функцию "01110000"
// тогда get_polynom вернет строку "x0 + x1 + x0x1 + x0x2 + x1x2 + x0x1x2"
std::string get_polynom(const boolean_function& v)
{
	boolean_function c = v.anf();
	std::string res;
	for (int i = 0; i < c.size(); i++)
	{
		if (c[i] != 0)
		{
			if (i == 0)
			{
				res += "1";
				res += " + ";
				continue;
			}
			int ch = i;
			std::vector<int> num;
			while (ch > 0)
			{
				num.push_back(ch % 2);
				ch /= 2;
			}
			for (int j = 0; j < num.size(); j++)
			{
				if (num[j] == 1)
				{
					res += "x";
					res += std::to_string(j+1);
				}
			}
			if (i + 1 != c.size())
				res += " + ";
		}
	}
	return res;
}

boolean_function operator + (const boolean_function& a, const boolean_function& b)
{
	boolean_function f(a);
	f += b;
	return f;
}

boolean_function operator * (const boolean_function& a, const boolean_function& b)
{
	boolean_function f(a);
	f *= b;
	return f;
}

boolean_function operator | (const boolean_function& a, const boolean_function& b)
{
	boolean_function f(a);
	f |= b;
	return f;
}

bool operator != (const boolean_function& a, const boolean_function& b)
{
	return !(a == b);
}


#endif // __BOOLEAN_FUNCTION_INCLUDED__

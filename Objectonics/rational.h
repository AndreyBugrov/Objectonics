#pragma once
#include "exc_class.h"
class Rational
{
private:
	int num;
	unsigned den;
	unsigned NOD(unsigned min, unsigned max)
	{
		if (max % min == 0)
		{
			return min;
		}
		else
		{
			unsigned min_tmp = min, max_tmp = max, tmp;
			while (max_tmp % min_tmp)
			{
				tmp = max_tmp;
				max_tmp = min_tmp;
				min_tmp = tmp % min_tmp;
			}
			return min_tmp;
		}
	}
	unsigned NOK(int& one, int& two) //////////////////////////////////
	{
		bool neg_one = false, neg_two = false;
		if (one < 0) {
			one *= -1;
			neg_one = true;
		}
		if (two < 0) {
			two *= -1;
			neg_two = true;
		}
		unsigned nod;
		if (one > two) {
			nod = NOD(two, one);
		}
		else {
			nod = NOD(one, two);
		}
		int unic_one = one / nod, unic_two = two / nod;
		int nok = unic_one * unic_two * nod;
		one *= unic_two;
		two *= unic_one;
	}
	void to_common_den(int& _num, const unsigned& _den)
	{
		num *= _den;
		_num *= den;
	}
	void reduction() //Сокращение дроби на НОД числителя и знаменателя
	{
		if (num == 0)
		{
			den = 1;
			return;
		}
		unsigned p_tmp, nod;//p_tmp - чтобы не потерять значения при переходе в беззнаковые
		if (num < 0)
			p_tmp = (-1) * num;
		else
			p_tmp = num;
		if (p_tmp < den)
			nod = NOD(p_tmp, den);
		else
			nod = NOD(den, p_tmp);
		num /= int(nod);
		den /= nod;
	}
public:
	Rational& operator+(const Rational& r) // Should we use NOD ?
	{
		int _num = r.num;
		unsigned _den = r.den;
		to_common_den(_num, _den);
		num += r.num;
		den *= r.den;
		reduction();
	}
	Rational& operator-(const Rational& r)
	{
		int _num = r.num;
		unsigned _den = r.den;
		to_common_den(_num, _den);
		num -= r.num;
		den *= r.den;
		reduction();
	}
	Rational& operator*(const Rational& r)
	{
		num *= r.num;
		den *= r.den;
		reduction();
	}
	Rational& operator/(const Rational& r)
	{
		if (r.num < 0) {
			int tmp_num = -r.num;
			den *= tmp_num;
			num *= -r.den;
		}
		else {
			num *= r.den;
			den *= r.num;
			reduction();
		}
	}
	Rational& operator*(int k) 
	{
		num *= k;
		reduction();
	}
	Rational& operator/(int k)
	{
		if (k < 0) {
			num *= -1;
			k *= -1;
		}
		den *= k;
		reduction();
	}
	Rational(int a = 0, unsigned b = 1)
	{
		if (b == 0)
			throw Exc_class(Exc_class::DIVIDING_BY_ZERO_IN_RATIONAL);
		num = a;
		den = b;
		reduction();
	}
	void operator = (const Rational& r)
	{
		num = r.num;
		den = r.den;
	}
	int round()
	{
		if (num >= 0)
		{
			return num / den;
		}
		if ((-num) < den)
		{
			return -1;
		}
		long long tmp = long long(num) / long long(den);
		return int(tmp);
	}
};
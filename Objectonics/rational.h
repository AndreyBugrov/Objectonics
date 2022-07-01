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
	Rational& operator*(const int& k);
	Rational& operator/(const int& k);
	Rational out() const
	{
		return *this;
	}
	Rational(int a = 0, unsigned b = 1) /////dividing by zero ?
	{
		num = a;
		den = b;
		reduction();
	}
	void operator = (const Rational& r)
	{
		num = r.num;
		den = r.den;
	}
};
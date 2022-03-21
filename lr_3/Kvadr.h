#pragma once
#include "Uravnenie.h"
//ax^2+bx+c=y

class Quadr : public Equation
{
private:
	double a;
	double b;
	double c;
	double y;
	static int count;


public:
	Quadr();
	Quadr(double  m_a, double m_b, double m_c, double m_y);
	Quadr(const Quadr& copy_quadr);
	void set_coeff(double a, double b, double c, double y);
	virtual ~Quadr() {};
	virtual void Root() override final;
	virtual void saving_to_file() override;
	int get_count();
};

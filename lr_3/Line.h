#pragma once
#include "Uravnenie.h"
#include <fstream>
#include <string>
//kx+b=y
class Linear : public Equation
{
private:
	float a;
	float b;
	float y;
	static int count;

public:
	//������������
	Linear();//�� ��������� 
	Linear(float m_a, float m_b, float m_y);//� �����������
	Linear(const Linear& copy_line);//�����������
	void set_coeff(float a, float b, float y);
	virtual ~Linear() {}
	virtual void Root() override;
	virtual void saving_to_file() override;
	int get_count();
};
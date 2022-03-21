#pragma once
//abstract class
class Equation
{
public:
	Equation() {};
	virtual ~Equation() {};
	virtual void Root() = 0;
	virtual int get_count() = 0;
	virtual void saving_to_file() = 0;
};
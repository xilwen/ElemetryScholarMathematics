//written by 

#ifndef OPERATION_H
#define OPERATION_H

class Operation
{
public:
	Operation() = delete;

	inline double Addition(double num1, double num2){ return num1 + num2; }
	inline double Subtraction(double num1, double num2){ return num1 - num2; }
	inline double Multiplication(double num1, double num2){ return num1*num2; }
	inline double Division(double num1, double num2){ return num1 / num2; }
	
private:

};

#endif

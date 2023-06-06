#include <iostream>
#include <sstream>
using namespace std;

class Figura {
protected:
	string tipo;
public:
	Figura(string);
	virtual ~Figura();
	string getTipo();
	virtual double area() = 0;
	virtual double perimetro() = 0;
};

Figura::Figura(string tip) : tipo(tip)
{
}

Figura::~Figura()
{
}

string Figura::getTipo()
{
	return tipo;
}

class Circulo : public Figura {
private:
	double radio;
public:
	Circulo(string, double);
	double area();
	double perimetro();
};

Circulo::Circulo(string fig, double rad):Figura(fig), radio(rad)
{
}

double Circulo::area()
{
	return 3.141516 * radio * radio;
}

double Circulo::perimetro()
{
	return 2 * 3.141516 * radio;
}

class Cuadrado : public Figura {
private:
	double lado;
public:
	Cuadrado(string, double);
	double area();
	double perimetro();
};

Cuadrado::Cuadrado(string fig, double lad) :Figura(fig), lado(lad)
{
}

double Cuadrado::area()
{
	return lado * lado;
}

double Cuadrado::perimetro()
{
	return 4 * lado;
}


class Triangulo : public Figura {
private:
	double lado; // Triangulo equilatero
public:
	Triangulo(string, double);
	double area();
	double perimetro();
};

Triangulo::Triangulo(string fig, double lad) : Figura(fig), lado(lad)
{
}

double Triangulo::area()
{
	return 0; // formula de Heron
}

double Triangulo::perimetro()
{
	return 3 * lado;
}

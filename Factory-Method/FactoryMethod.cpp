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


class CreadorDeFigura {
public:
	virtual Figura* creaFigura() = 0;
};

class CreadorDeCirculo : public CreadorDeFigura {
public:
	virtual Figura* creaFigura();
};

Figura* CreadorDeCirculo::creaFigura()
{
	return new Circulo("Circulo", 10);
}

class CreadorDeCuadrado : public CreadorDeFigura {
public:
	virtual Figura* creaFigura();
};

Figura* CreadorDeCuadrado::creaFigura()
{
	return new Cuadrado("Cuadrado", 10);
}

class CreadorDeTriangulo : public CreadorDeFigura {
public:
	virtual Figura* creaFigura();
};

Figura* CreadorDeTriangulo::creaFigura()
{
	return new Triangulo("Triangulo", 10);
}

//-------------------------------------------------------------------
//----------------------Manejador de figuras-------------------------

class ManejadorDeFigura {
private:
	Figura* figura;
	CreadorDeFigura* creador;
public:
	void setCreador(CreadorDeFigura* cread) {
		creador = cread;
	}
	void crearFigura() {
		figura = creador->creaFigura();
	}
	Figura* getFigura() {
		return figura;
	}
};


int main() {
	Figura* miFigura = nullptr;
	CreadorDeFigura* cf1 = nullptr;
	ManejadorDeFigura* mf = new ManejadorDeFigura();

	int op = 0;

	cout << "----------Menu----------\n";
	cout << "------------------------\n";
	cout << "1- Crea circulo\n";
	cout << "2- Crea cuadrado\n";
	cout << "3- Crea triangulo\n";
	cout << "------------------------\n" << endl;
	cout << "Digite la opcion: ";
	cin >> op;
	switch (op) {
	case 1: cf1 = new CreadorDeCirculo(); break;
	case 2: cf1 = new CreadorDeCuadrado(); break;
	case 3: cf1 = new CreadorDeTriangulo(); break;
	};
	mf->setCreador(cf1);
	mf->crearFigura();
	miFigura = mf->getFigura();

	cout << "Se acaba de crear la figura...." << endl;
	cout << miFigura->getTipo() << endl;
	cout << "Area de la figura: " << miFigura->area() << endl;
	cout << "Perimetro de la figura: " << miFigura->perimetro() << endl;

	return 0;
}



// Tarea moral
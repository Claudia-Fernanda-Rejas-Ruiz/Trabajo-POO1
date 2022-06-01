#include<string>
using namespace std;
class Venta
{
private:
	int 	codigo;
	string	nombre;

public:
	Venta()
	{

	}

	~Venta()
	{

	}
	void	setCodigo(int cod)
	{
		codigo = cod;
	}
	void	setNombre(string nom)
	{
		nombre = nom;
	}

	int 	getCodigo()
	{
		return this->codigo;
	}
	string 	getNombre()
	{
		return this->nombre;
	}
};

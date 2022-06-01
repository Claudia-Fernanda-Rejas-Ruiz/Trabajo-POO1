#include<string>
using namespace std;
class Cliente
{
private:
	int 	orden;
  int codigo; 
	string	nombre;

public:
	Cliente()
	{

	}

	~Cliente()
	{

	}
	void	setOrden(int ord)
	{
		orden = ord;
	}
  void	setCodigo(int cod)
	{
		codigo = cod;
	}
	void	setNombre(string nom)
	{
		nombre = nom;
	}

	int 	getOrden()
	{
		return this->orden;
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

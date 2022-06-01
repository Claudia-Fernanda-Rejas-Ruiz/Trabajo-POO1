#include<iostream>
#include<vector>
#include<fstream>
#include"cliente.h"
using std::stoi;
using namespace std;
class ClienteVector
{
	private:
		vector<Cliente> vectorCliente;
	public:
		ClienteVector()
		{
			cargarDatosDelArchivoAlVector();
			vector<Cliente> vectorCliente;
		}
		int getCorrelativo()
		{
			if(vectorCliente.size() == 0)
			{
				return 1;
			}
			else
			{
				return vectorCliente[vectorCliente.size() - 1].getOrden() + 1;
			}
		}
		
		void add(Cliente obj)/*Agrgar Objetos al Vector*/
		{
			vectorCliente.push_back(obj);
		}
		
		Cliente get(int pos)/*entregar el objeto actual, según la posicion pasada como parámetro*/
		{
			return vectorCliente[pos];
		}
		
		int rows()
		{
			return vectorCliente.size();
		}
		
		
		Cliente buscarPorOrden(int orden)
		{
			for(int i=0;i<rows();i++)			
			{
				if(orden == get(i).getOrden())
				{
					return get(i);
				}
			}
		}
		
		int getPostArray(Cliente obj)
		{
			for(int i=0;i<rows();i++)
			{
				if(obj.getOrden() == get(i).getOrden())
				{
					return i;
				}
			}
			return -1;
		}
		
		
		void grabarEnArchivo(Cliente cliente)
		{
			try
			{
				fstream archivoCliente;
				archivoCliente.open("clientes.csv",ios::app);
				if(archivoCliente.is_open())
				{
					archivoCliente<<cliente.getOrden()<<"; "<<cliente.getCodigo()<<"; "<<cliente.getNombre()<<";"<<endl;
					archivoCliente.close();
				}
			}			
			catch(exception e)
			{
				cout<<"Ocurrio un error al grabar el registro!!!";
			}
		}
	void grabarModificarEliminarArchivo()
	{
		try
		{
			fstream archivoClientes;
			archivoClientes.open("clientes.csv", ios::out);
			if (archivoClientes.is_open())
			{
				for (Cliente x : vectorCliente)
				{
					archivoClientes << x.getOrden() << ";" <<x.getCodigo()<<"; "<< x.getNombre() << ";" << "\n";
					
				}
				archivoClientes.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar en el archivo";
		}
	}

void cargarDatosDelArchivoAlVector()
{
	try
	{
		int i;
		size_t posi;//Cantidad maxima
		string linea;
		string temporal[3];//Cantidad de columnas
		fstream archivoCliente;
		archivoCliente.open("clientes.csv", ios::in);
		if (archivoCliente.is_open())
		{
			while (!archivoCliente.eof()) 
			{
				while (getline(archivoCliente, linea))
				{
					i = 0;
					while ((posi = linea.find(";")) != string::npos) 
					{/*string::npos es -1, termina cuando llega a este punto*/
						temporal[i] = linea.substr(0, posi);/*posi = Es la cantidad de caracteres antes del ;*/
						linea.erase(0, posi + 1);//borra la palabra de la primera posición encontrada   y con el +1 incluye hasta el ; y luego borra ese elemento, para que en la siguiente iteracion iniciar con la siguiente palabra y de ese modo seguir el proceso , 
						i++;
					}
					//Asignando los valores al vector
					Cliente cliente;
					cliente.setOrden(std::stoi(temporal[0]));
          cliente.setCodigo(std::stoi(temporal[1]));
					cliente.setNombre(temporal[2]);
					add(cliente);
				}
			}
		}
		archivoCliente.close();
	}
	catch (exception e)
	{
		cout << "Ocurrio un error al leer el archivo";
	}
}
};

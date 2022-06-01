#include<iostream>
#include<vector>
#include<fstream>
#include"venta.h"
using std::stoi;
using namespace std;
class VentaVector
{
	private:
		vector<Venta> vectorVenta;
	public:
		VentaVector()
		{
			cargarDatosDelArchivoAlVector();
			vector<Venta> vectorVenta;
		}
		int getCorrelativo()
		{
			if(vectorVenta.size() == 0)
			{
				return 1;
			}
			else
			{
				return vectorVenta[vectorVenta.size() - 1].getCodigo() + 1;
			}
		}
		
		void add(Venta obj)/*Agrgar Objetos al Vector*/
		{
			vectorVenta.push_back(obj);
		}
		
		Venta get(int pos)/*entregar el objeto actual, según la posicion pasada como parámetro*/
		{
			return vectorVenta[pos];
		}
		
		int rows()
		{
			return vectorVenta.size();
		}
		
		
		Venta buscarPorCodigo(int codigo)
		{
			for(Venta x:vectorVenta)
			{
				if(codigo == x.getCodigo())
				{
					return x;
				}
			}
		}
		Venta buscarPorCodigo2(int codigo)
		{
			for(int i=0;i<rows();i++)			
			{
				if(codigo == get(i).getCodigo())
				{
					return get(i);
				}
			}
		}
		
		int getPostArray(Venta obj)
		{
			for(int i=0;i<rows();i++)
			{
				if(obj.getCodigo() == get(i).getCodigo())
				{
					return i;
				}
			}
			return -1;
		}
		
		void remove(Venta obj)
		{
			vectorVenta.erase(vectorVenta.begin() + getPostArray(obj));	
		}
		
		
		bool modificar(Venta obj, string nom)
		{
			for(int i=0;i<rows();i++)
			{
				if(obj.getCodigo() == get(i).getCodigo())
				{
					vectorVenta[i].setNombre(nom);
					return true;
				}
			}
			return false;
		}
		void grabarEnArchivo(Venta venta)
		{
			try
			{
				fstream archivoVenta;
				archivoVenta.open("ventas.csv",ios::app);
				if(archivoVenta.is_open())
				{
					archivoVenta<<venta.getCodigo()<<";"<<venta.getNombre()<<";"<<endl;
					archivoVenta.close();
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
			fstream archivoVentas;
			archivoVentas.open("ventas.csv", ios::out);
			if (archivoVentas.is_open())
			{
				for (Venta x : vectorVenta)
				{
					archivoVentas << x.getCodigo() << ";" << x.getNombre() << ";" << "\n";
					
				}
				archivoVentas.close();
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
		string temporal[2];//Cantidad de columnas
		fstream archivoVenta;
		archivoVenta.open("alumnos.csv", ios::in);
		if (archivoVenta.is_open())
		{
			while (!archivoVenta.eof()) 
			{
				while (getline(archivoVenta, linea))
				{
					i = 0;
					while ((posi = linea.find(";")) != string::npos) 
					{/*string::npos es -1, termina cuando llega a este punto*/
						temporal[i] = linea.substr(0, posi);/*posi = Es la cantidad de caracteres antes del ;*/
						linea.erase(0, posi + 1);//borra la palabra de la primera posición encontrada   y con el +1 incluye hasta el ; y luego borra ese elemento, para que en la siguiente iteracion iniciar con la siguiente palabra y de ese modo seguir el proceso , 
						i++;
					}
					//Asignando los valores al vector
					Venta venta;
					venta.setCodigo(std::stoi(temporal[0]));
					venta.setNombre(temporal[1]);
					add(venta);
				}
			}
		}
		archivoVenta.close();
	}
	catch (exception e)
	{
		cout << "Ocurrio un error al leer el archivo";
	}
}
};

#include<iostream>
#include<vector>
#include<cstring>
#include"ventaVector.h"
//Crear un Objeto
VentaVector ventaVector;//Instancia de la clase AlumnoVector
//Prototipos
void 	menuDeOpciones();
void 	adicionarVentas();
void 	eliminarVentas();
void	modificarVentas();
void	buscarVenta();
void	listarVentas();
int main()
{
	menuDeOpciones();
}
//Implementacion
void menuDeOpciones()
{
	//Declarar Variables
	int opt;
	do
	{
		cout<<"MENU DE OPCIONES\n";
		cout<<"Ingresar Nuevas Ventas		[1]\n";
		cout<<"Eliminar las Ventas		[2]\n";
		cout<<"Modificar las Ventas		[3]\n";
		cout<<"Buscar las Ventas		[4]\n";
		cout<<"Listar de Ventas		[5]\n";
		cout<<"Salir				[6]\n";
		cout<<"Ingrese una opcion[1-6]:";
		cin>>opt;
		switch(opt)
		{
			case 1:	system("cls");
					adicionarVentas();
					break;
			case 2:system("cls");eliminarVentas();break;
			case 3:system("cls");modificarVentas();break;
			case 4:system("cls");buscarVenta();break;
			case 5:	system("cls");listarVentas();break;
			case 6:	cout<<"###########Gracias por tu compra##########\n";
					exit(0);
					break;
			default:cout<<"Ingrese una opcion correcta[1-6]"<<endl;
		}
	}
	while(opt!=6);
}
void adicionarVentas()
{
	//Crear Variables
	int 	cod;
	string 	nom,
			rpta;
	//Crear el Objeto de la clase alumno
	do
	{	
		//Entrada de datos
		cod = ventaVector.getCorrelativo();
		
		cout<<"Codigo("<<cod<<")"<<endl;
		cin.ignore();
		cout<<"Ingresar Nombre:";
		getline(cin,nom);
		
		Venta venta;/*Crear el Objeto*/
		
		venta.setCodigo(cod);
		venta.setNombre(nom);
		
		
		ventaVector.add(venta);//Agregar el Objeto al vector dinamico
		
		ventaVector.grabarEnArchivo(venta);
		cout<<"Para continuar pulsar(SI o si):";
		cin>>rpta;
		system("cls");//Limpiar
	}
	while(rpta=="SI" || rpta=="si");

}
void listarVentas()
{
	for(int i=0;i<ventaVector.rows();i++)
	{
		cout<<ventaVector.get(i).getCodigo()<<"-"<<ventaVector.get(i).getNombre()<<"\n";	
	}	
	system("pause");
	system("cls");
}
void eliminarVentas()
{
	int cod;
	cout<<"Ingresar el codigo a eliminar:";
	cin>>cod;
	Venta objAEliminar = ventaVector.buscarPorCodigo(cod);	
	if(objAEliminar.getNombre() != "Error")
	{
		ventaVector.remove(objAEliminar);
		cout<<"Registro Eliminado Satisfactoriamente";
		ventaVector.grabarModificarEliminarArchivo();
	}
	else
	{
		cout<<"No se encontro el registro!\n";
	}
	system("cls");
}
void modificarVentas()
{
	int cod;
	cout<<"Ingresar el codigo a modificar:";
	cin>>cod;
	Venta objAModificar = ventaVector.buscarPorCodigo(cod);	
		
	cout<<"Registro Encontrado\n";
	cout<<"Codigo:"<<objAModificar.getCodigo()<<"\n";
	cout<<"Nombre:"<<objAModificar.getNombre()<<"\n";
	cin.ignore();
	
	string nomModificado;
	cout<<"Modificar campos\n";
	getline(cin,nomModificado);
	bool estado = ventaVector.modificar(objAModificar,nomModificado);	
	if(estado = true)
	{
		cout<<"Registro Modificado Satisfactoriamente\n";
		/*Grabar en archivo*/
		ventaVector.grabarModificarEliminarArchivo();
	}
	else
	{
		cout<<"No se Edito el registro!\n";
		system("pause");
		menuDeOpciones();
	}
	system("pause");
	system("cls");
}
void buscarVenta()
{
	int cod;
	cout<<"Ingresar el codigo a buscar:";
	cin>>cod;
	Venta ven = ventaVector.buscarPorCodigo(cod);	
	if(ven.getNombre() != "Error")
	{
		cout<<"Registro Encontrado\n";
		cout<<"Codigo:"<<ven.getCodigo()<<"\n";
		cout<<"Nombre:"<<ven.getNombre()<<"\n";
	}
	else
	{
		cout<<"No se encontro el registro!\n";
		system("pause");
		menuDeOpciones();
	}
	system("pause");	
}





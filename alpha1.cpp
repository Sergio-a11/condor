//proyecto condor

#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include<string.h>
#include<fstream>
//tildes
#include<wchar.h>
#include<locale.h>
using namespace std;
//variables
int opc=0;
//estructurass
struct admin
{
	string cod;
	string auxcod;
	string clave;
	string auxclave;	
}ad;

struct estudiante
{
	string cod;
	string auxcod;
	string nombre;
	string auxnombre;
	string sexo;
	string auxsexo;
	string carrera;
	string auxcarrera;
	string semestre;
	string auxsemestre;
	string facultad;
	string auxfacultad;
	string ano;
	string auxano;
	//se creo el aux de todos para buscar por filtros de lo que quiera
}alu;
//funciones
void menu();
void administrador();
void agregarEst();
void agregarMateria();
void agregarProfesor();
void consultarEst();
void consultarMaterias();
void consultarProfesor();
void eliminarEst();
void eliminarMaterias();
void eliminarProfesor();
void listarEst();
void listarProfesor();
void listarMaterias();

int main()
{
	setlocale(LC_ALL, "");//para tildes y acentos
	system("color 37");//fondo aguamarina y letra blanca suave//ammm no se si dejarlo
	//menu de inicio
	menu();
	return 0;
}

void administrador()
{
		//ofstream escritura;
		//escritura.open("usuarioAdmin.txt", ios::out|ios::app);
		bool ingreso=false;
		ifstream verificador;
		verificador.open("usuarioAdmin.txt", ios::in);
		if(verificador.is_open())
		{
			fflush(stdin);
			cout<<"por favor identifiquese: "<<endl;
			cout<<"Codigo: ";
			fflush(stdin);
			//cin.getline(ad.auxcod,5);
			getline(cin,ad.auxcod);
			cout<<"Clave: ";
			fflush(stdin);
			//cin.getline(ad.auxclave,5);
			getline(cin,ad.auxclave);
			//escritura<<ad.auxcod<<"\n\n"<<ad.auxclave<<"\n\n";
			//strcpy(ad.auxclave,ad.clave);
			//strcpy(ad.auxcod,ad.cod);
			//verificador.seekg(0);
			//fflush(stdin);
				getline(verificador,ad.cod);
			//	fflush(stdin);
				getline(verificador,ad.clave);
			while(!verificador.eof())
			{
				//para llamar el archivo con string s ahora se usa getline
				
				//verificador>>ad.cod>>ad.clave;
				//if(strcmp(ad.auxcod,ad.cod)==0)
				if(ad.auxcod==ad.cod and ad.auxclave==ad.clave)
				{
					//if(ad.auxclave==ad.clave)
					//if(strcmp(ad.auxclave,ad.clave)==0)
					//{
						ingreso=true;
						
					//}
					//else
					//{
					//	ingreso = false;
						//opc=0;	
						//break;
					//}	
				}
				//fflush(stdin);
				getline(verificador,ad.cod);
				//fflush(stdin);
				getline(verificador,ad.clave);
			}
		}
	if(ingreso==true)
	{
	do{
					system("cls");
					cout<<"Bienvenido Adnistrador"<<endl<<endl;
					cout<<"Seleccione una opción"<<endl;
					cout<<"1.Consultar"<<endl;
					cout<<"2.Eliminar"<<endl;
					cout<<"3.Añadir"<<endl;
					cout<<"4.Regresar"<<endl;
					cout<<"Seleccione una opción: ";
					cin>>opc;
					
					switch(opc)
					{
						case 1:
							//menu que desea consultar//por ahora
							do{
							system("cls");
							cout<<"1.Listar todos los estudinates"<<endl;
							cout<<"2.Buscar un estudiante especifico"<<endl;
							cout<<"3.Inicio del programa"<<endl;
							cout<<"4.Salir"<<endl;
							cout<<"Opción: ";
							cin>>opc;
							switch(opc)
							{
								case 1:
									listarEst();
								break;
								case 2:
									do
									{
									system("cls");	
									cout<<"Seleccione el filtro a usar: "<<endl;
									cout<<"1.Codigo:"<<endl;
									//agregar los otros
									cout<<"2.Inicio del programa"<<endl;
									cout<<"3.Salir"<<endl;
									cout<<"Opción: ";
									cin>>opc;
									
									switch(opc)
									{
										case 1:
										consultarEst();
										break;
										case 2:
											menu();
										break;				
									}
								}while(opc!=3);
								break;
								case 3:
									menu();
								break;
							}
						}while(opc!=4);
						break;
						case 2:
						break;
						case 3:
						break;
						case 4:
							menu();
						break;
					}
					
				}while(opc!=4);	
	}
	else if(ingreso==false)
	{
		cout<<"Acseso denegado"<<endl;
		system("pause");
		menu();	
	}		
}

void consultarEst()
{
	
	bool encontrado = false;
	ifstream consultar;
	consultar.open("estudiantes.txt",ios::in);
	if(consultar.is_open())
	{
		system("cls");
		fflush(stdin);
		cout<<"Digite el código del estudiante a consultar: ";
		getline(cin,alu.auxcod);
		getline(consultar,alu.cod);
		//cin.getline(alu.auxcod,30);
		//consultar>>alu.cod;
		//consultar.seekg(0);
		while(!consultar.eof())
		{
		//	fflush(stdin);
		//	consultar>>alu.nombre>>alu.sexo>>alu.carrera>>alu.semestre>>alu.facultad>>alu.ano;//cargar en ram
			/*consultar.getline(alu.nombre,sizeof(100));
			consultar.getline(alu.sexo,sizeof(20));
			consultar.getline(alu.carrera,sizeof(100));
			consultar.getline(alu.semestre,sizeof(20));
			consultar.getline(alu.facultad,sizeof(100));
			consultar.getline(alu.ano,sizeof(50));
			*/
			//istream& get(char*,char alu.nombre,char='\n');
			getline(consultar,alu.nombre);
			getline(consultar,alu.sexo);
			getline(consultar,alu.carrera);
			getline(consultar,alu.semestre);
			getline(consultar,alu.facultad);
			getline(consultar,alu.ano);
			
			//if(strcmp(alu.auxcod,alu.cod)==0)
			if(alu.auxcod==alu.cod)
			{
				encontrado = true;
				cout<<"\n\nRegistro encontrado:";
			//	fflush(stdin);
				cout<<"\n\nCódigo: "<<alu.cod<<endl;
				cout<<"Nombre: "<<alu.nombre<<endl;
				cout<<"Sexo: "<<alu.sexo<<endl;
				cout<<"Carrera: "<<alu.carrera<<endl;
				cout<<"Semestre: "<<alu.semestre<<endl;
				cout<<"Año de ingreso: "<<alu.ano<<endl;
				cout<<"\n\n";
			}
			//todo cambia ahora usando strings
			//consultar>>alu.cod;//para seguir buscando hasta que encuentre otro igual y lo muestra, para filtros a futuro
			getline(consultar,alu.cod);
			
		}
		if(encontrado==false)
		{
			cout<<"\n\nNo se encontro un estudiante matricualdo con el codigo: "<<alu.auxcod<<endl;
		}
		
	}
	else
	{
		cout<<"No se pudo abrir el archivo";
	}
	
	consultar.close();
	system("pause");
	menu();
	
}


void agregarEst()
{
	
}

void listarEst()
{
	int i=0;//iterador para saber cunatos datos hay
	system("cls");
	ifstream leer;
	leer.open("estudiantes.txt",ios::in);
	if(leer.is_open())
	{
		cout<<"Lista de datos generales de todos los estudiantes"<<endl<<endl;
		getline(leer,alu.cod);
		while(!leer.eof())
		{
			i++;
			getline(leer,alu.nombre);
			getline(leer,alu.sexo);
			getline(leer,alu.carrera);
			getline(leer,alu.semestre);
			getline(leer,alu.facultad);
			getline(leer,alu.ano);
			
			cout<<"Código: "<<alu.cod<<endl;
			cout<<"Nombre: "<<alu.nombre<<endl;
			cout<<"Sexo: "<<alu.sexo<<endl;
			cout<<"Carrera: "<<alu.carrera<<endl;
			cout<<"Semestre: "<<alu.semestre<<endl;
			cout<<"Facultad: "<<alu.facultad<<endl;
			cout<<"Año de ingreso: "<<alu.ano<<endl;
			cout<<"\n\n";
			
			getline(leer,alu.cod);
		}
		if(i==1)
		{
			cout<<"Hay un solo estudiante registrado\n\n";
		}
		else
		{
			cout<<"Hay "<<i<<" estudiantes registrados\n\n";	
		}
		
	}
	else
	{
		cout<<"Esto no deberia haber pasado";
	}
	leer.close();
	system("pause");
	menu();
}
void menu()
{
	do
	{
	system("cls");	
	cout<<"Universidad Distrital Francisco José de Caldas"<<endl;
	cout<<"Binevenido al Sistema de Gestión Académica: CONDOR"<<endl;
	cout<<"Seleccione una opción:"<<endl;
	cout<<"1.Estudiante"<<endl;
	cout<<"2.Profesor"<<endl;
	cout<<"3.Administrador"<<endl;
	cout<<"4.Salir"<<endl;
	cout<<"Opcion: "; cin>>opc;
	
	switch(opc)
	{
		case 1:
			do{system("cls");
			cout<<"Ingreso al menu de estudiante"<<endl;
			cout<<"Seleccione una opcion"<<endl;
			cout<<"1.Consultar"<<endl;
			cout<<"2.Regresar"<<endl;
			cout<<"Opcion: "; cin>>opc;
			
			switch(opc)
			{
				case 1:
					consultarEst();
				break; 
				case 2:
				break;
			}
		}while(opc!=2);
			
		break; 
		case 2:
			do
			{system("cls");
			cout<<"Ingreso al menu de profesores"<<endl;
			cout<<"Seleccione una opcion"<<endl;
			cout<<"1.Consultar"<<endl;
			cout<<"2.Modificar"<<endl;
			cout<<"3.Eliminar"<<endl;
			cout<<"4.Adicionar"<<endl;
			cout<<"5.Regresar"<<endl;
			cout<<"Opcion: "; cin>>opc;
			switch(opc)
			{
				case 1:
					//otro menu
					listarEst();
				break; 
				case 2:
				break;
				case 3:
				break; 
				case 4:
				break;
				case 5:
				break;
			}
		}while(opc!=5);
		break;
		case 3:
			//do{
			system("cls");
			administrador();
			//}
			//Indentificarte
			//menu, consultar, eliminar, adicionar,golpear, ver xd
			//while();
		break;
		case 4:
			exit(1);
		break;
	}
	}while(opc!=4);
}


//las tilde que onda
//al mirar una lsita debe llevar atras no al inicio

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<wchar.h>
#include<locale.h>

using namespace std;

int opc=0;
bool ingreso=false;
void menu();//70%
void ingresoEst();//ya
void ingresoProfesor();//ya
void ingresoAdministrador();//50%
void agregarEst();//ya
void agregarMateria();//ya
void agregarProfesor();
void consultarEst();
void consultarMaterias();
void consultarProfesor();
void eliminarEst();
void eliminarMaterias();
void eliminarProfesor();
void listarEst();//ya
void listarProfesor();//ya
void listarMaterias();//ya
void listarNotas();

int main()
{
	setlocale(LC_ALL,"");
	system("color 37");
	menu();
	return 0;
}

struct estudiante
{
	string cod;
	string auxcod;
	string clave;
	string auxclave;
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
}alu;

struct admin
{
	string cod;
	string auxcod;
	string clave;
	string auxclave;
}ad;

struct profesor
{
	string cod;
	string auxcod;
	string clave;
	string auxclave;
	string nombre;
	string auxnombre;
}prof;

struct materia
{
	string cod;
	string auxcod;
	string nombre;
	string auxnombre;
	struct profesor profe;//mat.profe.cod
}mat;
 
struct notas
{
	float nota1;
	float nota2;
	float nota3;
}nota;

struct notasEst
{
	struct estudiante est;
	struct materia mate;
	struct notas nota;
}est;

void menu()
{
	setlocale(LC_ALL,"");
	do
	{
		system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                           Seleccione una opción:"<<endl;
		cout<<"                           1.Estudiante"<<endl;
		cout<<"                           2.Profesor"<<endl;
		cout<<"                           3.Administrador"<<endl;
		cout<<"                           4.Salir"<<endl;
		cout<<"                           Opcion: "; cin>>opc;
		
		switch(opc)
		{
			case 1:
				ingresoEst();
				if(ingreso==true)
				{
						cout<<"    ";
				}
				else
				{
					system("cls");
					cout<<"\n--------------------------------------------------------------------------------";
					cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"                                Acseso denegado"<<endl;
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					system("pause");
					opc=0;	
				}
			break;
			case 2:
				ingresoProfesor();
				if(ingreso==true)
				{
					system("pause");
				}
				else
				{
					system("cls");
					cout<<"\n--------------------------------------------------------------------------------";
					cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"                                Acseso denegado"<<endl;
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					system("pause");
					opc=0;	
				}
			break;
			case 3:
				ingresoAdministrador();
				if(ingreso==false)
				{
					system("cls");
					cout<<"\n--------------------------------------------------------------------------------";
					cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"                                Acseso denegado"<<endl;
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					system("pause");
					opc=0;	
				
				}					
			break;
			case 4://hack para salir
				exit(1);
			break;	
		}
	}while(opc!=5);
}

void ingresoEst()
{
	setlocale(LC_ALL,"");
	ingreso=false;
	ifstream verificador;
	verificador.open("estudiantes.txt", ios::in);
	if(verificador.is_open())
	{
		system("cls");
		fflush(stdin);
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                            Por favor identifiquese: "<<endl;
		cout<<"                            Código: ";
		fflush(stdin);
		getline(cin,alu.auxcod);
		cout<<"                            Clave: ";
		fflush(stdin);
		getline(cin,alu.auxclave);
		//solo el primer dato? SÍ
		getline(verificador,alu.cod);
		
		while(!verificador.eof() and !ingreso)
		{
			getline(verificador,alu.clave);	
			getline(verificador,alu.nombre);
			getline(verificador,alu.sexo);
			getline(verificador,alu.carrera);
			getline(verificador,alu.semestre);
			getline(verificador,alu.facultad);
			getline(verificador,alu.ano);
			
			if(alu.auxcod==alu.cod and alu.auxclave==alu.clave)
			{
				ingreso=true;
				alu.auxnombre=alu.nombre;
			}
			//solo el siguente dato?	= SÏ
			getline(verificador,alu.cod);
				
		}
	}
	else
		{
		system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                         Error: Esto no deberia haber pasado";
		}
	verificador.close();
}

void ingresoProfesor()
{
	ingreso=false;
	ifstream verificador;
	verificador.open("usuarioProfesores.txt", ios::in);
	if(verificador.is_open())
	{
		system("cls");
		fflush(stdin);
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                            Por favor identifiquese: "<<endl;
		cout<<"                            Código: ";
		fflush(stdin);
		getline(cin,prof.auxcod);
		cout<<"                            Clave: ";
		fflush(stdin);
		getline(cin,prof.auxclave);
		getline(verificador,prof.cod);
		while(!verificador.eof())
		{
			getline(verificador,prof.clave);
			getline(verificador,prof.nombre);
			if(prof.auxcod==prof.cod and prof.auxclave==prof.clave)
			{
				ingreso=true;
				prof.auxnombre=prof.nombre;
			}
			getline(verificador,prof.cod);
		}
	}
	else
		{
		system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                         Error: Esto no deberia haber pasado";
		verificador.close();
	}
}
	
void ingresoAdministrador()
{
		ingreso=false;
		ifstream verificador;
		verificador.open("usuarioAdmin.txt", ios::in);
		if(verificador.is_open())
		{
			system("cls");
			fflush(stdin);
			cout<<"\n--------------------------------------------------------------------------------";
			cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                            Por favor identifiquese: "<<endl;
			cout<<"                            Código: ";
			fflush(stdin);
			getline(cin,ad.auxcod);
			cout<<"                            Clave: ";
			fflush(stdin);
			getline(cin,ad.auxclave);
			//funciona asi no como est porque solo hay esos datos no otros que no compara
			getline(verificador,ad.cod);
			while(!verificador.eof())
			{
				getline(verificador,ad.clave);
				if(ad.auxcod==ad.cod and ad.auxclave==ad.clave)
				{
					ingreso=true;
				}
				getline(verificador,ad.cod);
			}
		}
		else
		{
		system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                         Error: Esto no deberia haber pasado";
		}
		verificador.close();
		if(ingreso==true)
				{
					do
					{
						system("cls");
						cout<<"\n--------------------------------------------------------------------------------";
						cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
						cout<<"\n--------------------------------------------------------------------------------"<<endl;
						cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
						cout<<"\n--------------------------------------------------------------------------------"<<endl;
						cout<<"                           Bienvenido Adnistrador"<<endl;
						cout<<"\n--------------------------------------------------------------------------------"<<endl;
						cout<<"                           Seleccione una opción"<<endl;
						cout<<"                           1.Consultar"<<endl;
						cout<<"                           2.Eliminar"<<endl;
						cout<<"                           3.Añadir"<<endl;
						cout<<"                           4.Regresar"<<endl;
						cout<<"                           Seleccione una opción: ";
						cin>>opc;
					
						switch(opc)
						{
							case 1:
								do
								{
									system("cls");
									cout<<"\n--------------------------------------------------------------------------------";
									cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
									cout<<"\n--------------------------------------------------------------------------------"<<endl;
									cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
									cout<<"\n--------------------------------------------------------------------------------"<<endl;
									cout<<"                           Seleccione una opción"<<endl;
									cout<<"                           1.Listar todos los estudinates"<<endl;
									cout<<"                           2.Listar todos los profesores"<<endl;
									cout<<"                           3.Listar todas las materias"<<endl;
									cout<<"                           4.Listar todas las notas"<<endl;
									cout<<"                           5.Buscar un estudiante especifico1"<<endl;
									cout<<"                           6.Buscar un profesor especifico"<<endl;
									cout<<"                           7.Buscar una materia especifica"<<endl;
									cout<<"                           8.Inicio del programa"<<endl;
									cout<<"                           9.Salir"<<endl;
									cout<<"                           Opción: ";
									cin>>opc;
								
									switch(opc)
									{
										case 1:
											listarEst();
										break;
										case 2:
											listarProfesor();
										break;
										case 3:
											listarMaterias();
										break;
										case 4:
											listarNotas();
										break;
										case 5:
											consultarEst();
										break;
										case 6:
											consultarProfesor();
										break;
										case 7:
											consultarMaterias();
										break;	
										case 8:
											menu();
										break;
									}
								}while(opc!=9);
							break;
							case 2:
							break;
							
							case 3:
								do{
									system("cls");
									cout<<"\n--------------------------------------------------------------------------------";
									cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
									cout<<"\n--------------------------------------------------------------------------------"<<endl;
									cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
									cout<<"\n--------------------------------------------------------------------------------"<<endl;
									cout<<"                           Seleccione una opción"<<endl;
									cout<<"                           1.Agregar estudiante"<<endl;
									cout<<"                           2.Agregar profesor"<<endl;
									cout<<"                           3.Agregar materia"<<endl;
									cout<<"                           4.Agregar notas"<<endl;
									cout<<"                           5.Salir"<<endl;
									cout<<"                           Opción: ";
									cin>>opc;
								
									switch(opc)
									{
										case 1:
											agregarEst();
										break;
										case 2:
											agregarProfesor();
										break;
										case 3:
											agregarMateria();
										break;
										case 4:
										break;	
									}	
								}while(opc!=5);
							break;
							case 4:
								menu();
							break;
						}
					}while(opc!=4);	
				}
}
		

void agregarEst()
{
	setlocale(LC_ALL,"");
	system("cls");
	ofstream escritura;
	ifstream verificador;
	bool coincidencia = false;
	verificador.open("estudiantes.txt", ios::in);
	escritura.open("estudiantes.txt", ios::app | ios::out);
	if(verificador.is_open() and escritura.is_open())
	{
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                              Añadir estudiante"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                Digite el código del estudiante: ";
		fflush(stdin);
		getline(cin,alu.auxcod);
		if(alu.auxcod=="")
		{
			do
			{
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"              Código no valido, intente nuevamente: ";
				fflush(stdin);
				getline(cin,alu.auxcod);
			}while(alu.auxcod=="");
		}
		do
		{
			verificador.seekg(0);
			getline(verificador,alu.cod);
		
			while(!verificador.eof())
			{
				getline(verificador,alu.clave);	
				getline(verificador,alu.nombre);
				getline(verificador,alu.sexo);
				getline(verificador,alu.carrera);
				getline(verificador,alu.semestre);
				getline(verificador,alu.facultad);
				getline(verificador,alu.ano);
				if(alu.auxcod==alu.cod)
				{
					coincidencia=true;
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"                El estudiante con ese codigo ya esxixte"<<endl;
					cout<<"                El estudiante es: "<<alu.nombre<<endl;
					cout<<"                Ingrese un codigo valido: ";
					fflush(stdin);
					getline(cin,alu.auxcod);
					if(alu.auxcod=="")
					{
						do
						{
						cout<<"\n--------------------------------------------------------------------------------"<<endl;
						cout<<"              Código no valido, intente nuevamente: ";
						fflush(stdin);
						getline(cin,alu.auxcod);
						}while(alu.auxcod=="");
					}
					break;
				}
				getline(verificador,alu.cod);	
			}
			if(verificador.eof() and alu.auxcod!=alu.cod)
			{
				coincidencia=false;
			}
			
		}while(coincidencia==true);
	//datos
	system("cls");
	alu.cod=alu.auxcod;
	cout<<"\n--------------------------------------------------------------------------------";
	cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"                              Añadir estudiante"<<endl;
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"                Digite el código del estudiante: "<<alu.cod;
	cout<<"\n\n                Digite la clave del estudiante: ";
	fflush(stdin);
	getline(cin,alu.clave);
	cout<<"\n                Digite el nombre del estudiante: ";
	fflush(stdin);
	getline(cin,alu.nombre);
	cout<<"\n                Digite el sexo del estudiante: ";
	fflush(stdin);
	getline(cin,alu.sexo);
	cout<<"\n                Digite la carrera del estudiante: ";
	fflush(stdin);
	getline(cin,alu.carrera);
	cout<<"\n                Digite el semestre del estudiante: ";
	fflush(stdin);
	getline(cin,alu.semestre);
	cout<<"\n                Digite la facultad del estudiante: ";
	fflush(stdin);
	getline(cin,alu.facultad);	
	cout<<"\n                Digite el año de ingreso del estudiante: ";
	fflush(stdin);
	getline(cin,alu.ano);
	
	escritura<<alu.cod<<"\n"<<alu.clave<<"\n"<<alu.nombre<<"\n"<<alu.sexo<<"\n"<<alu.carrera<<"\n"<<alu.semestre<<"\n"<<alu.facultad<<"\n"<<alu.ano<<"\n";
	escritura.close();
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"                            Estudiante Añadido";
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"                     ";
	system("pause");
	}
	else
	{
		system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                         Error: Esto no deberia haber pasado";
	}
	verificador.close();
	escritura.close();
}
void agregarMateria()
{
	system("cls");
	//codigo materia, nombre, cod profesor
	//si el profesor esxiste y si solo ya tiene las dos materias añadidas
	//mirar si el codigo de la materia no esiste
	//se guarda en ram, luego ver si el nombre no existe,
	//se guarda en ram, luego ver si el codigo del profesor exite y si no esta repetido dos veces, con un contardor en un condicional
	// si se cumple hay si se guarda, reutilizable para las notas???
	ifstream leer;
	ifstream aux;
	ifstream leer1;
	ofstream escribir;
	bool coincidencia=false;
	bool coincidencia1=false;
	bool coincidencia2=false;
	int cont=0;
	string codigoAux;
	leer.open("materias.txt", ios::in);
	aux.open("materias.txt", ios::in);
	escribir.open("materias.txt", ios::app);
	leer1.open("usuarioProfesores.txt", ios::in);
	
	//no se pueden agrefar materias si no hay profesores
	if(leer.is_open() and leer1.is_open() and aux.is_open() and escribir.is_open())
	{
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                              Añadir materia"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                Digite el código de la materia: ";
		fflush(stdin);
		getline(cin,mat.auxcod);
		if(mat.auxcod=="")
		{
			do
			{
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"              Código no valido, intente nuevamente: ";
				fflush(stdin);
				getline(cin,mat.auxcod);
			}while(mat.auxcod=="");
		}
		do
		{
			//codigo materia
			leer.seekg(0);
			getline(leer,mat.cod);
			while(!leer.eof())
			{
				getline(leer,mat.nombre);
				getline(leer,mat.profe.auxcod);
				if(mat.auxcod==mat.cod)
				{
					coincidencia=true;
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"                La materia con ese codigo ya esxixte"<<endl;
					cout<<"                La mateia es: "<<mat.nombre<<endl;
					cout<<"                Ingrese un codigo valido: ";
					fflush(stdin);
					getline(cin,mat.auxcod);
					if(mat.auxcod=="")
					{
						do
						{
						cout<<"\n--------------------------------------------------------------------------------"<<endl;
						cout<<"              Código no valido, intente nuevamente: ";
						fflush(stdin);
						getline(cin,mat.auxcod);
						}while(mat.auxcod=="");
					}
					break;
				}
				getline(leer,mat.cod);
			}
			if(leer.eof() and mat.auxcod!=mat.cod)
			{
				coincidencia=false;
			}	
		}while(coincidencia==true);
		//ahora el codigo del profesor
		//mat.cod=mat.auxcod; guardar en el archivo mat.auxcod
		if(leer.is_open() and leer1.is_open() and aux.is_open() and escribir.is_open())
		{
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                              Añadir materia"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                Digite el código de la materia: ";	
		cout<<mat.cod;
		cout<<"\n                Digite el nombre de la materia: ";	
		getline(cin,mat.auxnombre);
		if(mat.auxnombre=="")
		{
			do
			{
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"              Nombre no valido, intente nuevamente: ";
				fflush(stdin);
				getline(cin,mat.auxnombre);
			}while(mat.auxnombre=="");
		}
		do
		{
			//codigo materia
			aux.seekg(0);
			getline(aux,mat.cod);
			getline(aux,mat.nombre);
			while(!aux.eof())
			{
				getline(leer,mat.profe.auxcod);
				getline(leer,mat.cod);
				if(mat.auxnombre==mat.nombre)
				{
					coincidencia1=true;
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"                La materia con ese nombre ya esxixte"<<endl;
					cout<<"                La mateia es: "<<mat.nombre<<endl;
					cout<<"                Ingrese un nombre valido: ";
					fflush(stdin);
					getline(cin,mat.auxnombre);
					if(mat.auxnombre=="")
					{
						do
						{
						cout<<"\n--------------------------------------------------------------------------------"<<endl;
						cout<<"              Nombre no valido, intente nuevamente: ";
						fflush(stdin);
						getline(cin,mat.auxnombre);
						}while(mat.auxnombre=="");
					}
					break;
				}
				getline(leer,mat.nombre);
			}
			if(aux.eof() and mat.auxnombre!=mat.nombre)
			{
				coincidencia1=false;
			}	
		}while(coincidencia1==true);
		}
		//ahora si debe coincidir cod profe	
		if(leer.is_open() and leer1.is_open() and aux.is_open() and escribir.is_open())
		{
			cout<<"\n--------------------------------------------------------------------------------";
			cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                              Añadir materia"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                Digite el código de la materia: ";	
			cout<<mat.auxcod;
			cout<<"\n                Digite el nombre de la materia: ";	
			cout<<mat.auxnombre;
			cout<<"\n                Digite el codigo del profesor: ";
			fflush(stdin);
			getline(cin,mat.profe.auxcod);
			//comparar datos de leer(materias) con leer1(usuarioProfesores)
			if(mat.profe.auxcod=="")
			{
				do
				{
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"          Código de profesor no valido, intente nuevamente: ";
					fflush(stdin);
					getline(cin,mat.profe.auxcod);
				}while(mat.profe.auxcod=="");
		}
		do
		{
			//codigo materia
			leer.seekg(0);
			leer1.seekg(0);
			getline(leer,mat.cod);
			getline(leer,mat.nombre;)
			getline(leer,mat.profe.cod);
			getline(leer1,codigoAux);
			while(!leer.eof() or !leer1.eof())
			{
				getline(leer,mat.cod);
				getline(leer,mat.nombre);
				getline(leer,mat.profe.auxcod);
				getline(leer1,mat.profe.clave);
				getline(leer1,mat.profe.nombre);
				if(mat.profe.auxcod==mat.profe.cod==codigoAux)
				{
					coincidencia2=true;
					break;
				}
				getline(leer,mat.profe.cod);
				getline(leer1,codigoAux);
			}
			if(leer.eof() and leer1.eof() and mat.profe.auxcod!=mat.profe.cod!=codigoAux)
			{
				coincidencia=false;
			}	
		}while(coincidencia2==false);
			
		if(coincidencia==false and coincidencia1==false and coincidencia2==true)
		{
//			se guarda en el archivo, los auxiliares
		}
		}
	}
	else
	{
		system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                         Error: Esto no deberia haber pasado";
	}
}
void agregarProfesor()
{
	system("cls");
	ofstream escritura;
	ifstream verificador;
	bool coincidencia = false;
	verificador.open("usuarioProfesores.txt", ios::in);
	escritura.open("usuarioProfesores.txt", ios::app | ios::out);
	if(verificador.is_open() and escritura.is_open())
	{
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                              Añadir profesor"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                Digite el código del profesor: ";
		fflush(stdin);
		getline(cin,prof.auxcod);
		if(prof.auxcod=="")
		{
			do
			{
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"              Código no valido, intente nuevamente: ";
				fflush(stdin);
				getline(cin,prof.auxcod);
			}while(prof.auxcod=="");
		}
		do
		{
			verificador.seekg(0);
			getline(verificador,prof.cod);
			while(!verificador.eof())
			{
				getline(verificador,prof.clave);	
				getline(verificador,prof.nombre);
				if(prof.auxcod==prof.cod)
				{
					coincidencia=true;
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"                El profesor con ese codigo ya esxixte"<<endl;
					cout<<"                El profesor es: "<<prof.nombre<<endl;
					cout<<"                Ingrese un codigo valido: ";
					fflush(stdin);
					getline(cin,prof.auxcod);
					if(prof.auxcod=="")
					{
						do
						{
						cout<<"\n--------------------------------------------------------------------------------"<<endl;
						cout<<"              Código no valido, intente nuevamente: ";
						fflush(stdin);
						getline(cin,prof.auxcod);
						}while(prof.auxcod=="");
					}
					break;
				}
				getline(verificador,prof.cod);	
				
			}
			if(verificador.eof() and prof.auxcod!=prof.cod)
			{
				coincidencia=false;
			}
		}while(coincidencia==true);
	//datos
	system("cls");
	prof.cod=prof.auxcod;
	cout<<"\n--------------------------------------------------------------------------------";
	cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"                              Añadir profesor"<<endl;
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"                Digite el código del profesor: "<<prof.cod;
	cout<<"\n\n                Digite la clave del profesor: ";
	fflush(stdin);
	getline(cin,prof.clave);
	cout<<"\n                Digite el nombre del profesor: ";
	fflush(stdin);
	getline(cin,prof.nombre);
	escritura<<prof.cod<<"\n"<<prof.clave<<"\n"<<prof.nombre<<"\n";
	escritura.close();
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"                            Profesor Añadido";
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"                     ";
	system("pause");
	}
	else
	{
		system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                         Error: Esto no deberia haber pasado";
	}
}
void consultarEst()
{
	
}
void consultarMaterias()
{
	
}
void consultarProfesor()
{
	
}
void eliminarEst()
{
	
}
void eliminarMaterias()
{
	
}
void eliminarProfesor()
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
		system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                Lista de datos generales de todos los estudiantes"<<endl<<endl;
		getline(leer,alu.cod);
		while(!leer.eof())
		{
			i++;
			getline(leer,alu.clave);
			getline(leer,alu.nombre);
			getline(leer,alu.sexo);
			getline(leer,alu.carrera);
			getline(leer,alu.semestre);
			getline(leer,alu.facultad);
			getline(leer,alu.ano);
			
			cout<<"                       Código: "<<alu.cod<<endl;
			cout<<"                       Nombre: "<<alu.nombre<<endl;
			cout<<"                       Clave: "<<alu.clave<<endl;
			cout<<"                       Sexo: "<<alu.sexo<<endl;
			cout<<"                       Carrera: "<<alu.carrera<<endl;
			cout<<"                       Semestre: "<<alu.semestre<<endl;
			cout<<"                       Facultad: "<<alu.facultad<<endl;
			cout<<"                       Año de ingreso: "<<alu.ano<<endl;
			cout<<"\n\n";
			
			getline(leer,alu.cod);
		}
		if(i==1)
		{
			cout<<"                  Hay un solo estudiante registrado\n\n";
		}
		else
		{
			cout<<"                 Hay "<<i<<" estudiantes registrados\n\n";	
		}
		
	}
	else
	{
		system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                         Error: Esto no deberia haber pasado";
	}
	leer.close();
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"                     ";
	system("pause");
	menu();
}
void listarProfesor()
{
	int i=0;
	system("cls");
	ifstream leer;
	leer.open("UsuarioProfesores.txt", ios::in);
	if(leer.is_open())
	{
		system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                Lista de datos generales de todos los profesores"<<endl<<endl;
		getline(leer,prof.cod);
		while(!leer.eof())
		{
			i++;
			getline(leer,prof.clave);
			getline(leer,prof.nombre);
			cout<<"                         Código: "<<prof.cod<<endl;
			cout<<"                         Clave: "<<prof.clave<<endl;
			cout<<"                         Nombre: "<<prof.nombre<<endl;
			cout<<"\n\n";
			getline(leer,prof.cod);
		}
		if(i==1)
		{
			cout<<"                         Hay un solo profesor registrado\n\n";
		}
		else
		{
			cout<<"                        Hay "<<i<<" profesores registrados\n\n";	
		}
	}
	else
	{
		system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                         Error: Esto no deberia haber pasado";
	}
	leer.close();
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"                     ";
	system("pause");
	menu();
}
void listarMaterias()//repenzar
{
	int i=0;
	ifstream leer;
	leer.open("materias.txt", ios::in);
	if(leer.is_open())
	{
		system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                 Lista de datos generales de todas los materias"<<endl<<endl;
		getline(leer,mat.cod);
		while(!leer.eof())
		{
			i++;
			getline(leer,mat.nombre);
			getline(leer,mat.profe.auxcod);
			cout<<"                      Código Materia:  "<<mat.cod<<endl;
			cout<<"                      Nombre Materia:  "<<mat.nombre<<endl;
			cout<<"                      Código Profesor: "<<mat.profe.auxcod<<endl;
			cout<<"\n\n";
			getline(leer,mat.cod);
		}
		if(i==1)
		{
			cout<<"                         Hay una sola materia registrada\n\n";
		}
		else
		{
			cout<<"                        Hay "<<i<<" materias registradas\n\n";	
		}
	}
	else
	{
		system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                         Error: Esto no deberia haber pasado";
	}
	leer.close();
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"                     ";
	system("pause");
	menu();
	
}
void listarNotas()
{
	
}

//el syste de cls de agragr materia
//arreglar agreagar profe
//y ver lo del codigo del profe en agregar materia
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<wchar.h>
#include<locale.h>

using namespace std;

int opc=0,cont=0;
bool ingreso=false;
void menu();//70%
void ingresoEst();//ya
void ingresoProfesor();//ya//1
void ingresoAdministrador();//50%
void agregarEst();//ya//2
void agregarMateria();//ya +-
void agregarProfesor();//ya +-
void agregarNota();
void consultarEst();//ya//3
void consultarMateria();//ya
void consultarProfesor();//ya
void consultarNota();
void editarEst();//6
void editarMateria();//ya
void editarProfesor();//ya
void editarNota();
void eliminarEst();//ya//5
void eliminarMateria();//ya
void eliminarProfesor();//ya
void eliminarNota();
void mostrarRegistroEst(string codigo);//funciones axiliares de editar//ya
void mostrarRegistroMat(string codigo);//ya
void mostrarRegistroProf(string codigo);//ya
void mostrarRegistroNota(string codigo);
void listarEst();//ya
void listarProfesor();//ya//4
void listarMateria();//ya
void listarNotas();
void fail();

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
	string materia1;
	string auxmateria1;
	string materia2;
	string auxmateria2;
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
	float notaFinal;
}nota;

struct notasEst
{
	struct estudiante estu;
	struct materia mate;
	struct profesor profes;
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
	}while(opc!=6);
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
			getline(verificador,prof.materia1);
			getline(verificador,prof.materia2);
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
						cout<<"                           4.Editar"<<endl;
						cout<<"                           5.Regresar"<<endl;
						cout<<"                           Seleccione una opción: ";
						cin>>opc;
					
						switch(opc)
						{
							case 1://consulta
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
									cout<<"                           5.Buscar un estudiante especifico"<<endl;
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
											listarMateria();
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
											consultarMateria();
										break;	
										case 8:
											menu();
										break;
									}
								}while(opc!=9);
							break;
							case 2://eliminar
								do
								{
									system("cls");
									cout<<"\n--------------------------------------------------------------------------------";
									cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
									cout<<"\n--------------------------------------------------------------------------------"<<endl;
									cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
									cout<<"\n--------------------------------------------------------------------------------"<<endl;
									cout<<"                           Seleccione una opción"<<endl;
									cout<<"                           1.Eliminar estudiante"<<endl;
									cout<<"                           2.Eliminar profesor"<<endl;
									cout<<"                           3.Eliminar materia"<<endl;
									cout<<"                           4.Eliminar notas"<<endl;
									cout<<"                           5.Salir"<<endl;
									cout<<"                           Opción: ";
									cin>>opc;
								
									switch(opc)
									{
										case 1:
											eliminarEst();
										break;
										case 2:
											eliminarProfesor();
										break;
										case 3:
											eliminarMateria();
										break;
										case 4:
											eliminarNota();
										break;	
									}	
								}while(opc!=5);
							break;
							
							case 3://agregar
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
											agregarNota();
										break;	
									}	
								}while(opc!=5);
							break;
							case 4:
								do{
									system("cls");
									cout<<"\n--------------------------------------------------------------------------------";
									cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
									cout<<"\n--------------------------------------------------------------------------------"<<endl;
									cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
									cout<<"\n--------------------------------------------------------------------------------"<<endl;
									cout<<"                           Seleccione una opción"<<endl;
									cout<<"                           1.Editar estudiante"<<endl;
									cout<<"                           2.Editar profesor"<<endl;
									cout<<"                           3.Editar materia"<<endl;
									cout<<"                           4.Edirar notas"<<endl;
									cout<<"                           5.Salir"<<endl;
									cout<<"                           Opción: ";
									cin>>opc;
								
									switch(opc)
									{
										case 1:
											editarEst();
										break;
										case 2:
											editarProfesor();
										break;
										case 3:
											editarMateria();
										break;
											editarNota();
										case 4:
										break;	
									}	
								}while(opc!=5);
							break;
							case 5:
								menu();
							break;
							default:
								break;
						}
					}while(opc!=5);	
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
		fail();
	}
	verificador.close();
	escritura.close();
}

void agregarMateria()
{
	ifstream leer;
	ifstream leer1;
	ifstream leer2;
	ofstream escribir;
	bool coincidencia=false;
	bool existe=false;
	bool existe2=false;
	
	escribir.open("materias.txt",ios::app);
	if(escribir.is_open())
	{
		system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                              Añadir materia"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"  Nota: Para poder agregar una materia debe haber sido asignada \n  previamente a un profesor al momneto de registrarlo. \n  Maximo 2 materias por docente.";
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                Digite el código de la materia: ";
		fflush(stdin);
		getline(cin,mat.auxcod);		
		do
		{
			
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
			leer.open("materias.txt", ios::in);
			leer.seekg(0);
			getline(leer,mat.cod);
			while(!leer.eof())
			{
				getline(leer,mat.nombre);
				getline(leer,mat.profe.cod);
				
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
		leer.close();
		}while(coincidencia==true);
		
	while(existe==false)
		{
			system("cls");
			cout<<"\n--------------------------------------------------------------------------------";
			cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                              Añadir materia"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"\n                Digite el nombre de la materia: ";
			cout<<mat.auxcod<<endl;
			cout<<"\n                Digite el nombre de la materia: ";
			fflush(stdin);
			getline(cin,mat.auxnombre);
			if(mat.auxnombre=="")
					{
						do
						{
						cout<<"\n--------------------------------------------------------------------------------"<<endl;
						cout<<"              Código no valido, intente nuevamente: ";
						fflush(stdin);
						getline(cin,mat.auxnombre);
						}while(mat.auxnombre=="");
					}
			leer1.open("usuarioProfesores.txt", ios::in);
			leer1.seekg(0);
			getline(leer1, mat.profe.cod);
			
			while(!leer1.eof())
			{
				getline(leer1,mat.profe.clave);
				getline(leer1,mat.profe.nombre);
				getline(leer1,mat.profe.materia1);
				getline(leer1,mat.profe.materia2);
				if(mat.auxnombre==mat.profe.materia1 or mat.auxnombre==mat.profe.materia2)
				{
					existe=true;
				}
				getline(leer1,mat.profe.cod);
			}
			
			if(existe==false)
			{
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"No existe una materia con ese nombre asociada a un profesor, intente nuevamente"<<endl;
			}	//pause maybe
		leer1.close();
		}
		
		//cod profe
		while(existe2==false)
		{
			system("cls");
			cout<<"\n--------------------------------------------------------------------------------";
			cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                              Añadir materia"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"\n                Digite el nombre de la materia: ";
			cout<<mat.auxcod<<endl;
			cout<<"\n                Digite el nombre de la materia: ";
			cout<<mat.auxnombre<<endl;
			cout<<"\n                Digite el codigo del profesor: ";
			fflush(stdin);
			getline(cin,mat.profe.auxcod);
			if(mat.profe.auxcod=="")
			{	
				do
				{
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"              Código no valido, intente nuevamente: ";
				fflush(stdin);
				getline(cin,mat.profe.auxcod);
				}while(mat.profe.auxcod=="");
			}
			leer2.open("usuarioProfesores.txt", ios::in);
			leer2.seekg(0);
			getline(leer2, mat.profe.cod);
			
			while(!leer2.eof())
			{
				getline(leer2,mat.profe.clave);
				getline(leer2,mat.profe.nombre);
				getline(leer2,mat.profe.materia1);
				getline(leer2,mat.profe.materia2);
				if(mat.profe.auxcod==mat.profe.cod)
				{
					existe2=true;
				}
				getline(leer2,mat.profe.cod);
			}
			
			if(existe2==false)
			{
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"No existe un profesor con ese código, intente nuevamente"<<endl;
			}	//pause maybe
		leer2.close();
		}
		escribir<<mat.auxcod<<"\n"<<mat.auxnombre<<"\n"<<mat.profe.auxcod<<"\n";		
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                            Materia Añadido";
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                     ";
		system("pause");
	}
	else
	{
		fail();
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
	cout<<"\n                Digite la materia 1 del profesor: ";
	fflush(stdin);
	getline(cin,prof.materia1);
	cout<<"\n                Digite la materia 2 del profesor: ";
	fflush(stdin);
	getline(cin,prof.materia2);
	escritura<<prof.cod<<"\n"<<prof.clave<<"\n"<<prof.nombre<<"\n"<<prof.materia1<<"\n"<<prof.materia2<<"\n";
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"                            Profesor Añadido";
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"                     ";
	system("pause");
	}
	else
	{
		fail();
	}
	escritura.close();
	verificador.close();
}

void agregarNota()
{
	ifstream leer;
	ifstream leer1;
	ifstream leer2;
	ofstream escribir;
	bool existe=false;
	bool existe1=false;
	bool existe2=false;
	escribir.open("notas.txt", ios::app);
	if(escribir.is_open())
	{
		while(existe==false)
		{
			system("cls");
			cout<<"\n--------------------------------------------------------------------------------";
			cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                              Agregar nota"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                Digite el código del estudiante: ";
			fflush(stdin);
			getline(cin,est.estu.auxcod);
			if(est.estu.auxcod=="")
			{
				do
				{
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"              Código no valido, intente nuevamente: ";
					fflush(stdin);
					getline(cin,est.estu.auxcod);
				}while(est.estu.auxcod=="");
			}
			leer.open("estudiantes.txt", ios::in);
			leer.seekg(0);
			getline(leer,est.estu.cod);
			while(!leer.eof())
			{
				getline(leer,est.estu.clave);
				getline(leer,est.estu.nombre);
				getline(leer,est.estu.sexo);
				getline(leer,est.estu.carrera);
				getline(leer,est.estu.semestre);
				getline(leer,est.estu.facultad);
				getline(leer,est.estu.ano);
				if(est.estu.auxcod==est.estu.cod)
				{
					existe=true;
				}
				getline(leer,est.estu.cod);
			}
			if(existe==false)
			{
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"No existe un estudiante asociado a ese código, intente nuevamente"<<endl;
			}
		leer.close();		
		}
		
		while(existe1==false)
		{
			system("cls");
			cout<<"\n--------------------------------------------------------------------------------";
			cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                              Agregar nota"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                Digite el código del estudiante: ";
			cout<<est.estu.auxcod<<endl;;
			cout<<"\n                Digite el código del profesor: ";
			fflush(stdin);
			getline(cin,est.profes.auxcod);
			if(est.profes.auxcod=="")
			{
				do
				{
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"              Código no valido, intente nuevamente: ";
					fflush(stdin);
					getline(cin,est.profes.auxcod);
				}while(est.profes.auxcod=="");
			}
			leer1.open("usuarioProfesores.txt", ios::in);
			leer1.seekg(0);
			getline(leer1,est.profes.cod);
			while(!leer1.eof())
			{
				getline(leer1,est.profes.clave);
				getline(leer1,est.profes.nombre);
				getline(leer1,est.profes.materia1);
				getline(leer1,est.profes.materia2);
				if(est.profes.auxcod==est.profes.cod)
				{
					existe1=true;
				}
				getline(leer1,est.profes.cod);
			}
			if(existe1==false)
			{
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"No existe un profesor asociado a ese código, intente nuevamente"<<endl;
			}
		leer1.close();		
		}
		
		while(existe2==false)
		{
			system("cls");
			cout<<"\n--------------------------------------------------------------------------------";
			cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                              Agregar nota"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                Digite el código del estudiante: ";
			cout<<est.estu.auxcod<<endl;;
			cout<<"\n                Digite el código del profesor: ";
			cout<<est.profes.auxcod<<endl;
			cout<<"\n                Digite el código de la materia: ";
			fflush(stdin);
			getline(cin,est.mate.auxcod);
			if(est.mate.auxcod=="")
			{
				do
				{
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"              Código no valido, intente nuevamente: ";
					fflush(stdin);
					getline(cin,est.mate.auxcod);
				}while(est.mate.auxcod=="");
			}
			leer2.open("materias.txt", ios::in);
			leer2.seekg(0);
			getline(leer2,est.mate.cod);
			while(!leer2.eof())
			{
				getline(leer2,est.mate.nombre);
				getline(leer2,est.mate.profe.cod);
				if(est.mate.auxcod==est.mate.cod)
				{
					existe2=true;
				}
				getline(leer2,est.mate.cod);
			}
			if(existe2==false)
			{
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"No existe una materia asociada a ese código, intente nuevamente"<<endl;
			}
		leer2.close();		
		}
		//todos los leer verificaron datos ahoara si entro lo logico seria pedir las notas
		//al archivo de notas se va a escribir
		//est.estu.auxcod<<est.profes.auxcod<<est.mate.auxcod
		if(existe==true and existe1==true and existe2==true)
		{
			system("cls");
			cout<<"\n--------------------------------------------------------------------------------";
			cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                              Agregar nota"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                Digite el código del estudiante: ";
			cout<<est.estu.auxcod<<endl;;
			cout<<"\n                Digite el código del profesor: ";
			cout<<est.profes.auxcod<<endl;
			cout<<"\n                Digite el código de la materia: ";
			cout<<est.mate.auxcod<<endl;
			cout<<"\n                Digite la nota 1 por un valor de 35%: ";
			fflush(stdin);
			cin>>est.nota.nota1;
//	
			if(est.nota.nota1<0 or est.nota.nota1>5)//seguridad 2
			{
				do
				{
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"              Nota no valida, intente nuevamente: ";
				fflush(stdin);
				cin>>est.nota.nota1;
				}while(est.nota.nota1<0 or est.nota.nota1>5);
			}
			cout<<"\n                Digite la nota 2 por un valor de 35%: ";
			fflush(stdin);
			cin>>est.nota.nota2;
//			
			if(est.nota.nota2<0 or est.nota.nota2>5)
			{
				do
				{
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"              Nota no valida, intente nuevamente: ";
				fflush(stdin);
				cin>>est.nota.nota2;
				}while(est.nota.nota2<0 or est.nota.nota2>5);
			}
			cout<<"\n                Digite la nota 3 por un valor de 30%: ";
			fflush(stdin);
			cin>>est.nota.nota3;
//			
			if(est.nota.nota3<0 or est.nota.nota3>5)
			{
				do
				{
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"              Nota no valida, intente nuevamente: ";
				fflush(stdin);
				cin>>est.nota.nota3;
				}while(est.nota.nota3<0 or est.nota.nota3>5);
			}
			//suma de las nota para nota final acumulado
			//mostrar eso en pantalla
			//escribir en archivo
			cout<<"--------------------------------------------------------------------------------";
			cout<<"                  El acumulado del estudiante es: ";
			est.nota.notaFinal=(est.nota.nota1*0.35)+(est.nota.nota2*0.35)+(est.nota.nota3*0.30);
			cout<<est.nota.notaFinal;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			escribir<<est.estu.auxcod<<"\n"<<est.profes.auxcod<<"\n"<<est.mate.auxcod<<"\n"<<est.nota.nota1<<"\n"<<est.nota.nota2<<"\n"<<est.nota.nota3<<"\n"<<est.nota.notaFinal<<"\n";
			cout<<"                            Registro agregado";
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                     ";
			system("pause");
		}
	}//si se abrio escritura
	else
	{
		fail();
	}
	escribir.close();
}

void consultarEst()
{
	ifstream leer;
	bool existe=false;
	leer.open("estudiantes.txt", ios::in);
	if(leer.is_open())
	{
		system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                Digite el código del estudiante a consultar: ";
		fflush(stdin);
		getline(cin,alu.auxcod);
		leer.seekg(0);
		getline(leer,alu.cod);
		while(!leer.eof())
		{
				getline(leer,alu.clave);
				getline(leer,alu.nombre);
				getline(leer,alu.sexo);
				getline(leer,alu.carrera);
				getline(leer,alu.semestre);
				getline(leer,alu.facultad);
				getline(leer,alu.ano);
				if(alu.auxcod==alu.cod)
				{
					existe=true;
					cout<<"--------------------------------------------------------------------------------"<<endl;
					cout<<"                       Consulta: Exitosa"<<endl;
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"                       Código: "<<alu.cod<<endl;
					cout<<"                       Nombre: "<<alu.nombre<<endl;
					cout<<"                       Clave: "<<alu.clave<<endl;
					cout<<"                       Sexo: "<<alu.sexo<<endl;
					cout<<"                       Carrera: "<<alu.carrera<<endl;
					cout<<"                       Semestre: "<<alu.semestre<<endl;
					cout<<"                       Facultad: "<<alu.facultad<<endl;
					cout<<"                       Año de ingreso: "<<alu.ano<<endl;
					cout<<"\n";
				}
				getline(leer,alu.cod);
		}
		if(existe==false)
		{
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                       Consulta: NO exitosa"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"          El estudiante con el código: "<<alu.auxcod<<" no se encuentra registrado"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                     ";
			system("pause");
		}
	}
	else
	{
		fail();
	}
	leer.close();
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"                     ";
	system("pause");
}
void consultarMateria()
{
	ifstream leer;
	bool existe=false;
	leer.open("materias.txt", ios::in);
	if(leer.is_open())
	{
		system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                Digite el código de la materia a consultar: ";
		fflush(stdin);
		getline(cin,mat.auxcod);
		leer.seekg(0);
		getline(leer,mat.cod);
		while(!leer.eof())
		{
				getline(leer,mat.nombre);
				getline(leer,mat.profe.cod);
				if(mat.auxcod==mat.cod)
				{
					existe=true;
					cout<<"--------------------------------------------------------------------------------"<<endl;
					cout<<"                       Consulta: Exitosa"<<endl;
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"                       Código Materia: "<<mat.cod<<endl;
					cout<<"                       Nombre Materia: "<<mat.nombre<<endl;
					cout<<"                       Código Profesor: "<<mat.profe.cod<<endl;
					cout<<"\n";
				}
				getline(leer,mat.cod);
		}
		if(existe==false)
		{
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                       Consulta: NO exitosa"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"          La materia con el código: "<<mat.auxcod<<" no se encuentra registrada"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                     ";
			system("pause");
		}
	}
	else
	{
		fail();
	}
	leer.close();
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"                     ";
	system("pause");
}
void consultarProfesor()
{
	ifstream leer;
	bool existe=false;
	leer.open("usuarioProfesores.txt", ios::in);
	if(leer.is_open())
	{
		system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                Digite el código del profesor a consultar: ";
		fflush(stdin);
		getline(cin,prof.auxcod);
		leer.seekg(0);
		getline(leer,prof.cod);
		while(!leer.eof())
		{
				getline(leer,prof.clave);
				getline(leer,prof.nombre);
				getline(leer,prof.materia1);
				getline(leer,prof.materia2);
				if(prof.auxcod==prof.cod)
				{
					existe=true;
					cout<<"--------------------------------------------------------------------------------"<<endl;
					cout<<"                       Consulta: Exitosa"<<endl;
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"                       Código: "<<prof.cod<<endl;
					cout<<"                       Nombre: "<<prof.nombre<<endl;
					cout<<"                       Clave: "<<prof.clave<<endl;
					cout<<"                       Materia 1: "<<prof.materia1<<endl;
					cout<<"                       Materia 2: "<<prof.materia2<<endl;
					cout<<"\n";
				}
				getline(leer,prof.cod);
		}
		if(existe==false)
		{
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                       Consulta: NO exitosa"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"          El profesor con el código: "<<prof.auxcod<<" no se encuentra registrado"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                     ";
			system("pause");
		}
	}
	else
	{
		fail();
	}
	leer.close();
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"                     ";
	system("pause");
}
void consultarNota()
{
	
}
void editarEst()
{
	ifstream leer;
	ifstream verificador;
	ofstream auxiliar;
	string codigoAux;
	bool existe=false;
	bool coincidencia=false;
	bool repetido=false;
	leer.open("estudiantes.txt", ios::in);
	verificador.open("estudiantes.txt", ios::in);
	auxiliar.open("auxiliar.txt", ios::out);
		system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                               Editar Estudiante"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
	if(leer.is_open() and verificador.is_open() and auxiliar.is_open())
	{
		cout<<"               Digite el código del estudiante a editar: ";
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
		//copiar codigo
		codigoAux=alu.auxcod;
		getline(leer,alu.cod);
		while(!leer.eof())
		{
			getline(leer,alu.clave);
			getline(leer,alu.nombre);
			getline(leer,alu.sexo);
			getline(leer,alu.carrera);
			getline(leer,alu.semestre);
			getline(leer,alu.facultad);
			getline(leer,alu.ano);
			if(alu.auxcod==alu.cod)
			{
				existe=true;
				mostrarRegistroEst(codigoAux);
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"                       Ingrese la nueva información"<<endl;
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
				if(alu.auxcod==codigoAux)
				{
					repetido=true;
				}
				if(repetido==false)
				{
					do
					{
						if(alu.auxcod==alu.cod)
						{
							coincidencia=false;
							break;
						}
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
				}
				//datos
				system("cls");
			//	alu.cod=alu.auxcod;
				cout<<"\n--------------------------------------------------------------------------------";
				cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"                                Editar estudiante"<<endl;
				mostrarRegistroEst(codigoAux);
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"                       Ingrese la nueva información"<<endl;
				cout<<"\n--------------------------------------------------------------------------------"<<endl;	
				cout<<"                Digite el código del estudiante: "<<alu.auxcod;
				cout<<"\n\n                Digite la clave del estudiante: ";
				fflush(stdin);
				getline(cin,alu.auxclave);
				cout<<"\n                Digite el nombre del estudiante: ";
				fflush(stdin);
				getline(cin,alu.auxnombre);
				cout<<"\n                Digite el sexo del estudiante: ";
				fflush(stdin);
				getline(cin,alu.auxsexo);
				cout<<"\n                Digite la carrera del estudiante: ";
				fflush(stdin);
				getline(cin,alu.auxcarrera);
				cout<<"\n                Digite el semestre del estudiante: ";
				fflush(stdin);
				getline(cin,alu.auxsemestre);
				cout<<"\n                Digite la facultad del estudiante: ";
				fflush(stdin);
				getline(cin,alu.auxfacultad);	
				cout<<"\n                Digite el año de ingreso del estudiante: ";
				fflush(stdin);
				getline(cin,alu.auxano);
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				auxiliar<<alu.auxcod<<"\n"<<alu.auxclave<<"\n"<<alu.auxnombre<<"\n"<<alu.auxsexo<<"\n"<<alu.auxcarrera
						   <<"\n"<<alu.auxsemestre<<"\n"<<alu.auxfacultad<<"\n"<<alu.auxano<<"\n";
				cout<<"                             Registro editado"<<endl;
			}
			else
			{
				//copiar al auxiliar
				auxiliar<<alu.cod<<"\n"<<alu.clave<<"\n"<<alu.nombre<<"\n"<<alu.sexo<<"\n"<<alu.carrera
						   <<"\n"<<alu.semestre<<"\n"<<alu.facultad<<"\n"<<alu.ano<<"\n";
			}
			
			getline(leer,alu.cod);
		}
	}
	else
	{
		fail();
	}
	
	if(existe==false)
	{
		//no se encontro
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                       Edición: NO exitosa"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"          El estudiante con el código: "<<alu.auxcod<<" no se encuentra registrado"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                     ";
		system("pause");
	}
	leer.close();
	verificador.close();
	auxiliar.close();
	remove("estudiantes.txt");
	rename("auxiliar.txt","estudiantes.txt");
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"                     ";
	system("pause");
}

void mostrarRegistroEst(string codigo)
{
	ifstream leer;
	leer.open("estudiantes.txt", ios::in);
	getline(leer,alu.cod);
	while(!leer.eof())
	{
		getline(leer,alu.clave);	
		getline(leer,alu.nombre);
		getline(leer,alu.sexo);						
		getline(leer,alu.carrera);
		getline(leer,alu.semestre);
		getline(leer,alu.facultad);
		getline(leer,alu.ano);
		if(codigo==alu.cod)
		{
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"                       Registro encontrado"<<endl;
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"                       Código: "<<alu.cod<<endl;
				cout<<"                       Clave: "<<alu.clave<<endl;
				cout<<"                       Nombre: "<<alu.nombre<<endl;
				cout<<"                       Sexo: "<<alu.sexo<<endl;
				cout<<"                       Carrera: "<<alu.carrera<<endl;
				cout<<"                       Semestre: "<<alu.semestre<<endl;
				cout<<"                       Facultad: "<<alu.facultad<<endl;
				cout<<"                       Año de ingreso: "<<alu.ano<<endl;		
		}
		getline(leer,alu.cod);
	}
	leer.close();
}
void editarMateria()
{
	ifstream leer;
	ifstream verificador;
	ofstream auxiliar;
	string codigoAux;
	bool existe=false;
	bool coincidencia=false;
	bool repetido=false;
	leer.open("materias.txt", ios::in);
	verificador.open("materias.txt", ios::in);
	auxiliar.open("auxiliar.txt", ios::out);
		system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                               Editar Materia"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
	if(leer.is_open() and verificador.is_open() and auxiliar.is_open())
	{
		cout<<"               Digite el código de la materia a editar: ";
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
		//copiar codigo para mostrar el registro
		codigoAux=mat.auxcod;
		getline(leer,mat.cod);
		while(!leer.eof())
		{
			getline(leer,mat.nombre);
			getline(leer,mat.profe.cod);
			if(mat.auxcod==mat.cod)
			{
				existe=true;
				mostrarRegistroMat(codigoAux);
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"                       Ingrese la nueva información"<<endl;
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
				if(mat.auxcod==codigoAux)
				{
					repetido=true;
				}
				if(repetido==false)
				{
					do
					{
						if(mat.auxcod==mat.cod)
						{
							//Aquí no entra en la primera vuelta
							//Si el usuario vueleve a repetir el codigo pues quiere decir que lo va a mantener
							coincidencia=false;
							break;
						}
						//Hay que ver si el código esta repetido
						verificador.seekg(0);
						getline(verificador,mat.cod);
						while(!verificador.eof())
						{
							getline(verificador,mat.nombre);
							getline(verificador,mat.profe.cod);
							//mirar si no existe un estudiante con el código nuevo
							if(mat.auxcod==mat.cod)
							{
								coincidencia=true;
								cout<<"\n--------------------------------------------------------------------------------"<<endl;
								cout<<"                La materia  con ese codigo ya esxixte"<<endl;
								cout<<"                La materia es: "<<mat.nombre<<endl;
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
							getline(verificador,mat.cod);
						}
						if(verificador.eof() and mat.auxcod!=mat.cod)
						{
							coincidencia=false;
						}
					}while(coincidencia==true);
				}
			//resto de datos
			system("cls");
			cout<<"\n--------------------------------------------------------------------------------";
			cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                                Editar Materia"<<endl;
			mostrarRegistroMat(codigoAux);
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                       Ingrese la nueva información"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;	
			cout<<"                Digite el código de la materia: "<<mat.auxcod;
			cout<<"\n\n                Digite la el nombre de la materia: ";
			fflush(stdin);
			getline(cin,mat.auxnombre);
			cout<<"\n                Digite el código del profesor: ";
			fflush(stdin);
			getline(cin,mat.profe.auxcod);
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			//guardar el editado
			auxiliar<<mat.auxcod<<"\n"<<mat.auxnombre<<"\n"<<mat.profe.auxcod<<"\n";
			cout<<"                             Registro editado"<<endl;
		}
		else
		{
			//copiar registro no editado al auxiliar
			auxiliar<<mat.cod<<"\n"<<mat.nombre<<"\n"<<mat.profe.cod<<"\n";
		}
			//si lo modifico se edito
			//si no pasa al siguiente estudiante con la linea de abajo, lo copeea o lo eidta si no era
			getline(leer,mat.cod);
		}
	}
	else
	{
		fail();
	}
	
	if(existe==false)
	{
		//no se encontro
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                       Edición: NO exitosa"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"          La nateria con el código: "<<mat.auxcod<<" no se encuentra registrado"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                     ";
		system("pause");
	}
	leer.close();
	verificador.close();
	auxiliar.close();
	remove("materias.txt");
	rename("auxiliar.txt", "materias.txt");
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"                     ";
	system("pause");
}

void mostrarRegistroMat(string codigo)
{
	ifstream leer;
	leer.open("materias.txt", ios::in);
	getline(leer,mat.cod);
	while(!leer.eof())
	{
		getline(leer,mat.nombre);
		getline(leer,mat.profe.cod);
		if(codigo==mat.cod)
		{
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"                       Registro encontrado"<<endl;
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"                       Código Materia: "<<mat.cod<<endl;
				cout<<"                       Nombre Materia: "<<mat.nombre<<endl;
				cout<<"                       Código Profesor: "<<mat.profe.cod<<endl;
		}
		getline(leer,mat.cod);
	}
	leer.close();
}

void editarProfesor()
{
	ifstream leer;
	ifstream verificador;
	ofstream auxiliar;
	string codigoAux;
	bool existe=false;
	bool coincidencia=false;
	bool repetido=false;
	leer.open("usuarioProfesores.txt", ios::in);
	verificador.open("usuarioProfesores.txt", ios::in);
	auxiliar.open("auxiliar.txt", ios::out);
	system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                               Editar Profesor"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
	if(leer.is_open() and verificador.is_open() and auxiliar.is_open())
	{
		cout<<"               Digite el código del profesor a editar: ";
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
		//copiar codigo
		codigoAux=prof.auxcod;
		getline(leer,prof.cod);
		while(!leer.eof())
		{
			getline(leer,prof.clave);
			getline(leer,prof.nombre);
			getline(leer,prof.materia1);
			getline(leer,prof.materia2);
			if(prof.auxcod==prof.cod)
			{
				existe=true;
				mostrarRegistroProf(codigoAux);
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"                       Ingrese la nueva información"<<endl;
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
				if(prof.auxcod==codigoAux)
				{
					repetido=true;
				}
				if(repetido==false)
				{
					do
					{
						if(prof.auxcod==prof.cod)
						{
							coincidencia=false;
							break;
						}
						verificador.seekg(0);
						getline(verificador,prof.cod);
					
						while(!verificador.eof())
						{
							getline(verificador,prof.clave);	
							getline(verificador,prof.nombre);
							getline(verificador,prof.materia1);
							getline(verificador,prof.materia2);
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
				}
				//datos
				system("cls");
			//	prof.cod=prof.auxcod;
				cout<<"\n--------------------------------------------------------------------------------";
				cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"                                Editar profesor"<<endl;
				mostrarRegistroProf(codigoAux);
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"                       Ingrese la nueva información"<<endl;
				cout<<"\n--------------------------------------------------------------------------------"<<endl;	
				cout<<"                Digite el código del profesor: "<<prof.auxcod;
				cout<<"\n\n                Digite la clave del profesor: ";
				fflush(stdin);
				getline(cin,prof.auxclave);
				cout<<"\n                Digite el nombre del profesor: ";
				fflush(stdin);
				getline(cin,prof.auxnombre);
				cout<<"\n                Digite la materia 1: ";
				fflush(stdin);
				getline(cin,prof.auxmateria1);
				cout<<"\n                Digite la materia 2: ";
				fflush(stdin);
				getline(cin,prof.auxmateria2);
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				auxiliar<<prof.auxcod<<"\n"<<prof.auxclave<<"\n"<<prof.auxnombre<<"\n"<<prof.auxmateria1<<"\n"<<prof.auxmateria2<<"\n";
				cout<<"                             Registro editado"<<endl;
			}
			else
			{
				//copiar al auxiliar
				auxiliar<<prof.cod<<"\n"<<prof.clave<<"\n"<<prof.nombre<<"\n"<<prof.materia1<<"\n"<<prof.materia2<<"\n";
			}
			
			getline(leer,prof.cod);
		}
	}
	else
	{
		fail();
	}
	
	if(existe==false)
	{
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                       Edición: NO exitosa"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"          El profesor con el código: "<<prof.auxcod<<" no se encuentra registrado"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                     ";
		system("pause");
	}
	
	leer.close();
	verificador.close();
	auxiliar.close();
	remove("usuarioProfesores.txt");
	rename("auxiliar.txt","usuarioProfesores.txt");
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"                     ";
	system("pause");
}

void mostrarRegistroProf(string codigo)
{
	ifstream leer;
	leer.open("usuarioProfesores.txt");
	getline(leer,prof.cod);
	while(!leer.eof())
	{
		getline(leer,prof.clave);
		getline(leer,prof.nombre);
		getline(leer,prof.materia1);
		getline(leer,prof.materia2);
		if(codigo==prof.cod)
		{
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                       Registro encontrado"<<endl;
			cout<<"\n--------------------------------------------------------------------------------"<<endl;
			cout<<"                       Código: "<<prof.cod<<endl;
			cout<<"                       Clave: "<<prof.clave<<endl;
			cout<<"                       Nombre: "<<prof.nombre<<endl;
			cout<<"                       Materia 1: "<<prof.materia1<<endl;
			cout<<"                       Materia 2: "<<prof.materia2<<endl;
		}
		getline(leer,prof.cod);
	}
	leer.close();
}

void editarNota()
{
	
}

void mostrarRegistroNota(string codigo)
{
	
}
//consultar las notas de un estudiante??
void eliminarEst()
{
	ifstream leer;
	ofstream auxiliar;
	bool existe=false;
	string confirmacion;
	leer.open("estudiantes.txt",ios::in);
	auxiliar.open("auxiliar.txt",ios::out);
	system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                             Eliminar Estudiante"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		if(leer.is_open() and auxiliar.is_open())
		{
			cout<<"             Digite el código del estudiante a eliminar: ";
			fflush(stdin)	;
			getline(cin,alu.auxcod);
			leer.seekg(0);
			getline(leer,alu.cod);
			while(!leer.eof())
			{
				getline(leer,alu.clave);
				getline(leer,alu.nombre);
				getline(leer,alu.sexo);
				getline(leer,alu.carrera);
				getline(leer,alu.semestre);
				getline(leer,alu.facultad);
				getline(leer,alu.ano);
				if(alu.auxcod==alu.cod)
				{
					existe=true;
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"                       Registro encontrado"<<endl;
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"                       Código: "<<alu.cod<<endl;
					cout<<"                       Nombre: "<<alu.nombre<<endl;
					cout<<"                       Clave: "<<alu.clave<<endl;
					cout<<"                       Sexo: "<<alu.sexo<<endl;
					cout<<"                       Carrera: "<<alu.carrera<<endl;
					cout<<"                       Semestre: "<<alu.semestre<<endl;
					cout<<"                       Facultad: "<<alu.facultad<<endl;
					cout<<"                       Año de ingreso: "<<alu.ano<<endl;
					cout<<"\n";
					cout<<"    ¿Está seguro de eliminar el registro de: "<<alu.nombre<<"(s/n)? " ;
					getline(cin,confirmacion);//agreagr variable
					if(confirmacion=="s" or confirmacion=="si" or confirmacion=="sii" 
					or confirmacion=="SI" or confirmacion=="Sí" or confirmacion=="S"
					or confirmacion=="Si" or confirmacion=="sI")
					{
						cout<<"--------------------------------------------------------------------------------";
						cout<<"                 Se ha eliminado correctamente al estudiante";
					}
					else
					{
						cout<<"--------------------------------------------------------------------------------";
						cout<<"                 Se ha conservado correctamente al estudiante";
						auxiliar<<alu.cod<<"\n"<<alu.clave<<"\n"<<alu.nombre<<"\n"<<alu.sexo<<"\n"<<alu.carrera
							   <<"\n"<<alu.semestre<<"\n"<<alu.facultad<<"\n"<<alu.ano<<"\n";
					}
					
				}
				else
				{
					auxiliar<<alu.cod<<"\n"<<alu.clave<<"\n"<<alu.nombre<<"\n"<<alu.sexo<<"\n"<<alu.carrera
						   <<"\n"<<alu.semestre<<"\n"<<alu.facultad<<"\n"<<alu.ano<<"\n";
				}
				getline(leer,alu.cod);
			}
			if(existe==false)
			{
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"               No se ha encontrado al estudiante con código: "<<alu.auxcod;
			}
		}
		else
		{
			fail();
		}
		leer.close();
		auxiliar.close();
		remove("estudiantes.txt");
		rename("auxiliar.txt","estudiantes.txt");
		cout<<"--------------------------------------------------------------------------------"<<endl;
		cout<<"                     ";
		system("pause");
}

void eliminarMateria()
{
	ifstream leer;
	ofstream auxiliar;
	bool existe=false;
	string confirmacion;
	leer.open("materias.txt",ios::in);
	auxiliar.open("auxiliar.txt",ios::out);
		system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                               Eliminar Materia"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		if(leer.is_open() and auxiliar.is_open())
		{
			cout<<"             Digite el código de la materia a eliminar: ";
			fflush(stdin)	;
			getline(cin,mat.auxcod);
			leer.seekg(0);
			getline(leer,mat.cod);
			while(!leer.eof())
			{
				getline(leer,mat.nombre);
				getline(leer,mat.profe.cod);
				
				if(mat.auxcod==mat.cod)
				{
					existe=true;
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"                       Registro encontrado"<<endl;
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"                       Código Materia: "<<mat.cod<<endl;
					cout<<"                       Nombre Materia: "<<mat.nombre<<endl;
					cout<<"                       Código Profesor "<<mat.profe.cod<<endl;
					cout<<"\n";
					cout<<"    ¿Está seguro de eliminar el registro de: "<<mat.nombre<<"(s/n)? " ;
					getline(cin,confirmacion);
					if(confirmacion=="s" or confirmacion=="si" or confirmacion=="sii" 
					or confirmacion=="SI" or confirmacion=="Sí" or confirmacion=="S"
					or confirmacion=="Si" or confirmacion=="sI")
					{
						cout<<"--------------------------------------------------------------------------------";
						cout<<"                 Se ha eliminado la materia correctamente";
					}
					else
					{
						cout<<"--------------------------------------------------------------------------------";
						cout<<"                 Se ha conservado la materia correctamente";
						auxiliar<<mat.cod<<"\n"<<mat.nombre<<"\n"<<mat.profe.cod<<"\n";
					}
					
				}
				else
				{
					auxiliar<<mat.cod<<"\n"<<mat.nombre<<"\n"<<mat.profe.cod<<"\n";
				}
				getline(leer,mat.cod);
			}
			if(existe==false)
			{
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"               No se ha encontrado la materia con código: "<<mat.auxcod;
			}
		}
		else
		{
			fail();
		}
		leer.close();
		auxiliar.close();
		remove("materias.txt");
		rename("auxiliar.txt","materias.txt");
		cout<<"--------------------------------------------------------------------------------"<<endl;
		cout<<"                     ";
		system("pause");
}
void eliminarProfesor()
{
	ifstream leer;
	ofstream auxiliar;
	bool existe=false;
	string confirmacion;
	leer.open("usuarioProfesores.txt",ios::in);
	auxiliar.open("auxiliar.txt",ios::out);
	system("cls");
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"               Bienvenido al Sistema de Gestión Académica: CONDOR"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		cout<<"                             Eliminar Profesor"<<endl;
		cout<<"\n--------------------------------------------------------------------------------"<<endl;
		if(leer.is_open() and auxiliar.is_open())
		{
			cout<<"             Digite el código del profesor a eliminar: ";
			fflush(stdin)	;
			getline(cin,prof.auxcod);
			leer.seekg(0);
			getline(leer,prof.cod);
			while(!leer.eof())
			{
				getline(leer,prof.clave);
				getline(leer,prof.nombre);
				getline(leer,prof.materia1);
				getline(leer,prof.materia2);
				if(prof.auxcod==prof.cod)
				{
					existe=true;
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"                       Registro encontrado"<<endl;
					cout<<"\n--------------------------------------------------------------------------------"<<endl;
					cout<<"                       Código: "<<prof.cod<<endl;
					cout<<"                       Nombre: "<<prof.nombre<<endl;
					cout<<"                       Clave: "<<prof.clave<<endl;
					cout<<"                       Materia 1: "<<prof.materia1<<endl;
					cout<<"                       Materia 2: "<<prof.materia2<<endl;
					cout<<"\n";
					cout<<"    ¿Está seguro de eliminar el registro de: "<<prof.nombre<<"(s/n)? " ;
					getline(cin,confirmacion);//agreagr variable
					if(confirmacion=="s" or confirmacion=="si" or confirmacion=="sii" 
					or confirmacion=="SI" or confirmacion=="Sí" or confirmacion=="S"
					or confirmacion=="Si" or confirmacion=="sI")
					{
						cout<<"--------------------------------------------------------------------------------";
						cout<<"                 Se ha eliminado correctamente al profesor";
					}
					else
					{
						cout<<"--------------------------------------------------------------------------------";
						cout<<"                 Se ha conservado correctamente al profesor";
						auxiliar<<prof.cod<<"\n"<<prof.clave<<"\n"<<prof.nombre<<"\n"<<prof.materia1<<"\n"<<prof.materia2<<"\n";
					}
					
				}
				else
				{
					auxiliar<<prof.cod<<"\n"<<prof.clave<<"\n"<<prof.nombre<<"\n"<<prof.materia1<<"\n"<<prof.materia2<<"\n";
				}
				getline(leer,prof.cod);
			}
			if(existe==false)
			{
				cout<<"\n--------------------------------------------------------------------------------"<<endl;
				cout<<"               No se ha encontrado al profesor con código: "<<prof.auxcod;
			}
		}
		else
		{
			fail();
		}
		leer.close();
		auxiliar.close();
		remove("usuarioProfesores.txt");
		rename("auxiliar.txt","usuarioProfesores.txt");
		cout<<"--------------------------------------------------------------------------------"<<endl;
		cout<<"                     ";
		system("pause");
}

void eliminarNota()
{
	
}
//2016001006
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
		fail();
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
			getline(leer,prof.materia1);
			getline(leer,prof.materia2);
			cout<<"                         Código: "<<prof.cod<<endl;
			cout<<"                         Clave: "<<prof.clave<<endl;
			cout<<"                         Nombre: "<<prof.nombre<<endl;
			cout<<"                         Materia 1: "<<prof.materia1<<endl;
			cout<<"                         Materia 2: "<<prof.materia2<<endl;
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
		fail();
	}
	leer.close();
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"                     ";
	system("pause");
	menu();
}
void listarMateria()//repenzar
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
		fail();
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

void fail()
{
	system("cls");
	cout<<"\n--------------------------------------------------------------------------------";
	cout<<"\n                 Universidad Distrital Francisco José de Caldas"<<endl;
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"                         Error: Esto no deberia haber pasado";
	cout<<"\n--------------------------------------------------------------------------------"<<endl;
	cout<<"                     ";
	system("pause");
	menu();
	exit(1);
}

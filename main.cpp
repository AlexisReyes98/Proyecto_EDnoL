#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "ABB.h"

//Clase que simula la autenticacion del sistema de la Empresa X
class Sistema
{
    private:
        ABB<string> abbUsuarios;    //Se crea un ABB de strings (para introducir a los usuarios)
        //Como atributo de la clase
    public:
        //Para buenas practicas
        Sistema(){}
        ~Sistema(){}
        //Funcion para dar acceso al sistema de usuarios
        void acceso()
        {
            ifstream archivo;   //Use esta variable para leer el archivo
            string usuario;     //Use esta variable para extraer a cada usuario
            
            archivo.open("usuarios.txt",ios::in);   //Se abre el archivo en modo lectura

            if (archivo.fail())     //En caso de no poder abrir el archivo
            {
                cerr<<"No se pudo abrir el archivo usuarios.txt"<<endl;
                exit(1);
            }
            
            //Una vez abierto el archvio
            while (!archivo.eof())      //Mientras no sea el final del archivo
            {
                getline(archivo,usuario);   //Se lee cada linea del archivo (cada usuario)
                abbUsuarios.insertar(usuario);  //Se inserta em el ABB a cada usuario
            }

            archivo.close();    //Cierro el archivo ya que no se utilizara mas
            
            string userName="", password="";     //Creo dos strings
            //Username para leer el nombre de usuario y password para leer la contraseña 

            cout<<endl<<"Leyendo el arvicho usuarios.txt..."<<endl;
            cout<<"Escriba 'salir' en 'Username' para terminar la ejecucion"<<endl;
            cout<<endl<<"Bienvenido al sistema de identificacion de usuarios :)"<<endl<<endl;
            for (;;)    //Use un for 'infinito' ya que no tiene parametros de inicio, fin y de avance
            {
                cout<<"Username:"<<endl;
                cout<<"--->"; cin>>userName;    //Se lee el nombre de usuario
                if (userName == "salir")    //Si el usuario escribe salir
                {
                    break;  //Termino la ejecución
                }
                else{   //Otra caso
                    cout<<"Password:"<<endl;
                    cout<<"--->"; cin>>password;    //Se lee la contraseña
                    string buscarUsuario = userName+"-"+password;   //Concateno el username y password
                    //Usando este formato: 'username-password' ya que asi estan almacenados los usuarios en el .txt

                    if (abbUsuarios.buscar(buscarUsuario))  //Si se encuentra al usuario en el ABB
                    {
                        cout<<endl<<"Welcome!!!"<<endl;
                        cout<<"Acceso permitido"<<endl<<endl;
                    }
                    else    //En caso de no encontrar al usuario
                    {
                        cout<<endl<<"Warning!!!"<<endl;
                        cout<<"Acceso denegado"<<endl;
                        cout<<"Por favor escriba un 'username' y 'password' validos..."<<endl<<endl;
                    }
                }
            }
        }
};

int main()
{
    Sistema sistema;    //Objeto para instanciar la clase Sistema

    sistema.acceso();   //Se con el objeto de la clase a la funcion acceso()

    return 0;
}

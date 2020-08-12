// Programa que lee un archivo CSV para texto.
//Creado por Juan Sebastian Gomez Vera.
//Basado en programa de Cesar Aceros


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctype.h>

using namespace std;

void prom() //creamos una funcion prom.
{
	ifstream archivo("PromedioCSV.csv"); //leemos el archivo y lo almacenamos en una variable.
	string linea; //creamos un string "linea."
	vector<vector<string>> parsedCsv; //creamos un vector.
    int rowcount=0; //Creamos dos contadores
    int colcount=0;
	while (getline (archivo, linea)) { //Leemos una lina del archivo
		stringstream l(linea); //almacenamos esa linea en una variable
		string celda; // creamos un string "Celda"
        vector<string> parsedRow; // creamos un vector.
        colcount=0; // le damos un valor inicial al contador.
		while(getline(l, celda, ',')) { //leemos la variable celda de la linea, separada por comas.
 			parsedRow.push_back(celda);//tomamos de la celda el dato.
            colcount++;//incrementamos colcount en 1.
		}
        rowcount++;//aumentamos rowcount en 1.
        parsedCsv.push_back(parsedRow);
	}
    int suma = 0;//creamos una variable para almacenar la suma.
    for (int i=0 ; i<rowcount ; i++){ //para cada variable i, tomamos el rowcount y aumentamos en 1.
        int j = 2;//j siempre valdrá 2, esta es la columna que vamos a tomar. Contanto la primera columna como 0.
        std::string::size_type sz; //creamos un alias para el tamaño del string.
        double valor = stod(parsedCsv[i][j],&sz); //convertimos ese string en una variabe double.
        suma= suma + valor;//la suma aumentará dependiendo del valor.
    }
    int prom = 0;// creamos una variable para almacenar el promdeio con un valor nulo.
    prom= suma/19;//ese promedio será la suma antes definida, dividida por la cantidad de datos.
	archivo.close(); //cerramos el archivo.
    cout << "El promedio de las notas es: " << prom << endl; // imprimimos un mensaje con el promedio.
}
int main()
{
	prom(); //llamamos a la funcion prom antes creada.
	return 0;
}
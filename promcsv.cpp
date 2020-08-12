// Programa que lee un archivo CSV para texto.
//Creado por Juan Sebastian Gomez Vera.
//


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctype.h>

using namespace std;

void prom() 
{
	ifstream archivo("PromedioCSV.csv");
	string linea; 
	vector<vector<string>> parsedCsv;
    int rowcount=0;
    int colcount=0;
	while (getline (archivo, linea)) { 
		stringstream l(linea);
		string celda; 
        vector<string> parsedRow;
        colcount=0;
		while(getline(l, celda, ',')) { 
 			parsedRow.push_back(celda);
             colcount++;
		}
        rowcount++;
        parsedCsv.push_back(parsedRow);
	}
    int suma = 0;
    for (int i=0 ; i<rowcount ; i++){
        int j = 2;
        std::string::size_type sz; 
        double valor = stod(parsedCsv[i][j],&sz);
        suma= suma + valor;
    }
    int prom = 0;
    prom= suma/19;
	archivo.close();
    cout << prom << endl;
}
int main()
{
	prom();
	return 0;
}
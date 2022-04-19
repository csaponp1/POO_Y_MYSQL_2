#pragma once
#include "ConexionBD.h"
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

class Marca {
	private: string marca;

	public:
		Marca() {
		};
		Marca(string nom_marc) {
			marca=nom_marc;
		}
		//metodos CRUD
		void crear() {
			ConexionBD cn = ConexionBD();
			cn.abrir_conexion();
			int q_estado;
			
			if (cn.getConectar()) {
				string insert = "insert into marcas (marca) values ('" + marca + "');";
				const char* i = insert.c_str(); //convertido a char
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "ingreso exitoso!" << endl;
				}
					else {
						cout << " xxx error al hacer insert xxx " << endl;
					}
				}
				else {
					cout << " xxx error de conexion xxx" << endl;
				}
			cn.cerrar_conexion();
		}

		void leer() {
			ConexionBD cn = ConexionBD();
			int q_estado;
			MYSQL_ROW fila;
			MYSQL_RES* resultado;
			cn.abrir_conexion();
			cout << " id_marca " << " | " << " marca " <<" | " << endl;
			if (cn.getConectar()) {
				string consulta = "select *from marcas";
				const char* con = consulta.c_str(); //coxnvertimos a char
				q_estado = mysql_query(cn.getConectar(), con);
				if (!q_estado) {
					resultado = mysql_store_result(cn.getConectar());

					while (fila = mysql_fetch_row(resultado)) {
						for (int i = 0; i <= 1; i++) {
							cout << fila[i] << " , ";
							}
							cout << endl;
						}
					}
					else {
						cout << " error al hacer select XXX" << endl;
					}
				}
				else {
					cout << " xxx sin conexion xxx" << endl;
				}
			cn.cerrar_conexion();
		}

		void leer(int x) {
			ConexionBD cn = ConexionBD();
			int q_estado;
			MYSQL_ROW fila;
			MYSQL_RES* resultado;
			string aux = to_string(x);
			cn.abrir_conexion();
			cout << " id_marca " << " | " << " marca " << " | " << endl;
			if (cn.getConectar()) {
				string consulta = "select *from marcas where id_marca="+ aux +";";
				const char* con = consulta.c_str(); //convertimos a char
				q_estado = mysql_query(cn.getConectar(), con);
				if (!q_estado) {
					resultado = mysql_store_result(cn.getConectar());

					while (fila = mysql_fetch_row(resultado)) {
						for (int i = 0; i <= 1; i++) {
							cout << fila[i] << " , ";
						}
						cout << endl;
					}
				}
				else {
					cout << " XXX" << endl;
				}
			}
			else {
				cout << " xxx sin conexion xxx" << endl;
			}
			cn.cerrar_conexion();
		}

		void actualizar() {
			int q_estado = 0;
			ConexionBD cn = ConexionBD();
			cn.abrir_conexion();
			cout << "ingrese indice a actualizar" << endl;
			int aux;
			cin >> aux;
			string i = to_string(aux);
			if (cn.getConectar()) {
				string update = "update marcas set marca = '" + marca + "' where id_marca ="+ i +" ;";
				const char* upda = update.c_str();
				q_estado = mysql_query(cn.getConectar(), upda);
				if(!q_estado){
					cout << " modificado " << endl;
				}
				else {
					cout << "error xxx" << endl;
				}

			}
			else{
				cout << " error de conexion xxx" << endl;
			}
			cn.cerrar_conexion();
		}

		void eliminar(int x) {
			int q_estado;
			ConexionBD cn = ConexionBD();
			cn.abrir_conexion(); \
				
			string i = to_string(x);
			if (cn.getConectar()) {
				string eliminar = "delete from marcas where id_marca =" + i + ";";
				
				const char* eli = eliminar.c_str();
				q_estado = mysql_query(cn.getConectar(), eli);
				if (!q_estado) {
					cout << " fila borrada " << endl;
				}
				else {
					cout << "xxx  error al hacer delete xxx" << endl;
				}
			}
			else {
				cout << "xxx error de conexion xxx" << endl;
			}
			cn.cerrar_conexion();
	}

		void setMarca(string nom_marc) {
			marca = nom_marc;
		}
};


#pragma once
#include "ConexionBD.h"
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class Producto
{
protected: string producto, descripcion, fecha_ingreso;
		 int id_marca = 0, existencia = 0;
		 float precio_costo = 0, precio_venta = 0;

public:
	Producto() {
	};
	Producto(string prod, string descrip, string f_ingreso, int id_mar, int exist, float precio_c, float precio_v) {
		producto = prod;
		descripcion = descrip;
		fecha_ingreso = f_ingreso;
		id_marca = id_mar;
		existencia = exist;
		precio_costo = precio_c;
		precio_venta = precio_v;
	}


	void crear() {
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		int q_estado;
		string i_aux = to_string(id_marca);
		string ii = to_string(existencia);
		string x = to_string(precio_costo);
		string xx = to_string(precio_venta);

		if (cn.getConectar()) {
			string insert = "INSERT INTO productos(producto, id_marca, descripcion, precio_costo, precio_venta, existencia, fecha_ingreso)VALUES('" + producto + "','" + i_aux + "','" + descripcion + "','" + x + "','" + xx + "','" + ii + "','" + fecha_ingreso + "');";
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
		cout << "id_producto" << " | " << "producto" << " | " << "id_marca" << " | " << "descripcion" << " | " << "p costo" << " | " << "p venta " << " | " << "existencia:" << " | " << "ingreso" << " | " << endl;
		if (cn.getConectar()) {
			string consulta = "select *from productos";
			const char* con = consulta.c_str(); //coxnvertimos a char
			q_estado = mysql_query(cn.getConectar(), con);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					for (int i = 0; i <= 7; i++) {
						cout<< fila[i] << " , ";
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
		cout << "id_producto" << " | " << "producto" << " | " << "id_marca" << " | " << "         descripcion           " << " | " << "p costo" << " | " << "p venta " << " | " << "existencia:" << " | " << "ingreso" << " | " << endl;
		if (cn.getConectar()) {
			string consulta = "select *from productos where id_producto=" + aux + ";";
			const char* con = consulta.c_str(); //convertimos a char
			q_estado = mysql_query(cn.getConectar(), con);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					for (int i = 0; i <= 7; i++) {
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
		int aux;
		cout << "ingrese id a actualizar " << endl;
		cin >> aux;
		string i = to_string(aux);
		string i_aux = to_string(id_marca);
		string ii = to_string(existencia);
		string xx = to_string(precio_costo);
		string xxx = to_string(precio_venta);

		if (cn.getConectar()) {
			string update = "update productos SET producto = '"+producto+"', id_marca ="+i_aux+ " , descripcion = '" + descripcion + "', precio_costo = "+xx+", precio_venta = "+xxx+", existencia = "+ii+", fecha_ingreso = '" +fecha_ingreso+ "' WHERE id_producto ="+i+";";
			const char* upda = update.c_str();
			q_estado = mysql_query(cn.getConectar(), upda);
			if (!q_estado) {
				cout << " modificado " << endl;
			}
			else {
				cout << "error xxx" << endl;
			}

		}
		else {
			cout << " error de conexion xxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar(int x) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string i = to_string(x);
		if (cn.getConectar()) {
			string eliminar = "delete from productos where id_producto =" + i + ";";

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

	void setProducto(string prod) { producto = prod; }
	void setID_Marca(int id_mar) { id_marca = id_mar; }
	void setDescripcion(string descrip) { descripcion = descrip; }
	void setP_costo(float precio_c) { precio_costo=precio_c; }
	void setP_venta(float precio_v) { precio_venta = precio_v; }
	void setExistencia(int exist) { existencia = exist; }
	void setF_ingreso(string f_ingreso) { fecha_ingreso = f_ingreso; }
	//get (mostrar)
	string getProducto() { return producto; }
	int getID_marca() { return id_marca; }
	string getDescripcion() { return descripcion; }
	float getP_costo() { return precio_costo; }
	float getP_venta() { return precio_venta; }
	int getExistencia() { return existencia; }
	string getF_ingreso() { return fecha_ingreso; }
};




#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include "ConexionBD.h"
#pragma once

class Proveedor
{
private: string proveedor, nit, direccion;
	   int telefono=0;

public:
	   Proveedor() {
	   }

	   Proveedor(string pro, string nit2, string dir, int tel) {
		   proveedor = pro;
		   nit = nit2;
			   direccion = dir;
			   telefono = tel;

	   }

	   void crear() {

		   ConexionBD cn = ConexionBD();
		   cn.abrir_conexion();
		
		   int q_estado;
		   string telaux = to_string(telefono);

		   if (cn.getConectar()) {
			   string insert = "INSERT INTO proveedores (proveedor,nit,direccion,telefono)VALUES ('" + proveedor + "','" + nit + "','" + direccion + "','" + telaux + "');";
			   const char* i = insert.c_str();
			   q_estado = mysql_query(cn.getConectar(), i);
			   if (!q_estado) {
				   cout << " ingreso Exitoso !" << endl;
			   }
			   else {
				   cout << " xxx error xxx" << endl;
			   }
		   }
		   else {
			   cout << "  xxx Error al ingresar xxx" << endl;
		   }
		   cn.cerrar_conexion();

	   }

	   void leer() {
		   ConexionBD cn = ConexionBD();
		   int q_estado;
		   MYSQL_ROW fila;
		   MYSQL_RES* resultado;
		   cn.abrir_conexion();
		   cout << "id_prov" << " | " << "proveedor" << " | " << "nit" << " | " << "direccion" << " | " << "telefono" << endl;
		   if (cn.getConectar()) {
			   string consulta = "select *from proveedores";
			   const char* con = consulta.c_str(); //coxnvertimos a char
			   q_estado = mysql_query(cn.getConectar(), con);
			   if (!q_estado) {
				   resultado = mysql_store_result(cn.getConectar());

				   while (fila = mysql_fetch_row(resultado)) {
					   for (int i = 0; i <= 4; i++) {
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

	   void actualizar() {
		   int aux;
		   ConexionBD cn = ConexionBD();
		   cn.abrir_conexion();
		   int q_estado;
		   cout << "ingrese id a actualizar " << endl;
		   cin >> aux;
		   
		   string i = to_string(aux);
		   string ii = to_string(telefono);

		   if (cn.getConectar()) {
			   string update = "update proveedores SET proveedor = '" + proveedor + "', nit ='" + nit + "', direccion = '"+ direccion +"', telefono = "+ ii +"  WHERE id_proveedor =" + i + ";";
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
			   string eliminar = "delete from proveedores where id_proveedor =" + i + ";";

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

	   void leer(int x) {
		   ConexionBD cn = ConexionBD();
		   int q_estado;
		   MYSQL_ROW fila;
		   MYSQL_RES* resultado;
		   string aux = to_string(x);
		   cn.abrir_conexion();
		   cout << "id_prov" << " | " << "proveedor" << " | " << "nit" << " | " << "direccion" << " | " << "telefono" << endl;
		   if (cn.getConectar()) {
			   string consulta = "select *from proveedores where id_proveedor=" + aux + ";";
			   const char* con = consulta.c_str(); //convertimos a char
			   q_estado = mysql_query(cn.getConectar(), con);
			   if (!q_estado) {
				   resultado = mysql_store_result(cn.getConectar());

				   while (fila = mysql_fetch_row(resultado)) {
					   for (int i = 0; i <= 4; i++) {
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

	   void setProveedor(string pro) { proveedor = pro; }
	   void setNit(string nit2) { nit = nit2; }
	   void setDireccion(string dir) { direccion = dir; }
	   void setTelefono(int tel) { telefono = tel; }
};


#include<stdio.h>
#include <iostream>
#include <mysql.h>
#include "Marca.h"
#include "Producto.h"
#include "Proveedor.h"



int x = 0;
using namespace std;
int main() {
    string producto, descripcion, fecha_ingreso, marca;
    int id_marca=0, existencia=0, op=0;
    float precio_c=0, precio_v=0;

    string proveedor, nit, direccion;
    int telefono=0;
    bool ciclo = true;
    
    

    do {
        bool ciclo2 = true;
        cout << "BIENVENIDO" << endl;
        cout << " 1. CRUD productos" << endl;
        cout << " 2. CRUD marcas" << endl;
        cout << " 3. CRUD proveedores" << endl;
        cout << " 4. salir" << endl;
        cin >> op;
        do
        {
           
            int op2; 
            string res;
            switch (op) {

                {
            case 1:
                bool ciclo3 = true;
                Producto obj = Producto(producto, descripcion, fecha_ingreso, id_marca, existencia, precio_c, precio_v);
                cout << "ingrese opcion" << endl;
                cout << " PRODUCTOS" << endl;
                cout << "1. crear registro" << endl;
                cout << "2. leer registro" << endl;
                cout << "3. modificar registro" << endl;
                cout << "4. eliminar registro" << endl;
                cout << "5. salir" << endl;
                cout << "Elija" << endl;
                cin >> op2;
                switch (op2) {

                    {
                case 1:
                    cout << "ingrese producto" << endl;
                    cin >> producto;
                    cout << " ingrese id_marca" << endl;
                    cin >> id_marca;
                    cin.ignore();
                    cout << "ingrese descripcion" << endl;
                    getline(cin, descripcion);
                    cout << "ingrese precio costo" << endl;
                    cin >> precio_c;
                    cout << "ingrese precio venta" << endl;
                    cin >> precio_v;
                    cout << "ingrese existencia" << endl;
                    cin >> existencia;
                    cin.ignore();
                    cout << "ingrese fecha ingreso" << endl;
                    getline(cin, fecha_ingreso);

                    obj.setProducto(producto);
                    obj.setID_Marca(id_marca);
                    obj.setDescripcion(descripcion);
                    obj.setP_costo(precio_c);
                    obj.setP_venta(precio_v);
                    obj.setExistencia(existencia);
                    obj.setF_ingreso(fecha_ingreso);
                    obj.crear();
                    break;
                    }

                    {
                case 2:
                    cout << " Mostrar registros" << endl;
                    system("cls");
                    obj.leer();
                    break;
                    }

                    {
                case 3:
                    cout << "---------ACTUALIZACION---------------" << endl;
                    cout << "ingrese nuevos datos...! luego dele un valor a where" << endl;
                    cout << "ingrese producto" << endl;
                    cin >> producto;
                    cout << " ingrese id_marca" << endl;
                    cin >> id_marca;
                    cin.ignore();
                    cout << "ingrese descripcion" << endl;
                    getline(cin, descripcion);
                    cout << "ingrese precio costo" << endl;
                    cin >> precio_c;
                    cout << "ingrese precio venta" << endl;
                    cin >> precio_v;
                    cout << "ingrese existencia" << endl;
                    cin >> existencia;
                    cin.ignore();
                    cout << "ingrese fecha ingreso" << endl;
                    getline(cin, fecha_ingreso);

                    obj.setProducto(producto);
                    obj.setID_Marca(id_marca);
                    obj.setDescripcion(descripcion);
                    obj.setP_costo(precio_c);
                    obj.setP_venta(precio_v);
                    obj.setExistencia(existencia);
                    obj.setF_ingreso(fecha_ingreso);
                    obj.actualizar();
                    break;

                    }

                    {
                case 4:
                    int op3 = 0;
                    cout << "ingrese registro a eliminar" << endl;
                    cin >> x;
                    obj.leer(x);

                    cout << "desea eliminar? (1/0)" << endl;
                    cin >> op3;

                    if (op3 == 1)
                        obj.eliminar(x);
                    else {
                        cout << "no se elimino" << endl;
                    }
                    break;
                    }

                case 5:
                    ciclo3 = false;
                    ciclo2 = false;
                  
                    break;

                }

                break;
                }
            
            
            {
                
                case 2:

                    
                    bool ciclo4 = true;
                    Marca obj2 = Marca(marca);
                    cout << "ingrese opcion" << endl;
                    cout << " MARCAS " << endl;
                    cout << "1. crear registro" << endl;
                    cout << "2. leer registro" << endl;
                    cout << "3. modificar registro" << endl;
                    cout << "4. eliminar registro" << endl;
                    cout << "Elija" << endl;
                    cin >> op2;

                    switch (op2) {

                        {
                    case 1:
                        cout << "ingrese marca" << endl;
                        cin >> marca;
                        obj2.setMarca(marca);
                        obj2.crear();
                        obj2.leer();
                        break;
                        }

                        {
                    case 2:
                        cout << " Mostrar registros" << endl;
                        system("cls");
                        obj2.leer();
                        break;
                        }

                        {
                    case 3:

                        cout << "ingrese valor nuevo!!! luego haga el where" << endl;
                        cin >> marca;
                        obj2.setMarca(marca);
                        obj2.actualizar();
                        obj2.leer();
                        break;

                        }

                        {
                    case 4:
                        int op4;
                        cout << "ingrese registro a eliminar" << endl;
                        cin >> x;
                        obj2.leer(x);

                        cout << "desea eliminar? (1/0)" << endl;
                        cin >> op4;

                        if (op4 == 1)
                            obj2.eliminar(x);
                        else
                            cout << "no se elimino" << endl;

                        break;
                        }

                    case 5:
                        ciclo4 = false;
                        ciclo2 = false;
                        break;

                    }




                    break;
            }
            {
                case 3:
                    bool ciclo5 = true;
                    Proveedor obj3 = Proveedor(proveedor, nit, direccion, telefono);
                   
                    cout << " PROVEEDORES " << endl;
                    cout << "1. crear" << endl;
                    cout << "2. leer" << endl;
                    cout << "3. actualizar" << endl;
                    cout << "4. eliminar" << endl;
                    cout << "5. salir" << endl;
                    cin >> op2;
                        switch (op2) {
                            {
                            case 1:
                                cout << "\n-----------------------------CREAR-----------------------------------------" << endl;
                                cin.ignore();
                                cout << "ingrese proveedor" << endl;
                                getline(cin, proveedor);
                                cout << "ingrese nit" << endl;
                                getline(cin,nit);
                                cout << "ingrese direccion" << endl;
                                getline(cin, direccion);
                                cout << "ingrese telefono" << endl;
                                cin >> telefono;

                                obj3.setProveedor(proveedor);
                                obj3.setNit(nit);
                                obj3.setDireccion(direccion);
                                obj3.setTelefono(telefono);
                                obj3.crear();
                                
                                break;
                            }
                            {
                            case 2:
                                system("cls");
                                cout << "-------------------------------MOSTRAR----------------------------------------" << endl;
                                obj3.leer();
                                break;
                            }
                        
                            {
                            case 3:
                                cout << "\n---------------------------------ACTUALIZAR--------------------------------------" << endl;
                                cout << "ingrese nuevos datos! luego haga el where" << endl;       
                                cin.ignore();
                                cout << "ingrese proveedor" << endl;
                                getline(cin, proveedor);
                                cout << "ingrese nit" << endl;
                                getline(cin, nit);
                                cout << "ingrese direccion" << endl;
                                getline(cin, direccion);
                                cout << "ingrese telefono" << endl;
                                cin >> telefono;

                                obj3.setProveedor(proveedor);
                                obj3.setNit(nit);
                                obj3.setDireccion(direccion);
                                obj3.setTelefono(telefono);

                                obj3.actualizar();
                                break;
                            }
                            {
                            case 4:
                                int op5 = 0;
                                cout << "ingrese el id a eliminar" << endl;
                                cin >> x;
                                obj3.leer(x);

                                cout << "desea eliminar? (1/0)" << endl;
                                cin >> op5;

                                if (op5 == 1) {
                                    obj3.eliminar(x);
                                }
                                else {
                                    cout << "no se elimino!" << endl;
                                }
                                break; 
                            }
                        
                        case 5:
                            ciclo5 = false;
                            ciclo2 = false;
                            break;
                        }

                    break;
            }
            
         
            
            ////////////////////////////////
            case 4:
             ciclo2 = false;
             break;
            
            }


        }while (ciclo2 != 0);

    } while (op<4);

    system("pause");

    }
    

   

   

  
   
    
    
        





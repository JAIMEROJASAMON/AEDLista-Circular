/*Rodrigo Mayett Guzman
se definen los constructores del nodo 
y sus atributos*/
#include <iostream>

class Nodo
{
private://atributos
	int Dato;
	Nodo* Sig;
public://constructores
	Nodo(int Dato, Nodo* Sig);
	Nodo(int Dato);
	void setDato(int Dato);
	void setSig(Nodo* Sig);
	int getDato();
	Nodo* getSig();
	//~Nodo();
};
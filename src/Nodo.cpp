/*Rodrigo Mayett Guzman
el programa define los metodos del nodo*/
#include "Nodo.h"
//crea un nodo con un dato dado por el usuario
//y se le indica cual es su sucesor
Nodo::Nodo(int Dato , Nodo* Sig)
{
	this->Dato = Dato;
	this->Sig = Sig;
}
//crea un nodo unico 
Nodo::Nodo(int Dato)
{
	this->Dato = Dato;
	this->Sig = NULL;
}
//modifica el dato del nodo actual
void Nodo::setDato(int Dato)
{
	this->Dato = Dato;
}
//indica el nuevo sucesor del nodo
void Nodo::setSig(Nodo* Sig)
{
	this->Sig = Sig;
}
//obtiene el dato del nodo
int Nodo::getDato()
{
	return this->Dato;
}
//obtiene el sucesor del nodo
Nodo* Nodo::getSig()
{
	return this->Sig;
}
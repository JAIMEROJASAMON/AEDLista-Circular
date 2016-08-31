/*Rodrigo Mayett Guzman
define los metodos de la lista
 que ya se habian definido en Lista.h*/
#include "Lista.h"
//crea una lista vacia
Lista::Lista()
{
	this->H=NULL;
	this->T=NULL;
}
//crea una lista con un dato
Lista::Lista(int Dato)
{
	Nodo * aux= new Nodo(Dato);
	this->H=aux;
	this->T=aux;
}
//verifica si la lista esta vacia 
bool Lista::ListaVacia()
{
	if (this->H == NULL && this->T == NULL)
		return true;
	return false;
}
//agrega un elemento al inicio de la lista
//y cambia la referencia de H
void Lista::AddInicio(int Dato)
{
	Nodo* aux = new Nodo(Dato,this->H);
	if (ListaVacia())
	{
		this->T= aux;
	}
	this->H= aux;
}
//agrega un elemento al final de la lista 
//y cambia la referencia de T
void Lista::AddFinal(int Dato){
	Nodo * aux = new Nodo(Dato);
	if (!ListaVacia())
	{
		T->setSig(aux);
		T=aux;
		this->T->setSig(this->H);		
	}
	else{
		this->H=aux;
		this->T=aux;
	}		
}
//Agrega un dato en la lista despues de la referencia
void Lista::AddRef(int Dato, int Ref){
	if (ListaVacia())
	{
		Nodo * aux = new Nodo(Dato);
		this->H =aux;
		this->T =this->H;
		std::cout<<"No se encontro la referencia porque la lista esta vacia"<<std::endl;
		return ;		
	}
	Nodo * aux = this->H;
	while(aux->getDato()!=Ref&&aux!=this->T){
		aux = aux->getSig();
	}
	if (aux!=NULL)
	{
		Nodo * aux2 = new Nodo(Dato,aux->getSig());
		aux->setSig(aux2);
		T->setSig(this->H);
	}
	else{
		std::cout<<"No existe la referenci aen la lista"<<std::endl;
	}
}
//remueve el primer elemento de la lista 
//y cambia la referencia de H
int Lista::RemoveInicio(){
	if (!ListaVacia())
	{
		int Dato =this->H->getDato();	
	if (this->H==NULL)
	{
		this->T=NULL;
	}
	this->H=this->H->getSig();
	this->T->setSig(this->H);
	return Dato;
	}
	else{
		std::cout<<"La lista esta vacia"<<std::endl;		
	}	
}
//remueve el ultimo nodo de la lista y 
//cambia la referencia de T
int Lista::RemoveFinal(){
	if (ListaVacia())
	{
		std::cout<<"La lista esta vacia"<<std::endl;
	}
	int Dato =T->getDato();
	if (this->H!=this->T)
	{
		Nodo * aux = this->H;
		while(aux->getSig()!=this->T){
			aux = aux->getSig();
		}
		this->T=aux;
		this->T->setSig(this->H);		
	}
	else{
		this->H=NULL;
		this->T=NULL;
	}
	return Dato;
}
//busca un dato  en la lista 
Nodo * Lista::BuscarElemento(int Dato){
	if (ListaVacia())
	{
		std::cout<<"No se encuentra el elemento"<<std::endl;
		return NULL;		
	}
	Nodo * aux = this->H;
	while(aux->getDato()!=Dato&&aux!=T){
		aux=aux->getSig();
	}	
	if (aux->getDato()!=Dato)
	{//en caso de no encontrar el dato regresa null e indica que no lo encontro
		std::cout<<"No se encuentra el elemento"<<std::endl;
		return NULL;
	}
	if (aux->getDato()==Dato)
	{
		std::cout<<aux->getDato()<<" se encuentra en la lista"<<std::endl;	
	}
	return aux;
}
//remueve un dato basado en la referencia dada 
Nodo * Lista::RemoveRef(int Ref){
	if (ListaVacia())
	{
		Nodo * aux = new Nodo(Ref);
		this->H =aux;
		this->T =this->H;
		std::cout<<"No se encontro la referencia porque la lista esta vacia"<<std::endl;
		return NULL;		
	}
	Nodo * aux = this->H;
	Nodo * aux2 = this->H;
	while(aux->getDato()!=Ref&&aux!=this->T){
		aux = aux->getSig();
	}
	while(aux2->getSig()!=aux){
		aux2 = aux2->getSig();
	}
	if (aux!=NULL)
	{		
		aux2->setSig(aux->getSig());
	}
	else{
		std::cout<<"No existe la referencia en la lista"<<std::endl;
	}
}
//vacia la lista completa
int Lista::VaciarLista(){	
	this->H=NULL;
	this->T=NULL;
	std::cout<<"Lista Vaciada"<<std::endl;	
}
//muestra los elementos de la lista
void Lista::Show()
{
	Nodo* aux = this->H;
	while(aux!=T)
	{
		std::cout<<aux->getDato()<<std::endl;
		aux=aux->getSig();
	}
	if (!ListaVacia())
	{		
		std::cout<<aux->getDato()<<std::endl;
	}
}
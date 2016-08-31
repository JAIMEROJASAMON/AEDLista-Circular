#include "Lista.h"

Lista::Lista()
{
	this->H=NULL;
	this->T=NULL;
}

Lista::Lista(int Dato)
{
	Nodo * aux= new Nodo(Dato);
	this->H=aux;
	this->T=aux;
	/*std::cout<<H->getDato()<<std::endl;
	std::cout<<H->getSig()<<std::endl;
	std::cout<<T->getDato()<<std::endl;
	std::cout<<T->getSig()<<std::endl;*/
}

bool Lista::ListaVacia()
{
	if (this->H == NULL && this->T == NULL)
		return true;
	return false;
}

void Lista::AddInicio(int Dato)
{
	Nodo* aux = new Nodo(Dato,this->H);
	if (ListaVacia())
	{
		this->T= aux;
	}
	this->H= aux;
/*	std::cout<<H->getDato()<<std::endl;
	std::cout<<H->getSig()<<std::endl;
	std::cout<<T->getDato()<<std::endl;
	std::cout<<T->getSig()<<std::endl;*/
}
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
	if (aux->getDato()==Dato)
	{
		std::cout<<aux->getDato()<<" se encuentra en la lista"<<std::endl;	
	}
	return aux;
}
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
int Lista::VaciarLista(){	
	this->H=NULL;
	this->T=NULL;
	std::cout<<"Lista Vaciada"<<std::endl;	
}
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
/*EXERCICIO 1 de PDS feito por:
 -Andre Martins Miranda 
 -Nicholas Sorice Baracho Fabriz
 */
#include <iostream>	//usamos essa bibilioteca pela manipulação de fluxo de dados padrão do sistema
#include <string.h>// usamos essa biblioteca para funcoes com string como strcpy()
#include <string>// usamos essa bibiblioteca para poder lidar cm strings
#include <fstream>// usamos essa bibilioteca para o arquivo
#include <sstream>// usamos essa bibilioteca para o arquivo
#include <stdlib.h>// usamos essa biblioteca para usar as funcoes atoi e atof;
#include "lista.hpp"

	void lista:: inicia(){
		int i = 0;
		inicio = 0;//nullptr
		fim = 0;//nullptr
		mes *novo = new mes;
		inicio = novo;
		fim = novo;
		strcpy(fim->nome_mes, "janeiro");
		fim->pdia = new dia;
		for(i = 0; i<=31; i++){
			fim->pdia->pcomp[i]=0;
		}
		novo = new mes;
		fim->proximo = novo;
		fim = novo;
		strcpy(fim->nome_mes, "fevereiro");
		fim->pdia = new dia;
		for(i = 0; i<=31; i++){
			fim->pdia->pcomp[i]=0;
		}
		novo = new mes;
		fim->proximo = novo;
		fim = novo;
		strcpy(	fim->nome_mes, "marco");
		fim->pdia = new dia;
		for(i = 0; i<=31; i++){
			fim->pdia->pcomp[i]=0;
		}
		novo = new mes;
		fim->proximo = novo;
		fim = novo;
		strcpy(	fim->nome_mes, "abril");
		fim->pdia = new dia;
		for(i = 0; i<=31; i++){
			fim->pdia->pcomp[i]=0;
		}
		novo = new mes;
		fim->proximo = novo;
		fim = novo;
		strcpy(	fim->nome_mes, "maio");
		fim->pdia = new dia;
		for(i = 0; i<=31; i++){
			fim->pdia->pcomp[i]=0;
		}
		novo = new mes;
		fim->proximo = novo;
		fim = novo;
		strcpy(	fim->nome_mes, "junho");
		fim->pdia = new dia;
		for(i = 0; i<=31; i++){
			fim->pdia->pcomp[i]=0;
		}
		novo = new mes;
		fim->proximo = novo;
		fim = novo;
		strcpy(	fim->nome_mes, "julho");
		fim->pdia = new dia;
		for(i = 0; i<=31; i++){
			fim->pdia->pcomp[i]=0;
		}
		novo = new mes;
		fim->proximo = novo;
		fim = novo;
		strcpy(	fim->nome_mes, "agosto");
		fim->pdia = new dia;
		for(i = 0; i<=31; i++){
			fim->pdia->pcomp[i]=0;
		}
		novo = new mes;
		fim->proximo = novo;
		fim = novo;
		strcpy(	fim->nome_mes, "setembro");
		fim->pdia = new dia;
		for(i = 0; i<=31; i++){
			fim->pdia->pcomp[i]=0;
		}
		novo = new mes;
		fim->proximo = novo;
		fim = novo;
		strcpy(	fim->nome_mes, "outubro");
		fim->pdia = new dia;
		for(i = 0; i<=31; i++){
			fim->pdia->pcomp[i]=0;
		}
		novo = new mes;
		fim->proximo = novo;
		fim = novo;
		strcpy(	fim->nome_mes, "novembro");
		fim->pdia = new dia;
		for(i = 0; i<=31; i++){
			fim->pdia->pcomp[i]=0;
		}
		novo = new mes;
		fim->proximo = novo;
		fim = novo;
		strcpy(	fim->nome_mes, "dezembro");
		fim->pdia = new dia;
		for(i = 0; i<=31; i++){
			fim->pdia->pcomp[i]=0;
		}
		fim->proximo = 0;
	}
	void lista :: insere_compromisso(char Fmes[],int Fdia, float Fhora, char Fcompromisso[]){
		
		mes *marcador;
		compromisso *marcador2;
		compromisso *temporario;
		int i=0;
		marcador = inicio;
		while ((strcmp(Fmes, marcador->nome_mes) != 0)&&(i<=11)){
			if (i != 11){
			marcador=marcador->proximo;
		}
			i++;
		}
		if(i == 12){//digitou algum mes que não existe
			std :: cout << "mes invalido \n";
		}
		else if(Fdia>=32|| ( Fdia==31 && (i==3||i==5||i==8||i==10) ) || ( Fdia>28 && i==1 ) ){//condicoes dos dias para os meses
			std :: cout << "dia invalido \n";
		}
		else if(Fhora>=24){//dia so tem 24 hrs
			std :: cout<< "hora invalida \n";
		}
		else{//caso não haja nenhum problema como mes invalido, dia invaliido ou hora ivalida sera registrado o compromisso agora.
			if(marcador->pdia->pcomp[Fdia] == 0){//se o dia ainda não possui nenhum compromisso sera criado o primeiro
				marcador->pdia->pcomp[Fdia] = new compromisso;
				marcador->pdia->pcomp[Fdia]->hora = Fhora;
				strcpy(marcador->pdia->pcomp[Fdia]->comp, Fcompromisso);
				marcador->pdia->pcomp[Fdia]->proximo = 0;	
			}
			else{// se o dia ja possuir algum compromisso, sera registrado no fim da lista encadeada de compromissos.
				temporario = new compromisso;
				marcador2 = marcador->pdia->pcomp[Fdia];
				while(marcador2->proximo != 0){
					marcador2 = marcador2->proximo;
				}
				marcador2->proximo =  temporario;
				temporario->hora = Fhora;
				strcpy(temporario->comp, Fcompromisso);
				temporario->proximo = 0;
			}
		}
		
	}
	void lista :: remove_compromisso(char Fmes[],int Fdia, float Fhora){
		mes *marcador;
		compromisso *marcador2;
		compromisso *antecessor;
		marcador = inicio;
		while ((strcmp(Fmes, marcador->nome_mes) != 0) && (marcador != 0)){
			marcador=marcador->proximo;
			
		}
		if(marcador == 0){
			std::cout << "compromisso inexistente\n";
		}
		else{
			if(Fdia >=32 || marcador->pdia->pcomp[Fdia] == 0){
				std :: cout << "compromisso inexistente \n ";
			}
			else{
				marcador2 = marcador->pdia->pcomp[Fdia];
				antecessor = 0;
				while((Fhora != marcador2->hora)&&(marcador2 != 0)){
					antecessor = marcador2;
					marcador2 = marcador2->proximo;
					
				}
				if((marcador2 != 0)&&(antecessor!= 0 )){
					antecessor->proximo = marcador2->proximo;
					delete marcador2;
					std :: cout << "compromisso deletado\n";
				}
				else if((marcador2 != 0)&&(antecessor == 0 )){
					marcador->pdia->pcomp[Fdia] = 0;
				std ::cout << "compromisso deletado\n" ;
				}
				else{
				std :: cout << "compromisso inexistente\n";
				}
			}
		}
	}
	void lista :: lista_compromissos(){
		std::cout << "\n-----------------------------------------------------";
		std:: cout << "\nLista de compromissos :\n";
		mes *marcador;
		compromisso *marccomp;
		
		marcador = inicio;
		int i = 0;
	//	cout << marcador->nome_mes;
		while(marcador != 0){
			std :: cout<< marcador->nome_mes<< ": \n";
			for(i = 1; i<=31 ; i++){
				marccomp=marcador->pdia->pcomp[i];
				if(marccomp != 0){
					std::cout<< "	dia " << i << ": \n";
					while(marccomp != 0){
						std::cout<<"		" << marccomp->hora << "hrs: " << marccomp->comp << "\n";
						marccomp= marccomp->proximo;
					} 
				}
				
			}
			std::cout << "\n";
			marcador = marcador->proximo;
		}
	}
	void lista:: verifica_compromisso_agendado(char Fmes[], int Fdia, float Fhora){
		std :: cout<<"\n";
		int i=0;
		mes *marcador;
		compromisso *marcador2;
		compromisso *antecessor;
		marcador = inicio;
		while ((strcmp(Fmes, marcador->nome_mes) != 0) && (marcador != 0)){
			marcador=marcador->proximo;
			
		}
		if(marcador == 0){
			std::cout << "compromisso inexistente\n" ;
		}
		else{
			if(Fdia >=32){
				std :: cout << "compromisso inexistente\n" ;
			}
			else if(marcador->pdia->pcomp[Fdia] == 0){
				std :: cout << "compromisso inexistente\n" ;
			}
			else{
				marcador2 = marcador->pdia->pcomp[Fdia];
				while(marcador2 != 0){
					if(marcador2->hora == Fhora){
						i=1;
					}
					marcador2 = marcador2->proximo;
					
				}
				if(i==1){
					std :: cout << "Existe compromisso agendado nesse horario!\n" ;
				}
				else{
					std::cout << "compromisso inexistente\n";
				}
			}
		}
		
	}
	int lista::menu (){
		std::cout << "Digite :\n1 - para abrir a agenda e carregar dados ja salvos\n2 - para inserir compromisso\n";
		std::cout << "3 - para remover compromisso\n4 - para verificar se existe compromisso agendado\n";
		std::cout << "5 - para listar compromisso\n6 - para fechar agenda e salvar\n";
		int i = 0;
		std::cin >> i;
		while (i<1 || i>6){
			std::cout << "numero invalido, digite denovo!\n";
			std::cin >> i;
		}
		return i;
	}
	//Salva agenda em arquivo e libera a memoria dinamicamente alocada
	void lista ::salva_lista(){
		std::ofstream arquivo;
		arquivo.open("agenda.txt");
		mes *marcador, *auxm;
		compromisso *marccomp, *auxc;
		
		
		
		marcador = inicio;
		int i = 0;
	
		while(marcador != 0){
			arquivo<<"---";//sinalidador de mes no arquivo
			//arquivo<< marcador->nome_mes;
			//arquivo<< "";
			arquivo<< "\n";
			for(i = 1; i<=31 ; i++){
				marccomp=marcador->pdia->pcomp[i];
				if(marccomp != 0){
					arquivo<< "+++";//sinalidador de dia
					arquivo<< "\n";
					arquivo<< i;
					arquivo<< "\n";
					while(marccomp != 0){
						arquivo<<"###";//sinalizador de hora
						arquivo<<"\n";
						arquivo<< marccomp->hora ;
						arquivo<< "\n";
						arquivo<< marccomp->comp;
						arquivo<< "\n";
						auxc = marccomp;
						marccomp= marccomp->proximo;
						delete auxc;// deletando nodo de compromisso;
					} 
				}
				
			}
			delete marcador->pdia;//deletando nodo dias do mes
			auxm = marcador;
			marcador = marcador->proximo;
			delete auxm;// deletando o nodo de mes do mes
		}
		arquivo.close();
		
	}
	//carrega dados salvos anteriormente
	void lista :: abrir_agenda(){
		std::ifstream arquivo;
		mes *marcadorm;
		marcadorm = inicio;
		compromisso *marcadorc;
		char linha[60];
		std::string linhaaux;
		char aux1[3],aux2[3],aux3[3],aux4[3];
		strcpy(aux1,"---");
		strcpy(aux2,"+++");
		strcpy(aux3,"###");
		
		int j,i=0;
		int dia;
		float hora;
		arquivo.open("agenda.txt");
		if(arquivo.is_open()){
			while(getline(arquivo, linhaaux)){
				for (j = 0; j<=59 ;j++){
					linha[j]=linhaaux[j];
				}
				if( (i>0) && (strcmp(linha,aux1)==0) ){//for uma linha indicando mudança de mes
					marcadorm = marcadorm->proximo;
				}
				else if(strcmp(linha,aux2)==0){
					getline(arquivo, linhaaux);
					for (j = 0; j<=59 ;j++){
						linha[j]=linhaaux[j];
						
					}
					dia = atoi(linha);
					
				}
				else if(strcmp(linha,aux3)==0){
					getline(arquivo, linhaaux);
					for (j = 0; j<=59 ;j++){
						linha[j]=linhaaux[j];
						
					}
					hora = atof(linha);
					getline(arquivo, linhaaux);
					for (j = 0; j<=59 ;j++){
						linha[j]=linhaaux[j];
						
					}
					insere_compromisso(marcadorm->nome_mes, dia, hora, linha);
					
				}
				i=1;						
			}	
		}
	}

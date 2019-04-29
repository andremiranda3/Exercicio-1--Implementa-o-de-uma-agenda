#include <iostream>
#include "lista.hpp"
/*EXERCICIO 1 de PDS feito por:
 -Andre Martins Miranda 
 -Nicholas Sorice Baracho Fabriz
 */

int main(int argc, char** argv) {
	lista agenda;
	enum sequencia{UM=1,DOIS,TRES,QUATRO,CINCO,SEIS};
	char mes[10];
	int dia,i=1;
	float hora;
	char comp[50];
	agenda.inicia();
	while(i!=0){
		i = agenda.menu();
		switch (i){
			case UM:{
				agenda.abrir_agenda();
				break;
			}
			case DOIS:{
				std::cout << "digite o mes(use 'c' ao inves de c cedilha): ";
				fflush(stdin);
				//fgets(mes, 10, stdin);
				std::cin >> mes;
				std::cout << "digite o dia: ";
				fflush(stdin);
				std::cin >> dia;
				std::cout << "digite a hora: ";
				fflush(stdin);
				std::cin >> hora;
				std::cout << "digite o compromisso: ";
				fflush(stdin);
				fgets(comp, 50, stdin);				
				agenda.insere_compromisso(mes, dia, hora, comp);
				break;
			}
			case TRES:{
				std::cout << "digite o mes(use 'c' ao inves de c cedilha): ";
				fflush(stdin);
				std::cin >> mes;
				std::cout << "digite o dia: ";
				fflush(stdin);
				std::cin >> dia;
				std::cout << "digite a hora: ";
				fflush(stdin);
				std::cin >> hora;
				agenda.remove_compromisso(mes, dia, hora);
				break;
			}
			case QUATRO:{
				std::cout << "digite o mes(use 'c' ao inves de c cedilha): ";
				fflush(stdin);
				std::cin >> mes;
				std::cout << "digite o dia: ";
				fflush(stdin);
				std::cin >> dia;
				std::cout << "digite a hora: ";
				fflush(stdin);
				std::cin >> hora;
				agenda.verifica_compromisso_agendado(mes, dia, hora);
				break;
			}
			case CINCO:{
				agenda.lista_compromissos();
				break;
			}
			case SEIS:{
				agenda.salva_lista();
				i = 0;
				break;
			}
		}
	}
	return 0;
}

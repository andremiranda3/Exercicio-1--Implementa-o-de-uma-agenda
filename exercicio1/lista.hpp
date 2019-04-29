/*EXERCICIO 1 de PDS feito por:
 -Andre Martins Miranda 
 -Nicholas Sorice Baracho Fabriz
 */
struct compromisso{
	float hora;
	char comp[50];
	compromisso *proximo;	
};
struct dia{ //células da lista
 	compromisso *pcomp[32]; 	
};
struct mes{
	char nome_mes[15];
	dia *pdia;
	mes *proximo;		
};
struct lista{
	mes *inicio;
	mes *fim;
	void inicia();
	void insere_compromisso(char Fmes[],int Fdia, float Fhora, char Fcompromisso[]);
	void remove_compromisso(char Fmes[],int Fdia, float Fhora);
	void lista_compromissos();
	void verifica_compromisso_agendado(char Fmes[], int Fdia, float Fhora);
	int menu ();
	//salva a lista e libera as memorias alocadas dinamicamente
	void salva_lista();
	//carrega dados salvos anteriormente
	void abrir_agenda();
};

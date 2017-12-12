#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KANO0 3
#define KANO1 5
#define KANO2 4
#define KCUR0 1
#define KCUR1 4
#define KCUR2 2
#define KNUM0 6
#define KNUM1 8
#define KNUM2 4

typedef
	struct Aluno {
		char nome[256];
		int matricula;
		unsigned int idade;
	}
Aluno;

void mostrar(Aluno aluno) {
	printf("> %s: MAT %03d\n: %u anos;\n", aluno.nome, aluno.matricula, 
		aluno.idade);
}
		
void gravar(Aluno aluno) {
	FILE * arq;
	arq = fopen("registro.txt","a");
	fwrite(&(aluno.nome),256,1,arq);
	fwrite(&(aluno.matricula),sizeof(int),1,arq);
	fwrite(&(aluno.idade),sizeof(unsigned int),1,arq);
	
	fclose(arq);
}

int ler(FILE * arq, Aluno * paluno, int id) {
	fseek(arq,id*sizeof(Aluno), SEEK_SET);
	int ok = fread(&(paluno->nome),256,1,arq);
	fread(&(paluno->matricula),sizeof(int),1,arq);
	fread(&(paluno->idade),sizeof(unsigned int),1,arq);
	return ok;
}

void inicia() {
	remove("registro.txt");
	Aluno aluno;
	strncpy(aluno.nome,"Oswald",256);
	aluno.matricula = rand()%999 + 1;
	aluno.idade = rand()%11 + 17;
	gravar(aluno);
	strncpy(aluno.nome,"Leonardo", 256);
	aluno.matricula = 5;
	aluno.idade = 19;
	gravar(aluno);
    strncpy(aluno.nome,"Ermengardo", 256);
    aluno.matricula = 34;
    aluno.idade = 101;
    gravar(aluno);
    strncpy(aluno.nome,"Juriemo", 256);
    aluno.matricula = 75;
    aluno.idade = 12;
	gravar(aluno);
	strncpy(aluno.nome,"Silvia", 256);
	aluno.matricula = rand()%999 + 1;
	aluno.idade = rand()%15 + 17;
	gravar(aluno);
	strncpy(aluno.nome,"Mickey", 256);
	aluno.matricula = rand()%999 + 1;
	aluno.idade = rand()%9 + 17;
	gravar(aluno);
}

int main() {
    int ID0 = (KANO0+KANO1+KANO2)%9 + 1,
        ID1 = (KCUR0+KCUR1+KCUR2)%9 + 1,
        ID2 = (KNUM0+KNUM1+KNUM2)%9 + 1;
	srand(ID0*100+ID1*10+ID2);
	Aluno aluno;
	FILE * arq;
	int i;
	inicia();
	arq = fopen("registro.txt","r");
	i = 0;
	while(!feof(arq)) {
		if(ler(arq, &aluno, i))
			mostrar(aluno);
		i++;
	}
	fclose(arq);
	return EXIT_SUCCESS;
}
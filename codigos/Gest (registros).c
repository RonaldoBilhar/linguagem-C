#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<locale.h>

#define ARQ "Dados.Dat"		/*arquivos com os dados*/

#define OP_INSERIR		'1'
#define OP_ALTERAR		'2'
#define OP_APAGAR		'3'
#define OP_LISTAR		'4'
#define OP_PESQUISAR	'5'
#define OP_SAIR			'0'

#define OP_PESQ_IDADE	'1'
#define OP_PESQ_NOME	'2'

char *MainMenu[]={
	"1. Inserir Registro",
	"2. Alterar Registro",
	"3. Apagar Registro",
	"4. Listar Registros",
	"5. Pesquisas",
	"0. Sair",
	NULL		/* acabaram as opções*/
};

char *PesqMenu[]={
	"1. Pesquisar por Intervalo de Idades",
	"2. Pesquisar por Nome",
	"0. Voltar",
	NULL		/*acabaram as opções*/
};

FILE *fp;	/*variavel global pois é útil ao longo do programa*/

typedef struct{
	char Nome[30+1];
	int Idade;
	float Salario;
	char Status;	/*  '*' indica que o registro esta apagado*/
}PESSOA;

void Mensagem(char *msg);

		/* le os dados de um registro introduzidos pelo usuario */
void Ler_Pessoa(PESSOA *p){
	printf("\tNome	:"); gets(p->Nome);
	printf("\tIdade	:"); scanf("%d",&p->Idade);
	printf("\tSalário	:"); scanf("%f",&p->Salario);
	p->Status=' ';
	fflush(stdin);
}

		/*mostra na tela, os dados existentes no registro*/
void Mostrar_Pessoa(PESSOA p){
	printf("\tNome: %-30s Idade: %3d   Salário: %10.2f\n",p.Nome,p.Idade,p.Salario);
}

		/*adiciona uma pessoa ao arquivo*/
void Adicionar_Pessoa(PESSOA p){
	fseek(fp, 0L, SEEK_END);
	if(fwrite(&p,sizeof(p),1,fp)!=1)
		Mensagem("Adicionar Pessoa: Falhou a escrita do Registro");
}

		/*coloca uma mensagem na tela*/
void Mensagem(char *msg){
	printf(msg);
	getchar();
}

		/* verifica se o arquivo já existe. se não existir, ele é criado
			se já existir, abre-o em modo de leitura e escrita ( r+b )*/
void Inic(){
	fp=fopen(ARQ,"r+b"); /*tentar abrir*/
	if(fp==NULL){
		fp=fopen(ARQ,"w+b"); /*criar arquivo*/
		if(fp==NULL){
			fprintf(stderr,"ERRO FATAL: Impossível Criar Arquivo de Dados\n");
			exit(1);
		}
	}
}

		/* faz um menu simples com as opções do vetor de strings. seleciona a 
			opção, usando o primeiro caractere de cada string. devolve
				 o primeiro caractere da opção*/
char Menu(char *Opcoes[]){
	int i;
	char ch;
	
	while(1){	/* Cls */
		printf("\n\n\n\n");
			for(i=0;Opcoes[i]!=NULL;i++)
				printf("\t\t%s\n\n",Opcoes[i]);
			
			printf("\n\t\t\tOpcão: ");
			ch=getchar(); fflush(stdin);
			for(i=0;Opcoes[i]!=NULL;i++)
				if(Opcoes[i][0]==ch)
					return ch;
	}
}

void Inserir_Pessoa(){
	PESSOA x;
	Ler_Pessoa(&x);
	Adicionar_Pessoa(x);
}

void Alterar_Pessoa(){
	PESSOA x;
	long int n_reg;
	printf("Qual o número do registro: ");
	scanf("%ld",&n_reg); fflush(stdin);
	if(fseek(fp,(n_reg-1)*sizeof(PESSOA),SEEK_SET)!=0){
		Mensagem("Registro Inexistente ou Problema no posicionamento!!!");
		return;
	}	
	if(fread(&x,sizeof(PESSOA),1,fp)!=1){
		Mensagem("Problema na leitura do Registro!!!");
		return;
	}
	if(x.Status=='*'){
		Mensagem("Um Registro Apagado não Pode ser Alterado!!!\n\n");
		return;
	}
	
	printf("\n\nDados Atuais\n\n");
	Mostrar_Pessoa(x);
	printf("\n\nNovos Dados\n\n");
	Ler_Pessoa(&x);
	
	// Recuar um Registro no arquivo
	fseek(fp,-(long)sizeof(PESSOA),SEEK_CUR);
	// Reescrever o Registro;
	fwrite(&x,sizeof(PESSOA),1,fp);
	fflush(fp); /* despejar os dados no disco rígido*/
}

void Apagar_Pessoa(){
	PESSOA x;
	long int n_reg;
	char resp;
	
	printf("Qual o número do registro: ");
	scanf("%ld", &n_reg); fflush(stdin);
	if(fseek(fp,(n_reg-1)*sizeof(PESSOA),SEEK_SET)!=0){
		Mensagem("Registro Inexistente ou Problemas de posicionamento!!!");
		return;
	}
	if(fread(&x,sizeof(PESSOA),1,fp)!=1){
		Mensagem("Problema na Leituta do Registro!!!");
		return;
	}
	if(x.Status=='*'){
		Mensagem("Registro já está Apagado!!!");
		return;
	}
	printf("\n\nDados Atuais\n\n");
	Mostrar_Pessoa(x);
	printf("\n\nApagar o Registro (s/n)???");
		resp=getchar();
	fflush(stdin);
	if(toupper(resp)!='S')
		return;
		
	x.Status='*';
	//recuar um registro no arquivo
	fseek(fp,-(long)sizeof(PESSOA),SEEK_CUR);
	//reescrever o registro
	fwrite(&x,sizeof(PESSOA),1,fp);
	fflush(fp);  //despejar os dados no disco rígido
}

void Listar(){
	long int N_Linhas=0;
	PESSOA reg;
	rewind(fp);
	while(1){
		if(fread(&reg,sizeof(reg),1,fp)!=1)
			break; //sair do laço
		if(reg.Status=='*')
			continue; //passa ao próximo
		Mostrar_Pessoa(reg);
		N_Linhas++;
		if(N_Linhas%20==0)
			Mensagem("Pressione <ENTER> para continuar . . .");
	}
	Mensagem("\n\nPressione <ENTER> para continuar . . ."); //no fim da listagem
}

void Pesquisar_Idades(int ini, int fim){
	PESSOA reg;
	rewind(fp);
	while(fread(&reg,sizeof(PESSOA),1,fp))
		if(reg.Status!='*' && reg.Idade>=ini && reg.Idade<=fim)
			Mostrar_Pessoa(reg);
	Mensagem("\n\nPressione <ENTER> para continuar . . ."); //no fim da listagem
}

void Pesquisar_Nome(char *s){
	PESSOA reg;
	rewind(fp);
	
	while(fread(&reg,sizeof(PESSOA),1,fp))
		if(reg.Status!='*' && strstr(reg.Nome,s))
			Mostrar_Pessoa(reg);
	Mensagem("\n\nPressione <ENTER> para continuar . . ."); //no fim da listagem
}

main(){
	setlocale(LC_ALL,"Portuguese");
	char Opcao;
	Inic();
	while((Opcao=Menu(MainMenu))!=OP_SAIR)
		switch(Opcao){
			case OP_INSERIR: Inserir_Pessoa(); break;
			case OP_ALTERAR: Alterar_Pessoa(); break;
			case OP_APAGAR : Apagar_Pessoa();  break;
			case OP_LISTAR : Listar();  	   break;
			case OP_PESQUISAR:
				while((Opcao=Menu(PesqMenu))!=OP_SAIR)
					switch(Opcao){
						case OP_PESQ_IDADE:{
							int n1,n2;
							printf("Qual o intervalo de idade: ");
								scanf("%d%d",&n1,&n2); fflush(stdin);
								Pesquisar_Idades(n1,n2);
							break;
						}
						case OP_PESQ_NOME:{
							char string[BUFSIZ+1];
							printf("Qual o Nome a Procurar: ");
								gets(string); fflush(stdin);
							Pesquisar_Nome(string);
						}
					}
		}
}

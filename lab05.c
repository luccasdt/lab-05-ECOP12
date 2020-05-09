// Luccas Delgado Targa - 2019011503
// Professor, infelizmente meu código não está rodando perfeitamente.
// Nos teste que eu fiz aqui, estava dando o seguinte erro " Dumping stack trace to lab05.exe.stackdump"
// Mesmo procurando esse erro na internet não consegui resolver, e pelo
// horário decidi entregar dessa forma

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM_PRODUTO 50
#define TAM_CODIGO 10

//Booleano para ANSI C
typedef enum {false, true} bool;

//Estrutura
typedef struct no
{
  char produto[TAM_PRODUTO];
  char codigo[TAM_CODIGO];
  int quantidade;
  struct no *prox;
  struct no *ant;
} noProduto;

//Itens iniciais e finais da lista
noProduto* prim = NULL;
noProduto* ult = NULL;


//funções a serem implementadas
bool insereProduto(noProduto *novo){
  //alocando memória para um novo produto
  noProduto *novoProduto = (noProduto *) malloc(sizeof(noProduto));
  noProduto *ant = NULL;
  noProduto *atual = prim;

  //encontra a posição de inserção e quem é seu anterior
  while((atual!=NULL)&&(strcmp(atual->produto, novo->produto) < 0)){
    ant = atual;
    atual = atual->prox;
  }//fim while

  if(strcmp(atual->codigo, novo->codigo) == 0){
    return false;
  }

  //conferindo para ver se é a primeira posição
  if(ant == NULL){
    prim = novoProduto;
  }else{//se estiver inserindo em outra posição
    ant->prox = novoProduto;
  }//fim if

  //atualizando valores para o novo nó
  strcpy(novoProduto->produto, novo->produto);
  strcpy(novoProduto->codigo, novo->codigo);
  novoProduto->quantidade = novo->quantidade;

  return true;
}//fim insereProduto

void inserirLista(){

//professor, fiquei com dúvida sobre a funcionalidade dessa função
//mesmo lendo a sua resposta no fórum da sala. Mesmo assim fiz essa
//função com a função que inicializa a lista de produtos passado


    int i;
    noProduto *novo;

    char listaCodigos[40][TAM_CODIGO] = {
      "22752", "21730", "22633", "22632", "84879", "22745", "22748", "22749", "22310", "84969",
      "22623", "22622", "21754", "21755", "21777", "48187", "22960", "22913", "22912", "22914",
      "21756", "22728", "22727", "22726", "21724", "21883", "10002", "21791", "21035", "22326",
      "22626", "22659", "22631", "22661", "21731", "22900", "21913", "22540", "22544", "22492",
    };
    char listaProdutos[40][TAM_PRODUTO] = {
      "SET 7 BABUSHKA NESTING BOXES", "GLASS STAR FROSTED T-LIGHT HOLDER",
      "HAND WARMER UNION JACK", "HAND WARMER RED POLKA DOT", "ASSORTED COLOUR BIRD ORNAMNET",
      "POPPOYS PLAYHOUSE BEDROOM", "POPPYS PLAYHOUSE KITCHEN", "FELTCRAFT PRINCESS CHARLOTTE DOLL",
      "IVORY KNITTER MUG COSY", "BOX OF 6 ASSORTED COLOUR TEASPOONS",
      "BOX OF VINTAGE JIGSAW BLOCKS", "BOX OF VINTAGE ALPHABET BLOKS",
      "HOME BUILDING BLOCK WORD", "LOVE BUILDING BLOCK WORD", "RECIPE BOX WITH METAL HEART",
      "DOORMA NEW ENGLAND", "JAM MAKING SET WITH JARS",
      "RED COAT RACK PARIS FASHION", "YELLOW COAT RACK PARIS FASHION",
      "BLUE COAT RACK PARIS FASHION", "BATH BUILDING BLOCK WORD",
      "ALARM CLOCK BAKELIKE PINK", "ALARM CLOCK BAKELIKE RED", "ALARM CLOCK BAKELIKE GREEN",
      "PANDA AND BUNNIES STICKER SHEET", "STARS GIFT TAPE", "INFLATABLE POLITICAL GLOBE",
      "VINTAGE HEADS AND TAILS CARD GAME", "SET/2 RED RETROSPOT TEA TOWELS",
      "ROUND SNACK BOXES SET OF 4 WOODLAND", "SPACEBOY LUNCH BOX", "LUNCH BOX I LOVE LONDON",
      "CIRCUS PARADE LUNCH BOX", "CHARLOTTE BAG DOLLY GIRL DESIGN", "RED TOADSTOOL LED NIGHT LIGHT",
      "SET 2 TEA TOWELS I LOVE LONDON", "VINTGE SEASIDE JIGSAW PUZZLES",
      "MIN JIGSAW CIRCUS PARADE", "MINI JIGSAW SPACEBOY", "MINI PAINT SET VINTAGE"
    };
    int listaQuantidade[40] = {
      2,6,6,6,32,6,6,8,6,6,
      3,2,3,3,4,4,6,3,3,3,3,
      24,24,12,12,24,48,24,18,24,24,
      24,24,20,24,24,12,24,24,36
    };

    for(i=0;i<40;i++){
      novo = (noProduto *) malloc(sizeof(noProduto));
      novo->ant = NULL;
      novo->prox = NULL;

      strcpy(novo->produto, listaProdutos[i]);
      strcpy(novo->codigo, listaCodigos[i]);
      novo->quantidade = listaQuantidade[i];

      insereProduto(novo);
      free(novo);
    }
}
void imprimeUp(){
  noProduto* atual = prim;
  while(atual != NULL){
    printf("%s\n", atual->produto);
    atual = atual->prox;
  }
}//fim imprimeUp
void imprimeDown(){
  noProduto* atual = ult;
  while(atual != NULL){
    printf("%s\n", atual->produto);
    atual = atual->ant;
  }
}//fim imprimeDown
void removeProduto(char produto[]){
  noProduto *atual, *anterior;
  atual = prim;
  anterior = prim;

  while((atual != NULL)&&(strcmp(atual->codigo, produto) != 0)){
    anterior = atual;
    atual = atual->prox;
  }
  if(atual!=NULL){
    printf("---Removendo produto %s...\n", atual->produto);
    if(atual == prim){
      //remoção do primiro elemento
      prim = prim->prox;
    }else{
      //remoçaõ dos outros elementos
      anterior->prox = atual->prox;
    }
    free(atual);
    return true;
  }else{
    return false;
  }
}//fim removeProduto

//rotina principal
int main()
{
  //Para inserir um novo
  noProduto *novo;
  //Para localizar o produto
  char codigo[TAM_CODIGO];
  //Insere produtos da guia na lista
  inserirLista();
  //Opções do menu
  int opcao = 0;
  while(opcao != 5)
  {
    //Gerando menu
    printf("\n> Digite uma das opcoes abaixo: \n");
    printf(">> 1 para inserir um produto\n");
    printf(">> 2 para remover um produto\n");
    printf(">> 3 para imprimir crescente\n");
    printf(">> 4 para imprimir decrescente\n");
    printf(">> 5 para sair\n");
    printf(">> ");
    scanf("%d", &opcao);
    getchar();
    switch(opcao)
    {
      case 1: //Inserindo novo produto
        printf(">> Inserção de no contato: \n");
        novo = (noProduto *) malloc(sizeof(noProduto));
        novo->ant = NULL;
        novo->prox = NULL;
        printf(">>> Produto: ");
        scanf("%[^\n]s", (novo->produto));
        setbuf(stdin, NULL);
        printf(">>> Código: ");
        scanf("%s", (novo->codigo));
        setbuf(stdin, NULL);
        printf(">>> Quantidade: ");
        scanf("%i", (&novo->quantidade));
        bool inserido = insereProduto(novo);
        if(!inserido)
          printf(">>>> Produto já existente!!\n");
          else
          printf(">>>> Produto adicionado com sucesso!!\n");
        getchar();
      break;

      case 2: //Removendo produto pelo código
        printf(">> Remocao de um produto: \n");
        printf(">>> Codigo: \n");
        scanf("%s", codigo);
        removeProduto(codigo);
        getchar();
      break;
      case 3: //Imprimindo todos os produtos em ordem crescente
        printf(">> Produtos Crescente:\n");
        imprimeUp();
        getchar();
      break;
      case 4: //Imprimindo todos os produtos em ordem decrescente
        printf(">> Produtos Decrescente:\n");
        imprimeDown();
        getchar();
      break;
      case 5: //Sair
        printf(">> Saindo do programa…\n");
        getchar();
      break;
      default: //opção invalida escolhida pelo usuario
        printf(">> Opção inválida; %c\n", opcao);
      break;
    }
    //Limpa a tela
    system("cls");
  }
  return 0;
}

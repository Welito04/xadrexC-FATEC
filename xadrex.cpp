//Jose Roberto Alves de Lima Julior RA:1840482212044
//Welito Tixeira do Nascimento RA: 1840482212033

#include <cstdlib>
#include <iostream>         //Biblioteca que são usadas para entrada e saída de dados
#include <string>
#include <stdlib.h>

std::string tabuleiro[9][9] {            //Linha que declara uma matriz de caracteres chamada "tabuleiro" com 9 linhas e 9 colunas

    " ",      "1",      "2",      "3",      "4",      "5",      "6",
    "7",      "8",      "1",      "\u265C", "\u265E", "\u265D", "\u265B",
    "\u265A", "\u265D", "\u265E", "\u265C", "2",      "\u265F", "\u265F",
    "\u265F", "\u265F", "\u265F", "\u265F", "\u265F", "\u265F", "3",
    " ",      " ",      " ",      " ",      " ",      " ",      " ",
    " ",      "4",      " ",      " ",      " ",      " ",      " ",                //Inicializa a matriz acima com caracteres que representam as peças e espaços vazios no tabuleiro de xadrez
    " ",      " ",      " ",      "5",      " ",      " ",      " ",
    " ",      " ",      " ",      " ",      " ",      "6",      " ",
    " ",      " ",      " ",      " ",      " ",      " ",      " ",
    "7",      "\u2659", "\u2659", "\u2659", "\u2659", "\u2659", "\u2659",
    "\u2659", "\u2659", "8",      "\u2656", "\u2658", "\u2657", "\u2655",
    "\u2654", "\u2657", "\u2658", "\u2656",
};

void limparTabuleiro() {            //Linha declara uma função chamada "limparTabuleiro"
  for (int linha = 0; linha < 9; linha++) {
    for (int coluna = 0; coluna < 9; coluna++) {
      if (tabuleiro[linha][coluna] == "X") {            //Este bloco de código dentro da função acima percorre a matriz "tabuleiro" e substitui todos os caracteres 'X' por um espaço em branco ' '
        tabuleiro[linha][coluna] = " ";
      }
    }
  }
}

void colocarTabuleiro() {           //Linha que declara uma função chamada "colocarTabuleiro"
system("clear");
    
  for (int linha = 0; linha < 9; linha++) {
    std::cout << std::endl;
    for (int coluna = 0; coluna < 9; coluna++) {
      std::cout << tabuleiro[linha][coluna];
      if (linha == 0) {             //Este bloco de código dentro da função acima percorre a matriz "tabuleiro" e imprime na tela o caractere em cada posição
        std::cout << "   ";
      } else {
        std::cout << " | ";
      }
    }
  }

  std::cout << std::endl;           //Serve para adicionar uma nova linha na saída do console
}

void validarPosicao(int linhaPeca, int colunaPeca) {            //Declaração de uma função chamada "validarPosicao" que recebe duas variáveis inteiras chamadas "linhaPeca" e "colunaPeca"

  int destinoLinha;             //Declaração de variáveis inteiras "destinoLinha"
  int destinoColuna;            //Declaração de variáveis inteiras "destinoColuna" 
  std::string letra = tabuleiro[linhaPeca][colunaPeca];            //Declaração de variável string "letra", que armazena o caractere da posição do tabuleiro correspondente às coordenadas da peça que se deseja movimentar
  int i = 0;            //A variável "i" é inicializada com zero e será utilizada para controlar o loop do-while que será executado a seguir

  do {          //Início do loop do-while que será executado pelo menos uma vez, para receber as coordenadas da posição para a qual a peça deve ser movida

    if (i > 0) {
      std::cout << "Movimento Invalido, escolha uma casa X.";           //Se o valor de "i" for maior que zero, significa que o usuário já tentou realizar um movimento inválido anteriormente.
      std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Digite a linha destino: ";            
    std::cin >> destinoLinha;
                                                    //Nesse bloco de código a função solicita que o usuário informe a linha e a coluna de destino da peça, lendo esses valores a partir do console usando "std::cin"
    std::cout << "Digite a coluna destino: ";
    std::cin >> destinoColuna;

    i++;            //Nessa parte de ler as coordenadas de destino, a variável "i" é incrementada em 1
      
  } while (tabuleiro[destinoLinha][destinoColuna] != "X");          //Aqui o loop do-while continuará sendo executado enquanto a posição de destino para a qual a peça deve ser movida não conter o caractere 'X' no tabuleiro.

  if (tabuleiro[destinoLinha][destinoColuna] == "X") {
    tabuleiro[destinoLinha][destinoColuna] = letra;             ////Nesse bloco de codigo se a posição de destino para a qual a peça deve ser movida contiver o caractere 'X' no tabuleiro, significa que o movimento é válido
    tabuleiro[linhaPeca][colunaPeca] = " ";
    limparTabuleiro();              //Aqui a função "liparTabuleiro" é chamada para limpar o tabuleiro antes de iniciar a proxima jogada
  }
}

void movimentarBispo(int linhaPeca, int colunaPeca) {           //Declaração da função "movimentarBispo" com dois argumentos dentro dela: a linha e coluna da peça que representa o bispo

  int i = 1;            //Declaração e inicialização da variável "i" com 1, que será usada para percorrer as diagonais

  while (tabuleiro[linhaPeca + i][colunaPeca + i] == " ") {
    tabuleiro[linhaPeca + i][colunaPeca + i] = "X";             //Aqui a peça é movida para a proxima casa na inferior a direita e o contador "i" é incrementado para continuar a busca pela diagonal
    i++;
  }

  i = 1;            //Reinicia o contador "i" para 1

  while (tabuleiro[linhaPeca - i][colunaPeca + i] == " ") {
    tabuleiro[linhaPeca - i][colunaPeca + i] = "X";             //Aqui a peça percorre a diagonal inferior esquerda, movendo-se para cada casa vazia até encontrar uma peça ou chegar ao limite do tabuleiro
    i++;
  }

  i = 1;            //Reinicia o contador "i" para 1

  while (tabuleiro[linhaPeca - i][colunaPeca - i] == " ") {
    tabuleiro[linhaPeca - i][colunaPeca - i] = "X";             //Aqui a peça percorre a diagonal superior esquerda, movendo-se para cada casa vazia até encontrar uma peça ou chegar ao limite do tabuleiro
    i++;
  }

  i = 1;            //Reinicia o contador "i" para 1

  while (tabuleiro[linhaPeca + i][colunaPeca - i] == " ") {
    tabuleiro[linhaPeca + i][colunaPeca - i] = "X";             ////Aqui a peça percorre a diagonal superior direita, movendo-se para cada casa vazia até encontrar uma peça ou chegar ao limite do tabuleiro
    i++;
  }
}

void movimentarTorre(int linhaPeca, int colunaPeca) {           //Definição da função "movimentarTorre" que recebe como parâmetros a linha e coluna da torre que será movimentada

  int contador = 1;             //Declaração e inicialização da variável contador com o valor 1, que é para controlar a quantidade de casas a serem percorridas em cada direção

  while (tabuleiro[linhaPeca + contador][colunaPeca] == " ") {              //Início de um laço de repetição que irá percorrer todas as casas acima da torre até encontrar um obstáculo
    tabuleiro[linhaPeca + contador][colunaPeca] = "X";              //Quando uma casa é percorrida ela é marcada com um X no tabuleiro
    contador++;             //A variável "contador" é incrementada para que a próxima casa seja verificada na próxima iteração do laço
  }

  contador = 1;             //A variável "contador" é reinicializada para o valor 1

  while (tabuleiro[linhaPeca - contador][colunaPeca] == " ") {              //Início de um laço de repetição que irá percorrer todas as casas abaixo da torre até encontrar um obstáculo
    tabuleiro[linhaPeca - contador][colunaPeca] = "X";              //Quando uma casa é percorrida ela é marcada com um X no tabuleiro
    contador++;             //A variável "contador" é incrementada para que a próxima casa seja verificada na próxima iteração do laço
  }

  contador = 1;             //A variável contador é reinicializada para o valor 1

  while (tabuleiro[linhaPeca][colunaPeca - contador] == " ") {              //Início de um laço de repetição que irá percorrer todas as casas à esquerda da torre até encontrar um obstáculo
    tabuleiro[linhaPeca][colunaPeca - contador] = "X";              //Quando uma casa é percorrida ela é marcada com um X no tabuleiro
    contador++;             //A variável "contador" é incrementada para que a próxima casa seja verificada na próxima iteração do laço
  }

  contador = 1;             //A variável contador é reinicializada para o valor 1

  while (tabuleiro[linhaPeca][colunaPeca + contador] == " ") {              //Início de um laço de repetição que irá percorrer todas as casas à direita da torre até encontrar um obstáculo
    tabuleiro[linhaPeca][colunaPeca + contador] = "X";              //Quando uma casa é percorrida ela é marcada com um X no tabuleiro
    contador++;             //A variável "contador" é incrementada para que a próxima casa seja verificada na próxima iteração do laço
  }
}

void movimentarCavalo(int linhaPeca, int colunaPeca) {              //Esta linha define a função movimentarCavalo com dois argumentos, a linha e a coluna da posição atual da peça

  if (tabuleiro[linhaPeca + 2][colunaPeca + 1] == " ") {            //Verifica se há uma posição vazia dois espaços abaixo e um espaço à direita da posição atual da peça
    tabuleiro[linhaPeca + 2][colunaPeca + 1] = "X";             //Se a condição acima for verdadeira, coloca um 'X' nessa posição no tabuleiro para indicar que a peça pode se mover para essa posição
  }

  if (tabuleiro[linhaPeca + 2][colunaPeca - 1] == " ") {            //Verifica se há uma posição vazia dois espaços abaixo e um espaço à esquerda da posição atual da peça
    tabuleiro[linhaPeca + 2][colunaPeca - 1] = "X";             //Se a condição acima for verdadeira, coloca um 'X' nessa posição no tabuleiro para indicar que a peça pode se mover para essa posição
  }

  if (tabuleiro[linhaPeca - 2][colunaPeca + 1] == " ") {            //Verifica se há uma posição vazia dois espaços acima e um espaço à direita da posição atual da peça
    tabuleiro[linhaPeca - 2][colunaPeca + 1] = "X";             //Se a condição acima for verdadeira, coloca um 'X' nessa posição no tabuleiro para indicar que a peça pode se mover para essa posição
  }

  if (tabuleiro[linhaPeca - 2][colunaPeca - 1] == " ") {            //Verifica se há uma posição vazia dois espaços acima e um espaço à esquerda da posição atual da peça
    tabuleiro[linhaPeca - 2][colunaPeca - 1] = "X";             //Se a condição acima for verdadeira, coloca um 'X' nessa posição no tabuleiro para indicar que a peça pode se mover para essa posição
  }
}

void movimentarRei(int linhaPeca, int colunaPeca) {             //Declaração da função "movimentoRei" com dois parâmetros: a linha e a coluna da peça do tipo Rei no tabuleiro

  int i = -1;           //Inicializa a variável 'i' com o valor -1, essa variável é usada para iterar pelas posições em torno do Rei no tabuleiro

  while (i < 2) {           //Inicio do loop while que será executado duas vezes: quando "i" é -1 e quando "i" é 0
    if (tabuleiro[linhaPeca + 1][colunaPeca + i] == " ")            //Verifica se a casa imediatamente abaixo ou diagonalmente da direita do Rei está vazia
      tabuleiro[linhaPeca + 1][colunaPeca + i] = "X";           //Se a casa estiver vazia, a posição é marcada no tabuleiro com um "X", indicando que o Rei pode se mover para lá
    i++;            //Incrementa a variável "i" para que o loop possa verificar a próxima posição em torno do Rei
  }

  i = -1;           //Redefine "i" como -1 para prepará-lo para o próximo loop

  while (i < 2) {           //Início do segundo loop while que também será executado duas vezes: quando "i" é -1 e quando "i" é 0
    if (tabuleiro[linhaPeca - 1][colunaPeca + i] == " ")            //Verifica se a casa imediatamente acima ou diagonalmente da direita do Rei está vazia
      tabuleiro[linhaPeca - 1][colunaPeca + i] = "X";           //Se a casa estiver vazia, a posição é marcada no tabuleiro com um "X", indicando que o Rei pode se mover para lá
    i++;            //Incrementa a variável "i" para que o loop possa verificar a próxima posição em torno do Rei
  }

  if (tabuleiro[linhaPeca][colunaPeca + 1] == " ")              //Verifica se a casa imediatamente à direita do Rei está vazia
    tabuleiro[linhaPeca][colunaPeca + 1] = "X";             //Se a casa estiver vazia, marca essa posição no tabuleiro com um "X", indicando que o Rei pode se mover para lá

  if (tabuleiro[linhaPeca][colunaPeca - 1] == " ")              //Verifica se a casa imediatamente à esquerda do Rei está vazia
    tabuleiro[linhaPeca][colunaPeca - 1] = "X";             //Se a casa estiver vazia, marca essa posição no tabuleiro com um "X", indicando que o Rei pode se mover para lá
}

// PEÇAS BRANCAS

void movimentarReiBranco(int linhaPeca, int colunaPeca) {           //Declaração da função "movimentarReiBranco" que recebe dois argumentos inteiros linhaPeca e colunaPeca

  movimentarRei(linhaPeca, colunaPeca);             //Chama a função movimentarRei passando linhaPeca e colunaPeca como argumentos

  colocarTabuleiro();           //Chama a função colocarTabuleiro que provavelmente atualiza a exibição do tabuleiro após a movimentação

  validarPosicao(linhaPeca, colunaPeca);            //Chama a função validarPosicao que provavelmente verifica se a posição da peça é válida após a movimentação
}

void movimentarCavaloBranco(int linhaPeca, int colunaPeca) {            //Declaração da função "movimentarCavaloBranco" que recebe dois argumentos inteiros linhaPeca e colunaPeca

  movimentarCavalo(linhaPeca, colunaPeca);          //Chama a função movimentarCavalo passando linhaPeca e colunaPeca como argumentos

  colocarTabuleiro();           //Chama a função colocarTabuleiro que provavelmente atualiza a exibição do tabuleiro após a movimentação

  validarPosicao(linhaPeca, colunaPeca);            //Chama a função validarPosicao que provavelmente verifica se a posição da peça é válida após a movimentação
}

void movimentarBispoBranco(int linhaPeca, int colunaPeca) {             //Declaração da função "movimentarBispoBranco" que recebe dois argumentos inteiros linhaPeca e colunaPeca

  movimentarBispo(linhaPeca, colunaPeca);           //Chama a função movimentarBispo passando linhaPeca e colunaPeca como argumentos

  colocarTabuleiro();           //Chama a função colocarTabuleiro que provavelmente atualiza a exibição do tabuleiro após a movimentação

  validarPosicao(linhaPeca, colunaPeca);            //Chama a função validarPosicao que provavelmente verifica se a posição da peça é válida após a movimentação
}

void movimentarPeaoBranco(int linhaPeca, int colunaPeca) {              //Declaração da função "movimentarPeaoBranco" que recebe a linha e a coluna da peça como parâmetros

  std::string linhaInicial = "7";              //Declaração de uma variável string "linhaInicial" com o valor "7"

  if (*tabuleiro[linhaPeca] == linhaInicial &&
      tabuleiro[linhaPeca - 1][colunaPeca] == " " &&            //Verifica se a linha da peça é igual à "linhaInicial" e se as duas casas à frente da peça estão vazias
      tabuleiro[linhaPeca - 2][colunaPeca] == " ") {
      
    tabuleiro[linhaPeca - 1][colunaPeca] = "X";             //Se essas condições não forem verdadeiras, marca as duas casas à frente da peça com "X", indicando que a peça pode se mover para essas casas
    tabuleiro[linhaPeca - 2][colunaPeca] = "X";
      
  } else if (tabuleiro[linhaPeca - 1][colunaPeca] == " ") {             //Se a condição acima não for verdadeira, verifica se a casa imediatamente à frente da peça está vazia
   
    tabuleiro[linhaPeca - 1][colunaPeca] = "X";             //Se a casa imediatamente à frente da peça estiver vazia marca essa casa com "X", indicando que a peça pode se mover para essa casa

  } else {
    std::cout << "Movimento invalido.";             //Se a casa imediatamente à frente da peça estiver ocupada e as duas casas à frente da peça também estiverem ocupadas, imprime a mensagem "Movimento invalido" e retorna da função
    std::cout << std::endl;
    return;
  }

  colocarTabuleiro();           //Atualiza o tabuleiro com as marcações "X"

  std::cout << std::endl;           //Imprime uma linha em branco

  validarPosicao(linhaPeca, colunaPeca);            //Verifica se a posição atual da peça é válida
}

void movimentarTorreBranca(int linhaPeca, int colunaPeca) {             //Declaração da função "movimentarTorreBranca" que recebe a linha e coluna da peça como parâmetro

  movimentarTorre(linhaPeca, colunaPeca);           //Chama a função movimentarTorre passando as mesmas coordenadas da torre branca para realizar o movimento da torre

  colocarTabuleiro();           //A função colocarTabuleiro é chamada para atualizar o tabuleiro após o movimento

  validarPosicao(linhaPeca, colunaPeca);            //A função validarPosicao é chamada para verificar se a posição final da torre é válida
}

void movimentarRainhaBranca(int linhaPeca, int colunaPeca) {            //Declaração da função "movimentarRainhaBranca" que recebe a linha e coluna da peça como parâmetro

  movimentarBispo(linhaPeca, colunaPeca);           //A função movimentarBispo é chamada passando as mesmas coordenadas da rainha branca para realizar o movimento do bispo
  movimentarTorre(linhaPeca, colunaPeca);           //A função movimentarTorre é chamada passando as mesmas coordenadas da rainha branca para realizar o movimento da torre

  colocarTabuleiro();           //A função colocarTabuleiro é chamada para atualizar o tabuleiro após o movimento

  validarPosicao(linhaPeca, colunaPeca);            //A função validarPosicao é chamada para verificar se a posição final da rainha é válida
}

// PEÇAS PRETAS

void movimentarReiPreto(int linhaPeca, int colunaPeca) {            //Declaração da função "movimentarReiPreto" que recebe como parâmetros linhaPeca e colunaPeca

  movimentarRei(linhaPeca, colunaPeca);             //Chama a função movimentarRei que passa como parâmetros linhaPeca e colunaPeca

  colocarTabuleiro();           //Chama a função colocarTabuleiro que imprime o estado atual do tabuleiro

  validarPosicao(linhaPeca, colunaPeca);            //Chama a função validarPosicao que passa como parâmetros linhaPeca e colunaPeca
}

void movimentarRainhaPreta(int linhaPeca, int colunaPeca) {             //Declaração da função "movimentarRainhaPreta" que recebe como parâmetros linhaPeca e colunaPeca

  movimentarBispo(linhaPeca, colunaPeca);           //Chama a função movimentarBispo que passa como parâmetros linhaPeca e colunaPeca
  movimentarTorre(linhaPeca, colunaPeca);           //Chama a função movimentarTorre que passa como parâmetros linhaPeca e colunaPeca

  colocarTabuleiro();           //Chama a função colocarTabuleiro que imprime o estado atual do tabuleiro

  validarPosicao(linhaPeca, colunaPeca);            //Chama a função validarPosicao que passa como parâmetros linhaPeca e colunaPeca
}

void movimentarBispoPreto(int linhaPeca, int colunaPeca) {              //Declaração da função "movimentarBispoPreto" que recebe como parâmetros linhaPeca e colunaPeca

  movimentarBispo(linhaPeca, colunaPeca);           //Chama a função movimentarBispo que passa como parâmetros linhaPeca e colunaPeca

  colocarTabuleiro();           //Chama a função colocarTabuleiro que imprime o estado atual do tabuleiro

  validarPosicao(linhaPeca, colunaPeca);            //Chama a função validarPosicao que passa como parâmetros linhaPeca e colunaPeca
}

void movimentarCavaloPreto(int linhaPeca, int colunaPeca) {             //Declaração da função "movimentarCavaloPreto" que recebe como parâmetros linhaPeca e colunaPeca

  movimentarCavalo(linhaPeca, colunaPeca);          //Chama a função movimentarCavalo que passa os parâmetros linhaPeca e colunaPeca

  colocarTabuleiro();           //Chama a função colocarTabuleiro que atualiza o estado do tabuleiro

  validarPosicao(linhaPeca, colunaPeca);            //Chama a função validarPosicao que verifica se a posição da peça é válida
}

void movimentarPeaoPreto(int linhaPeca, int colunaPeca) {           //Declaração da função movimentarPeaoPreto que recebe como parâmetros linhaPeca e colunaPeca

  std::string linhaInicial = "2";              //Define uma variável linhaInicial do tipo String com o valor 2

  if (*tabuleiro[linhaPeca] == linhaInicial &&
      tabuleiro[linhaPeca + 1][colunaPeca] == " " &&            //Verificam se a peça está na posição inicial e se as duas casas à frente estão vazias
      tabuleiro[linhaPeca + 2][colunaPeca] == " ") {
      
    tabuleiro[linhaPeca + 1][colunaPeca] = "X";             //Atualizam as duas casas à frente com o valor X
    tabuleiro[linhaPeca + 2][colunaPeca] = "X";
      
  } else if (tabuleiro[linhaPeca + 1][colunaPeca] == " ") {             //Verifica se a casa à frente está vazia
    tabuleiro[linhaPeca + 1][colunaPeca] = "X";             //Atualiza a casa à frente com o valor X

  } else {
    std::cout << "Movimento invalido.";             //Caso contrário, exibe uma mensagem de erro na tela e retorna da função
    std::cout << std::endl;
    return;
  }

  colocarTabuleiro();           //Chama a função colocarTabuleiro que atualiza o estado do tabuleiro

  std::cout << std::endl;           //Imprime uma linha em branco na tela

  validarPosicao(linhaPeca, colunaPeca);            //Chama a função validarPosicao que verifica se a posição da peça é válida
}

void movimentarTorrePreta(int linhaPeca, int colunaPeca) {              //Declaração da função "movimentarTorrePreta" que recebe como parâmetros linhaPeca e colunaPeca

  movimentarTorre(linhaPeca, colunaPeca);           //Chamada da função movimentarTorre que passa a linha e a coluna da peça como argumentos

  colocarTabuleiro();           //Chamada da função colocarTabuleiro que atualiza a visualização do tabuleiro

  validarPosicao(linhaPeca, colunaPeca);            //Chamada da função validarPosicao que verifica se a posição da peça após o movimento é válida
}

int main() {            //Início da função principal

  int i = 0;            //Declaração e inicialização da variável inteira "i" com o valor 0

  do {          //Início de um loop do-while

    int linhaPeca;          //Declaração da variável inteira linhaPeca
    int colunaPeca;         //Declaração da variável inteira colunaPeca

    colocarTabuleiro();             //Chama a função colocarTabuleiro que imprime o tabuleiro na tel

    std::cout << std::endl;             //Imprime uma linha em branco.

    std::cout << "Digite a linha da peça: ";            //Imprime uma mensagem solicitando que o usuário digite a linha da peça
    std::cin >> linhaPeca;              //Lê um valor inteiro digitado pelo usuário e o armazena na variável linhaPeca

    std::cout << "Digite a coluna da peça: ";           //Imprime uma mensagem solicitando que o usuário digite a coluna da peça
    std::cin >> colunaPeca;             //Lê um valor inteiro digitado pelo usuário e o armazena na variável colunaPeca

    if (tabuleiro[linhaPeca][colunaPeca] == "\u2659") {              //Verifica se a posição selecionada contém um peão branco
      movimentarPeaoBranco(linhaPeca, colunaPeca);              //Chama a função movimentarPeaoBranco() passando a linha e a coluna da peça como argumentos
    }

    if (tabuleiro[linhaPeca][colunaPeca] == "\u265F") {              //Verifica se a posição selecionada contém um peão preto
      movimentarPeaoPreto(linhaPeca, colunaPeca);               //Chama a função movimentarPeaoPreto() passando a linha e a coluna da peça como argumentos
    }

    if (tabuleiro[linhaPeca][colunaPeca] == "\u2656") {              //Verifica se a posição selecionada contém uma torre branca
      movimentarTorreBranca(linhaPeca, colunaPeca);             //Chama a função movimentarTorreBranca() passando a linha e a coluna da peça como argumentos
    }

    if (tabuleiro[linhaPeca][colunaPeca] == "\u265c") {              //Verifica se a posição selecionada contém uma torre preta
      movimentarTorrePreta(linhaPeca, colunaPeca);              //Chama a função movimentarTorrePreta() passando a linha e a coluna da peça como argumentos
    }

    if (tabuleiro[linhaPeca][colunaPeca] == "\u2658") {              //Verifica se a posição selecionada contém um cavalo branco
      movimentarCavaloBranco(linhaPeca, colunaPeca);            //Chama a função movimentarCavaloBranco() passando a linha e a coluna da peça como argumentos
    }

    if (tabuleiro[linhaPeca][colunaPeca] == "\u265E") {              //Verifica se a posição selecionada contém um cavalo preto
      movimentarCavaloPreto(linhaPeca, colunaPeca);             //Chama a função movimentarCavaloPreto() passando a linha e a coluna da peça como argumentos
    }

    if (tabuleiro[linhaPeca][colunaPeca] == "\u2657") {              //Verifica se a posição selecionada contém um bispo branco
      movimentarBispoBranco(linhaPeca, colunaPeca);             //Chama a função movimentarBispoBranco() passando a linha e a coluna da peça como argumentos
    }

    if (tabuleiro[linhaPeca][colunaPeca] == "\u265D") {              //Verifica se a posição selecionada contém um bispo preto
      movimentarBispoPreto(linhaPeca, colunaPeca);              //Chama a função movimentarBispoPreto() passando a linha e a coluna da peça como argumentos
    }

    if (tabuleiro[linhaPeca][colunaPeca] == "\u2655") {              //Verifica se a posição selecionada contém uma rainha branca
      movimentarRainhaBranca(linhaPeca, colunaPeca);            //Chama a função movimentarRainhaBranca() passando a linha e a coluna da peça como argumentos
    }

    if (tabuleiro[linhaPeca][colunaPeca] == "\u265B") {              //Verifica se a posição selecionada contém uma rainha preta
      movimentarRainhaPreta(linhaPeca, colunaPeca);             //Chama a função movimentarRainhaPreta() passando a linha e a coluna da peça como argumentos
    }


    if (tabuleiro[linhaPeca][colunaPeca] == "\u2655") {              //Verifica se a posição selecionada contém um rei branco
      movimentarReiBranco(linhaPeca, colunaPeca);               //Chama a função movimentarReiBranco() passando a linha e a coluna da peça como argumentos
    }

    if (tabuleiro[linhaPeca][colunaPeca] == "\u265A") {              //Verifica se a posição selecionada contém um rei preto
      movimentarReiPreto(linhaPeca, colunaPeca);                //Chama a função movimentarReiPreto() passando a linha e a coluna da peça como argumentos
    }

    colocarTabuleiro();             //Chama a função para imprimir o estado atual do tabuleiro

    i++;            //Incrementa o valor da variável "i"
  } while (i < 6);          //Realiza o loop do-while enquanto o valor de i for menor que 6
}

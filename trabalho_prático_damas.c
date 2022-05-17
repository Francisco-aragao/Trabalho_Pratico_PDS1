#include <stdio.h>
#include <stdlib.h>

int main () {

int tamanho; //tamanho do tabuleiro 
const int t_max = 14; //maior tamanho do tabuleiro considerando \n
char entrada[t_max]; // "buffer" que armazena valores digitados
int Rp = 0; //pontos pretas
int Rb = 0; //pontos brancas
//variaveis das coordenadas dos movimentos
int inicio_x; //xo
int inicio_y; //yo
int final_x;  //xf
int final_y;  //yf

//leio valor do tamanho do tabuleiro digitado, salvo no buffer e depois salvo em tamanho
fgets(entrada, t_max, stdin);
sscanf(entrada, "%d", &tamanho);

char tabuleiro[tamanho][tamanho]; //crio tabuleiro do jogo (vetor)
//leio os valores de cada linha da entrada e salvo no tabuleiro
for (int i = 0; i < tamanho; i++) {
 fgets(tabuleiro[i], t_max, stdin);
}

/*definindo as damas caso já estiverem presentes nos valores de entrada, considerando:
'P' = dama preta
'B' = dama branca
*/
//peça preta na ultima linha torna-se uma dama
for(int j = 0; j <= tamanho - 1; j++) {
 if (tabuleiro[tamanho - 1][j] == 'p') {
     tabuleiro[tamanho - 1][j] = 'P';
 }
//peça branca na primeira linha torna-se uma dama
 if (tabuleiro[0][j] == 'b') {
     tabuleiro[0][j] = 'B';
 }
}

//crio do while para atuar até movimentos forem 0 0 0 0, o que sinaliza o fim da entrada
do { 

//recebo coordenadas iniciais e finais do movimento
scanf("%d", &inicio_x);
scanf("%d", &inicio_y);
scanf("%d", &final_x);
scanf("%d", &final_y);

//---utilizei "abs" nas condiçoes quando quero delimitar que a peça pode tanto ir para uma linha e/ou coluna maior ou menor que os valores atuais (damas podem andar em todas as direções e peças comuns podem ir para a esquerda ou direita)---

/*considerando damas:
'P' = dama preta
'B' = dama branca
*/

//---definindo movimentação das damas sem captura de peças (so andam uma casa em direção a um espaço vazio)---
//damas pretas
if (abs(final_x - inicio_x) == 1 && abs(final_y - inicio_y) == 1) {
 if (tabuleiro[inicio_x][inicio_y] == 'P' && tabuleiro[final_x][final_y] == 'o') {
     tabuleiro[final_x][final_y] = 'P';
     tabuleiro[inicio_x][inicio_y] = 'o';
 } 
 //damas brancas
 if (tabuleiro[inicio_x][inicio_y] == 'B' && tabuleiro[final_x][final_y] == 'o') {
     tabuleiro[final_x][final_y] = 'B';
     tabuleiro[inicio_x][inicio_y] = 'o';
 }
}

//---definindo movimentação das damas com captura de peças (andam duas casas para capturar, vão em direção a um espaço vazio e encontram uma peça inimiga no caminho)---
//damas pretas capturando da esquerda para a direitaa e para baixo
if (abs(final_x - inicio_x) == 2 && abs(final_y - inicio_y) == 2) {
 if (tabuleiro[inicio_x][inicio_y] == 'P' && tabuleiro[final_x][final_y] == 'o' && (tabuleiro[inicio_x + 1][inicio_y + 1] == 'b' || tabuleiro[inicio_x + 1][inicio_y + 1] == 'B')) {
     Rp += 1;
     tabuleiro[final_x][final_y] = 'P';
     tabuleiro[inicio_x][inicio_y] = 'o';
     tabuleiro[inicio_x + 1][inicio_y + 1] = 'o';
 }
 //damas pretas capturando da direita para a esquerda e para baixo
 if (tabuleiro[inicio_x][inicio_y] == 'P' && tabuleiro[final_x][final_y] == 'o' && (tabuleiro[inicio_x + 1][inicio_y - 1] == 'b' || tabuleiro[inicio_x + 1][inicio_y - 1] == 'B')) {
     Rp += 1;
     tabuleiro[final_x][final_y] = 'P';
     tabuleiro[inicio_x][inicio_y] = 'o';
     tabuleiro[inicio_x + 1][inicio_y - 1] = 'o';
 }
 //damas pretas capturando da esquerda para a direita e para cima
 if (tabuleiro[inicio_x][inicio_y] == 'P' && tabuleiro[final_x][final_y] == 'o' && (tabuleiro[inicio_x - 1][inicio_y + 1] == 'b' || tabuleiro[inicio_x - 1][inicio_y + 1] == 'B')) {
     Rp += 1;
     tabuleiro[final_x][final_y] = 'P';
     tabuleiro[inicio_x][inicio_y] = 'o';
     tabuleiro[inicio_x - 1][inicio_y + 1] = 'o';
 }
 //damas pretas capturando da direita para a esquerda e para cima
 if (tabuleiro[inicio_x][inicio_y] == 'P' && tabuleiro[final_x][final_y] == 'o' && (tabuleiro[inicio_x - 1][inicio_y - 1] == 'b' || tabuleiro[inicio_x - 1][inicio_y - 1] == 'B')) {
     Rp += 1;
     tabuleiro[final_x][final_y] = 'P';
     tabuleiro[inicio_x][inicio_y] = 'o';
     tabuleiro[inicio_x - 1][inicio_y - 1] = 'o';
 }
 //damas brancas capturando da esquerda para a direita e para baixo
 if (tabuleiro[inicio_x][inicio_y] == 'B' && tabuleiro[final_x][final_y] == 'o' && (tabuleiro[inicio_x + 1][inicio_y + 1] == 'p' || tabuleiro[inicio_x + 1][inicio_y + 1] == 'P')) {
     Rb += 1;
     tabuleiro[final_x][final_y] = 'B';
     tabuleiro[inicio_x][inicio_y] = 'o';
     tabuleiro[inicio_x + 1][inicio_y + 1] = 'o';
 }
 //damas brancas capturando da direita para a esquerda e para baixo
 if (tabuleiro[inicio_x][inicio_y] == 'B' && tabuleiro[final_x][final_y] == 'o' && (tabuleiro[inicio_x + 1][inicio_y - 1] == 'p' || tabuleiro[inicio_x + 1][inicio_y - 1] == 'P')) {
     Rb += 1;
     tabuleiro[final_x][final_y] = 'B';
     tabuleiro[inicio_x][inicio_y] = 'o';
     tabuleiro[inicio_x + 1][inicio_y - 1] = 'o';
 }
 //damas brancas capturando da esquerda para a direita e para cima
 if (tabuleiro[inicio_x][inicio_y] == 'B' && tabuleiro[final_x][final_y] == 'o' && (tabuleiro[inicio_x - 1][inicio_y + 1] == 'p' || tabuleiro[inicio_x - 1][inicio_y + 1] == 'P')) {
     Rb += 1;
     tabuleiro[final_x][final_y] = 'B';
     tabuleiro[inicio_x][inicio_y] = 'o';
     tabuleiro[inicio_x - 1][inicio_y + 1] = 'o';
 }
 //damas brancas capturando da direita para a esquerda e para cima
 if (tabuleiro[inicio_x][inicio_y] == 'B' && tabuleiro[final_x][final_y] == 'o' && (tabuleiro[inicio_x - 1][inicio_y - 1] == 'p' || tabuleiro[inicio_x - 1][inicio_y - 1] == 'P')) {
     Rb += 1;
     tabuleiro[final_x][final_y] = 'B';
     tabuleiro[inicio_x][inicio_y] = 'o';
     tabuleiro[inicio_x - 1][inicio_y - 1] = 'o';
 }
}

//---movimento válido pretas e brancas sem captura de peça (só andam uma casa em direção a um espaço vazio)---
//---definindo também as damas caso sejam obtidas através de movimentos sem captura de peça---
//peças pretas
if (final_x - inicio_x == 1 && abs(final_y - inicio_y) == 1) {
 if (tabuleiro[inicio_x][inicio_y] == 'p' && tabuleiro[final_x][final_y] == 'o') {
     tabuleiro[final_x][final_y] = 'p';
     tabuleiro[inicio_x][inicio_y] = 'o';
     //peça preta se tornando dama
     if (final_x == tamanho - 1) {
         tabuleiro[final_x][final_y] = 'P';
         Rp += 1;
     }
 }
}
//peças brancas
if (inicio_x - final_x == 1 && abs(final_y - inicio_y) == 1) {
 if (tabuleiro[inicio_x][inicio_y] == 'b' && tabuleiro[final_x][final_y] == 'o') {
     tabuleiro[final_x][final_y] = 'b';
     tabuleiro[inicio_x][inicio_y] = 'o';
     //peça branca se tornando dama 
     if (final_x == 0) {
         tabuleiro[final_x][final_y] = 'B';
         Rb += 1;
     }
 }
}

//---movimentos válidos pretas e brancas com captura de peça (capturando tanto peças comuns quanto damas) (andam duas casas para capturar, vão em direção a um espaço vazio e encontram uma peça inimiga no caminho))---
//---definindo também as damas caso sejam obtidas através de movimentos com captura de peça---
if (final_x - inicio_x == 2 && final_y - inicio_y == 2) {
//peças pretas capturando da esquerda para a direita
 if (tabuleiro[inicio_x][inicio_y] == 'p' && tabuleiro[final_x][final_y] == 'o' && (tabuleiro[inicio_x + 1][inicio_y + 1] == 'b' || tabuleiro[inicio_x + 1][inicio_y + 1] == 'B')) {
     Rp += 1;
     tabuleiro[final_x][final_y] = 'p';
     tabuleiro[inicio_x + 1][inicio_y + 1] = 'o';
     tabuleiro[inicio_x][inicio_y] = 'o';
     //peça preta capturando branca (comum ou dama) e se tornando dama
     if (final_x == tamanho - 1) {
         Rp += 1;
         tabuleiro[final_x][final_y] = 'P';
     } 
 } 
}
if (final_x - inicio_x == 2 && inicio_y - final_y == 2) {
 //peças pretas capturando da direita para a esquerda
 if (tabuleiro[inicio_x][inicio_y] == 'p' && tabuleiro[final_x][final_y] == 'o' && (tabuleiro[inicio_x + 1][inicio_y - 1] == 'b' || tabuleiro[inicio_x + 1][inicio_y - 1] == 'B')) {
     Rp += 1;
     tabuleiro[final_x][final_y] = 'p';
     tabuleiro[inicio_x + 1][inicio_y - 1] = 'o';
     tabuleiro[inicio_x][inicio_y] = 'o';
     //peça preta capturando branca (comum ou dama) e se tornando dama
     if (final_x == tamanho - 1) {
         Rp += 1;
         tabuleiro[final_x][final_y] = 'P';
     } 
 }
}

if (inicio_x - final_x == 2 && inicio_y - final_y == 2) {
//peças brancas capturando da direita para a esquerda
 if (tabuleiro[inicio_x][inicio_y] == 'b' && tabuleiro[final_x][final_y] == 'o' && (tabuleiro[inicio_x - 1][inicio_y - 1] == 'p' || tabuleiro[inicio_x - 1][inicio_y - 1] == 'P')) {
     Rb += 1;
     tabuleiro[final_x][final_y] = 'b';
     tabuleiro[inicio_x - 1][inicio_y - 1] = 'o';
     tabuleiro[final_x + 1][final_y + 1] = 'o';
     tabuleiro[inicio_x][inicio_y] = 'o';
     //peça branca capturando preta (comum ou dama) e se tornando dama
     if (final_x == 0) {
         Rb += 1;
         tabuleiro[final_x][final_y] = 'B';
     } 
 } 
}

if (inicio_x - final_x == 2 && final_y - inicio_y == 2) {
 //peças brancas capturando da esquerda para a direita
 if (tabuleiro[inicio_x][inicio_y] == 'b' && tabuleiro[final_x][final_y] == 'o' && (tabuleiro[inicio_x - 1][inicio_y + 1] == 'p' || tabuleiro[inicio_x - 1][inicio_y + 1] == 'P' )) {
     Rb += 1;
     tabuleiro[final_x][final_y] = 'b';
     tabuleiro[inicio_x - 1][inicio_y + 1] = 'o'; 
     tabuleiro[inicio_x][inicio_y] = 'o';
     //peça branca capturando preta (comum ou dama) e se tornando dama
     if (final_x == 0) {
         Rb += 1;
         tabuleiro[final_x][final_y] = 'B';
     } 
 } 
}

//---caso jogada invalida, recebo proximos movimentos---
//---loop até movimentos forem 0 0 0 0 ---

} while (inicio_x + inicio_y + final_x + final_y != 0);

//imprimindo os resultados e o placar do jogo
printf("PRETAS %d\n", Rp);
printf("BRANCAS %d\n", Rb);
if (Rp > Rb) {
  printf("PRETAS VENCERAM\n");
} else if (Rp < Rb) {
  printf("BRANCAS VENCERAM\n");
} else  {
  printf("EMPATE\n");
}

return 0;
}

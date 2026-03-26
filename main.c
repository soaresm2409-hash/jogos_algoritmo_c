#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main(){
	
int menuPrincipal();
int jogoPerguntaResposta();
int jogoCobraNaCaixa();
int jogoGousmasWar();

    int opcao;
    do {
        printf("\n       ARCADE DE ALGORITMOS      ");
        printf("\n1: Pergunta e Resposta");
        printf("\n2: Cobra na Caixa!");
        printf("\n3: Gousmas War");
        printf("\n4: Sair");
        printf("\nEscolha uma opcao: ");
        
        while (scanf("%d", &opcao) != 1 || opcao < 1 || opcao > 4) {
            printf("Opcao invalida! Digite de 1 a 4: ");
            while(getchar() != '\n'); 
        }

        if (opcao == 1) {
            jogoPerguntaResposta();
        } else if (opcao == 2) {
            jogoCobraNaCaixa();
        } else if (opcao == 3) {
            jogoGousmasWar();
        } else {
            printf("\nSaindo do sistema... Ate a proxima!\n");
        }

    } while (opcao != 4);

    return 0;
}

// JOGO 1: PERGUNTA E RESPOSTA 
int jogoPerguntaResposta() {
    int jogarNovamente;
    do {
        printf("\n--- JOGO 1: CAPITAIS DO MUNDO ---\n");
        int i, acertos = 0;
        char resp;

        for (i = 1; i <= 5; i++) {
            if (i == 1) printf("\n1. Capital da Eslovaquia?\nA) Ljubljana B) Bratislava C) Tirana D) Praga");
            else if (i == 2) printf("\n2. Capital do Japao?\nA) Seul B) Pequim C) Toquio D) Bangcoc");
            else if (i == 3) printf("\n3. Capital do Suriname?\nA) Georgetown B) Caracas C) Paramaribo D) Quito");
            else if (i == 4) printf("\n4. Capital da Mongolia?\nA) Ulaanbaatar B) Kuala Lumpur C) Tashkent D) Dushanbe");
            else if (i == 5) printf("\n5. Capital da Australia?\nA) Sydney B) Canberra C) Melbourne D) Perth");

            do {
                printf("\nSua resposta (A-D): ");
                scanf(" %c", &resp);
                resp = toupper(resp);
            } while (resp < 'A' || resp > 'D');

            if ((i==1 && resp=='B') || (i==2 && resp=='C') || (i==3 && resp=='C') || (i==4 && resp=='A') || (i==5 && resp=='B')) {
                printf("Correto!\n");
                acertos++;
            } else {
                printf("Incorreto!\n");
            }
        }
        printf("\nVoce acertou %d de 5!", acertos);
        if (acertos == 5) {
            printf("\nPARABENSS! Voce teve um desempenho perfeito!");
        } else if (acertos >= 3) {
            printf("\nMuito bom! Voce conhece bastante de capitais.");
        } else {
            printf("\nBom treino! Tente melhorar na proxima vez.");
        }
        printf("\n1: Jogar de novo | 0: Menu: ");
        scanf("%d", &jogarNovamente);
    } while (jogarNovamente == 1);
}

// JOGO 2: COBRA NA CAIXA 
int jogoCobraNaCaixa() {
    int jogarNovamente;
    srand(time(NULL));
    do {
        printf("\n--- JOGO 2: COBRA NA CAIXA! ---\n");
        int c1=0, c2=0, c3=0, c4=0, c5=0; // 0=fechada, 1=aberta
        int pBotao, pCobra, escolha, jogoAtivo=1, turno=1;

        pBotao = (rand() % 5) + 1;
        do { pCobra = (rand() % 5) + 1; } while (pCobra == pBotao);

        while (jogoAtivo == 1) {
            printf("\nTurno Jogador %d. Caixas: ", (turno % 2 == 0) ? 2 : 1);
            printf("%s %s %s %s %s", c1?"[X]":"[1]", c2?"[X]":"[2]", c3?"[X]":"[3]", c4?"[X]":"[4]", c5?"[X]":"[5]");
            
            printf("\nEscolha (1-5): ");
            scanf("%d", &escolha);

            int valida = 0;
            if (escolha==1 && c1==0) { c1=1; valida=1; }
            else if (escolha==2 && c2==0) { c2=1; valida=1; }
            else if (escolha==3 && c3==0) { c3=1; valida=1; }
            else if (escolha==4 && c4==0) { c4=1; valida=1; }
            else if (escolha==5 && c5==0) { c5=1; valida=1; }

            if (valida == 1) {
                if (escolha == pBotao) { printf("VITORIA! Achou o botao!"); jogoAtivo=0; }
                else if (escolha == pCobra) { printf("DERROTA! A cobra te pegou!"); jogoAtivo=0; }
                else { printf("Vazia..."); turno++; }
            } else printf("Invalida!");
        }
        printf("\n1: Jogar de novo | 0: Menu: ");
        scanf("%d", &jogarNovamente);
    } while (jogarNovamente == 1);
}


// JOGO 3: GOUSMAS WAR 

int jogoGousmasWar() {
    int jogarNovamente;
    do {
        printf("\n--- JOGO 3: GOUSMAS WAR ---\n");
        int f1=1, f2=1, f3=1, f4=1; // Gousmas J1 e J2
        int turno=1, jogoAtivo=1;

        while (jogoAtivo == 1) {
            printf("\nJ1: [%d][%d] | J2: [%d][%d] - Vez: J%d", f1, f2, f3, f4, turno);
            int acao; printf("\n1-Atacar 2-Dividir: "); scanf("%d", &acao);

            if (acao == 1) {
                int at, al; printf("Sua Gousma (1-2) no Alvo (1-2): "); scanf("%d %d", &at, &al);
                if (turno == 1) {
                    if (at==1 && f1>0 && al==1 && f3>0) f3+=f1;
                    else if (at==1 && f1>0 && al==2 && f4>0) f4+=f1;
                    else if (at==2 && f2>0 && al==1 && f3>0) f3+=f2;
                    else if (at==2 && f2>0 && al==2 && f4>0) f4+=f2;
                    else { printf("Invalido!"); continue; }
                } else {
                    if (at==1 && f3>0 && al==1 && f1>0) f1+=f3;
                    else if (at==1 && f3>0 && al==2 && f2>0) f2+=f3;
                    else if (at==2 && f4>0 && al==1 && f1>0) f1+=f4;
                    else if (at==2 && f4>0 && al==2 && f2>0) f2+=f4;
                    else { printf("Invalido!"); continue; }
                }
            } else if (acao == 2) {
                int doa, pts; printf("Doadora (1-2) e Pontos: "); scanf("%d %d", &doa, &pts);
                if (turno==1) {
                    if (doa==1 && f1>pts && pts>0) { f1-=pts; f2+=pts; }
                    else if (doa==2 && f2>pts && pts>0) { f2-=pts; f1+=pts; }
                    else { printf("Erro!"); continue; }
                } else {
                    if (doa==1 && f3>pts && pts>0) { f3-=pts; f4+=pts; }
                    else if (doa==2 && f4>pts && pts>0) { f4-=pts; f3+=pts; }
                    else { printf("Erro!"); continue; }
                }
            }
            if(f1>5)f1=0; if(f2>5)f2=0; if(f3>5)f3=0; if(f4>5)f4=0;
            if ((f1==0 && f2==0) || (f3==0 && f4==0)) {
                printf("\nFIM DE JOGO! J1:[%d][%d] J2:[%d][%d]", f1, f2, f3, f4);
                jogoAtivo = 0;
            } else turno = (turno == 1) ? 2 : 1;
        }
        printf("\n1: Reiniciar | 0: Menu: "); scanf("%d", &jogarNovamente);
    } while (jogarNovamente == 1);
}

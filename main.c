#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
int menuPrincipal();
int jogoPerguntaResposta();
int jogoCobraNaCaixa();
int jogoGousmasWar();

    int opcao;
    do {
        printf("\n      ARCADE DE ALGORITMOS     ");
        printf("\n1: Pergunta e Resposta");
        printf("\n2: Cobra na Caixa!");
        printf("\n3: Gousmas War");
        printf("\n4: Sair");
        printf("\nEscolha uma opcao: ");
        
        while (scanf("%d", &opcao) != 1 || opcao < 1 || opcao > 4) {
            printf("naoo,digitou errado! Digite de 1 a 4: ");
            while(getchar() != '\n'); 
        }

        if (opcao == 1) {
            jogoPerguntaResposta();
        } else if (opcao == 2) {
            jogoCobraNaCaixa();
        } else if (opcao == 3) {
            jogoGousmasWar();
        } else {
            printf("\nSaindo do sistema... au revoir!\n");
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
            printf("\nPARABENSS!Voce teve um desempenho perfeito!");
        } else if (acertos >= 3) {
            printf("\nMuito bom!mas tente melhorar na proxima vez.");
        } else {
            printf("\nBom treino!.");
        }
        printf("\n1: Jogar de novo | 0: Menu: ");
        scanf("%d", &jogarNovamente);
    } while (jogarNovamente == 1);
}

// JOGO 2: COBRA NA CAIXA 
   int jogoCobraNaCaixa() 
{
    int jogarNovamente;
    srand(time(NULL));
    do 
    {
        printf("\n--- JOGO 2: COBRA NA CAIXA! ---\n");
        int c1 = 0;
        int c2 = 0;
        int c3 = 0;
        int c4 = 0;
        int c5 = 0;
        int pBotao;
        int pCobra;
        int escolha;
        int rodando = 1; 
        int turno = 1;

        pBotao = (rand() % 5) + 1;
        do 
        { 
            pCobra = (rand() % 5) + 1; 
        } 
        while (pCobra == pBotao);

        while (rodando == 1) 
        {
            int quemJoga;

            
            if (turno % 2 == 0) 
            {
                quemJoga = 2;
            } 
            else 
            {
                quemJoga = 1;
            }
            printf("\nTurno Jogador %d.", quemJoga);
            printf("\nStatus das Caixas: ");

            if (c1 == 1) 
            {
                printf("[X] ");
            } 
            else 
            {
                printf("[1] ");
            }
            if (c2 == 1) 
            {
                printf("[X] ");
            } 
            else 
            {
                printf("[2] ");
            }
            if (c3 == 1) 
            {
                printf("[X] ");
            } 
            else 
            {
                printf("[3] ");
            }
            if (c4 == 1) 
            {
                printf("[X] ");
            } 
            else 
            {
                printf("[4] ");
            }
            if (c5 == 1) 
            {
                printf("[X] ");
            } 
            else 
            {
                printf("[5] ");
            }

            printf("\nEscolha uma caixa (1-5): ");
            scanf("%d", &escolha);

            int valida = 0;

            if (escolha == 1 && c1 == 0) 
            { 
                c1 = 1; 
                valida = 1; 
            }
            else if (escolha == 2 && c2 == 0) 
            { 
                c2 = 1; 
                valida = 1; 
            }
            else if (escolha == 3 && c3 == 0) 
            { 
                c3 = 1; 
                valida = 1; 
            }
            else if (escolha == 4 && c4 == 0) 
            { 
                c4 = 1; 
                valida = 1; 
            }
            else if (escolha == 5 && c5 == 0) 
            { 
                c5 = 1; 
                valida = 1; 
            }

            if (valida == 1) 
            {
                if (escolha == pBotao) 
                {
                    printf("VITORIA! Voce achou o botao e escapou!\n");
                    rodando = 0; 
                } 
                else if (escolha == pCobra) 
                {
                    printf("DERROTA! A cobra estava ai e te pegou!\n");
                    rodando = 0; 
                } 
                else 
                {
                    printf("Ufa... Esta vazia. Passando a vez!\n");
                    turno++; 
                }
            } 
            else 
            {
                printf("Essa escolha e invalida ou a caixa ja esta aberta!\n");
            }

        } 

        printf("\nDigite 1 para jogar de novo ou 0 para voltar ao menu: ");
        scanf("%d", &jogarNovamente);

    } 
    while (jogarNovamente == 1);

    return 0;
}

// JOGO 3: GOUSMAS WAR 
int jogoGousmasWar() 
{
    int jogarNovamente;
    do 
    {
        printf("\n--- JOGO 3: GOUSMAS WAR ---\n");
        
        int mao1J1 = 1;
        int mao2J1 = 1;
        
        int mao1J2 = 1;
        int mao2J2 = 1;

        int turno = 1;
        int rodando = 1;

        while (rodando == 1) 
        {
            printf("\n------------------------------");
            printf("\nJ1: [%d][%d] | J2: [%d][%d]", mao1J1, mao2J1, mao1J2, mao2J2);
            printf("\nVez do Jogador: %d", turno);
            
            int acao; 
            printf("\n1 - Atacar");
            printf("\n2 - Dividir Pontos");
            printf("\nEscolha sua acao: "); 
            scanf("%d", &acao);

            
            if (acao == 1) 
            {
                int qualMaoMinha, qualMaoAlvo;
                printf("Qual mao voce vai usar? (1 ou 2): ");
                scanf("%d", &qualMaoMinha);
                printf("Qual mao do alvo quer atacar? (1 ou 2): ");
                scanf("%d", &qualMaoAlvo);

                if (turno == 1) 
                {

                    if (qualMaoMinha == 1 && mao1J1 > 0 && qualMaoAlvo == 1 && mao1J2 > 0) 
                    {
                        mao1J2 = mao1J2 + mao1J1;
                    }
                    else if (qualMaoMinha == 1 && mao1J1 > 0 && qualMaoAlvo == 2 && mao2J2 > 0) 
                    {
                        mao2J2 = mao2J2 + mao1J1;
                    }
                    else if (qualMaoMinha == 2 && mao2J1 > 0 && qualMaoAlvo == 1 && mao1J2 > 0) 
                    {
                        mao1J2 = mao1J2 + mao2J1;
                    }
                    else if (qualMaoMinha == 2 && mao2J1 > 0 && qualMaoAlvo == 2 && mao2J2 > 0) 
                    {
                        mao2J2 = mao2J2 + mao2J1;
                    }
                    else 
                    {
                        printf("\nAcao invalida! Tente de novo.\n");
                        continue; 
                    }
                } 
                else 
                {
                    if (qualMaoMinha == 1 && mao1J2 > 0 && qualMaoAlvo == 1 && mao1J1 > 0) 
                    {
                        mao1J1 = mao1J1 + mao1J2;
                    }
                    else if (qualMaoMinha == 1 && mao1J2 > 0 && qualMaoAlvo == 2 && mao2J1 > 0) 
                    {
                        mao2J1 = mao2J1 + mao1J2;
                    }
                    else if (qualMaoMinha == 2 && mao2J2 > 0 && qualMaoAlvo == 1 && mao1J1 > 0) 
                    {
                        mao1J1 = mao1J1 + mao2J2;
                    }
                    else if (qualMaoMinha == 2 && mao2J2 > 0 && qualMaoAlvo == 2 && mao2J1 > 0) 
                    {
                        mao2J1 = mao2J1 + mao2J2;
                    }
                    else 
                    {
                        printf("\nAcao invalida! Tente de novo.\n");
                        continue; 
                    }
                }
            } 
            else if (acao == 2) 
            {
                int doar, pontos; 
                printf("Mao doadora (1 ou 2) e quantos pontos passar: "); 
                scanf("%d %d", &doar, &pontos);

                if (turno == 1) 
                {
                    if (doar == 1 && mao1J1 > pontos && pontos > 0) 
                    { 
                        mao1J1 = mao1J1 - pontos; 
                        mao2J1 = mao2J1 + pontos; 
                    }
                    else if (doar == 2 && mao2J1 > pontos && pontos > 0) 
                    { 
                        mao2J1 = mao2J1 - pontos; 
                        mao1J1 = mao1J1 + pontos; 
                    }
                    else 
                    { 
                        printf("\nNao pode dividir assim!\n"); 
                        continue; 
                    }
                } 
                else 
                {
                    if (doar == 1 && mao1J2 > pontos && pontos > 0) 
                    { 
                        mao1J2 = mao1J2 - pontos; 
                        mao2J2 = mao2J2 + pontos; 
                    }
                    else if (doar == 2 && mao2J2 > pontos && pontos > 0) 
                    { 
                        mao2J2 = mao2J2 - pontos; 
                        mao1J2 = mao1J2 + pontos; 
                    }
                    else 
                    { 
                        printf("\nNao pode dividir assim!\n"); 
                        continue; 
                    }
                }
            }

            if (mao1J1 >= 5) { mao1J1 = 0; }
            if (mao2J1 >= 5) { mao2J1 = 0; }
            if (mao1J2 >= 5) { mao1J2 = 0; }
            if (mao2J2 >= 5) { mao2J2 = 0; }

            if ((mao1J1 == 0 && mao2J1 == 0) || (mao1J2 == 0 && mao2J2 == 0)) 
            {
                printf("\n--- FIM DE JOGO! ---");
                printf("\nResultado final - J1:[%d][%d] J2:[%d][%d]", mao1J1, mao2J1, mao1J2, mao2J2);
                rodando = 0;
            } 
            else 
            {
                // Troca o turno
                if (turno == 1) 
                {
                    turno = 2;
                }
                else 
                {
                    turno = 1;
                }
            }
        }

        printf("\nDigite 1 para reiniciar ou 0 para o menu: "); 
        scanf("%d", &jogarNovamente);

    } while (jogarNovamente == 1);
    
    return 0;
}

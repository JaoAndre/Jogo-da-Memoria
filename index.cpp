#include <Windows.h>
#include <iostream>
#include <time.h>
using namespace std;

void limparConsole(bool pausar)
{
    if (pausar)
        system("pause");
    system("cls");
}

void imprimirTabela(int matriz[2][4])
{
    cout << "    ";

    for (int i = 0; i < 4; i++)
    {
        cout << i << " ";
    }

    cout << "\n";

    for (int i = 0; i < 2; i++)
    {
        cout << (i == 0 ? "A | " : "B | ");

        for (int j = 0; j < 4; j++)
        {
            cout << matriz[i][j] << " ";
        }

        cout << "\n";
    }
}

int main()
{
    // VARIAVEIS DO JOGO.
    int matrizDado[2][4] = {};
    int matrizJogo[2][4] = {};
    int randomHistory[4] = {};
    int acertos = 0;

    srand(time(0));
    setlocale(LC_ALL, "Portuguese");

    // INICIAR MATRIZ RANDOMICA.
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int random = 1 + rand() % 4;

            while (randomHistory[random - 1] == 2)
            {
                random = 1 + rand() % 4;
            }

            randomHistory[random - 1]++;
            matrizDado[i][j] = random;
        }
    }

    // TABULEIRO.
    imprimirTabela(matrizDado);
    cout << "Você tem 5 segundos!\n";

    Sleep(5000);
    limparConsole(false);

    string linha1, linha2;
    int casa1, casa2;

    while (true)
    {
        // TABULEIRO.
        imprimirTabela(matrizJogo);

        cout << "Escreva a casa que quer jogar: ";
        cin >> linha1 >> casa1;

        matrizJogo[linha1 != "A"][casa1] = matrizDado[linha1 != "A"][casa1];

        // TABULEIRO.
        limparConsole(false);
        imprimirTabela(matrizJogo);

        cout << "Escreva outra casa que quer jogar: ";
        cin >> linha2 >> casa2;

        matrizJogo[linha2 != "A"][casa2] = matrizDado[linha2 != "A"][casa2];

        // TABULEIRO.
        limparConsole(false);
        imprimirTabela(matrizJogo);

        // VERIFICAÇÃO SE OS VALORES SÃO IGUAIS.
        if (matrizJogo[linha2 != "A"][casa2] == matrizJogo[linha1 != "A"][casa1])
        {
            acertos++;

            cout << "Acertou!\n";
            limparConsole(true);
        }
        else
        {
            matrizJogo[linha1 != "A"][casa1] = 0;
            matrizJogo[linha2 != "A"][casa2] = 0;

            cout << "Errou!\n";
            limparConsole(true);
        }

        // VERIFICAÇÃO SE O JOGO ACABOU.
        if (acertos == 4)
        {
            imprimirTabela(matrizJogo);
            cout << "Acabou o jogo. Parabéns!\n";
            break;
        }
    }
}
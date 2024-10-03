#include <stdio.h>
#include <stdlib.h>
struct Funcionario
{
    char nome[20];
    float salario;
    float salarioComReajuste;
    int id;
};

float reajustarSalario(float salario, float porcentagem)
{
    return salario + salario * (porcentagem / 100);
}

float lerDados(struct Funcionario dados[], int quantidade)
{
    float porcentagem;
    printf("Qual a porcentagem de aumnento de salario %%: ");
    scanf("%f", &porcentagem);
    for (int i = 0; i < quantidade; i++)
    {
        printf("Nome do funcionario(a): ");
        scanf(" %s", &dados[i].nome);
        printf("Salario do funcinario(a) %s R$: ", dados[i].nome);
        scanf("%f", &dados[i].salario);
        dados[i].salarioComReajuste = reajustarSalario(dados[i].salario, porcentagem);
        dados[i].id = i;
    }
    return porcentagem;
}

int maiorSalario(struct Funcionario dados[], int quantidade)
{
    float maiorSalario = dados[0].salarioComReajuste;
    int funcionarioId = dados[0].id;
    for (int i = 0; i < quantidade; i++)
    {
        if (dados[i].salarioComReajuste > maiorSalario)
        {
            maiorSalario = dados[i].salarioComReajuste;
            funcionarioId = dados[i].id;
        }
    }
    return funcionarioId;
}
void linha()
{
    printf("---------------------------------------------------------------------------------------------\n");
}
void mostraResultado(struct Funcionario dados[], int quantidade, int id, float porcentagem)
{
    system("cls");
    for (int i = 0; i < quantidade; i++)
    {
        linha();
        printf(
            "Salario do(a) funcionario %s = R$ %.2f. Com reajuste de %.2f %% = R$ %.2f. \n",
            dados[i].nome,
            dados[i].salario,
            porcentagem,
            dados[i].salarioComReajuste);
    }
    linha();
    printf(
        "\nO maior salario com reajuste foi do(a) funcionario(a) %s no valor de R$ %.2f.\n",
        dados[id].nome, dados[id].salarioComReajuste);
}
void inicio(int quntidade)
{
    int id;
    float porcentagem;
    struct Funcionario funcionario[quntidade];
    porcentagem = lerDados(funcionario, quntidade);
    id = maiorSalario(funcionario, quntidade);
    mostraResultado(funcionario, quntidade, id, porcentagem);
}

int main()
{
    inicio(3);
    system('pause');
    return 0;
}
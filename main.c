#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct carro
{
    char marca[20];
    char modelo[20];
    char placa[9];
    int ano;
} TYPE_VEICULO;

void TodosVeiculos(TYPE_VEICULO car[]) {
    for (int i = 0; i<10; i++) {
            printf("\n Marca: %s, Modelo: %s, Placa: %s, Ano: %d", car[i].marca, car[i].modelo, car[i].placa, car[i].ano);
        }

}
void ListarAno(int listaAno, TYPE_VEICULO car[]) {

for(int i=0; i<10; i++) {

    if(car[i].ano > listaAno)
    {
        printf("\n Marca: %s, Modelo: %s, Placa: %s, Ano: %d", car[i].marca, car[i].modelo, car[i].placa, car[i].ano);
    }

}
}

void ListarModelo(char listaModelo[], TYPE_VEICULO car[]) {
for (int i = 0; i < 10; i ++) {
    if(strcmp(listaModelo, car[i].modelo) == 0) {

       printf("\n Marca: %s, Modelo: %s, Placa: %s, Ano: %d", car[i].marca, car[i].modelo, car[i].placa, car[i].ano);
    }
}

}

void OrganizarVeiculos(int in, TYPE_VEICULO carros[]){

    printf("\n Organizando a tabela em ordem crescente (ano de fabrica��o).\n");

    TYPE_VEICULO aux;

    for (int i = 0; i < in+1; i++) {
        for (int j = i +1; j < in+1; j++) {
            if (carros[i].ano > carros[j].ano)
            {
                aux = carros[i];
                carros[i] = carros[j];
                carros[j] = aux;
            }

        }
    }
}

void CadastrarVeiculo(int index, TYPE_VEICULO car[]) {

    if(index < 10) {

            printf("\n Carro %d", index);
            printf("\n Digite a marca: ");
            scanf("%s", &car[index].marca);

            printf("\n Digite o modelo: ");
            scanf("%s", &car[index].modelo);

            printf("\n Digite a placa no formato XXX-YYYY: ");
            scanf("%s", &car[index].placa);

            while (strlen(car->placa) != 8) {

        printf("Voc� inseriu um formato inv�lido, favor inserir a placa do ve�culo no formato XXX-YYYY (X letra e Y n�mero): ");
        scanf("%s", &car[index].placa);
    }



            printf("\n Digite o ano: ");
            scanf("%d", &car[index].ano);

            OrganizarVeiculos(index, car);


    } else {
    printf("\n O n�mero m�ximo de ve�culos j� foi atingido");
    }

}

int main()
{
    //comando de regionaliza��o para idioma portugu�s
    setlocale(LC_ALL,"Portuguese_Brazil");

    TYPE_VEICULO car[10] = {};
    int escolha = 6;
    int i = 0;
    int listaAno = 0;
    char listaModelo[20];


    while(escolha !=0) {
        switch(escolha) {

            //Listar ve�culos cadastrados
    case 1:

        TodosVeiculos(car);
        escolha = 6;
        break;

        // Cadastro de ve�culos
    case 2:
        CadastrarVeiculo(i, car);
        i+=1;
        escolha = 6;
        break;

        // Listar Ve�culos em ordem crescente (ano de fabrica��o)
    case 3:

        TodosVeiculos(car);
        escolha = 6;
        break;

        // Listar ve�culos a partir do ano...
    case 4:

        printf("\n Digite a partir de qual ano voc� deseja buscar os ve�culos: ");
        scanf("%d", &listaAno);
        ListarAno(listaAno, car);
        escolha = 6;
        break;

        // Mostrar ve�culos de acordo com modelo
    case 5:

        printf("\n Digite o modelo do ve�culo que deseja buscar: ");
        scanf("%s", &listaModelo);
        ListarModelo(listaModelo, car);
        escolha = 6;
        break;


    default:
        printf("\n 1 - Listar os ve�culos cadastrados.");
        printf("\n 2 - Inserir um novo ve�culo.");
        printf("\n 3 - Listar ve�culos por ano de fabrica��o.");
        printf("\n 4 - Listar ve�culos com ano de fabrica��o a partir de:");
        printf("\n 5 - Filtrar ve�culos pelo modelo:");
        printf("\n 0 - Sair.");
        printf("\n Digite o n�mero de uma das op��es: ");
        scanf("%d", &escolha);
        break;

        }
    }

    return 0;
}

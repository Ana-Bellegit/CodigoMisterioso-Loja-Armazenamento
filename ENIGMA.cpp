#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "portuguese");

	int m[3][2], op;  	
	float v[3];

	for( int i = 0 ; i < 3; i++) {
		printf("\nPreencha as informaC'C5es do produto %d (ID e Quantidade no estoque):\n", i + 1);
		scanf("%d %d", &m[i][0], &m[i][1]);

	}

	for (int i = 0; i < 3; i++) {
		printf("\nInsira o preC'o do produto %d (ID: %d):\n", i + 1, m[i][0]);
		scanf("%f", &v[i]);

	}

	do {
		printf("\n1: Exibir produtos;\n2: Vender produto;\n0: Encerrar programa;\n");
		scanf("%d", &op);

		switch(op) {
		case 1:
			printf("\nTabela de Produtos no Freezer:\n");
			printf("ID\tQuantidade\tPreC'o\n");
			for(int i = 0; i < 3; i++) {
				printf("%d\t%d\t\t%.2f\n", m[i][0], m[i][1], v[i]);
				if (m[i][1] < 3) {  // Alerta de estoque baixo
					printf("\nATENCCO: O produto de ID %d estC! com estoque baixo!\n", m[i][0]);
				}
			}
			break;

		case 2:
		{
			int id, qtd;
			float preco;
			printf("\nInsira o ID do produto a ser vendido:\n");
			scanf("%d", &id);

			int produtoEncontrado = 0;

			for(int i = 0; i < 3; i++) {
				if (id == m[i][0]) {
					produtoEncontrado = 1;
					printf("\nProduto encontrado! Quantidade disponC-vel: %d\n", m[i][1]);
					printf("Insira a quantidade a ser vendida:\n");
					scanf("%d", &qtd);

					if (m[i][1] <= 0) {
						printf("\nEstoque esgotado! Venda nC#o permitida.\n");
					}

				
					// m[i][1] = m[i][1] - qtd;
					printf("A quantidade restante desse produto ainda C) %d.\n", m[i][1]);

				
					if (m[i][1] < qtd) {
						printf("\nVenda permitida! Quantidade vendida: %d\n", qtd);
					} else {
						preco = qtd * v[i];
						printf("\nVenda realizada com sucesso! Valor total: %.2f\n", preco);
					}

					break;
				}
			}

			if (!produtoEncontrado) {
				printf("\nProduto com ID %d nC#o encontrado!\n", id);
			}
		}
		break;

		case 0:
			printf("\nPrograma encerrado.\n");
			break;

		default:
			printf("\nOpC'C#o invC!lida, tente novamente.\n");
		}
	} while(op != 0);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");
    
    int m[3][2], op;  
    float v[3];       
    
    for (int i = 0; i < 3; i++) {
        printf("\nPreencha as informações do produto %d (ID e Quantidade no estoque):\n", i + 1);
        scanf("%d", &m[i][0]);
        
        do {
            printf("Digite a quantidade em estoque (não pode ser negativa):\n");
            scanf("%d", &m[i][1]);
            if (m[i][1] < 0) {
                printf("\nErro: Quantidade não pode ser negativa. Tente novamente.\n");
            }
        } while (m[i][1] < 0);
    }
    
    for (int i = 0; i < 3; i++) {
        printf("\nInsira o preço do produto %d (ID: %d):\n", i + 1, m[i][0]);
        
        do {
            scanf("%f", &v[i]);
            if (v[i] < 0) {
                printf("\nErro: Preço não pode ser negativo. Tente novamente.\n");
            }
        } while (v[i] < 0);
    }
    
    do {
        printf("\n1: Exibir produtos;\n2: Vender produto;\n0: Encerrar programa;\n");
        scanf("%d", &op);
        
        switch (op) {
            case 1:
                printf("\nTabela de Produtos no Freezer:\n");
                printf("ID\tQuantidade\tPreço\n");
                for (int i = 0; i < 3; i++) {
                    printf("%d\t%d\t\t%.2f\n", m[i][0], m[i][1], v[i]);
                    if (m[i][1] < 3) {  // Alerta de estoque baixo
                        printf("\nATENÇÃO: O produto de ID %d está com estoque baixo!\n", m[i][0]);
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
                    
                    for (int i = 0; i < 3; i++) {
                        if (id == m[i][0]) {
                            produtoEncontrado = 1;
                            printf("\nProduto encontrado! Quantidade disponível: %d\n", m[i][1]);
                            printf("Insira a quantidade a ser vendida:\n");
                            scanf("%d", &qtd);
                            
                            if (qtd <= 0) {
                                printf("\nErro: A quantidade a ser vendida deve ser maior que zero.\n");
                            } else if (qtd > m[i][1]) {
                                printf("\nEstoque insuficiente! Apenas %d unidades disponíveis.\n", m[i][1]);
                            } else {
                                preco = qtd * v[i];
                                printf("\nVenda realizada com sucesso! Valor total: %.2f\n", preco);
                                
                                m[i][1] -= qtd;
                                printf("Quantidade restante após a venda: %d\n", m[i][1]);
                            }
                            break;
                        }
                    }
                    
                    if (!produtoEncontrado) {
                        printf("\nProduto com ID %d não encontrado!\n", id);
                    }
                }
                break;

            case 0:
                printf("\nPrograma encerrado.\n");
                break;

            default:
                printf("\nOpção inválida, tente novamente.\n");
        }
    } while (op != 0);

    return 0;
}


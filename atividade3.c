#include <stdio.h>
#include <stdlib.h>

typedef struct produto Produto;

// Definição da estrutura
struct produto {
    char nome[100];
    char categoria[50];
    double valor;
};

Produto produtos[20] = {
    {"Caneta BIC", "Material Escolar", 1.50 },
    {"Caderno 100 folhas", "Material Escolar", 15.00 },
    {"Mochila", "Material Escolar", 120.00 },
    {"Borracha", "Material Escolar", 2.00 },
    {"Tablet", "Eletrônicos", 1500.00 },
    {"Smartphone", "Eletrônicos", 3500.00 },
    {"Notebook", "Eletrônicos", 4500.00 },
    {"Fone de ouvido", "Eletrônicos", 200.00 },
    {"Camiseta", "Vestuário", 50.00 },
    {"Calça Jeans", "Vestuário", 120.00 },
    {"Tênis", "Vestuário", 300.00 },
    {"Jaqueta", "Vestuário", 250.00 },
    {"Livro de C++", "Livros", 80.00 },
    {"Livro de Java", "Livros", 90.00 },
    {"Livro de Python", "Livros", 70.00 },
    {"Livro de Algoritmos", "Livros", 100.00 },
    {"Garrafa de água", "Acessórios", 25.00 },
    {"Relógio de pulso", "Acessórios", 500.00 },
    {"Óculos de sol", "Acessórios", 150.00 },
    {"Chapéu", "Acessórios", 80.00 }
};

int salvar_produtos_bin(char *nome_arquivo, int n, Produto *prd) {
    FILE *fp = fopen(nome_arquivo, "wb");
    if(!fp) { // !(NULL)
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        return 0;
    }
    //operacoes de escrita
    int *p_n;
    fwrite(&n, sizeof(int), 1, fp);
    fwrite(prd, sizeof(Produto), n, fp);
    fclose(fp);
    *p_n = n;
    return 1;
}
void exibir_produtos_bin(char *nome_arquivo){
    //leitura
    printf("AAAAAA");
    FILE *fp = fopen(nome_arquivo, "rb");
    printf("BBBBBB");
    if(!fp) { // !(NULL)
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        return;
    }
    printf("CCCCCC");
    //operacoes de leitura
    Produto *prd;
    printf("DDDDDD");
    int n; // numero de elementos a serem lidos
    if(fread(&n, sizeof(int), 1, fp) != 1 ) return;
    n = fread(&n, sizeof(int), 1, fp);
    for(int i = 0; i < n; i++) {
        printf("Nome: %s\nCategoria: %s\nValor: %.2f\n\n", prd[i].nome, prd[i].categoria, prd[i].valor);
    }
    // while(fread(&prd, sizeof(Produto), 1, fp) == 1){
    //     printf("Nome: %s\nCategoria: %s\nValor: %.2f\n\n", prd.nome, prd.categoria, prd.valor);
    // }
    fclose(fp);
}
Produto *carregar_produtos_bin(char *nome_arquivo, int *p_n){
    //leitura
    FILE *fp = fopen(nome_arquivo, "rb");
    if(!fp) { // !(NULL)
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        return NULL;
    }
    //operacoes de leitura
    int n; // numero de elementos a serem lidos
    if(fread(&n, sizeof(int), 1, fp) != 1 ) return NULL;
    if(n <= 0) return NULL;
    Produto *p_produtos = malloc(sizeof(Produto)*n);
    if(p_produtos == NULL) return NULL;
    
    fread(p_produtos, sizeof(Produto), n, fp);
    fclose(fp);
};

int salvar_produtos_txt(char *nome_arquivo, int n, Produto *produtos) {
    FILE *fp = fopen(nome_arquivo, "w");
    if(!fp) { // !(NULL)
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        return 0;
    }
    //operacoes de escrita
    for(int i = 0; i < n; i++) {
        fprintf(fp, "%s\t%s\t%f\n", produtos[i].nome, produtos[i].categoria, produtos[i].valor);
    }
    fclose(fp);
    return 1;
}
void exibir_produtos_txt(char *nome_arquivo){
    //leitura
    FILE *fp = fopen(nome_arquivo, "r");
    if(!fp) { // !(NULL)
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        return;
    }
    //operacoes de leitura
    Produto prd;
    while(fscanf(fp, "%s[^\t]%s[^\t]%f*c", &prd) != EOF){
        printf("Nome: %s\nCategoria: %s\nValor: %.2f\n\n", prd.nome, prd.categoria, prd.valor);
    }
    fclose(fp);
}
int main() {
    if(!salvar_produtos_bin("./produtos.dat", 20, produtos)) return 1;
    exibir_produtos_bin("./produtos.dat");
    int n;
    Produto *vet_produtos = carregar_produtos_bin("./produtos.dat", &n);
    for(int i = 0; i < n; i++){
        printf("Nome: %s\nCategoria: %s\nValor: %.2f\n\n", vet_produtos->nome, vet_produtos->categoria, vet_produtos->valor);       
    }
    if(!salvar_produtos_txt("./produtos.txt", 20, produtos)) return 1;
    exibir_produtos_txt("./produtos.txt");
    return 0;
}
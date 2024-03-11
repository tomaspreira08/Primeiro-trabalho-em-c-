#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Material {
    string nome;
    int estoque;
    float preco;
    int vendidos;
};

int main() {
    map<int, Material> materiais;
    float lucroTotal = 0.0;

    // Inicializando os materiais
    materiais[1] = {"Caderno", 10, 5.0, 0};
    materiais[2] = {"Caneta", 20, 1.5, 0};
    materiais[3] = {"Afia", 15, 0.75, 0};
    materiais[4] = {"Borracha", 30, 0.5, 0};
    materiais[5] = {"Lápis", 25, 0.8, 0};

    int opcao;
    while (true) {
        cout << "Escolha uma opção:" << endl;
        cout << "1. Vender produto" << endl ;
        cout << "2. Mostrar estoque" << endl ;
        cout << "3. Mostrar lucro total" << endl ;
        cout << "4. Comprar produto para repor estoque" << endl;
        cout << "5. Sair" << endl;
        cout << "Opção: ";
        cin >> opcao;
        cout << endl;

        if (opcao == 1) {
            int codigo, quantidade;
            for (const auto& par : materiais) {
                cout << "Código: " << par.first << ", Nome: " << par.second.nome << ", Estoque: " << par.second.estoque << ", Preço: € " << par.second.preco << ", Vendidos: " << par.second.vendidos << endl;
            }
            cout << endl << "Digite o código do material que deseja vender: ";
            cin >> codigo;
            cout << endl;

            if (materiais.find(codigo) != materiais.end()) {
                cout << "Digite a quantidade que deseja vender: ";
                cin >> quantidade;
                cout << endl;

                if (quantidade > 0 && quantidade <= materiais[codigo].estoque) {
                    materiais[codigo].estoque -= quantidade;
                    materiais[codigo].vendidos += quantidade;
                    float total = quantidade * materiais[codigo].preco;
                    lucroTotal += total;
                    cout << "Venda realizada. Total: € " << total << endl << endl;
                } else {
                    cout << "Quantidade inválida ou insuficiente em estoque." << endl << endl;
                }
            } else {
                cout << "Código de material inválido." << endl << endl;
            }
        } else if (opcao == 2) {
            cout << "Estoque disponível:" << endl;
            for (const auto& par : materiais) {
                cout << "Código: " << par.first << ", Nome: " << par.second.nome << ", Estoque: " << par.second.estoque << ", Preço: € " << par.second.preco << ", Vendidos: " << par.second.vendidos << endl;
            }
            cout << endl;
        } else if (opcao == 3) {
            cout << "Lucro total: € " << lucroTotal << endl << endl;
        } else if (opcao == 4) {
            int codigo, quantidade;
            for (const auto& par : materiais) {
                cout << "Código: " << par.first << ", Nome: " << par.second.nome << ", Estoque: " << par.second.estoque << ", Preço: € " << par.second.preco << ", Vendidos: " << par.second.vendidos << endl;
            }
            cout << endl << "Digite o código do material que deseja comprar para repor o estoque: ";
            cin >> codigo;
            cout << endl;

            if (materiais.find(codigo) != materiais.end()) {
                cout << "Digite a quantidade que deseja comprar: ";
                cin >> quantidade;
                cout << endl;

                if (quantidade > 0) {
                    materiais[codigo].estoque += quantidade;
                    float total = quantidade * materiais[codigo].preco;
                    lucroTotal -= total; // Deduzindo o custo da compra do lucro total
                    cout << "Compra realizada. Total: € " << total << endl << endl;
                } else {
                    cout << "Quantidade inválida." << endl << endl;
                }
            } else {
                cout << "Código de material inválido." << endl << endl;
            }
        } else if (opcao == 5) {
            cout << "Saindo do programa." << endl << endl;
            break;
        } else {
            cout << "Opção inválida. Tente novamente." << endl << endl;
        }
    }

    return 0;
}

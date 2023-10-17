#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Usuario { //função finalizada
public:
    string cpf, nome, endereco, telefone;
    Usuario(string _cpf,
    string _nome,
    string _endereco,
    string _telefone) {
        cpf = _cpf;
        nome = _nome;
        endereco = _endereco;
        telefone = _telefone;
    };
};

class Data{ //função finalizada
public: 
    int dia, mes, ano;
    Data () : dia(0), mes(0), ano(0){}
    Data (int dia, int mes, int ano) : dia(dia), mes(mes), ano(ano){}

    bool operator<(const Data& outraData) const {
        if (ano < outraData.ano)
            return true;
        if (ano == outraData.ano && mes < outraData.mes)
            return true;
        if (ano == outraData.ano && mes == outraData.mes && dia < outraData.dia)
            return true;
        return false;
    }

    bool operator>(const Data& outraData) const {
        return !(*this < outraData) && !(*this == outraData);
    }

    bool operator==(const Data& outraData) const {
        return dia == outraData.dia && mes == outraData.mes && ano == outraData.ano;
    }
};

class Veiculo{ //classefinalizada  
public:
    string identificador, marca, modelo;
    int anoFabricacao;
    float precoDia;
    bool disponivel;

    Veiculo(string _identificador,
    string _marca,
    string _modelo,
    int _anoFabricacao,
    float _precoDia) : identificador(identificador), marca(marca), modelo(modelo), anoFabricacao(anoFabricacao), precoDia(precoDia), disponivel(true){}
};

class Aluguel;

class Cliente : public Usuario{
public:
    string habilitacao;
    Cliente(string _cpf,
        string _nome,
        string _endereco,
        string _telefone,
        string _habilitacao) : Usuario(_cpf,_nome, _endereco,_telefone){
        habilitacao = _habilitacao;
    };
    vector<Aluguel> historicoAlugueis;

    float cota_aluguel(Veiculo _veiculo, Data _datainicio, Data _datafim){

            int numDias = (_datafim.ano - _datainicio.ano) * 365 + (_datafim.mes - _datainicio.mes) * 30 + (_datafim.dia - _datainicio.dia);
            float custoBase = numDias * _veiculo.precoDia;
            custoBase -= (custoBase * desconto / 100); 
    
        return custoBase;
    }

    bool Cliente::verificarDisponibilidadeVeiculo(const Veiculo& veiculo, const Data& inicio, const Data& termino) {
                for (const Aluguel& aluguel : historicoAlugueis) {
                    if (aluguel.veiculo.marca == veiculo.marca && aluguel.veiculo.modelo == veiculo.modelo) {
                        if (!(aluguel.dataTermino < inicio || aluguel.dataInicio > termino)) {
                        return false;
                        }
                    }
                }
                return true;
            };  

    Aluguel solicitar_aluguel(Veiculo _veiculo, Data _datainicio, Data _datafim){

             
        if (!verificarDisponibilidadeVeiculo(_veiculo, _datainicio, _datafim)) {
            cout << "Veículo não disponível para o período desejado." << endl;
            return;
        }

        int numeroDias = calcularNumeroDias(_datainicio, _datafim);
        float valorTotal = numeroDias * veiculo.precoDia;
        valorTotal -= (valorTotal * desconto) / 100.0;

        Aluguel aluguelConf (veiculo, _datainicio, _datafim, desconto);
       
        _veiculo.disponivel = false;
        
        historicoAlugueis.push_back(aluguelConf);

        cout << "Aluguel solicitado com sucesso:" << endl;
        cout << "Veículo: " << veiculo.marca << " " << veiculo.modelo << endl;
        cout << "Período: " << _datainicio.dia << "/" << _datainicio.mes << "/" << _datainicio.ano
                  << " - " << _datafim.dia << "/" << _datafim.mes << "/" << _datafim.ano << endl;
        cout << "Valor Total: $" << valorTotal << endl;
    };

    Aluguel Cliente::solicitar_fim_aluguel (Aluguel _aluguel, Data _datadevolucao){
        
        bool aluguelPertenceAoCliente = false;
        for (const Aluguel& alug : historicoAlugueis) {
            if (alug == _aluguel) {
            aluguelPertenceAoCliente = true;
            break;
            }
        }

        if (!aluguelPertenceAoCliente) {
        cout << "Este aluguel não pertence a este cliente." << endl;
        return;
        }

        if (dataDevolucao < _aluguel.dataInicio || dataDevolucao > _aluguel.dataTermino) {
        cout << "A data de devolução não está dentro do período do aluguel." << endl;
        return;
        }

        _aluguel.dataDevolucao = dataDevolucao;
        _aluguel.finalizado = true;
        _aluguel.veiculo.disponivel = true;

        cout << "Aluguel finalizado com sucesso." << endl;

        return _aluguel;     
    }
};

class Funcionario : public Usuario, Aluguel {
public:
    string matricula;
    vector<Aluguel> historicoAlugueis;
    vector<Cliente> listaDeClientes;

    Funcionario(string _cpf,
            string _nome,
            string _endereco,
            string _telefone,
            string _matricula) : Usuario(_cpf,_nome,_endereco,_telefone){
                matricula = _matricula;
            };
    Cliente cadastrarCliente(string _cpf,
                    string _nome,
                    string _endereco,
                    string _telefone,
                    string _habilitacao){
            Cliente novoCliente(_cpf, _nome, _endereco, _telefone, _habilitacao);
            listaDeClientes.push_back(novoCliente);
            return novoCliente;
    }
    
    Cliente editarCliente(string _cpf, string _novoNome, string _novoEndereco, string _novoTelefone, string _novaHabilitacao) {
        for (Cliente& cliente : listaDeClientes) {
            if (cliente.cpf() == _cpf) {
                cliente.nome(_novoNome);
                cliente.endereco(_novoEndereco);
                cliente.telefone(_novoTelefone);
                cliente.habilitacao(_novaHabilitacao);
                return; 
            }
        }
    }

    Cliente excluirCliente(string _cpf,
                    string _nome,
                    string _endereco,
                    string _telefone,
                    string _habilitacao){
        Cliente excluirCliente(_novoCpf, _novoNome, _novoEndereco, _novoTelefone, _novaHabilitacao);
        return 0;
    }

};

class Aluguel { //classe finalizada
public:
    string identificador;
    Veiculo veiculo;
    Cliente cliente;
    Funcionario funcionario;
    Data dataInicio, dataTermino, dataDevolucao;
    float desconto = 0.3;
    float adicional, valorFinal;
    int precoDia;
    bool finalizado;

    Aluguel(string identificador,
        Veiculo veiculo, 
        Cliente cliente,
        Funcionario funcionario,
        Data inicio,
        Data termino,
        Data devolucao,
        float desconto,
        float adicional,
        float valorFinal,
        int precoDia,
        bool finalizado) : identificador(identificador), veiculo(veiculo), cliente(cliente), funcionario(funcionario), 
        dataInicio(inicio), dataTermino(termino), dataDevolucao(devolucao), desconto(0.3), adicional(0.0), valorFinal(0.0), precoDia(50), finalizado (true) {}

    void setDataAtual(){
        time_t tempoAtual;
        time(&tempoAtual);
        struct tm* tempoLocal = localtime(&tempoAtual);

        dataInicio.dia = tempoLocal->tm_mday;
        dataInicio.mes = tempoLocal->tm_mon + 1;
        dataInicio.ano = tempoLocal->tm_year + 1900;
    };

    int calcularNumeroDias(const Data& dataInicio, const Data& dataTermino) {
        
            tm inicio = {0};
            inicio.tm_year = dataInicio.ano - 1900; 
            inicio.tm_mon = dataInicio.mes - 1;   
            inicio.tm_mday = dataInicio.dia;

            tm termino = {0};
            termino.tm_year = dataTermino.ano - 1900;
            termino.tm_mon = dataTermino.mes - 1;
            termino.tm_mday = dataTermino.dia;

            time_t timestampInicio = mktime(&inicio);
            time_t timestampTermino = mktime(&termino);
            time_t diferencaSegundos = timestampTermino - timestampInicio;

        int diferencaDias = diferencaSegundos / (24 * 60 * 60);

        return diferencaDias;
    }
    
    void calcularValorFinal (){
        
        int numeroDias = calcularNumeroDias(dataInicio, dataTermino);
        float valorSemDesconto = veiculo.precoDia * numeroDias;
        float valorComDesconto = valorSemDesconto - desconto;
        
        valorFinal = valorComDesconto + adicional;
    }    

    bool operator==(const Aluguel& outroAluguel) const {
        return this->identificador == outroAluguel.identificador;
    }
};


#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <unordered_map>
#include <mutex>
#include <string>
std::size_t Bruno(const std::size_t& motivacao) { return (4 + motivacao)%10; }
std::size_t Maria(const std::size_t& motivacao) { return (6 + motivacao) % 7; }
std::size_t Roberto(const std::size_t& motivacao) { return (1 + motivacao) % 17; }
std::size_t Ana(const std::size_t& motivacao) { return (7+ motivacao) % 14; }
std::size_t Fred(const std::size_t& motivacao) { return (1 + motivacao) % 19; }


void RefreshCache(std::unordered_map<std::string, std::size_t>& funcionarios) {
	std::size_t(*ptr[])(const std::size_t&) {
		Bruno,
			Maria,
			Roberto,
			Ana,
			Fred
	};
	std::unordered_map<std::string, std::size_t> identificacao{
		{"Bruno", 0},
		{ "Maria",1 },
		{ "Roberto",2 },
		{ "Ana",3 },
		{ "Fred",4 }
	};
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 4);
	while (true)
		for (auto& it : funcionarios) {
			it.second += ptr[identificacao[it.first]](dis(gen));
			std::this_thread::sleep_for(std::chrono::seconds(3));
		}
}




int main() {

	std::unordered_map<std::string, std::size_t> funcionarios{
		{"Bruno", 0},
		{ "Maria",0 },
		{ "Roberto",0 },
		{ "Ana",0 },
		{ "Fred",0 }
	};
	std::unordered_map<std::string, std::size_t>::iterator it;
	std::thread atualizador{RefreshCache, std::ref(funcionarios)};
	atualizador.detach();
	int menu{};
	std::string funcionario;
	while (true) {
		std::cout << "--BEM VINDO AO GERENCIAMENTO DA EMPRESA SEI LA CORP--\n\n"
			<< "Nossos funcionarios estao trabalhando agora...\n\n"
			<< "O que deseja fazer?\n"
			<< "0 - sair\n"
			<< "1 - checar funcionario\n"
			<< "2 - checar todos os funcionarios\n";

		std::cin >> menu;
		switch (menu) {
		case 1:
#if _WIN32
			system("cls");
#else
			system("clear");
#endif
			std::cout << "qual funcionario voce quer analisar a produtividade?\n\n"
				<< "- Bruno\n"
				<< "- Maria\n"
				<< "- Roberto\n"
				<< "- Ana\n"
				<< "- Fred\n\ninput: ";
			std::cin >> funcionario;
			it=funcionarios.find(funcionario);

			if (it == funcionarios.end()) {
				std::cout << "Funcionario nao encontrado no nosso banco de dados.\n\n";
				break;
			}

			std::cout << "A producao desse funcionario e de " << funcionarios[funcionario] << " lagrimas choradas por falta de salario hoje\n\n";
			break;
		case 2:
#if _WIN32
			system("cls");
#else
			system("clear");
#endif
			std::cout << "As lagrimas choradas por falta de salario de cada funcionario e de \n\n"
				<< "- BRUNO : " << funcionarios["Bruno"] << "\n"
				<< "- MARIA : " << funcionarios["Maria"] << "\n"
				<< "- ROBERTO : " << funcionarios["Roberto"] << "\n"
				<< "- ANA : " << funcionarios["Ana"] << "\n"
				<< "FRED : " << funcionarios["Fred"] << "\n\n";
			break;
		case 0:
			return 0;
			break;
		default:
			std::cout << "Opcao invalida\n\n";
			break;
		}
	}
	return 0;
}
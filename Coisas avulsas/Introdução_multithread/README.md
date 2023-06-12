``Supervisionador de produção``

Neste código eu quis aprender o conceito de multi-threading e fiz uma situação bem simples, você checa a "produtividade" de um determinado funcionário enquanto ele continua a trabalhar, esse "índice" de trabalho atua em background enquanto uma thread está fazendo o levantamento do trabalho de cada um

``Neste código, usei``

-std::thread
-std::unordered_map
-std::chrono
-std::random

``std::thread``

-Basicamente você invoca uma thread de seu computador que vá realizar uma determinada tarefa, não usei thread.join() pois ela vai atuar em background e não em primeiro plano até que seja concluída. 

``std::unordered_map``

-Para fazermos a lista de funcionários ativos e suas referentes produções. Dada por std::unordered_map<std::string,std::size_t>

``std::random``

-Utilizei o random para fazer um número aleatório a ser gerado no cálculo da respectiva produtividade de um funcionário e para sortear qual funcionário terá seu índice atualizado.

``std::chrono``

-Utilizei o chrono pois há uma espera para ser atualizado a produtividade de um funcionário, fiz isso juntamente com std::thread. Ficando:
std::this_thread::sleep_for(std::chrono::seconds(5));
Se eu não utilizasse uma pausa, a produtividade de cada funcionário cresceria rápido demais
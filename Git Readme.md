# Trabalho1-MP
Primeiro trabalho da disciplina de métodos de programação

O trabalho consiste em testes da regra do jogo da velha.
As regras deste jogo da velha estão em:
http://portaldoprofessor.mec.gov.br/fichaTecnicaAula.html?aula=28141

Para execução dos testes: 

Com o g++ e o make instalado 

Para a execução do programa, copie o seguinte comando e cole no terminal 
make && ./testa_velha.exe && make gcov


Make foi utilizado para compilar o programa;
o ./testa_velha.exe para rodar o programa;
o make gcov para criar um arquivo .gcov com anotações.

Foi utilizado o cpplint para organizar o código
ex: cpplint ./testa_velha.cpp
nos arquivos .cpp e .hpp

F testada a memória com 
make valgrind
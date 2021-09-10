/**
 * \file  velha.cpp
 * Copyright 2021 Fernando Jorge Santos Melo
 */


#include "velha.hpp"

/** 
 * @brief verifica situacao do jogo da velha  
 * @author Programador 
 * @param  velha é uma matriz com 3 linhas e 3 colunas que espera receber valores 0, 1 ou 2, 
 * sendo o 1 ou 2 o preenchimento escolhido pelo jogador no jogo (x ou bola) e o 0 um espaço vazio
 * 
 * A função VerificaVelha  confere se o jogo da velha criado é possível e quem será seu ganhador.
 * Caso esteja incompleto (com 0), retornará um valor -1, criado para esta situação específica.
 * Mas caso o jogo tenha alguma situação fora do real, como um valor fora de 1 ou 2, caso um jogador tenha
 * um número ilegal de jogadas, retornará -2.
 * Caso o jogador 1 ganhe, retornará 1, caso o jogador 2 ganhe, retornará 2, e caso empate, retornará 0
 */ 

int VerificaVelha( int velha[3][3] ) {
    // Definindo as variáveis de todos os campos da matriz
	//
    // Primeira linha
	int a = velha[0][0];
    int b = velha[0][1];
    int c = velha[0][2];
	// Segunda linha
    int d = velha[1][0];
    int e = velha[1][1];
    int f = velha[1][2];
	// Terceira linha
    int g = velha[2][0];
    int h = velha[2][1];
    int i = velha[2][2];

	// Marcando contadores, para a primeira e a segunda jogadas
    int first_count = 0;
    int second_count = 0;

	// Guardando o winner da partida 
	int winner = 0;

	// Contando a quantidades de numeros 1 e 2, com loop para verificar as linhas e cada coluna dentro daquelas linhas
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (velha[i][j] == 1) {
                // Atualiza o contador de 1 se for encontrado um número 1
                first_count++;
            } else if (velha[i][j] == 2) {
                // Atualiza o contador de 2 se for encontrado um número 2
                second_count++;
            } else if (velha[i][j] != 0) {
                // Verifica existência de valor inválido e retorna -2, que será nossa forma de verificar.
                return -2;
            }
        }
    }

	// Conferindo se o jogo é invalido
    if (first_count > (second_count + 1) || second_count > (first_count + 1)) {
        // Se existir uma quantidade inválida de 1 ou 2, retorna -2, para verificar que é inválido.
        return -2;
    }

	 /* Para conferir se o ganhador foi o primeiro jogador */

    if (first_count >= 3) {
		
		/* Vencendo pelas linhas */

		if ((a == b && b == c && a == 1) || (d == e && e == f && d == 1) || (g == h && h == i && g == 1)) {
			winner = 1;
		} 
		
		/* Vencendo pelas colunas */

		else if ((a == d && d == g && a == 1) || (b == e && e == h && b == 1) || (c == f && f == i && c == 1)) {
			winner = 1;
		}

		/* Vencendo pelas diagonais */
		
		else if ((a == e && e == i && a == 1) || (c == e && e == g && c == 1)) {
			winner = 1;
		}
	}

	 /* Para conferir se o ganhador foi o segundo jogador */

	if (second_count >= 3) {
		
		/* Vencendo pelas linhas */

		if (a == b && b == c && a == 2) {
			// Se o primeiro já tiver "ganhado", não faz sentido ter um segundo ganhador. Retorna inválido
			if (winner == 1) {
				return -2;
			}
			winner = 2;
		} 
		else if (d == e && e == f && d == 2) {
			// Se o primeiro já tiver "ganhado", não faz sentido ter um segundo ganhador. Retorna inválido
			if (winner == 1) {
				return -2;
			}
			winner = 2;
		}
		else if (g == h && h == i && g == 2) {
			// Se o primeiro já tiver "ganhado", não faz sentido ter um segundo ganhador. Retorna inválido
			if (winner == 1) {
				return -2;
			}
			winner = 2;
		}
		
		/* Vencendo pelas colunas */

		else if (a == d && d == g && a == 2){
			// Se o primeiro já tiver "ganhado", não faz sentido ter um segundo ganhador. Retorna inválido
			if (winner == 1) {
				return -2;
			}
			winner = 2;
		} 
		else if (b == e && e == h && b == 2) {
			// Se o primeiro já tiver "ganhado", não faz sentido ter um segundo ganhador. Retorna inválido
			if (winner == 1) {
				return -2;
			}
			winner = 2;
		} 
		else if (c == f && f == i && c == 2) {
			// Se o primeiro já tiver "ganhado", não faz sentido ter um segundo ganhador. Retorna inválido
			if (winner == 1) {
				return -2;
			}
			winner = 2;
		}
		/* Vencendo pelas diagonais */
		else if (a == e && e == i && a == 2) {
			// Se o primeiro já tiver "ganhado", não faz sentido ter um segundo ganhador. Retorna inválido
			if (winner == 1) {
				return -2;
			}
			winner = 2;
		}
		else if (c == e && e == g && c == 2) {
			// Se o primeiro já tiver "ganhado", não faz sentido ter um segundo ganhador. Retorna inválido
			if (winner == 1) {
				return -2;
			}
			winner = 2;
		}
	}

	// Verifica se deu velha
    if (winner != 1 && winner != 2) {
		if (first_count + second_count == 9) {
    	    winner = 0;
    	} else if (first_count + second_count != 9) {  // Verifica se o jogo não foi finalizado
    	    winner = -1;
		}
	}
	return winner; /*!< retorna quem foi o vencedor */
}



#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void print_board(uint64_t board){
	printf("┏");
	for (int i = 0; i < 8; i++){printf("━━");}
	printf("━┓\n");
	for (int i = 0; i < 8; i++){
		printf("┃ ");
		for (int j = 0; j < 8; j++){
			if (board & (uint64_t)1 << (i*8+j)){
				printf("# ");
				continue;
			}
			printf(". ");
		}
		printf("┃\n");
	}
	printf("┗");
	for (int i = 0; i < 8; i++){printf("━━");}
	printf("━┛\n");
}

uint64_t get_queen_bitmask(uint64_t board, int idx){
	uint64_t col_mask = 0;
	uint64_t diag_mask_top = 0;
	uint64_t diag_mask_btm = 0;

	div_t rc = div(idx, 8);

	uint64_t row_mask = (((uint64_t)1 << 8) - 1) << ((rc.quot)*8);
	for (int i = 0; i < 8; i++){
		int rv = i*8+rc.rem;
		int diagonal_length = abs(rc.quot - i);

		col_mask |= (uint64_t)1 << (rv);
		if (rv + diagonal_length < (i+1)*8)
			diag_mask_btm |= ((uint64_t)1 << (rv + diagonal_length));
		if (i * 8 <= rv - diagonal_length)
			diag_mask_top |= ((uint64_t)1 << (rv - diagonal_length));
	}

	return(row_mask|col_mask|diag_mask_btm|diag_mask_top);
}

int main(int argc, char *argv[]){
	for (int i = 0; i < 64; i++){
		print_board(get_queen_bitmask((uint64_t)0, i));
	}
}

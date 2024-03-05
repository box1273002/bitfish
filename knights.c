#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void print_board(int n, uint64_t board){
	printf("┏");
	for (int i = 0; i < n; i++){printf("━━");}
	printf("━┓\n");
	for (int i = 0; i < n; i++){
		printf("┃ ");
		for (int j = 0; j < n; j++){
			if (board & (uint64_t)1 << (i*n+j)){
				printf("# ");
				continue;
			}
			printf(". ");
		}
		printf("┃\n");
	}
	printf("┗");
	for (int i = 0; i < n; i++){printf("━━");}
	printf("━┛\n");
}

int main() {
  int loc = 10;
  uint64_t mask = (uint64_t)1 << loc;

  for (int x = 0;x < 4;x++) {
    int row = 1 ^ (x % 2) - 2 * ((1 ^(x/2)) & (1 ^ (x%2)));
    int col = x % 2 - 2 * ((1 ^ (x / 2)) & (x % 2));
    mask |= (uint64_t)1 << loc + (row * 16 + col * 2) - (((abs(row) ^ 1) * 8) + (abs(col) ^ 1));
    mask |= (uint64_t)1 << loc + (row * 16 + col * 2) + (((abs(row) ^ 1) * 8) + (abs(col) ^ 1));
  }
    print_board(8, mask);

}

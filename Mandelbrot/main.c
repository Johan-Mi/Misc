#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define MAX_ITER 1000
#define WIDTH ((uint32_t)1366)
#define HEIGHT ((uint32_t)1366)
#define FILL_COLOR 0xffff000000000000
#define BLANK_COLOR 0xffffffffffffffff

int main(void) {
	uint32_t i, j;
	uint64_t* pic;
	FILE* fp;

	pic = (uint64_t*)malloc(WIDTH * HEIGHT * sizeof(uint64_t));

	for(i = 0; i < HEIGHT; i++) {
		for(j = 0; j < WIDTH; j++) {
			long double x = j * 4.0l / WIDTH - 2;
			long double y = i * 4.0l / HEIGHT - 2;
			long double const x2 = x;
			long double const y2 = y;
			size_t iter;

			for(iter = 0; iter < MAX_ITER && x * x + y * y < 2.0l; iter++) {
				long double const x3 = x * x - y * y + x2;
				y = 2 * x * y + y2;
				x = x3;
			}

			pic[i * WIDTH + j] = iter == MAX_ITER ? FILL_COLOR : BLANK_COLOR ;
		}
	}

	fp = fopen("pic.ff", "wb");
	if(!fp) {
		free(pic);
		perror("File opening failed");
		return EXIT_FAILURE;
	}

	fputs("farbfeld", fp);
	fputc((WIDTH >> 24) & 0xff, fp);
	fputc((WIDTH >> 16) & 0xff, fp);
	fputc((WIDTH >> 8) & 0xff, fp);
	fputc(WIDTH & 0xff, fp);
	fputc((HEIGHT >> 24) & 0xff, fp);
	fputc((HEIGHT >> 16) & 0xff, fp);
	fputc((HEIGHT >> 8) & 0xff, fp);
	fputc(HEIGHT & 0xff, fp);
	fwrite(pic, sizeof(pic[0]), WIDTH * HEIGHT, fp);
	fclose(fp);

	free(pic);

	system("ff2png < pic.ff > pic.png; rm pic.ff");

	return EXIT_SUCCESS;
}

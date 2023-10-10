#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FILENAME "new-file.txt"
#define FILENAME1 "new-file1.txt"
#define FILENAME2 "new-file2.txt"

void filter_write(const char *message, FILE *file);
bool same_content(FILE *f1, FILE *f2);


int main(void) {

	const char *message = "Questo e' un messaggio lungo!\nE anche in due linee\t";
	printf("%s\n", message);

	FILE *f = fopen(FILENAME, "w");
	FILE *f1 = fopen(FILENAME1, "w");
	FILE *f2 = fopen(FILENAME2, "w");
	if (f == NULL || f1 == NULL || f2 == NULL) return 1;

	// Test write
	filter_write(message, f);

	// Now write two other files
	filter_write(message, f1);
	const char *message1 = "Questo e' un messaggio diverso";
	filter_write(message1, f2);

	// Close files and reopen. Or..go to the beginning
	fclose(f);
	fclose(f1);
	fclose(f2);
	FILE *ff = fopen(FILENAME, "r");
	FILE *ff1 = fopen(FILENAME1, "r");
	FILE *ff2 = fopen(FILENAME2, "r");
	// fseek(f, 0, SEEK_SET);
	// fseek(f1, 0, SEEK_SET);
	// fseek(f2, 0, SEEK_SET);

	// Test same_content
	bool test1 = same_content(ff, ff1);
	bool test2 = same_content(ff, ff2);
	printf("This should be equal: %s\n", test1? "equal": "different");
	printf("This should not be equal: %s\n", test2? "equal": "different");
}

void filter_write(const char *message, FILE *file) {
	if (*message == '\0') return;
	if (*message >= 'a' && *message <= 'z') {
		int r = fputc(*message, file);
	}
	filter_write(message + 1, file);
}


bool same_content(FILE *f1, FILE *f2) {
	char c = fgetc(f1);
	if (c != fgetc(f2)) return false;
	if (c == EOF) return true;
	return same_content(f1, f2);
}

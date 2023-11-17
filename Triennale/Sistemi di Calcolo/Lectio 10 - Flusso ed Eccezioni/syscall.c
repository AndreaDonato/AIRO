#include <unistd.h>

void mywrite(int fd, const void* buffer, unsigned size);		// fd = file descriptor, 1 = stdout

int main(int argc, char const *argv[])
{
	write(1, "Hello\n", 6); 	// syscall standard write, 1 seleziona stdoutput, stringa da stampare e numero di caratteri della stringa
	mywrite(1, "Hello\n", 6);
	return 0;
}
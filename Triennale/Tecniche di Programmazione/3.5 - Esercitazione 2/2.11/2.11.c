#include <stdio.h>
#include <math.h>

int main() {
	
float sum = 0;
for (int i = 0; i < 10; ++i)
{sum += 0.1f;}
printf("\n\n\tsum vale %f", sum);
if(((int)(sum*10))/10.0 == 1.0f) printf("\n\tControllo corretto\n\n");
else printf("Controllo errato\n\n");
return 0;
}
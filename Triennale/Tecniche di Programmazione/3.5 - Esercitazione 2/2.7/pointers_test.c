#include <stdio.h>

int main() {

int a = 0, *pa, b = 0, *pb, *pa2;
long dist = 0;
pa = &a;
pa2 = &a;
pb = &b;
dist = &b - &a;
printf("\n\n\tVariable\tValue\t\tAddress\t\t\tPoints to...\t\t&var - pointer-to-var\n\n");
printf("\ta\t\t%d\t\t%p\n", a, &a);
printf("\t*pa\t\t%d\t\t%p\t\t%p\t\t%d\n", *pa, &pa, pa, (int)((long long int)pa-(long long int)&a));
printf("\tb\t\t%d\t\t%p\n", b, &b);
printf("\t*pb\t\t%d\t\t%p\t\t%p\t\t%d\n", *pb, &pb, pb, (int)(&b-pb));
printf("\tdist\t\t%ld\t\t%p\n", dist, &dist);

printf("\n\n\tAndrea sei un coglione :)\n\n");
return 0;

}

#include <stdarg.h>

// 6.1
float product(float vec[], int n)
{
	float m;
	if (n == 0) return 1;
	else
	{	
		n--;
		m = vec[n];
		return m*product(vec, n);
	}
}

// 6.2
void vec_integral(float *v, int n)
{
	if(n != 0)
	{	
		n--;
		v[n] = 0;
		for(int i = 0; i < n; i++) v[n] += v[i];  
		vec_integral(v, n);
	}
}
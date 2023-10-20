#include <stdio.h>
#include <stdarg.h>

double get_average(size_t nums_count, ...) {
	va_list valist;
	va_start(valist, nums_count);

	double sum = 0.0;

}

void d_and_i() {
	printf("%d\n", 033);
	printf("%i\n", 033);
}

int main() {
	d_and_i(); return 0;

	double a = 13.37, b = 12.34, c = 98.76;

	printf("Average = %lf\n", get_average(a, b, c));
}
#include <stdio.h>
#include <stdarg.h>

double get_average(size_t nums_count, ...) {
	va_list valist;
	va_start(valist, nums_count);

	double sum = 0.0;
	for (size_t i = 0; i < nums_count; ++i) {
		sum += va_arg(valist, double);
	}
	va_end(valist);
	return sum / nums_count;
}

void d_and_i() {
	printf("--------------------\n");
	printf("d and i tests\n");
	printf("010 with d = %d\n", 010);
	printf("010 with i = %i\n", 010);
	printf("--------------------\n");
}

void u() {
	printf("--------------------\n");
	printf("u tests\n");
	printf("-1 with u = %u\n", -1);
	printf("-10 with u = %u\n", -10);
	printf("-010 with u = %u\n", -010);
	printf("-0x10 with u = %u\n", -0x10);
	printf("--------------------\n");
}

int main() {
	// d_and_i();
	// u();


	double a = 13.37, b = 12.34, c = 98.76;

	printf("Average = %lf\n", get_average(3, a, b, c));
}
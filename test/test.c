#include <stdio.h>
#include "../ft_printf.h"

int main() {
	int ft_printed_count = 0;
	int real_printed_count = 0;
	char *ft_prefix = ""

	char *single_char_fmt = "[ FT ] Single char = %c\n";
	ft_printed_count = ft_printf(single_char_fmt, 'x');
	real_printed_count = printf(single_char_fmt, 'x');
	if (ft_printed_count != 16 || ft_printed_count != real_printed_count)
		printf("ERROR! Printed count expected = 16, real = %d, actual = %d\n", real_printed_count, ft_printed_count);

	char *s = "print me!";
	char *string_fmt = "[ FT ] String = %s\n";
	ft_printed_count = ft_printf(string_fmt, s);
	real_printed_count = printf(string_fmt, s);
	if (ft_printed_count != 16 || ft_printed_count != real_printed_count)
		printf("ERROR! Printed count expected = 16, real = %d, actual = %d\n", real_printed_count, ft_printed_count);

	void *ptr = 0xdeadbeaf;
	char *ptr_fmt = "[ FT ] Void ptr addr = %p\n";
	ft_printed_count = ft_printf(ptr_fmt, ptr);
	real_printed_count = printf(ptr_fmt, ptr);
	if (ft_printed_count != 16 || ft_printed_count != real_printed_count)
		printf("ERROR! Printed count expected = 16, real = %d, actual = %d\n", real_printed_count, ft_printed_count);

	int pos_num = 2147483647;
	char *pos_num_fmt = "[ FT ] Decimal positive number = %d\n";
	ft_printed_count = ft_printf(pos_num_fmt, pos_num);
	real_printed_count = printf(pos_num_fmt, pos_num);
	if (ft_printed_count != 16 || ft_printed_count != real_printed_count)
		printf("ERROR! Printed count expected = 16, real = %d, actual = %d\n", real_printed_count, ft_printed_count);

	int neg_num = -2147483648;
	ft_printed_count = ft_printf("[ FT ] Decimal negative number = %d\n", neg_num);
	real_printed_count = printf("[ FT ] Single char = %c\n", 'x');
	if (ft_printed_count != 16 || ft_printed_count != real_printed_count)
		printf("ERROR! Printed count expected = 16, real = %d, actual = %d\n", real_printed_count, ft_printed_count);

	int zero_num = 0;
	ft_printed_count = ft_printf("[ FT ] Decimal zero number = %d\n", zero_num);
	real_printed_count = printf("[ FT ] Single char = %c\n", 'x');
	if (ft_printed_count != 16 || ft_printed_count != real_printed_count)
		printf("ERROR! Printed count expected = 16, real = %d, actual = %d\n", real_printed_count, ft_printed_count);

	ft_printed_count = ft_printf("[ FT ] Decimal positive number = %i\n", pos_num);
	real_printed_count = printf("[ FT ] Single char = %c\n", 'x');
	if (ft_printed_count != 16 || ft_printed_count != real_printed_count)
		printf("ERROR! Printed count expected = 16, real = %d, actual = %d\n", real_printed_count, ft_printed_count);

	ft_printed_count = ft_printf("[ FT ] Decimal negative number = %i\n", neg_num);
	real_printed_count = printf("[ FT ] Single char = %c\n", 'x');
	if (ft_printed_count != 16 || ft_printed_count != real_printed_count)
		printf("ERROR! Printed count expected = 16, real = %d, actual = %d\n", real_printed_count, ft_printed_count);

	ft_printed_count = ft_printf("[ FT ] Decimal zero number = %i\n", zero_num);
	real_printed_count = printf("[ FT ] Single char = %c\n", 'x');
	if (ft_printed_count != 16 || ft_printed_count != real_printed_count)
		printf("ERROR! Printed count expected = 16, real = %d, actual = %d\n", real_printed_count, ft_printed_count);

	unsigned int uint_num = 4294967295;
	ft_printed_count = ft_printf("[ FT ] Unsigned number = %u\n", uint_num);
	real_printed_count = printf("[ FT ] Single char = %c\n", 'x');
	if (ft_printed_count != 16 || ft_printed_count != real_printed_count)
		printf("ERROR! Printed count expected = 16, real = %d, actual = %d\n", real_printed_count, ft_printed_count);

	unsigned int zero_uint_num = 0;
	ft_printed_count = ft_printf("[ FT ] Unsigned zero number = %u\n", zero_uint_num);
	real_printed_count = printf("[ FT ] Single char = %c\n", 'x');
	if (ft_printed_count != 16 || ft_printed_count != real_printed_count)
		printf("ERROR! Printed count expected = 16, real = %d, actual = %d\n", real_printed_count, ft_printed_count);

	unsigned int hex_num = 0xbadf00d;
	ft_printed_count = ft_printf("[ FT ] Hex lowercase number = %x\n", hex_num);
	real_printed_count = printf("[ FT ] Single char = %c\n", 'x');
	if (ft_printed_count != 16 || ft_printed_count != real_printed_count)
		printf("ERROR! Printed count expected = 16, real = %d, actual = %d\n", real_printed_count, ft_printed_count);

	ft_printed_count = ft_printf("[ FT ] Hex UPPERCASE number = %x\n", hex_num);
	real_printed_count = printf("[ FT ] Single char = %c\n", 'x');
	if (ft_printed_count != 16 || ft_printed_count != real_printed_count)
		printf("ERROR! Printed count expected = 16, real = %d, actual = %d\n", real_printed_count, ft_printed_count);

	ft_printed_count = ft_printf("[ FT ] Percentage sign (x3) = %%%%%%\n");
	real_printed_count = printf("[ FT ] Single char = %c\n", 'x');
	if (ft_printed_count != 16 || ft_printed_count != real_printed_count)
		printf("ERROR! Printed count expected = 16, real = %d, actual = %d\n", real_printed_count, ft_printed_count);
}

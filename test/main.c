#include <liblexer.h>

int 		test1(void);
int 		test2(void);
int 		test3(void);

int		main(void)
{
	printf("%s\n", (test1()) ? "OK" : "KO");
	printf("%s\n", (test2()) ? "OK" : "KO");
	printf("%s\n", (test3()) ? "OK" : "KO");
	return (0);
}

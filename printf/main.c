
#include "ft_printf.h"
#include <stdio.h>


int	main(void)
{
	void	*ptr;
	int		i;

	i = -1;
	ptr  = &i;
	unsigned int j = -1;
	ft_printf("my =%u\n",j);
	printf("def = %u", j);
}

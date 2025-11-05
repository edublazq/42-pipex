#include "inc/get_next_line/get_next_line.h"
#include "inc/Libft/libft.h"

int	main(void)
{
	int fd = open("outfile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	for (int i = 0; i < 5; i++)
		ft_putstr_fd(get_next_line(1), fd);
}

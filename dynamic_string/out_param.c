/* Level 3: creates the buffer and transfers it through the return value */
#include <stdlib.h>
#include <memory.h>

static char	*make_buf(size_t n)
{
	char	*buf;

	buf = malloc(n + 1);
	if (!buf)
		return (NULL);
	buf[n] = '\0';
	return (buf);
}

static int fill (char *buf, size_t n)
{
	size_t i = 0;

	if (!buf)
		return (-1);
	while (i < n)
	{
		buf[i] = 'a' + n % 26;
		++i;
	}
	return (i);
}

/* Level 2: owns buf temporarily and hands it over only on success */
static int	load(char **out, size_t n)
{
	char	*buf;

	if (!out)
		return (-1);
	*out = NULL;			/* the caller never sees a dangling or garbage value */
	buf = make_buf(n);
	if (!buf)
		return (-1);
	if (fill(buf, n) < 0)	/* fill() only borrows */
	{
		free(buf);			/* this level owns buf, so it cleans up */
		return (-1);
	}
	*out = buf;				/* transfer ownership */
	return (0);
}

/* Level 1: the final owner */
int	main(void)
{
	char	*data;

	if (load(&data, 42) < 0)
		return (1);
	//use(data);
	free(data);
	return (0);
}
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>

#include <time.h>
#include <stdio.h>//TODO: delete

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif

char	*use_preallocated (/*char **outstr,*/ char *buf)
{
	char	*fline;
	int		alen = 0;

	printf("\n[%s]:\n", __func__);
	printf("buf is local mem  = \t%p", &buf);
	printf("\n buf content = %p", buf);
	printf("\n *buf is deferenced of = %d", *buf);

	fline = buf;
	printf("\n &fline address = %p", &fline);
	printf("\n fline content = %p", fline);
	printf("\n *fline (dereferenced)= %c", *fline);
	printf("\n fline (string)= %s", fline);
	printf("\n");
	while ( alen < BUFFER_SIZE)
	{
		printf("%c", buf[alen]);
		fline[alen] += 1;
		++alen;
	}
	fline[alen -1] = '\0';

	while ( alen < BUFFER_SIZE)
	{
		printf("%c", fline[alen]);
		++alen;
	}

	printf("\n------------------------------------------\n");

	return fline;
}

char	*getbuf(void)
{

	char		*fline;;
	static char *next;

	printf("\n[%s]:\n", __func__);
	if(!(fline = (char *)malloc (BUFFER_SIZE * sizeof (char))))
		{
			printf ("NULL from malloc\n");
			return NULL;
		}
	memset(fline, 'A', BUFFER_SIZE);
	fline[BUFFER_SIZE -1 ] = '\0';
	printf("Local cstring address is %p\n"\
			"String content>\t%s"\
			"\nAddress of content  memory = %p", &fline, fline, &(*fline));
	next = use_preallocated(fline);
	printf("\n------------------------------------------\n");

	return next;
}

char	get_random_alpha(void)
{
	static int	seeded;
	char		c;

	if (!seeded)
	{
		srand(time(NULL));
		seeded = 1;
	}
	c = 'a' + (rand() % 26);
	if (rand() % 2)
		c -= 32;
	return (c);
}

char	*use_dynallocated(char **buf)
{
	char			*dynline;
	unsigned int 	cnt;

	printf("\n[%s]:\n", __func__);
	printf("buf is local mem with address $buf = \t%p", &buf);
	printf("\n buf content is an address = %p", buf);
	printf("\n *buf is deferenced of = %s", *buf);

	if(!(dynline = (char *) malloc (BUFFER_SIZE))) //
		return (NULL);

	cnt = 0;
	while (cnt < BUFFER_SIZE)
	{
		dynline[cnt] = get_random_alpha();
		++cnt;
	}
	dynline[cnt - 1] = '\0';

	printf("\n &dynline address = %p", &dynline);
	printf("\n dynline content = %p", dynline);
	printf("\n *dynline (dereferenced)= %c", *dynline);
	printf("\n dynline (string)= %s", dynline);

	*buf = dynline;
	printf("\n------------------------------------------\n");

	return (*buf);

}

char	*getdynbuf(void)
{

	char		*dyn_line;
	static char *next;

	printf("\n[%s]:\n", __func__);
	printf("Local string address is %p\n"\
		"String content>\t%s"\
		"\nAddress of content memory = %p", &dyn_line, dyn_line, &*dyn_line);
	next = use_dynallocated(&dyn_line);
	//next = dyn_line;
	printf("\n------------------------------------------\n");

	return next;
}

int	main()
{
	printf("TEST: Test ft_endline at the BUFFER_SIZE\'\\n'\n");
	{				//
		char *line;
		line = getbuf();

		printf("\nLine from getbuf():%s\n", line);

		line = getdynbuf();
		printf("\nLine from getdynbuf():%s\n", line);
	}
}
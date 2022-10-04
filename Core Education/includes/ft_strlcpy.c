

size_t strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;

	n = 0;
	size -= 1;
	while (src[n] && n < size)
	{
		dst[n] = src[n];
		n++;
	}
	dst[n] = '\0';
	return (n);
}

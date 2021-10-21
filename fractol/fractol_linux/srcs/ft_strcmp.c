char	ft_strcmp(const char *s1, const char *s2)
{
	const char unsigned	*c1;
	const char unsigned	*c2;

	c1 = (unsigned char *) s1;
	c2 = (unsigned char *) s2;
	while (*c1 || *c2)
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
		++c1;
		++c2;
	}
	return (0);
}

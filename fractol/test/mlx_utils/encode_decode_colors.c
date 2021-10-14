

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	//return ((trgb & (0xFF << 24));
	return (trgb >> 24);
}

int	get_r(int trgb)
{
	//return (trgb & (0xFF << 16));
	return ((trgb << 8) >> 24);
}

int	get_g(int trgb)
{
	//return (trgb & (0xFF << 8));
	return ((trgb << 16) >> 24);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}



int	get_opposite(int color)
{
	return (color ^ 0x00FFFFFF);
}

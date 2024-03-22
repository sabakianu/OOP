#include "math.h"
#include <cstring>
#include <cstdarg>

int Math::Add(int y, int z)
{
	return y + z;
}
int Math::Add(int y, int z, int t)
{
	return y + z + t;
}
int Math::Add(double y, double z)
{
	return y + z;
}
int Math::Add(double y, double z, double t)
{
	return y + z + t;
}
int Math::Mul(int y, int z)
{
	return y * z;
}
int Math::Mul(int y, int z, int t)
{
	return t * y * z;
}
int Math::Mul(double y, double z)
{
	return y * z;
}
int Math::Mul(double y, double z, double t)
{
	return y * z * t;
}
char* Math::Add(const char* y, const char* z)
{
	char* b;
	if (y == nullptr || z == nullptr)
	{
		return nullptr;
	}
	int m = strlen(y);
	if (strlen(z) > m)
		m = strlen(z);
	m++;
	b = new char[m];
	for (int i = 0; i < m; i++)
	{
		int c;
		c = int(y[i]) + int(z[i]);
		b[i] = char(c);
	}
	b[m] = NULL;
	return b;
}
int Math::Add(int count, ...)
{
	int x;
	x = 0;
	va_list arg;
	va_start(arg,count);
	for (int i = 0; i < count; i++)
		x = x + va_arg(arg, int);
	va_end(arg);
	return x;
}

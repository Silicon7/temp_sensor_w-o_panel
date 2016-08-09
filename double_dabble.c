#include "main.h"
char array[6];

int d_dabble(unsigned long  x)
{
	unsigned long  y;
	unsigned long  z;
	unsigned char a,b,c,d;
	char temp;
	int i;
	y = 0;
	z = 0;
	a =0;
	b=a=c;
	temp = 0;
	for(i=0; i<24 ; i++)
	{
		temp = x & 0x800000;
		x = x << 1;
		y = y << 1;
		y = y|temp;
		a = y&0xFF;
		b = (y&0xFF00UL)>>8;
		c = (y&0xFF0000UL)>>16;
		d = (y&0xFF000000UL)>>24;
		if(i<23)
		{
			a = check(a);
			b = check(b);
			c = check(c);
			d = check(d);
		}
		z = d;
		z = z<<8;
		z |= c;
		z = z<<8;
		z |=b;
		z = z<<8;
		z |= a;
		y = z;
		if(i==23)
		{
			array[5] = y&0xF;
			array[4] = (y&0xF0UL)>>4;
			array[3] = (y&0xF00UL)>>8;
			array[2] = (y&0xF000UL)>>12;
			array[1] = (y&0xF0000UL)>>16;
			array[0] = (y&0xF00000UL)>>20;
		}
	}
	
	return 27;
}

unsigned char check (unsigned char f)
{
	unsigned char upr , lwr , ret;
	lwr = f & 0x0F;
	upr = f & 0xF0;
	upr = upr >> 4;
	if(lwr >=5)
		lwr = lwr + 3;
	if(upr >=5)
		upr = upr+3;
	
	ret = lwr;
	upr = upr << 4;
	ret |= upr;
	
	return ret;
}
#include "Name.h"


Name :: Name(const char* f, const char* m, const char* l)
{
	copy(f,m,l);
}

Name Name :: readName(istream & in)
{
	cout << "first: ";
	char* x = read(in);
	cout << "\nmiddle: ";
	char* y = read(in);
	cout << "\nlast: ";
	char* z = read(in);
	Name b (x, y, z);
	return b;
}

char* Name:: read (istream& in)
	{
	const	long	GrowBy	(50);
	char	C;
	int max = 50;
	char*	n = new char[max];
	int len;
	len = 0;
	while (((C = in.get ()) != ' ')||(C != '\n'))
		{
		n [len++] = C;
		if (len == max)
				{
				char * pTemp;
				len += GrowBy;
				pTemp	= new char [max + 1];
				memcpy (pTemp, n, len);
				delete [] n;
				n = pTemp;
				}
			else;
		}
	n [len] = '\0';

	return n;
	}

char* Name :: copy(const Name n)
{
	
	first = new char[strlen(n.getFirst())];
	strcpy(first,n.getFirst());
	middle = new char[strlen(n.getMiddle())];
	strcpy(middle,n.getMiddle());
	last = new char[strlen(n.getLast())];
	strcpy(last,n.getLast());
}

char* Name :: copy(const char* f, const char* m, const char* l)
{
	first = new char[strlen(f)];
	strcpy(first,f);
	middle = new char[strlen(m)];
	strcpy(middle,m);
	last = new char[strlen(l)];
	strcpy(last,l);
}

int Name :: compareto(const Name& n)const
{
	int i;
	if((i = strcmpi(last,n.getLast()))!=0)
		return i;
	if((i = strcmpi(first,n.getFirst()))!=0)
		return i;
	if((i = strcmpi(middle,n.getMiddle()))!=0)
		return i;
	return 0;
}


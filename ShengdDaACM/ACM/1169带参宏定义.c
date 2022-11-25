#include <stdio.h>
#define SWAP(a, b, t) \
	{                 \
		t = a;        \
		a = b;        \
		b = t;        \
	}
int main()
{
	char a[3];
	int i, j, t;
	for (i = 0; i < 3; i++)
	{
		scanf("%c", &a[i]);
		if (a[i] == ' ')
			scanf("%c", &a[i]);
	}
	for (i = 0; i < 2; i++)
		for (j = 1; j < 3; j++)
			if (a[i] < a[j])
				SWAP(a[i], a[j], t);
	for (i = 0; i < 3; i++)
		printf("%c ", a[i]);
	return 0;
}

//Pedro Henrique de Paula Barbosa
//11811EAU012

#include <stdio.h>

int main()
{
	int estado = 0, i;
	char bits[256];
	printf("Insira a sequencia de bits: ");
	scanf("%s", bits);
	for(i=0;bits[i] !=  '\0'; i++)
	{
		if(estado==0&&bits[i]=='0')
		{
			estado = 0;
		}
		else if(estado==0&&bits[i]=='1')
		{
			estado = 1;
		}
		else if(estado==1&&bits[i]=='0')
		{
			estado = 2;
		}
		else if(estado==1&&bits[i]=='1')
		{
			estado = 0;
		}
		else if(estado==2&&bits[i]=='1')
		{
			estado = 2;
		}
		else if(estado==2&&bits[i]=='0')
		{
			estado = 1;
		}
	}
	printf("O valor da variavel e: %d", estado);
	printf("\nA sequecia original e: %s", bits);
	if(estado==0)
	{
		printf("\nE multiplo de 3");
	}
	else
	{
		printf("\nNao e");
	}
	return 0;
}

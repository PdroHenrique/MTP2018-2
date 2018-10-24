//Pedro Henrique de Paula Barbosa
//11811EAU012

#include <stdio.h>

int main()
{
	char num[256];
	int cum=0, i;
	printf("Insira um Numero: ");
	scanf("%s", num);
	for(i=0;num[i]!='\0';i++)
	{
		if(num[i] >= '0' && num[i]<= '9')
		{
			cum = (cum*10) + num[i] -48;
		}
		
	}
	printf("%d", cum);
	return 0;
}

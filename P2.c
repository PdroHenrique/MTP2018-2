//Pedro Henrique de Paula Barbosa	
//11811EAU012

#include <stdio.h>

void bintodec(char Bits[])
{
	int len, i, decimal=0, parcela, j;
	for(len=0;Bits[len]!='\0';len++);
	for(i=0;i<=len;i++)
	{
		if(Bits[len-i]=='1')
		{
			parcela=1;
			for(j=1;j<i;j++)
			parcela*=2;
			decimal+=parcela;
		}
	}
	printf("%d",decimal);
}

void bintohex(char bin[]){
	int caractere, len, posbin, poshex=0,q,parcela,j;
	for(len=0;bin[len]!='\0';len++);
	char hex[len/4];
	
	for(posbin=0;bin[posbin]!='\0';posbin+=4){
		caractere=0;
		for(q=posbin;q<posbin+4;q++)
		{
			parcela = 1;
			if(bin[q]=='1'){
			for(j=0;j<3-(q-posbin);j++)
			parcela*=2;
			caractere+=parcela;
			}
		}
		if(caractere<10)
		hex[poshex]=caractere+48;
		else
		hex[poshex]=caractere+55;
		poshex=q/4;

	}
	printf("%s",hex);
}

void hextodec(char shex[]){
	int len, dec=0, i, parcela, pot;
	for(len=0;shex[len]!='\0';len++);
	int hex[len];
	for(i=0;i<len;i++)
	{
		if(shex[i]>=48 && shex[i]<=57)
		hex[i]=shex[i]-48;
		if(shex[i]>=65 && shex[i]<=70)
		hex[i]=shex[i]-55;
		if(shex[i]>=97 && shex[i]<=102)
		hex[i] = shex[i]-87;
	}
	for(i=0;i<len;i++)
	{
		parcela=1;
		for(pot=0;pot<len-i-1;pot++)
		parcela*=16;
		dec+=parcela*hex[i];
	}
	printf("%d",dec);
}
void hextobin(char shex[256]){
	int len, primeiro;
	for(len=0;shex[len]!='\0';len++);
	int hex[len], i, j;
	int bin[len][4];
	for(i=0;i<len;i++)
	{
		if(shex[i]>=48 && shex[i]<=57)
		hex[i]=shex[i]-48;
		if(shex[i]>=65&&shex[i]<=70)
		hex[i]=shex[i]-55;
		if(shex[i]>=97 && shex[i]<=102)
		hex[i]=shex[i]-87;
	}
	for(i=0;i<len;i++)
	{
		for(j=0;j<4;j++)
		{
			bin[i][3-j] = hex[i]%2;
			hex[i]/=2;
		}
	}
	for(j=0;j<4;j++)
	{
		if(bin[0][j]==1)
		{
			primeiro = j;
			break;
		}
	}
	for(j=primeiro;j<4;j++)
	printf("%d",bin[0][j]);
	for(i=1;i<len;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d",bin[i][j]);
		}
	}
}

void dectobin(int dec){
	int nb, i;
	for(nb=0;dec>=(1<<nb);nb++);
	int bin[nb];
	for(i=0;nb-1-i>=0;i++)
	{
		bin[nb-1-i]=dec%2;
		dec/=2;
	}
	for(i=0;i<nb;i++)
	printf("%d",bin[i]);
}

int main()
{
	int Opcao, Num;
	char bits[256];
	printf("Escolha a Convercao Desejada: ");
	printf("\n1-Binario para Decimal. \n 2-Binario para Hexadecimal.");
	printf("\n 3-Hexadecimal para Decimal. \n 4-Hexadecimal para Binario.");
	printf("\n 5-Decimal para Binario. \n 6-Decimal para Hexadecimal.");
	printf("\n 7-Octal para Decimal. \n 8-Decimal para Octal.\n");
	scanf("%d", &Opcao);
	switch(Opcao)
	{
		case 1:{
			printf("Insira o numero a ser convertido: ");
			scanf("%s", bits);
			bintodec(bits);
			break;
		}
		case 2:{
			printf("Insira o numero a ser convertido: ");
			scanf("%s", bits);
			bintohex(bits);
			break;
		}
		case 3:{
			printf("Insira o numero a ser convertido: ");
			scanf("%s", bits);
			hextodec(bits);
			break;
		}
		case 4:{
			printf("Insira o numero a ser convertido: ");
			scanf("%s", bits);
			hextobin(bits);
			break;
		}
		case 5:{
			printf("Insira o numero a ser convertido: ");
			scanf("%d", &Num);
			dectobin(Num);
			break;
		}
		case 6:{
			printf("Insira o numero a ser convertido: ");
			scanf("%d", &Num);
			printf("%X", Num);
			break;
		}
		case 7:{
			printf("Insira o numero a ser convertido: ");
			scanf("%o", &Num);
			printf("%d", Num);
			break;
		}
		case 8:{
			printf("Insira o numero a ser convertido: ");
			scanf("%d", &Num);
			printf("%o", Num);
			break;
		}
		default:{
			printf("Opcao invalida!");
			break;
		}
	}

	return 0;
}

#include<stdio.h>

void hm(int t,int *h,int *m)
{
	if(t<0)
	{
	 printf("Erro Tempo Negativo!!!\n");
	     return;
	}
	 *h=t/60;
	 *m=t%60;
	 printf("-Tempo de %dmnts foi convertido para %dhrs %dmnts",t,*h,*m);

}

main()
{
	int t,h,m;
	
	 printf("-Introduza Tempo em minutos: ");
	     scanf("%d",&t);
	         hm(t,&h,&m);
	             t=60*h+m;
                 return 0;
	
}

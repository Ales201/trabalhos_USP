// trabalho um com funcao

#include <stdio.h>
#include <math.h>
#define PI 3.141592654

float qnt1 (float A){
	float resua;
	resua=(0.5*A)+(2.56*sqrt(A))*pow((cos((2*PI*A)/100)),2);
	return(resua);
}

float qnt2 (float B){
	float resub;
	resub=((0.5*B)+(1.58*B)*pow((sin(2*PI*B/100)),2));
	return(resub);
}

main(){
	int i;
	float resub, resua, resua1[101], resub2[101],A,B,resua2,resub3,maiorA=0,maiorB=0; 

		
printf("digite a quantidade do produto A: ");
	scanf("%f",&A);
printf("digite a quantidade do produto B: ");
	scanf("%f",&B);
	
	//LETRA A

		resua= qnt1(A);
		resub= qnt2(B);	
	
		printf("\n a quantidade de R, do reagente A eh: %fKg\n",resua);
		printf("\n a quantidade de R, do reagente B eh: %fkg\n",resub);	
	
	//LETRA B
	
	
	for(i=1;i<101;i++){
		resua1[i]=qnt1(i);
		resub2[i]=qnt2(i);
		printf("\nQuantidade: %dkg\n RA= %f RB= %f",i,resua1[i],resub2[i]);
}
	//LETRA C	
	
	for(i=20;i<=100;i++){
		resua2=(qnt1(i))/i;
			if(resua2>maiorA)
				maiorA=resua2;
	}
	printf("\n \n a maior relacao entre R/A eh:%fKg",maiorA);
	
	for(i=20;i<=100;i++){
		resub3=(qnt2(i))/i;
			if(resub3>maiorB)
				maiorB=resub3;
	}
	printf("\n a maior relacao entre R/B eh:%fKg",maiorB);	
		
		
	}

	


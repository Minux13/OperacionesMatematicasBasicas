#include <stdio.h>

int main(){

	int polinomio[15], g[15], i, e, c, y, r, factor, f, b_x0, base, exp, a;

	for(i=14; i>=0; i--){
		polinomio[i]=0;
	}
	
	scanf("%d", &a);

	for(i=1; i<=a; i++){
	    
	    scanf("%d", &base);	
	    scanf("%d", &exp);
	    
	    polinomio[exp]=base;	
	}

	printf("Los factores son ");

	if(polinomio[0]==0){
		for(i=13; i>=0; i--){
			polinomio[i]=polinomio[i+1];
		}

		printf("x ");
	}
	
	e=abs(polinomio[0]);
	y=-1*e;

	for(factor=-100; factor<=100; factor++){		////i es el exponente 
		r=0;
		for(i=14; i>=0; i--){	
			c=factor*r;
			r=polinomio[i]-c;
		}
		//printf("%d", r);

		if(r==0){
			f=factor*-1;
			printf("(x");
			if(f>=0)
				printf("+");
			printf("%d)", f);

		}
	}

	printf("\n\n");

}

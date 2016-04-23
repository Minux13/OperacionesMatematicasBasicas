#include <stdio.h>

/*Obtiene la derivada de dos polinomios multiplicados*/

int imprime_mon(int base, int exp, int p_mon);    /*Función que imprime un monomio, recibe su base,
											exponente y p_mon cambia a 1 si ha recibido el primer
											monomio del polinomio, el del exponente mayor, eso para 
											cuando el primer monomio es positivo no imprimir '+'  */
											
int main(){


	int num_monomios1, num_monomios2, i, p_x[5], q_x[5], base, exp, j, dp_x[5], dq_x[5], dp_q[5], dq_p[5], p_mon; 

	/*
	  Arreglos que contienen la base del polinomio y el número del arreglo es le número del exponente
	  Primer polinomio p(x) --> p_x[]
	  Segundo polinomio q(x) --> q_x[]
	  Derivada de p(x) --> dp_x[]
	  Derivada de q(x) --> dq_x[]
	  p'(x)·q(x) --> dp_x_q_x[]
	  q'(x)·p(x) --> dqp[]

	  p_mon cambia a 1 cuando la base del exponente no es cero,

	*/
	
	
	for(i=0; i<=5; i++){		//Inicializa las bases en cero hasta el exponente 5
	
	    p_x[i]=0;  			
	    q_x[i]=0;
	    dp_x[i]=0;
	    dq_x[i]=0;
	    dp_q[i]=0;			
	    dq_p[i]=0;
	}
	

    
	scanf("%d", &num_monomios1);        ///Ingreso el número de monomios que tiene el primer polinomio
	scanf("%d", &num_monomios2);	    ///Ingreso el número de monomios que tiene el segundo polinomio
	

	for(i=1; i<=num_monomios1; i++){
	    
	    scanf("%d", &base);	
	    scanf("%d", &exp);
	    
	    p_x[exp]=base;	
	}
	
	
	for(i=1; i<=num_monomios2; i++){
	    
	    scanf("%d", &base);	
	    scanf("%d", &exp);
	    
	    q_x[exp]=base;	
	}
	

	p_mon=0;
    

	printf("<p><span style=\"font-family: verdana; font-size: large;\"><strong>Solución:</strong><br /><br />Sean $$p(x)=");

	//For que imprime un polinomio, en cada ciclo manda a llamar la funcion que imprime monomio por monomio

	for(i=4; i>=0; i--){
	
	    imprime_mon(p_x[i], i, p_mon);
	     
	    if (p_x[i]!=0)
	        p_mon=1;	    
	}

	
	printf("$$ y $$q(x)=");


    p_mon=0;   ///Se evalúa otro arreglo nuevo

	for(i=5; i>=0; i--){
	
	    imprime_mon(q_x[i], i, p_mon);
	     if (q_x[i]!=0)
	        p_mon=1;
	}
	
	///Ciclos que guardan los valores de las derivadas de los polinomios
    for(i=1; i<=5; i++){
	    	    
	    dp_x[i-1]=p_x[i]*i;	
	}


	for(i=1; i<=5; i++){
	    	    
	    dq_x[i-1]=q_x[i]*i;	
	}
	
	
	printf("$$, entonces,</span></p><p style=\"text-align: center;\"><span style=\"font-family: verdana; font-size: large;\"><br />$$p'(x)="); 

    p_mon=0;

    
    ///imprime la derivada del primer polinomio
    
    for(i=5; i>=0; i--){
	
	    imprime_mon(dp_x[i], i, p_mon); 
	    if (dp_x[i]!=0)
	        p_mon=1;
	}

	printf("$$        y        $$q'(x)=");
	
	p_mon=0;
	
	for(i=5; i>=0; i--){  ///imprime la derivada del segundo polinomio
	
	    imprime_mon(dq_x[i], i, p_mon); 
	    if (dq_x[i]!=0)
	        p_mon=1;
	}


	printf("$$, </span></p><p><span style=\"font-family: verdana; font-size: large;\"><br />Como, </span></p><table style=\"width: 320px; height: 50px; margin-left: auto; margin-right: auto;\" border=\"3\"><tbody><tr><td style=\"text-align: center;\" valign=\"MIDDLE\"><p> $$f'(x)=q(x)\\cdot p'(x)+p(x)\\cdot q'(x)$$</p></td></tr></tbody></table><p style=\"text-align: center;\"> </p><p><span style=\"font-family: verdana; font-size: large;\">Entonces,<br /><br />$$f'(x)=(");

	p_mon=0;
	
	///Dos ciclos for, primero imprime q(x), luegro printf imprime ")(" y el segundo for imprime p'(x)
///Para imprimieron q(x)p'(x), La regla de la cadena es q(x)p'(x) + p(x)q'(x)

	for(i=5; i>=0; i--){    
	
	    imprime_mon(q_x[i], i, p_mon); 
	    if (q_x[i]!=0)
	        p_mon=1;
	}
	
	printf(")(");
	
	p_mon=0;
	
	for(i=5; i>=0; i--){
	
	    imprime_mon(dp_x[i], i, p_mon); 
	    if (dp_x[i]!=0)
	        p_mon=1;
	}


    ///Imprime ")+(" luego los dos ciclos for imprimen p(x)q'(x)
	   
	printf(")+(");
	
	p_mon=0;
	
	for(i=5; i>=0; i--){
	
	    imprime_mon(p_x[i], i, p_mon); 
	    if (p_x[i]!=0)
	        p_mon=1;
	}

	printf(")(");
	
	p_mon=0;
	
	for(i=5; i>=0; i--){
	
	    imprime_mon(dq_x[i], i, p_mon); 
	    if (dq_x[i]!=0)
	        p_mon=1;
	}

	
	printf(")$$.<br /><br />Simplificando la expresión,<br /><br />$$\\begin{eqnarray}f'(x)&amp;=&amp;(");
	

	p_mon=0;

	for(i=5; i>=0; i--){
	
	    imprime_mon(q_x[i], i, p_mon); 
	    if (q_x[i]!=0)
	        p_mon=1;
	}
	
	printf(")(");
	
	p_mon=0;
	
	for(i=5; i>=0; i--){
	
	    imprime_mon(dp_x[i], i, p_mon); 
	    if (dp_x[i]!=0)
	        p_mon=1;
	}

	printf(")+(");
	
	p_mon=0;
	
	for(i=5; i>=0; i--){
	
	    imprime_mon(p_x[i], i, p_mon); 
	    if (p_x[i]!=0)
	        p_mon=1;
	}

	printf(")(");
	
	p_mon=0;
	
	for(i=5; i>=0; i--){
	
	    imprime_mon(dq_x[i], i, p_mon); 
	    if (dq_x[i]!=0)
	        p_mon=1;
	}
	
	printf(")\\\\\\\\\\\\&amp;=&amp;(");
	
	/*Guarda los valores de  p'(x)q(x) y q'(x)p(x), se suma la base del valor anterior cuando hay monomios de la multiplicacion con el mismo exponente*/

    for(i=5; i>=0; i--){
	    
	    for(j=5; j>=0; j--){
	    
	        if(q_x[j]*dp_x[i]!=0)
	            dp_q[i+j]=dp_q[i+j]+q_x[j]*dp_x[i];		
	        
	        if(p_x[j]*dq_x[i]!=0)
	            dq_p[i+j]=dq_p[i+j]+p_x[j]*dq_x[i];
	    }
	}

    p_mon=0;
    
    
    /////Imprime la multiplicacion de cada monomio por cada monomio al multiplicar dos polinomios p'(x)q(x)
    
    for(i=5; i>=0; i--){
	    
	    for(j=5; j>=0; j--){	    
	              
	        imprime_mon(q_x[j]*dp_x[i], i+j, p_mon); 
	        if (q_x[j]*dp_x[i]!=0)
	        p_mon=1;
	        
	    }
	}
		
	printf(")+(");
	
	p_mon=0;
	
	/////Imprime la multiplicacion de cada monomio por cada monomio al multiplicar dos polinomios q'(x)p(x)
	for(i=5; i>=0; i--){
	    
	    for(j=5; j>=0; j--){	    
	              
	        imprime_mon(p_x[j]*dq_x[i], i+j, p_mon); 
	        if (p_x[j]*dq_x[i]!=0)
	        p_mon=1;
	        
	    }
	}

	printf(")\\\\\\\\\\\\&amp;=&amp;");
	
	p_mon=0;
	
	
	////Suma las bases de de los polinomios p'(x)q(x) y q'(x)p(x) que tienen el mismo exponente y los imprime
	for(i=5; i>=0; i--){
	 
	    imprime_mon(dq_p[i]+dp_q[i], i, p_mon); 
	    if (dq_p[i]+dp_q[i]!=0)
	        p_mon=1;
	   
	}
	
    printf("\\end{eqnarray}$$</span></p>");
    
	return 0;

}
////////////////////1

int imprime_mon(int base, int exp, int nepm) {
	
	
	    if (nepm!=0 && base>0)
	        printf("+");
	    
	    if(base!=0 && base!=1 && base!=-1){
	        printf("%d", base); 
	    
	    }
	    
	    if(base==-1 && base!=0){
	        printf("-"); 
	    
	    }
	    
	    if(exp>=2 && base!=0){
	        printf("x^%d", exp);
	       
	    }
	    
	    if(exp==1 && base!=0){
	        printf("x");
	        
	    }
	
	    if(exp==0 && (base==1 || base==-1)){
	        printf("1");
	        
	    }   
}


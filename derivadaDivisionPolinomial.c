#include <stdio.h>

/*Obtiene la derivada de la division de dos polinomios cuando el denominador tiene un exponente mayor de 1*/

int imprime_mon(int base, int exp, int p_mon);    /*Función que imprime un monomio, recibe su base,
											exponente y p_mon cambia a 1 si ha recibido el primer
											monomio del polinomio, el del exponente mayor, eso para 
											cuando el primer monomio es positivo no imprimir '+'  */
											
int main(){

	int num_monomios, i, k, p_x[5], q_x[5], q_x3[5], q_x5[5], q_x4[5], base, exp, exp_p, j, p_mon; 

	
	for(i=0; i<=5; i++){		//Inicializa las bases en cero hasta el exponente 15
	
	    p_x[i]=0;  			
	    q_x[i]=0;
	    q_x3[i]=0;
	    q_x4[i]=0;
	    q_x5[i]=0;
	    
	}
	
    
	scanf("%d", &exp_p);	            ///Ingreso el exponente
	scanf("%d", &num_monomios);         ///Numero de monomios que tiene el polinom

	for(i=1; i<=num_monomios; i++){
	    
	    scanf("%d", &base);	
	    scanf("%d", &exp);
	    
	    p_x[exp]=base;
	}
	
	
	
	
	/*Guarda los valores de  p'(x)q(x) y q'(x)p(x), se suma la base del valor anterior cuando hay monomios de la multiplicacion con el mismo exponente luego multiplica q'(x)p(x) por -1 */

    for(i=5; i>=0; i--){	    
	    for(j=5; j>=0; j--){	    
	        q_x[i+j]=q_x[i+j]+(p_x[j]*p_x[i]);		        
	    }
	}
	
      
    if(exp_p>=3 && exp_p<=5){
        for(i=5; i>=0; i--){	        
	        for(j=5; j>=0; j--){	        
	            q_x3[i+j]=q_x3[i+j]+q_x[j]*p_x[i];		            
	        }
	    }	
    }
      
      
    if(exp_p>=4 && exp_p<=5){
        for(i=5; i>=0; i--){	        
	        for(j=5; j>=0; j--){	        
	            q_x4[i+j]=q_x4[i+j]+q_x3[j]*p_x[i];		            
	        }
	    }	
    }
    
    if(exp_p==5){
        for(i=5; i>=0; i--){	        
	        for(j=5; j>=0; j--){	        
	            q_x5[i+j]=q_x5[i+j]+q_x4[j]*p_x[i];		            
	        }
	    }	
    }
    
    
	/////Imprime la multiplicaciones y simplificada
	
	if(exp_p==2){
        p_mon=0;
        for(i=5; i>=0; i--){	   	    
	        imprime_mon(q_x[i], i, p_mon); 
	        if (q_x[i]!=0)
	            p_mon=1;
	    }
	}
	
	if(exp_p==3){
        p_mon=0;
        for(i=5; i>=0; i--){	   	    
	        imprime_mon(q_x3[i], i, p_mon); 
	        if (q_x3[i]!=0)
	            p_mon=1;
	    }
	}
	
		
	if(exp_p==4){
        p_mon=0;
        for(i=5; i>=0; i--){	   	    
	        imprime_mon(q_x4[i], i, p_mon); 
	        if (q_x4[i]!=0)
	            p_mon=1;
	    }
	}
	
	
	if(exp_p==5){
        p_mon=0;
        for(i=5; i>=0; i--){	   	    
	        imprime_mon(q_x5[i], i, p_mon); 
	        if (q_x5[i]!=0)
	            p_mon=1;
	    }
	}
	
	printf("\n\n");
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


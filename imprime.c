#include "operaciones.h"

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

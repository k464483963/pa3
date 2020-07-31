#include <stdio.h>
#include <math.h>
#include "pa3.h"
#include "pa3Strings.h"
#define	TWO_COMMAND 2	

int main(int argc, char *argv[]){
	if(argc != TWO_COMMAND){
		fprintf(stderr,INVALID_ARGS);
		
		fprintf(stderr, SHORT_USAGE);

		return 1;
	}
	
	unsigned long newLong;

	newLong = parseNum(argv);

	ieeeParts_t newFill;

	extractParts(newLong,&newFill);

	printf(SIGN_STR,newFill.sign);

	printf(EXP_STR,newFill.exp);

	printf(MANTISSA_STR,newFill.mantissa);

	 float expDecimal = (float) newFill.exp;

	 float  mantissaDecimal = 
		(float)(newFill.mantissa/pow(2,23))
		*pow(2,expDecimal);


	 float sign = (float)newFill.sign;

	if(sign != 0){
	 mantissaDecimal 
		= mantissaDecimal-(mantissaDecimal*2);
	}

	printf(DECIMAL_STR,mantissaDecimal);

	

} 
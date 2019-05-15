#include<stdio.h>
#include<stdlib.h>


char token;

int exp(void);
int term(void);


void error(void){
	fprintf(stderr,"error\n");
	exit(1);
}
int main(){
	int result;

	printf("Enter your expression must contain only integer number and 	operators * and + : \n\n");
	token=getchar();
	result=exp();

	if(token=='\n'){
		printf("Result is %d\n",result);
	}
	else{
		error();
	}
	return 0;
}

int exp(void){
	int temp;
	temp=term();
	while((token=='+') || (token=='*'))
	{
		switch(token)
		{
			case '+':
				token=getchar();
				temp+=term();
			break;
			case '*':
				token=getchar();
				temp*=term();
			break;
		}
	}
	return temp;
}
int term(void){
	int temp;
	if(token == '(')
	{
		token=getchar();
		temp=exp();
		if(token==')'){
			token=getchar();
		}
	}
	else if(isdigit(token))
	{
		ungetc(token,stdin);
		scanf("%d",&temp);
		token = getchar();
		printf("%d\n", temp);

	}
	else{
		error();
	}
	return temp;
}


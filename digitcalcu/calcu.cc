#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
char lookhead;
FILE* infile;
FILE* outfile;
void match(char);
void expr();
void error();
void term();
int main(int argc, char**argv) {
	if(argc!=3){
		printf("argc != 3, exiting\n");
	}
	printf("argvs: %s * %s * %s\n", argv[0], argv[1], argv[2]);
	infile = fopen(argv[1], "r");
	outfile = fopen(argv[2], "w");	
	//printf("fopen done %d\n", infile);
	//lookhead = getchar();
	fscanf(infile, "%c", &lookhead);
	printf("fscanf first digit done\n");
	expr();
	//putchar("\n");
	printf("expr over\n");
	fclose(infile);
	fclose(outfile);
}
void expr() {
	term();
	//printf("first digit read: %d\n", lookhead);
	while(1){
		if(lookhead == '+'){
			match('+');term();/*putchar('+');*/fprintf(outfile, "%c", '+');
		} else if(lookhead == '-'){
			match('-');term();/*putchar('-');*/fprintf(outfile, "%c", '-');
		} else break;
	}
}
void term() {
	if (isdigit(lookhead)){
		//putchar(lookhead);
		fprintf(outfile, "%c", lookhead);
		match(lookhead);
	} else error();
}
void match(char t){
	printf("match %c\n", t);
	if(lookhead == t){
		//lookhead = getchar();
		fscanf(infile, "%c", &lookhead);
		//printf("scanf what??\n");
	} else error();
}

void error() {
	printf("syntax error\n");
	exit(1);
}

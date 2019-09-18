#include<ctype.h>
int lookhead;
int main() {
	lookhead = getchar();
	expr();
	putchar("\n");
}
void expr() {
	term();
	while(1){
		if(lookhead == '+'){
			match('+');term();putchar('+');
		} else if(lookhead == '-'){
			match('-');term();putchar('-');
		} else break;
	}
}
void term() {
	if (isdigit(lookhead)){
		putchar(lookhead);
		match(lookhead);
	} else error();
}
void match(int t){
	if(lookhead == t){
		lookhead = getchar();

	} else error();
}

void error() {
	printf("syntax error\n");
	exit(1);
}

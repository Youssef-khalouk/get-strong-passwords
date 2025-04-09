
# include<string.h>
# include<stdio.h>
# include<stdlib.h>
# include<math.h>
# include<time.h>

char lowerCase[26] ={
					'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 
					'j','k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
					's', 't','u', 'v', 'w', 'x', 'y', 'z'
				};
char upperCase[26] ={
					'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 
					'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 
					'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
				};
char nambers[10] ={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

char characters[32] ={
					'!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', 
					'+', ',', '-', '.', '/', ':', ';', '<', '=', '>', 
					'?', '@', '[', '\\', ']', '^', '_', '`', '{', '|', 
					'}', '~'
				};

void getLowerChars(char *var,int lingth){
	for(int i=0; i<lingth; i++){
		int randomNumber = rand()%26;
		var[i] = lowerCase[randomNumber];
	}
}
void getUpperChars(char *var, int lingth){
	for(int i=0; i<lingth; i++){
		int randomNumber = rand()%26;
		var[i] = upperCase[randomNumber];
	}
}
void getCharacters(char *var,int lingth){
	for(int i=0; i<lingth; i++){
		int randomNumber = rand()%32;
		var[i] = characters[randomNumber];
	}
}
void getNumbers(char *var, int lingth){
	for(int i=0; i<lingth; i++){
		int randomNumber = rand()%10;
		var[i] = nambers[randomNumber];
	}
}
void shafullPass(char *var, char list[], int lingth){
	int theLingth = lingth;
	for (int i=0; i<lingth; i++){
		int randomNumber = rand()%theLingth;
		var[i]= list[randomNumber];
		for(int x=randomNumber; x<theLingth; x++){
			list[x] = list[x+1];
		}
		list[theLingth]='\0';
		theLingth--;
	}
}
void scanfNumber(int *var){
	int ifGetNum= 0;
	while(!ifGetNum){
		printf("Enter the lingth of passwod:");
		char string[20];
		fgets(string,20,stdin);
		int i=0;
		int check= 1;
		int lingth = strlen(string);
		while(i< lingth-1){
			if(string[i] == '\0'){break;}
			if(!(string[i]<='9'&&string[i]>='0')){
				printf("This is not a Number!\n");
				check = 0;
				break;
			}
			i++;
		}
		if (check){
			ifGetNum =1;
			*var = atoi(string);
		}
	}
}
int main(){
	srand(time(0));
	int x = 1;
	while(x){
		int lengthOfPassword;
		scanfNumber(&lengthOfPassword);
		if (lengthOfPassword>5){
			int fullLingth = lengthOfPassword;
			int lCaseLingth = floor(lengthOfPassword*0.4);
			lengthOfPassword -= lCaseLingth*2;
			int numbersLingth= ceil(lengthOfPassword*0.5);
			int charLingth= floor(lengthOfPassword*0.5);
			char choosenLowerChars[lCaseLingth];
			char choosenUpperChars[lCaseLingth];
			char choosenCharacters[charLingth];
			char choosenNumbers[numbersLingth];
			getLowerChars(choosenLowerChars,lCaseLingth);
			getUpperChars(choosenUpperChars,lCaseLingth);
			getCharacters(choosenCharacters,charLingth);
			getNumbers(choosenNumbers,numbersLingth);
			char pass[fullLingth];
			int count = 0;
			for(int i =0; i<lCaseLingth; i++){
				pass[count]= choosenLowerChars[i];
				count++;
			}
			for(int i=0; i<lCaseLingth; i++){
				pass[count]=choosenUpperChars[i];
				count++;
			}
			for(int i=0; i<charLingth; i++){
				pass[count]=choosenCharacters[i];
				count++;
			}
			for(int i=0; i<numbersLingth; i++){
				pass[count]=choosenNumbers[i];
				count++;
			}
			char Password[fullLingth];
			shafullPass(Password,pass,fullLingth);
			printf("The Password is : ");
			for (int y=0; y<fullLingth; y++){
				printf("%c",Password[y]);
			}
			printf("\n");
		}else{
			printf("Plase make sure Your number is corict and more than 6 \n");
		}
	}
	return 0;
}
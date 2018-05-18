#include"Origem.h"
#include<stdio.h>
#include<string.h>

int main(void) {
	char input[200]   = { 0 };
	char output[500]  = { 0 };
	char inn[100][10] = { 0 };
	char curr;
	int index = 0, 
		j = 0, 
		k = 0;
	enum states state = (enum states) 0;
	enum inputType inputType = (enum inputType) 0;

	while (1) {
		fgets(input, 200, stdin);
		//printf("%s", input);	
		curr = input[j];
		while (curr != '\n') {
			if (curr != ' ') {
				inn[index][k] = curr;
				j++;
				k++;
			}
			else {
				inn[index][k] = '\0';
				k = 0;
				j++;
				index++;
			}
			curr = input[j];
		}
		index++;
		k = 0;
		for (int i = 0; i < index; i++) {
			curr = inn[i][k];
			while (curr != '\0') {
				validaEntrada(curr, getInputType(curr), &state);
				k++;
				curr = inn[i][k];
			}
			k = 0;
			switch (state)
			{
			case 2:  // [ if ]
				strcat(output, " IF ");
				break;
			case 3:  // [ in ]
				strcat(output, " IN ");
				break;
			case 6:  // [ out ]
				strcat(output, " OUT ");
				break;
			case 9: // [ for ]
				strcat(output, " FOR ");
				break;
			case 11: // [ number ]

			case 12: // [ number ]

			case 13: // [ number ]
				strcat(output, " NUMBER ( ");
				strcat(output, inn[i]);
				strcat(output, " )");
				break;
			case 14: // [ simbol ]			
				switch (getSimbolType(inn[i][0]))
				{
				case 0:
					strcat(output, " IGUAL ");
					break;
				case 1:
					strcat(output, " NOT ");
					break;
				case 2:
					strcat(output, " MAIOR ");
					break;
				case 3:
					strcat(output, " MENOR ");
					break;
				default:
					break;
				}
				break;
			case 15: // [ erro ]
				break;
			default: // [ ID ]
				strcat(output, " ID ( ");
				strcat(output, inn[i]);
				strcat(output, " )");
				break;
			}
			state = 0;
		}

		puts(output);
		index = k = j = 0;
		memset(output, '\0', 400);
		for (int i = 0; i < index; i++)
			memset(inn[i], '\0', 200);		
	}
	return 0;
}
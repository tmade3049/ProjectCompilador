#include <ctype.h>
#include <stdio.h>
#include "Origem.h"

enum states { S = 0, AJ = 1, BJ = 2, CJ = 3, DJ = 4, EJ = 5, FJ = 6, GJ = 7, HJ = 8, IJ = 9, J = 10, K = 11, L = 12, M = 13, N = 14, X = 15 };
enum simbols { EQ = '=', GT = '>', LT = '<', NO = '!' };
enum reservados { IF = 0, IN = 1, FOR = 2, OUT = 3 };
enum inputType { i = 0, n = 1, f = 2, o = 3, u = 4, t = 5, r = 6, other = 7, number = 8, simbol = 9, invalid = 10 };

struct branch {
	unsigned char new_state;
};
struct branch the_table[16][11] = {
	/*        [ i ] [ n ] [ f ] [ o ] [ u ] [ t ] [ r ] [oth] [0.9] [smb] [inv]      */
	/*  S */{ { AJ},{ J },{ GJ},{ DJ},{ J },{ J },{ J },{ J },{ K },{ N },{ X } },
	/* AJ */{ { J },{ CJ},{ BJ},{ J },{ J },{ J },{ J },{ J },{ J },{ X },{ X } }, // [ ID ]
	/* BJ */{ { J },{ J },{ J },{ J },{ J },{ J },{ J },{ J },{ J },{ X },{ X } }, // [ if ]
	/* CJ */{ { J },{ J },{ J },{ J },{ J },{ J },{ J },{ J },{ J },{ X },{ X } }, // [ in ]
	/* DJ */{ { J },{ J },{ J },{ J },{ EJ},{ J },{ J },{ J },{ J },{ X },{ X } }, // [ ID ]
	/* EJ */{ { J },{ J },{ J },{ J },{ J },{ FJ},{ J },{ J },{ J },{ X },{ X } }, // [ ID ]
	/* FJ */{ { J },{ J },{ J },{ J },{ J },{ J },{ J },{ J },{ J },{ X },{ X } }, // [ out ]
	/* GJ */{ { J },{ J },{ J },{ HJ},{ J },{ J },{ J },{ J },{ J },{ X },{ X } }, // [ ID ]
	/* HJ */{ { J },{ J },{ J },{ J },{ J },{ J },{ IJ},{ J },{ J },{ X },{ X } }, // [ ID ]
	/* IJ */{ { J },{ J },{ J },{ J },{ J },{ J },{ J },{ J },{ J },{ X },{ X } }, // [ for ]
	/*  J */{ { J },{ J },{ J },{ J },{ J },{ J },{ J },{ J },{ J },{ X },{ X } }, // [ ID ]
	/*  K */{ { X },{ X },{ X },{ X },{ X },{ X },{ X },{ X },{ L },{ X },{ X } }, // [ number ]
	/*  L */{ { X },{ X },{ X },{ X },{ X },{ X },{ X },{ X },{ M },{ X },{ X } }, // [ number ]
	/*  M */{ { X },{ X },{ X },{ X },{ X },{ X },{ X },{ X },{ X },{ X },{ X } }, // [ number ]
	/*  N */{ { X },{ X },{ X },{ X },{ X },{ X },{ X },{ X },{ X },{ X },{ X } }, // [ simbol ]
	/*  X */{ { X },{ X },{ X },{ X },{ X },{ X },{ X },{ X },{ X },{ X },{ X } }  // [ erro ]
};

int validaEntrada(char currChar, int inputType, enum states *state) {
	struct branch *b = &the_table[*state][inputType];
	*state = (enum states)(b->new_state);

	return 0;
}

int getSimbolType(char currChar) {
	switch (currChar)
	{
	case '=':
		return 0;
		break;
	case '!':
		return 1;
		break;
	case '>':
		return 2;
		break;
	case '<':
		return 3;
		break;
	default:
		return -1;
		break;
	}	
}

int getInputType(char currChar) {
	if (isdigit(currChar))
		return number;
	else if (!isalpha(currChar)) 
		return simbol;
	else {
		switch (currChar)
		{
		case 'i':
			return i;
			break;
		case 'n':
			return n;
			break;
		case 'f':
			return f;
			break;
		case 'o':
			return o;
			break;
		case 'u':
			return u;
			break;
		case 't':
			return t;
			break;
		case 'r':
			return r;
			break;
		default:
			return other;
			break;
		}
	}
}


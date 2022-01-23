#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int SPEC = -1;
int position = 0;
int countIDENT = 0;
unsigned int IDENT = -1;

typedef struct Tree {
	unsigned int k;
	int value, balance;
	struct Tree *parent;
	struct Tree *left;
	struct Tree *right;
} Tree;

int EmptyTree(Tree *T){
	if (!T)
		return 1;
	else
		return 0;
}

Tree *Descend(Tree *T, unsigned int k){
	Tree *X = T;
	while (X != NULL && X->k != k) {
		if (k < X->k)
			X = X->left;
		else
			X = X->right;
	}
	return X;
}

unsigned int Lookup(Tree *T, unsigned int k){
	Tree *X = Descend(T, k);
	if(X == NULL || k != X->k)
		return -1;
	else
		return X->value;
}

Tree *Insert(Tree **T, unsigned int k, unsigned int v){
	Tree *Y = malloc(sizeof(Tree));
	Tree *X;
	Y->k = k;
	Y->value = v;
	Y->parent = Y->left = Y->right = NULL;

	if (*T == NULL)
		*T = Y;
	else {
		X = *T;
		while (1) {
			if (k < X->k) {
				if (X->left == NULL) {
					X->left = Y;
					Y->parent = X;
					break;
				}
				X = X->left;
			}
			else {
				if (X->right == NULL) {
					X->right = Y;
					Y->parent = X;
					break;
				}
				X = X->right;
			}
		}
	}
	return *T;
}

Tree *ReplaceNode(Tree *T, Tree *X, Tree *Y){
	if (X == T){
		T = Y;
		if (Y != NULL){
			Y->parent = NULL;
		}
	}
	else{
		Tree *P = X->parent;
		if (Y != NULL) {
			Y->parent = P;
		}
		if (P->left == X) {
			P->left = Y;
		}
		else {
			P->right = Y;
		}
	}
	return T;
}

Tree *RotateRight(Tree *T,Tree *X){
	Tree *Y = X->left;
	if(Y == NULL)
		return T;
	T = ReplaceNode(T, X, Y);
	Tree *B = Y->right;
	if(B != NULL)
		B->parent = X;

	X->left = B;
	X->parent = Y;
	Y->right = X;
	X->balance++;
	if(Y->balance < 0)
		X->balance -= Y->balance;
	Y->balance++;
	if(X->balance > 0)
		Y->balance += X->balance;
	return T;
}

Tree *RotateLeft(Tree *T,Tree *X){
	Tree *Y = X->right;
	if(Y == NULL)
		return T;
	T = ReplaceNode(T, X, Y);
	Tree *B = Y->left;
	if(B != NULL)
		B->parent = X;

	X->right = B;
	X->parent = Y;
	Y->left = X;
	X->balance--;
	if(Y->balance > 0)
		X->balance -= Y->balance;
	Y->balance--;
	if(X->balance < 0)
		Y->balance += X->balance;
	return T;
}

Tree * InsertAVL(Tree *T, unsigned int k, unsigned int v){
	Tree *A = Insert(&T, k, v);
	Tree *X;
	A->balance = 0;
	while(1){
		X = A->parent;
		if(X == NULL) break;
		if(A == X->left){
			X->balance--;
			if(X->balance == 0) break;
			if(X->balance == -2){
				if(A->balance == 1) T = RotateLeft(T, A);
				T = RotateRight(T, X);
				break;
			}
		}
		else{
			X->balance++;
			if(X->balance == 0) break;
			if(X->balance == 2){
				if(A->balance == -1) T = RotateRight(T, A);
				T = RotateLeft(T, X);
				break;
			}
		}
		A = X;
	}
	return T;
}

void DeleteTree(Tree *T){
    if (!EmptyTree(T)) {
        DeleteTree(T->left);
        DeleteTree(T->right);
        free(T);
    }
}

int Spec(char a){
	char Specs[6];
	Specs[0] = '+';
	Specs[1] = '-';
	Specs[2] = '*';
	Specs[3] = '/';
	Specs[4] = '(';
	Specs[5] = ')';

	for (int j = 0; j < 6; j++){
		if (a == Specs[j])
			return j;
	}
	return -1;
}

unsigned int HashFAQ6(const char * str){
	unsigned int hash = 0;
	for (; *str; str++){
		hash += (unsigned char)(*str);
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash;
}
void Rewrite(char *word){
	for (int i = 0; i < 20; i++)
		word[i] = '\0';
	position = 0;
}
void Check_for_CONST(char *word){
	int number = atoi(word);
	printf("CONST %d\n", number);
}

void Check_for_IDENT(char *word, Tree **T){
	unsigned int crypt = HashFAQ6(word);
	IDENT = Lookup(*T, crypt);

	if(IDENT != -1)
		printf("IDENT %d\n",IDENT);
	else{
		printf("IDENT %d\n", countIDENT);
		*T = InsertAVL(*T, crypt, countIDENT);
		countIDENT++;
	}
}
void Add_Char_in_mass(char *word, char*arr, int i){
	word[position] = arr[i];
	position++;
}

int main(int args, char **argv){
	Tree *T = NULL;
	int length;
	scanf("%d ", &length);
	char *arr = (char *)malloc((length + 5)*sizeof(char));

	char *word = (char *)malloc(20*sizeof(char));
	Rewrite(word);

	gets(arr);
	length = (int)strlen(arr);

	for(int i = 0; i < length; i++){
		if(arr[i] != ' '){
			SPEC = Spec(arr[i]);
			if(SPEC != -1){
				if(word[0] != '\0'){
					if(((int)word[0]) < 48 || ((int)word[0]) > 57)
						Check_for_IDENT(word, &T);
					else
						Check_for_CONST(word);
					Rewrite(word);
				}
				printf("SPEC %d \n", SPEC);
			}
			else
				Add_Char_in_mass(word, arr, i);
			SPEC = -1;
		}
		else{
			if(word[0] != '\0'){
				if(((int)word[0]) < 48 || ((int)word[0]) > 57)
					Check_for_IDENT(word, &T);
				else
					Check_for_CONST(word);
				Rewrite(word);
			}
		}
	}
	if(word[0] != '\0')
	{
		if(((int)word[0]) < 48 || ((int)word[0]) > 57)
			Check_for_IDENT(word, &T);
		else
			Check_for_CONST(word);
	}
	free(arr);
	free(word);
	DeleteTree(T);
	return 0;
}

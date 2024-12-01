#include <stdio.h>
#include <stdlib.h>

#define MAX 10
float evaluer (char expression [])

{

	Pile * pile = NULL;

	float res = 0;

	float op1, op2;

	int i=0;


	while(expression[i]!='\0')
	{

		switch(expression[i])
		{

		case '+' : {
			 pile = depiler(pile, &op1);
			 pile = depiler(pile, &op2);  
			 pile = empiler (pile, (op1+op2)); 
			 break; 
		 }
		case '-' : {pile = depiler(pile, &op1); pile = depiler(pile, &op2);  pile = empiler (pile, (op2-op1)); break; }
		case '*' : {pile = depiler(pile, &op1); pile = depiler(pile, &op2);  pile = empiler (pile, (op1*op2)); break; }
		case '/' : {pile = depiler(pile, &op1); pile = depiler(pile, &op2);  pile = empiler (pile, (op2/op1)); break; }

		default :  {pile = empiler (pile, expression[i]-'0');}


		}


		i++;

	}


	pile = depiler(pile, &res);

	return res;


}
void afficher(int tab[], int n)
{
	int i =0 ;
	printf(" \n");
	for(i=0; i < n ;i++)
	{

		printf(" %d - ", tab[i]);

	}

}


void triInsertion(int tab[], int n)
{

	int i , j, element;



	for(i=1;i<n;i++)
	{

		element = tab[i];
        j =i;

		while(j>0 && tab[j-1]>element)
		{
			tab[j] = tab[j-1];

            j--;

		}

	
		tab[j] = element;



	}

}
 
void triSelection(int tab[], int n)
{

	int i, j, indice_min, tmp ;

	for(i=0;i<n-1;i++)
	{

		indice_min = i;

		for(j=i+1;j<n;j++)
		{
			// On recherche le minimum du tableau T[i+1..n]
			if(tab[j] < tab[indice_min])
				indice_min = j;

		}

		// On met le minimum à la première place dans le tableau T[i..n]
		tmp = tab[i];
		tab[i] = tab[indice_min];
		tab[indice_min] = tmp;


	}

}


void triBulle(int tab[], int n)
{

	int i, j, tmp ;

	for(i=0;i<n;i++)
	{
		for(j=n-1;j>i;j--)
		{
			if(tab[j] < tab[j-1]) /* on échange les deux cases*/
			{
				tmp = tab[j];
				tab[j] = tab[j-1];
				tab[j-1] = tmp;
			}

		}



	}

}

void fusion(int tab[], int debut, int milieu, int fin)
{
int i1 = debut;
int i2 = milieu+1;

int tab_result[MAX];
int i =0;
// copie des éléments jusqu’à ce qu’au moins un des tableaux soit terminé
while ((i1 <= milieu) && (i2 <= fin))
{
	if (tab[i1] < tab[i2])
	{
		tab_result[i]= tab[i1];
		i1++; i++;
	}
	else
	{
		tab_result[i]= tab[i2];
		i2++; i++;
	}
}


// on complète si besoin
if (i1 > milieu)
{	while (i2 <= fin)
	{
		tab_result[i]= tab[i2];
		i2++; i++;
	}
}else{
	while (i1 <= milieu)
	{
		tab_result[i]= tab[i1];
			i1++; i++;
	}

}

// on copie nouveau[0..fin-debut] dans tab[debut..fin)
	for ( i=debut; i <= fin; i++)
	tab[i] = tab_result[i-debut];
}


void triFusion(int tab[], int debut, int fin)
{
	if (debut < fin)
	{
		int milieu = (debut+fin)/2;
		triFusion(tab, debut, milieu);
		triFusion(tab, milieu+1, fin);
		fusion(tab, debut, milieu, fin);
	}
}


int partition(int tab[], int debut, int fin)
{
	int tmp;
int pivot = tab[fin];
int i = debut-1;
for (int j=debut; j<=fin-1; j++)
{
if (tab[j] <= pivot)
{
i++;
 tmp = tab[i];
tab[i]= tab[j];
tab[j] = tmp;
}
}
tmp = tab[i+1];
tab[i+1]= tab[fin];
tab[fin] = tmp;
return i+1;

}

void triRapide(int tab[], int debut, int fin)
{
	if (debut < fin)
	{
		int pivot = partition(tab, debut, fin);
		triRapide(tab, debut, pivot - 1);
		triRapide(tab, pivot + 1, fin);
	}
}


int main()
{

	int t[10] = { 60,10,70,90,50,80,40,0,30,20 };
    triInsertion(t, 10);
    afficher(t,10);
    int t1[10] = { 60,10,70,90,50,80,40,0,30,20 };
	triSelection(t1, 10);
	afficher(t1,10);
	int t2[10] = { 60,10,70,90,50,80,40,0,30,20 };
	triBulle(t2, 10);
	afficher(t2,10);
	int t3[10] = { 60,10,70,90,50,80,40,0,30,20 };
	triFusion(t3,0,9);
	afficher(t3,10);

	int t4[10] = { 60,10,70,90,50,80,40,0,30,20 };
	triFusion(t4,0,9);
	afficher(t4,10);

return 0;

}

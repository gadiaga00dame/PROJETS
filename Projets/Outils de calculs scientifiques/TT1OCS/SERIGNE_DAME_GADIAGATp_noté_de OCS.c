/*SRIGNE DAME GADIAGA MAM 3*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 8

void affiche_matrice(double** M)
{
    for (int i = 0; i<N;i++) 
    {
        for (int j = 0; j<N;j++) 
        {
            printf("%.2f ", A[i][j]);
        }
        
        printf("\n");
    }
    printf("\n");
}

double produit_scalaire(double* v1, double* v2)
{
    double p_s = 0;
	for (int i = 0; i<N;i++)
    {
		p_s= v1[i]*v2[i];
	}
}

void transpose_matrice(double** A)
{ 
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++) 
        {
            A[i][j]=M[j][i];
        }
    }
}

void matrice_unite(double** U)
{
    for (int i = 0; i<N;i++) 
    {
        for (int j = 0; j<N;j++) 
        {
             U[i][i]=1;
             U[i][j]=U[i][i];
        }
    }
}

int est_orthogonale(double** B)
{
    void produit_matrice(double** A, double** M)
    {
	    for (int i = 0; i<N;i++)
        {
		    for (int j = 0;j<N;j++)
            {
			    B[i][j] = 0;
			    for (int k=0;k<N;k++)
                {
                     B[i][j] += A[i][k]*M[k][j];
                }
               
		    }
	    }
    }

    if (B==U)
        return 1;
    else
        return 0;
}

int test_QR(double** M, double** Q, double** R)
{
    for (int i = 0; i<N;i++) 
    {
        for (int j = 0; j<i;j++) 
        {
            R[i][j];
        }
    }
    for (int i = 0; i<N;i++) 
    {
        for (int j = 0; j<N;j++) 
        {
            est_orthogonale(Q[i][j])=1;
        }
    }
    if (M==Q*R)
        return 1;
    else
        return 0;
}

void proj(double* u, double* v, double* p)
{
    for (int i = 0; i<N;i++)
    {
		p[i] = 0;
		p[i]=(produit_scalaire(u,v)/produit_scalaire(u,u))*u[j];
	}
}


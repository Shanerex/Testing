#include<omp.h>
#include<stdio.h>
#include<pthread.h>

int main() {
    int n;
    printf("\nEnter the dimension: ");
    scanf("%d",&n);
    int a[n][n];
    int b[n][n];
    int c[n][n];
    omp_set_num_threads(omp_get_num_procs());
    printf("\nEnter first matrix:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nEnter second matrix:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d",&b[i][j]);
        }
    }
    int i,j,k;
    #pragma open parallel for private(i,j,k) shared(a,b,c)
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            for(k=0; k<n; k++) {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }

    printf("\nResult:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
}
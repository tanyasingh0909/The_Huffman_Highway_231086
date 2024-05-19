#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<=5; i++){
        for(int j=1; j<=i; j++) printf("%d",j);
        for(int k=1; k<=2*(n-i); k++) printf(" ");
        for(int l=i; l>=1; l--) printf("%d",l);
        for(int m=1; m<=i; m++) printf("%d",m);
        for(int k=1; k<=2*(n-i); k++) printf(" ");
        for(int l=i; l>=1; l--) printf("%d",l);
        for(int m=1; m<=i; m++) printf("%d",m);
        printf("\n");
    }
    return 0;
}
#include<stdio.h>
#include<conio.h>

void main(){
    int arr[20][20],r,c,i,j;
    printf("How many rows and columns you want ?\n");
    scanf("%d %d",&r,&c);

    for(i=0;i<r;i++){
        printf("Enter value for %d row\n",i+1);
        for(j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    printf("The matrix you enter is as follows:\n");

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

    printf("The three tuple representation of the above matrix is:\n");
    printf("R  c  v\n");
    printf("-------\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(arr[i][j]!=0){
                printf("%d  %d  %d\n",i+1,j+1,arr[i][j]);
            }
        }
    }

}

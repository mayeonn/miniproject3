#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "product.h"

void addProduct(Product *p){
    printf("제품명?");
    while(getchar()!='\n');
    fgets(p->name, sizeof(p->name), stdin);
    p->name[strlen(p->name)-1]='\0';
    printf("중량?(g)");
    scanf("%d", &p->weight);
    printf("판매가격?");
    scanf("%ld", &p->price);
    printf("별점?");
    scanf("%f", &p->star);
    printf("별점개수?");
    scanf("%ld", &p->numofStar);
}

void readProduct(Product p){
    printf("%-20s\t %d\t %ld\t %.1f\t %ld\n", p.name,p.weight, p.price, p.star, p.numofStar);
}

void updateProduct(Product *p){
    printf("제품명?");
    while(getchar()!='\n');
    fgets(p->name, sizeof(p->name), stdin);
    p->name[strlen(p->name)-1]='\0';
    printf("중량?(g)");
    scanf("%d", &p->weight);
    printf("판매가격?");
    scanf("%ld", &p->price);
    printf("별점?");
    scanf("%f", &p->star);
    printf("별점개수?");
    scanf("%ld", &p->numofStar);
}

void savefile(Product *p, int count){
    FILE *fp;
    fp=fopen("product.txt", "wt");
    for(int i=0; i<count; i++){
        if(p[i].price==-1) continue;
        fprintf(fp, "%s", p[i].name);
        fprintf(fp, "%d %ld %.1f %ld\n", p[i].weight, p[i].price, p[i].star, p[i].numofStar);
    }
    fclose(fp);
    printf("=>저장됨!\n");
}

int loadfile(Product *p){
    int i;
    FILE *fp=fopen("product.txt","rt");
    for(i=0; i<100; i++){
        fgets(p[i].name, sizeof(p->name), fp);
        if(feof(fp)) break;
        fscanf(fp,"%d", &p[i].weight);
        fscanf(fp,"%ld", &p[i].price);
        fscanf(fp,"%f", &p[i].star);
        fscanf(fp,"%ld", &p[i].numofStar);
    }
    fclose(fp);
    return i;
}

void searchName(Product *p,int count){
    int pcnt=0;
    char search[50];

    printf("검색할 키워드?");
    scanf("%s", search);
    printf("---------------------------------------------------------\n");
    for(int i=0; i<count; i++){
        if(p[i].price==-1) continue;
        if(strstr(p[i].name,search)){
            printf("%d ", i+1);
            readProduct(p[i]);
            pcnt++;
        }
    }
    if(pcnt ==0) printf("=>검색된 데이터 없음!\n");
}

void searchPrice(Product *p, int count){
    long min,max;
    int pcnt=0;

    printf("최소 금액?");
    scanf("%ld", &min);
    printf("최대 금액?");
    scanf("%ld", &max);
    printf("---------------------------------------------------------\n");
    for(int i=0; i<count; i++){
        if(p[i].price==-1) continue;
        else if(p[i].price<min) continue;
        else if(p[i].price>max) continue;
        else{
            printf("%d ", i+1);
            readProduct(p[i]);
            pcnt++;
        }
    }
    if(pcnt ==0) printf("=>검색된 데이터 없음!\n");
}

void searchNumofStar(Product *p, int count){
    long min;
    int pcnt=0;

    printf("최소 별점 개수?");
    scanf("%ld", &min);
    printf("\n---------------------------------------------------------\n");
    for(int i=0; i<count; i++){
        if(p[i].price==-1) continue;
        if(min<=p[i].numofStar){
            printf("%d ", i+1);
            readProduct(p[i]);
            pcnt++;
        }
    }
    if(pcnt ==0) printf("=>검색된 데이터 없음!\n");
}

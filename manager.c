#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "manager.h"
#include "product.h"

void listProduct(Product *p, int count){
    int no=0;
    
    printf("No Name            Weight(g)   Price   Star    NumofStar\n");
    printf("---------------------------------------------------------\n");
    for(int i=0; i<count; i++){
        if(p[i].price==-1) continue;
        printf("%d ", ++no);
        readProduct(p[i]);
    }
}

int selectDataNo(Product *p, int count){
    int no;
    listProduct(p, count);
    printf("번호는 (취소:0)? ");
    scanf("%d", &no);
    return no;
}

void deleteProduct(Product *p){
    int del;
    printf("정말로 삭제하시겠습니까?(삭제:1)  ");
    scanf("%d", &del);
    if(del==1) p->price=-1;
    else printf("취소했습니다.\n");
}

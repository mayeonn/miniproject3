#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "product.h"
#include "manager.h"

#define DEBUG

int selectMenu(){
    int menu;
    printf("\n\n**** 과일 쇼핑몰 관리 ****\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("0. 종료     => ");
    scanf("%d", &menu);
    return menu;
}



int main(void){
#ifdef DEBUG
    printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__,__LINE__);
#endif
    printf("Hello World!!");

    Product plist[100];     //배열 버전
    int count=0, index=0;
    count = loadfile(plist);
    index=count;
    int menu;

    if(count==0) printf("=>파일 없음\n");
    else listProduct(plist, count);

    while(1){
        menu=selectMenu();

    if(menu==0) break;
    if(menu==1){
        listProduct(plist,count);
        continue;
    }
    else if (menu==2){
        addProduct(&plist[count++]);
        printf("=> 추가됨!\n");
        continue;
    }
    else if(menu==3){
        int no = selectDataNo(plist,count);
        if(no==0){
            printf("=> 취소됨! \n");
            continue;
        }
        else{
            updateProduct(&plist[no-1]);
            printf("=> 수정됨! \n");
            continue;
        }
    }
    else if(menu==4){
        listProduct(plist,count);
        int no=selectDataNo(plist,index);
        if(no==0){
            printf("=> 취소됨! \n");
            continue;
        }
        else{
            deleteProduct(&plist[no-1]);
            printf("=> 삭제됨! \n");
            continue;
        }
    }

    printf("=> 종료됨!\n");
    return 0;
}




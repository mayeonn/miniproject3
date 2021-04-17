#ifndef PRODUCT
#define PRODUCT

typedef struct{
    char name[50];
    int weight; //[g]
    long numofStar, price;
    float star;
}Product;
#endif

void listProduct(Product *p, int count);  //전체 제품 정보 리스트
int selectDataNo(Product *p, int count);
void deleteProduct(Product *p);



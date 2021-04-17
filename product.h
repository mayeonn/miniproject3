#ifndef PRODUCT
#define PRODUCT

typedef struct{
    char name[50];
    int weight; //[g]
    long numofStar, price;
    float star;
}Product;
#endif

void addProduct(Product *p);    //제품 추가
void readProduct(Product p);    //제품 하나 정보 읽기
void updateProduct(Product *p);     //제품 정보 수정

void savefile(Product *p, int count);   //파일에 제품 리스트 저장
int loadfile(Product *p);

void searchName(Product *p,int count);      //원하는 키워드 포함의 상품을 검색
void searchPrice(Product *p, int count);    //원하는 가격 범위 안의 상품을 검색
void searchNumofStar(Product *p, int count);    //특정 별점 갯수 이상의 상품을 검색




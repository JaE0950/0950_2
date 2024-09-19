#include <stdio.h>
#define MAX_PRODUCTS 100

int main() {
    int num;
    int jego;
    int ipgo;
    int pan;
    int id;
    int cho;
    int i;
    int stock[MAX_PRODUCTS];
    void inven(int stock[], int num_products);


    printf("상품 종류의 개수를 입력하세요 (1-100): ");
    scanf_s("%d", &num);
    if (num < 1 || num > 100) {
        printf("상품 종류의 개수는 1에서 100 사이여야 합니다.\n");
        return 0;
    }

    printf("각 상품의 입고 수량을 입력하세요:\n");
    for (i = 0; i < num; i++) {
        printf("상품 %d의 입고 수량: ", i + 1);
        scanf_s("%d", &ipgo);
        stock[i] = ipgo;  
    }
    
    printf("각 상품의 판매 수량을 입력하세요:\n");
    for (i = 0; i < num; i++) {
        printf("상품 %d의 판매 수량: ", i + 1);
        scanf_s("%d", &pan);
        stock[i] -= pan;
    }

    
    printf("재고를 확인할 상품의 ID를 입력하세요 (1-%d): ", num);
    scanf_s("%d", &id);

    
    if (id < 1 || id > num) {
        printf("유효하지 않은 상품 ID입니다.\n");
        return 0;
    }
   
    cho = id - pan;
    printf("상품 %d의 재고 수량: %d\n", id, stock[id - 1]);

   
    inven(stock, num);

    return 0;
}


void inven(int stock[], int num_products) {
    int total_stock = 0;
    printf("전체 재고 수량:\n");
    for (int i = 0; i < num_products; i++) {
        printf("상품 %d: %d\n", i + 1, stock[i]);
        total_stock += stock[i];
    }
    printf("전체 재고 수량: %d\n", total_stock);
}


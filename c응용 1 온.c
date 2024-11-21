#include <stdio.h>

#define MAX_PRODUCTS 100

int main() {
    int num_products;
    int stock[MAX_PRODUCTS], sold[MAX_PRODUCTS], inventory[MAX_PRODUCTS];
    int id, i;

    printf("상품 개수를 입력하세요: ");
    scanf("%d", &num_products);

    printf("상품 별 입고 수량을 입력하세요: ");
    for (i = 0; i < num_products; i++) {
        scanf("%d", &stock[i]);
        inventory[i] = stock[i]; 
    }

    printf("상품 별 판매 수량을 입력하세요: ");
    for (i = 0; i < num_products; i++) {
        scanf("%d", &sold[i]);
        inventory[i] -= sold[i]; 
    }

    printf("확인할 상품 ID를 입력하세요 (1~%d): ", num_products);
    scanf("%d", &id);

    if (id < 1 || id > num_products) {
        printf("잘못된 상품 ID입니다.\n");
    } else {
        printf("상품 ID %d의 재고 수량: %d\n", id, inventory[id - 1]);
    }

    printf("전체 상품의 재고 수량: ");
    for (i = 0; i < num_products; i++) {
        printf("%d ", inventory[i]);
    }
    printf("\n");

    return 0;
}


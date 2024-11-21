#include <stdio.h>

#define MAX_PRODUCTS 100

int main() {
    int num_products;
    int stock[MAX_PRODUCTS], sold[MAX_PRODUCTS], inventory[MAX_PRODUCTS];
    int total_sold = 0, max_sold = 0, min_sold = MAX_PRODUCTS;
    int max_id = -1, min_id = -1;
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
        total_sold += sold[i];

        if (sold[i] > max_sold) {
            max_sold = sold[i];
            max_id = i + 1;
        }
        if (sold[i] < min_sold) {
            min_sold = sold[i];
            min_id = i + 1;
        }
    }

    printf("전체 판매량: %d\n", total_sold);
    printf("전체 판매율: %.2f%%\n", (float)total_sold / (num_products * 100) * 100);

    printf("가장 많이 판매된 상품: ID %d, 판매량 %d\n", max_id, max_sold);
    printf("가장 적게 판매된 상품: ID %d, 판매량 %d\n", min_id, min_sold);

    printf("재고 부족 경고:\n");
    for (i = 0; i < num_products; i++) {
        if (inventory[i] <= 2) {
            printf("상품 ID %d: 재고 부족(%d)\n", i + 1, inventory[i]);
        }
    }

    return 0;
}

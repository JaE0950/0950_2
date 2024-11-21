#include <stdio.h>

#define MAX_PRODUCTS 5

int stock[MAX_PRODUCTS] = {0}, sold[MAX_PRODUCTS] = {0}, inventory[MAX_PRODUCTS] = {0};

void add_stock() {
    int choice, id, quantity;

    printf("입고수량 입력: 전체 상품 수량 입력(1), 개별 상품 입력(2)을 선택하세요: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("전체 상품의 입고 수량을 입력하세요 (%d개):\n", MAX_PRODUCTS);
        for (int i = 0; i < MAX_PRODUCTS; i++) {
            printf("상품 ID %d: ", i + 1);
            scanf("%d", &quantity);
            stock[i] += quantity;
            inventory[i] += quantity;
        }
    } else if (choice == 2) {
        printf("입고할 상품 ID를 입력하세요 (1~%d): ", MAX_PRODUCTS);
        scanf("%d", &id);
        if (id < 1 || id > MAX_PRODUCTS) {
            printf("잘못된 상품 ID입니다.\n");
            return;
        }
        printf("상품 ID %d의 입고 수량을 입력하세요: ", id);
        scanf("%d", &quantity);
        stock[id - 1] += quantity;
        inventory[id - 1] += quantity;
    } else {
        printf("잘못된 선택입니다. 다시 시도하세요.\n");
    }
}

void sell_product() {
    int choice, id, quantity;

    printf("판매수량 입력: 전체 상품 판매량 입력(1), 개별 상품 입력(2)을 선택하세요: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("전체 상품의 판매 수량을 입력하세요 (%d개):\n", MAX_PRODUCTS);
        for (int i = 0; i < MAX_PRODUCTS; i++) {
            printf("상품 ID %d: ", i + 1);
            scanf("%d", &quantity);
            if (inventory[i] < quantity) {
                printf("상품 ID %d: 재고 부족! 현재 재고: %d\n", i + 1, inventory[i]);
            } else {
                sold[i] += quantity;
                inventory[i] -= quantity;
            }
        }
    } else if (choice == 2) {
        printf("판매할 상품 ID를 입력하세요 (1~%d): ", MAX_PRODUCTS);
        scanf("%d", &id);
        if (id < 1 || id > MAX_PRODUCTS) {
            printf("잘못된 상품 ID입니다.\n");
            return;
        }
        printf("상품 ID %d의 판매 수량을 입력하세요: ", id);
        scanf("%d", &quantity);
        if (inventory[id - 1] < quantity) {
            printf("상품 ID %d: 재고 부족! 현재 재고: %d\n", id, inventory[id - 1]);
        } else {
            sold[id - 1] += quantity;
            inventory[id - 1] -= quantity;
            printf("판매 완료. 현재 재고: %d\n", inventory[id - 1]);
        }
    } else {
        printf("잘못된 선택입니다. 다시 시도하세요.\n");
    }
}

void view_inventory() {
    int total_sold = 0, total_stock = 0, max_sold = 0, min_sold = 1000000;
    int max_id = -1, min_id = -1;

    // 재고수량 출력
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        total_stock += inventory[i];  // 총 재고 수량 계산
        total_sold += sold[i];        // 총 판매량 계산

        if (sold[i] > max_sold) {
            max_sold = sold[i];
            max_id = i;
        }

        if (sold[i] < min_sold) {
            min_sold = sold[i];
            min_id = i;
        }
    }

    // 판매율 계산
    float sales_rate = (total_sold / (float)(total_stock + total_sold)) * 100;

    // 상품 현황 출력
    printf("\n[상품현황]\n");
    printf("재고수량: ");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        printf("%d ", inventory[i]);
    }
    printf("\n총 판매량 : %d (판매율 %.2f%%)\n", total_sold, sales_rate);

    if (max_id != -1) {
        printf("가장 많이 판매된 상품 : ID %d, 판매량 %d\n", max_id + 1, max_sold);
    }

    if (min_id != -1) {
        printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n", min_id + 1, min_sold);
    }

    // 재고 부족 상품 출력
    printf("\n[재고 부족 상품]\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i] <= 2) {
            printf("상품 ID %d : 재고부족(%d)\n", i + 1, inventory[i]);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n[메뉴]\n1. 입고\n2. 판매\n3. 상품현황\n4. 종료\n선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_stock(); break;
            case 2: sell_product(); break;
            case 3: view_inventory(); break;
            case 4: printf("프로그램 종료\n"); return 0;
            default: printf("잘못된 입력입니다. 다시 시도하세요.\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 5
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int stock;
    int sold;
    float price;
    float total_sales;
} Product;

Product products[MAX_PRODUCTS] = {0}; 

void add_stock() {
    int id, quantity;
    float price;
    char name[NAME_LENGTH];

    printf("상품ID : ");
    scanf("%d", &id);
    if (id < 1 || id > MAX_PRODUCTS) {
        printf("상품ID는 1에서 %d 사이여야 합니다.\n", MAX_PRODUCTS);
        return;
    }

    printf("상품명 : ");
    scanf(" %49[^\n]", name);
    printf("입고량 : ");
    scanf("%d", &quantity);
    printf("판매가격 : ");
    scanf("%f", &price);

    // 새로운 상품 
    products[id - 1].id = id;
    strcpy(products[id - 1].name, name);
    products[id - 1].stock += quantity;
    products[id - 1].price = price;
    products[id - 1].total_sales += quantity * price;

    printf("상품 ID %d: 입고 완료. 현재 재고: %d\n", id, products[id - 1].stock);
}

void sell_product() {
    int id, quantity;

    printf("상품ID : ");
    scanf("%d", &id);
    if (id < 1 || id > MAX_PRODUCTS || products[id - 1].id == 0) {
        printf("유효하지 않은 상품ID입니다.\n");
        return;
    }

    printf("판매량 : ");
    scanf("%d", &quantity);

    if (products[id - 1].stock < quantity) {
        printf("재고 부족! 현재 재고: %d\n", products[id - 1].stock);
    } else {
        products[id - 1].stock -= quantity;
        products[id - 1].sold += quantity;
        products[id - 1].total_sales += quantity * products[id - 1].price;
        printf("판매 완료. 현재 재고: %d\n", products[id - 1].stock);
    }
}

void view_product_info() {
    int id;

    printf("조회할 상품ID를 입력하세요 : ");
    scanf("%d", &id);
    if (id < 1 || id > MAX_PRODUCTS || products[id - 1].id == 0) {
        printf("유효하지 않은 상품ID입니다.\n");
        return;
    }

    printf("\n상품 ID %d 정보:\n", id);
    printf("상품명: %s\n", products[id - 1].name);
    printf("재고: %d\n", products[id - 1].stock);
    printf("판매량: %d\n", products[id - 1].sold);
    printf("판매가격: %.2f\n", products[id - 1].price);
    printf("총 판매금액: %.2f\n", products[id - 1].total_sales);
}

void view_inventory() {
    int total_sold = 0, max_sold = 0, min_sold = 1000000; 
    int max_id = -1, min_id = -1;
    float sales_rate;
    int total_stock = 0;

    printf("\n[상품현황]\n");

    // 재고 수량, 판매량
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].id != 0) {
            printf("ID %d: 이름 %s, 재고 %d, 판매량 %d, 판매가격 %.2f, 총 판매금액 %.2f\n", 
                   products[i].id, products[i].name, products[i].stock, products[i].sold, products[i].price, products[i].total_sales);

            total_sold += products[i].sold;
            total_stock += products[i].stock + products[i].sold; 

            if (products[i].sold > max_sold) {
                max_sold = products[i].sold;
                max_id = i;
            }

            if (products[i].sold < min_sold) {
                min_sold = products[i].sold;
                min_id = i;
            }
        }
    }

    // 판매율
    sales_rate = (total_sold / (float)total_stock) * 100;
    
    printf("\n총 판매량: %d (판매율 %.2f%%)\n", total_sold, sales_rate);

    if (max_id != -1) {
        printf("가장 많이 판매된 상품: ID %d, 상품명: %s, 판매량 %d\n", 
               products[max_id].id, products[max_id].name, max_sold);
    }

    if (min_id != -1) {
        printf("가장 적게 판매된 상품: ID %d, 상품명: %s, 판매량 %d\n", 
               products[min_id].id, products[min_id].name, min_sold);
    }

    // 재고 부족
    printf("\n[재고 부족 상품]\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].id != 0 && products[i].stock <= 2) {
            printf("상품 ID %d: 상품명: %s 재고부족(%d)\n", products[i].id, products[i].name, products[i].stock);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n[메뉴]\n1. 입고\n2. 판매\n3. 개별현황\n4. 전체현황\n5. 종료\n선택: ");
        if (scanf("%d", &choice) != 1) {
            printf("잘못된 입력입니다.\n");
            while (getchar() != '\n');  
            continue;
        }

        switch (choice) {
            case 1: add_stock(); break;
            case 2: sell_product(); break;
            case 3: view_product_info(); break;
            case 4: view_inventory(); break;
            case 5: printf("프로그램 종료\n"); return 0;
            default: printf("잘못된 입력입니다. 다시 시도하세요.\n");
        }
    }
}


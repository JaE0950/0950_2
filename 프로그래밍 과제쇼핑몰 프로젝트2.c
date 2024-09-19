include <stdio.h>
#define MAX_PRODUCTS 100

void inven(int stock[], int num_products);

int main() {
    int num;
    int ipgo[MAX_PRODUCTS]; 
    int pan[MAX_PRODUCTS];   
    int stock[MAX_PRODUCTS]; 
    int total_pan = 0;     
    float total_ipgo = 0;      
    int max_pan = 0;     
    int min_pan = MAX_PRODUCTS; 
    int max_id = -1;         
    int min_id = -1;         

    printf("상품 종류의 개수를 입력하세요 (1-100): ");
    scanf_s("%d", &num);
    if (num < 1 || num > MAX_PRODUCTS) {
        printf("상품 종류의 개수는 1에서 %d 사이여야 합니다.\n", MAX_PRODUCTS);
        return 0;
    }

    printf("각 상품의 입고 수량을 입력하세요:\n");
    for (int i = 0; i < num; i++) {
        printf("상품 %d의 입고 수량: ", i + 1);
        scanf_s("%d", &ipgo[i]);
        stock[i] = ipgo[i];  
        total_ipgo += ipgo[i];  
    }

    
    printf("각 상품의 판매 수량을 입력하세요:\n");
    for (int i = 0; i < num; i++) {
        printf("상품 %d의 판매 수량: ", i + 1);
        scanf_s("%d", &pan[i]);
        stock[i] -= pan[i];  
        total_pan += pan[i]; 

        
        if (pan[i] > max_pan) {
            max_pan = pan[i];
            max_id = i + 1; 
        }
        if (pan[i] < min_pan) {
            min_pan = pan[i];
            min_id = i + 1; 
        }
    }

    
    printf("재고 수량: ");
    for (int i = 0; i < num; i++) {
        printf("%d ", stock[i]);
    }
    printf("\n");

    
    float sales_rate = (total_ipgo > 0) ? ((float)total_pan / total_ipgo) * 100 : 0;
    printf("총 판매량: %d (판매율 %.2f%%)\n", total_pan, sales_rate);

    
    printf("가장 많이 판매된 제품: id %d, 판매량 %d\n", max_id, max_pan);

    
    printf("가장 적게 판매된 제품: id %d, 판매량 %d\n", min_id, min_pan);

    
    for (int i = 0; i < num; i++) {
        if (stock[i] <= 2) {
            printf("상품 id %d: 재고 부족 (%d)\n", i + 1, stock[i]);
        }
    }

    
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
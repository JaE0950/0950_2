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

    printf("��ǰ ������ ������ �Է��ϼ��� (1-100): ");
    scanf_s("%d", &num);
    if (num < 1 || num > MAX_PRODUCTS) {
        printf("��ǰ ������ ������ 1���� %d ���̿��� �մϴ�.\n", MAX_PRODUCTS);
        return 0;
    }

    printf("�� ��ǰ�� �԰� ������ �Է��ϼ���:\n");
    for (int i = 0; i < num; i++) {
        printf("��ǰ %d�� �԰� ����: ", i + 1);
        scanf_s("%d", &ipgo[i]);
        stock[i] = ipgo[i];  
        total_ipgo += ipgo[i];  
    }

    
    printf("�� ��ǰ�� �Ǹ� ������ �Է��ϼ���:\n");
    for (int i = 0; i < num; i++) {
        printf("��ǰ %d�� �Ǹ� ����: ", i + 1);
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

    
    printf("��� ����: ");
    for (int i = 0; i < num; i++) {
        printf("%d ", stock[i]);
    }
    printf("\n");

    
    float sales_rate = (total_ipgo > 0) ? ((float)total_pan / total_ipgo) * 100 : 0;
    printf("�� �Ǹŷ�: %d (�Ǹ��� %.2f%%)\n", total_pan, sales_rate);

    
    printf("���� ���� �Ǹŵ� ��ǰ: id %d, �Ǹŷ� %d\n", max_id, max_pan);

    
    printf("���� ���� �Ǹŵ� ��ǰ: id %d, �Ǹŷ� %d\n", min_id, min_pan);

    
    for (int i = 0; i < num; i++) {
        if (stock[i] <= 2) {
            printf("��ǰ id %d: ��� ���� (%d)\n", i + 1, stock[i]);
        }
    }

    
    inven(stock, num);

    return 0;
}


void inven(int stock[], int num_products) {
    int total_stock = 0;
    printf("��ü ��� ����:\n");
    for (int i = 0; i < num_products; i++) {
        printf("��ǰ %d: %d\n", i + 1, stock[i]);
        total_stock += stock[i];
    }
    printf("��ü ��� ����: %d\n", total_stock);
}
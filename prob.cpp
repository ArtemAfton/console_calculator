#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Структура для хранения истории операций
typedef struct {
    double num1;
    double num2;
    char operation;
    double result;
} Calculation;

// Глобальные переменные
Calculation history[100];
int historyCount = 0;

// Функции для математических операций
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
    if (b == 0) {
        printf("Ошибка: деление на ноль!\n");
        return 0;
    }
    return a / b;
}
double power(double a, double b) { return pow(a, b); }
double squareRoot(double a) {
    if (a < 0) {
        printf("Ошибка: корень из отрицательного числа!\n");
        return 0;
    }
    return sqrt(a);
}

// Функция для отображения меню
void displayMenu() {
    printf("\n=== РАСШИРЕННЫЙ КАЛЬКУЛЯТОР ===\n");
    printf("1. Сложение (+)\n");
    printf("2. Вычитание (-)\n");
    printf("3. Умножение (*)\n");
    printf("4. Деление (/)\n");
    printf("5. Возведение в степень (^)\n");
    printf("6. Квадратный корень (√)\n");
    printf("7. Показать историю вычислений\n");
    printf("8. Очистить историю\n");
    printf("0. Выход\n");
    printf("Выберите операцию: ");
}

// Функция для сохранения в историю
void saveToHistory(double num1, double num2, char op, double result) {
    if (historyCount < 100) {
        history[historyCount].num1 = num1;
        history[historyCount].num2 = num2;
        history[historyCount].operation = op;
        history[historyCount].result = result;
        historyCount++;
    }
}

// Функция для отображения истории
void showHistory() {
    if (historyCount == 0) {
        printf("История пуста.\n");
        return;
    }
    
    printf("\n=== ИСТОРИЯ ВЫЧИСЛЕНИЙ ===\n");
    for (int i = 0; i < historyCount; i++) {
        printf("%d. %.2lf %c %.2lf = %.2lf\n", 
               i + 1, 
               history[i].num1, 
               history[i].operation, 
               history[i].num2, 
               history[i].result);
    }
}

int main() {
    int choice;
    double num1, num2, result;
    char operation;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: // Сложение
                printf("Введите два числа: ");
                scanf("%lf %lf", &num1, &num2);
                result = add(num1, num2);
                operation = '+';
                printf("Результат: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                saveToHistory(num1, num2, operation, result);
                break;
                
            case 2: // Вычитание
                printf("Введите два числа: ");
                scanf("%lf %lf", &num1, &num2);
                result = subtract(num1, num2);
                operation = '-';
                printf("Результат: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                saveToHistory(num1, num2, operation, result);
                break;
                
            case 3: // Умножение
                printf("Введите два числа: ");
                scanf("%lf %lf", &num1, &num2);
                result = multiply(num1, num2);
                operation = '*';
                printf("Результат: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                saveToHistory(num1, num2, operation, result);
                break;
                
            case 4: // Деление
                printf("Введите два числа: ");
                scanf("%lf %lf", &num1, &num2);
                result = divide(num1, num2);
                operation = '/';
                printf("Результат: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                saveToHistory(num1, num2, operation, result);break;
                
            case 5: // Степень
                printf("Введите основание и показатель степени: ");
                scanf("%lf %lf", &num1, &num2);
                result = power(num1, num2);
                operation = '^';
                printf("Результат: %.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
                saveToHistory(num1, num2, operation, result);
                break;
                
            case 6: // Квадратный корень
                printf("Введите число: ");
                scanf("%lf", &num1);
                result = squareRoot(num1);
                operation = '√';
                printf("Результат: √%.2lf = %.2lf\n", num1, result);
                saveToHistory(num1, 0, operation, result);
                break;
                
            case 7: // История
                showHistory();
                break;
                
            case 8: // Очистка истории
                historyCount = 0;
                printf("История очищена.\n");
                break;
                
            case 0: // Выход
                printf("До свидания!\n");
                break;
                
            default:
                printf("Неверный выбор! Попробуйте снова.\n");
        }
        
    } while(choice != 0);
    
    return 0;
}
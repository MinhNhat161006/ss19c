#include <stdio.h>
#include <string.h>

#define MAX_SIZE 5 // Số lượng sinh viên tối đa trong mảng

// Định nghĩa cấu trúc sinh viên
typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

// Hàm sắp xếp sinh viên theo tên (tăng dần)
void sortStudentsByName(Student students[], int size) {
    Student temp;
    
    // Dùng thuật toán sắp xếp nổi bọt (Bubble Sort)
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                // Hoán đổi sinh viên[i] và sinh viên[j]
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Hàm hiển thị thông tin sinh viên
void displayStudents(Student students[], int size) {
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, So dien thoai: %s\n", 
            students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int main() {
    // Khai báo mảng sinh viên và gán giá trị cho mảng
    Student students[MAX_SIZE] = {
        {1, "Nguyen A", 20, "0123456789"},
        {2, "Tran B", 22, "0987654321"},
        {3, "Le C", 21, "0112233445"},
        {4, "Pham D", 23, "0999887766"},
        {5, "Hoang E", 24, "0765432109"}
    };

    // Hiển thị thông tin sinh viên ban đầu
    printf("Danh sach sinh vien ban dau:\n");
    displayStudents(students, MAX_SIZE);

    // Gọi hàm sắp xếp sinh viên theo tên
    sortStudentsByName(students, MAX_SIZE);

    // Hiển thị thông tin sinh viên sau khi sắp xếp
    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    displayStudents(students, MAX_SIZE);

    return 0;
}

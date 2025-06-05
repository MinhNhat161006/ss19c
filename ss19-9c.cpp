#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

Student students[MAX];
int studentCount = 0;

void displayStudents() {
    if (studentCount == 0) {
        printf("\nDanh sach sinh vien trong!\n");
        return;
    }

    printf("\nDanh sach sinh vien:\n");
    printf("%-5s %-30s %-10s\n", "ID", "Ten", "GPA");
    for (int i = 0; i < studentCount; i++) {
        printf("%-5d %-30s %-10.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}

void addStudent() {
    if (studentCount >= MAX) {
        printf("\nKhong the them sinh vien, danh sach da day!\n");
        return;
    }

    printf("\nNhap ID: ");
    scanf("%d", &students[studentCount].id);
    printf("Nhap ten: ");
    scanf(" %[^"]s", students[studentCount].name);
    printf("Nhap GPA: ");
    scanf("%f", &students[studentCount].gpa);

    studentCount++;
    printf("\nThem sinh vien thanh cong!\n");
}

void editStudent() {
    int id, found = 0;
    printf("\nNhap ID sinh vien can sua: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Nhap ten moi: ");
            scanf(" %[^"]s", students[i].name);
            printf("Nhap GPA moi: ");
            scanf("%f", &students[i].gpa);
            printf("\nSua thong tin sinh vien thanh cong!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nKhong tim thay sinh vien voi ID %d\n", id);
    }
}

void deleteStudent() {
    int id, found = 0;
    printf("\nNhap ID sinh vien can xoa: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("\nXoa sinh vien thanh cong!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nKhong tim thay sinh vien voi ID %d\n", id);
    }
}

void searchStudent() {
    int id, found = 0;
    printf("\nNhap ID sinh vien can tim: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("\nThong tin sinh vien:\n");
            printf("ID: %d\n", students[i].id);
            printf("Ten: %s\n", students[i].name);
            printf("GPA: %.2f\n", students[i].gpa);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nKhong tim thay sinh vien voi ID %d\n", id);
    }
}

void sortStudents() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = i + 1; j < studentCount; j++) {
            if (students[i].gpa < students[j].gpa) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("\nSap xep sinh vien theo GPA giam dan thanh cong!\n");
}

void menu() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayStudents();
                break;
            case 2:
                addStudent();
                break;
            case 3:
                editStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                searchStudent();
                break;
            case 6:
                sortStudents();
                break;
            case 7:
                printf("\nThoat chuong trinh!\n");
                break;
            default:
                printf("\nLua chon khong hop le!\n");
        }
    } while (choice != 7);
}

int main() {
    menu();
    return 0;
}

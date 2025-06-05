#include <stdio.h>
#include <string.h>

#define MAX_SIZE 5 // Số lượng tối đa sinh viên trong mảng

// Định nghĩa cấu trúc sinh viên
typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

// Hàm xóa sinh viên theo id
void deleteStudent(int id, Student students[], int *currentLength) {
    int found = -1;
    
    // Tìm sinh viên có id cần xóa
    for (int i = 0; i < *currentLength; i++) {
        if (students[i].id == id) {
            found = i;
            break;
        }
    }

    // Kiểm tra nếu sinh viên tồn tại
    if (found == -1) {
        printf("Sinh vien voi id %d khong ton tai.\n", id);
    } else {
        // Di chuyển các phần tử phía sau lên trước để xóa phần tử
        for (int i = found; i < *currentLength - 1; i++) {
            students[i] = students[i + 1];
        }

        // Giảm currentLength đi 1
        (*currentLength)--;
        printf("Sinh vien voi id %d da duoc xoa.\n", id);
    }
}

// Hàm hiển thị thông tin sinh viên
void displayStudents(Student students[], int currentLength) {
    if (currentLength == 0) {
        printf("Danh sach sinh vien rong.\n");
        return;
    }

    for (int i = 0; i < currentLength; i++) {
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

    int currentLength = 5; // Số lượng sinh viên hiện tại trong mảng

    // Hiển thị thông tin các sinh viên ban đầu
    printf("Danh sach sinh vien ban dau:\n");
    displayStudents(students, currentLength);

    // Nhập id sinh viên cần xóa
    int idToDelete;
    printf("\nNhap id sinh vien can xoa: ");
    scanf("%d", &idToDelete);

    // Gọi hàm xóa sinh viên
    deleteStudent(idToDelete, students, &currentLength);

    // Hiển thị thông tin sinh viên sau khi xóa
    printf("\nDanh sach sinh vien sau khi xoa:\n");
    displayStudents(students, currentLength);

    return 0;
}

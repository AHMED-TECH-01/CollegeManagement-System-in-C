#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNumber;
    char name[50];
    char className[10];
    char department[30];
};
void displayStudents(struct Student students[], int count);
void saveStudentsToFile(struct Student students[], int count);
void showDepartmentCourses(struct Student students[], int count);
void showTeachers(struct Student students[], int count);
void saveSingleStudentToFile(struct Student s);

int main() {
    struct Student students[25];
    int count = 20; 
    int choice;
    int i;

    struct Student temp[] = {
        {101, "Muhammad Anas", "XI", "CS"},
        {102, "Fatima Ali", "XI", "PreEng"},
        {103, "Ayesha Siddiqui", "XI", "PreMed"},
        {104, "Bilal Khan", "XI", "Commerce"},
        {105, "Ahmed Raza", "XI", "CS"},
        {106, "Konain Khan", "XI", "PreEng"},
        {107, "Usman Hanif", "XI", "PreMed"},
        {108, "Maryam Noor", "XI", "Commerce"},
        {109, "Zain Ali", "XI", "PreEng"},
        {110, "Hamza Tariq", "XI", "CS"},
        {201, "Ali Haider", "XII", "CS"},
        {202, "Laiba Naseem", "XII", "PreEng"},
        {203, "Zoya Iqbal", "XII", "PreMed"},
        {204, "Hammad Aslam", "XII", "Commerce"},
        {205, "Noor Fatima", "XII", "CS"},
        {206, "Muhammad Amir", "XII", "PreEng"},
        {207, "Sana Javed", "XII", "PreMed"},
        {208, "Rehan Ahmed", "XII", "Commerce"},
        {209, "Amina Rafiq", "XII", "PreEng"},
        {210, "Syed Abdullah Husain", "XII", "CS"}
    };

   
    memcpy(students, temp, count * sizeof(struct Student));

    // Save data to file once
    saveStudentsToFile(students, count);

    while (1) {
        printf("\n====== COLLEGE MANAGEMENT SYSTEM ======\n");
        printf("1. Display All Students\n");
        printf("2. Show Student information by Roll Number\n");
        printf("3. Department Wise Faculty\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayStudents(students, count);
                break;
            case 2:
                showDepartmentCourses(students, count);
                break;
            case 3:
                showTeachers(students, count);
                break;
            case 4:
                printf("Exiting program... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void displayStudents(struct Student students[], int count) {
    int i;
    printf("\n---- Student List ----\n");
    for (i = 0; i < count; i++) {
        printf("Roll No: %d\nName: %s\nClass: %s\nDepartment: %s\n\n",
               students[i].rollNumber, students[i].name,
               students[i].className, students[i].department);
    }
}

void saveStudentsToFile(struct Student students[], int count) {
    FILE *fp;
    int i;
    fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "==================== Student Records ====================\n\n");
    fprintf(fp, "%-10s %-25s %-10s %-15s\n", "Roll No", "Name", "Class", "Department");
    fprintf(fp, "----------------------------------------------------------\n");

    for (i = 0; i < count; i++) {
        fprintf(fp, "%-10d %-25s %-10s %-15s\n",
                students[i].rollNumber,
                students[i].name,
                students[i].className,
                students[i].department);
    }

    fprintf(fp, "==========================================================\n");
    fclose(fp);
    printf("\nStudent data saved successfully in readable form (students.txt)\n");
}

void saveSingleStudentToFile(struct Student s) {
    FILE *fp;
    fp = fopen("searched_student.txt", "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return;
    }

    fprintf(fp, "==================== Student Record ====================\n\n");
    fprintf(fp, "%-10s %-25s %-10s %-15s\n", "Roll No", "Name", "Class", "Department");
    fprintf(fp, "----------------------------------------------------------\n");
    fprintf(fp, "%-10d %-25s %-10s %-15s\n",
            s.rollNumber, s.name, s.className, s.department);
    fprintf(fp, "==========================================================\n");

    fclose(fp);
    printf("\nStudent data saved successfully as 'searched_student.txt'\n");
}

void showDepartmentCourses(struct Student students[], int count) {
    int roll;
    int i;
    printf("Enter Student Roll Number: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (students[i].rollNumber == roll) {
            printf("\nStudent: %s\nClass: %s\nDepartment: %s\n",
                   students[i].name, students[i].className, students[i].department);
            printf("Courses: ");

            if (strcmp(students[i].department, "PreEng") == 0)
                printf("Maths, Physics, Chemistry\n");
            else if (strcmp(students[i].department, "PreMed") == 0)
                printf("Biology, Physics, Chemistry\n");
            else if (strcmp(students[i].department, "CS") == 0)
                printf("Maths, Computer Science, Physics\n");
            else if (strcmp(students[i].department, "Commerce") == 0)
                printf("Accounting, Business Maths, Statistics\n");
            else
                printf("Unknown Department\n");

            saveSingleStudentToFile(students[i]);
            return;
        }
    }
    printf("Student not found!\n");
}


void showTeachers(struct Student students[], int count) {
    int roll;
    int i;
    printf("Enter Student Roll Number: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (students[i].rollNumber == roll) {
            printf("\nTeachers for %s Department:\n", students[i].department);

            if (strcmp(students[i].department, "PreMed") == 0)
                printf("Biology - Dr. Ashraf\nPhysics - Prof. Rahim\nChemistry - Prof. Samar Abbas\n");
            else if (strcmp(students[i].department, "PreEng") == 0)
                printf("Maths - Prof. Ovais Khan\nPhysics - Prof. Ashfaq\nChemistry - Dr. Naveed\n");
            else if (strcmp(students[i].department, "CS") == 0)
                printf("Computer Science - Prof. Nabiha Faisal\nPhysics - Prof. Younus\nMaths - Prof. Adnan\n");
            else if (strcmp(students[i].department, "Commerce") == 0)
                printf("Accounting - Prof. Tehseen\nStatistics - Prof. Ali\nBusiness Maths - Prof. Saad\n");
            else
                printf("Unknown Department\n");

            saveSingleStudentToFile(students[i]);
            return;
        }
    }
    printf("Student not found!\n");
}
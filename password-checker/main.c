#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPasswordComplaint(const char *password) {

    if (strlen(password) != 8) {
        return 0;
    }

    if (!isupper(password[0])) {
        return 0;
    }    

    if (!isdigit(password[1]) && !isdigit(password[5]) && !isdigit(password[6])) {
        return 0;
    }

    if (!islower(password[2]) && !islower(password[4]) && !islower(password[7])) {
        return 0;
    }

    if (isalpha(password[3]) || isdigit(password[3])) {
        return 0;
    }

    return 1;
}

int main() {
    char studentID[20];
    char password[20];

    printf("Enter your student ID: ");
    scanf("%s", studentID);

    printf("Enter your password: ");
    scanf("%s", password);

    int lastDigit = studentID[strlen(studentID) - 1] - '0';

    if (lastDigit % 2 == 0 && isPasswordComplaint(password)) {
        printf("Password compliant\n");
    } else {
        printf("Password not compliant\n");
    }

    return 0;
}



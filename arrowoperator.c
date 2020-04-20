#include <stdio.h>
typedef struct student{
    char name[100];
    int age;
    int roll;
}stu;

// Creating a pointer to the structure
struct student * emp = NULL;
// Normal struct object
stu s1;

int main()
{   
    
    emp = (stu *)malloc(sizeof(stu));
    
    // Assigning value to the emp variable
    emp -> age = 18;
    //Assigning value to the s1 variable
    s1.age = 19;
    //Input of struct element
    printf("Enter the name: ");
    scanf("%s",emp->name);
    printf("Enter the roll: ");
    scanf("%d",&emp->roll);
    printf("%d",emp->age);
    printf("\n%d",s1.age);
    return 0;

}
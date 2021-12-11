#include<iostream>
#include<string>

using namespace std;
#define OK 0
#define EXIT 1
#define ERROR 2
typedef int Status;
typedef struct {
    char no[8];
    char name[20];
    int price;
} Student;
typedef struct Node *PtrToNode;/*这里规定PtrToNode是一个指针*/

struct Node {
    Student data;
    PtrToNode next;
};
typedef PtrToNode List;

/*用list表示链表【本质上是前面规定的一个指针】*/
/*一言蔽之：list是node的指针形式*/
Status Init(List &l) {
    printf("Initializing...\n");
    l = new Node;
    l->next = NULL;
    return OK;
}

Status AddStudent(List &l, Student &e) {
    List temp;
    List nextone = new Node;
    temp = l;
    while (temp->next) {
        temp = temp->next;
    }
    for (int i = 0; i <= 7; i++) {
        nextone->data.no[i] = e.no[i];
    }
    for (int j = 0; j <= 19; j++) {
        nextone->data.name[j] = e.name[j];
    }
    nextone->data.price = e.price;
    nextone->next = NULL;
    temp->next = nextone;
    return OK;
}

Status ShowAllStudent(List &l) {
    List temp;
    temp = l->next;//first node have no data
    int i = 1;
    while (temp->next) {

        printf("No. %d\nName:", i);
        for (int j = 0; j <= 19; j++) {
            printf("%c", temp->data.name[j]);
        }
        printf("\nStudent ID:");
        for (int k = 0; k <= 7; k++) {
            printf("%c", temp->data.no[k]);
        }
        printf("\nGrade:%d", temp->data.price);
    }
    printf("That's all.\n");
    return OK;
}

Status SearchByName(List &l, string name) {
    List temp;
    temp = l->next;
    while (temp->next) {
        string str1(temp->data.name);
        if (name.compare(str1) == 0) {

            printf("Name: %s found.\nStudent ID:", &str1);
            for (int k = 0; k <= 7; k++) {
                printf("%c", temp->data.no[k]);
            }
            printf("\nGrade:%d", temp->data.price);
            return OK;
        }
        if (temp->next == NULL && name.compare(str1) != 0) {
            printf("Student did not found.\n");
            return EXIT;
        }
        temp = l->next;
    }
    return ERROR;
}

Status LocateByNumber(List &l, int num) {

    List temp = l;
    for (int i = 0; i < num; i++) {
        if (temp->next == NULL) {
            printf("Invalid number.\n");
            return ERROR;
        }
        temp = temp->next;
    }
    printf("Name:");
    for (int j = 0; j <= 19; j++) {
        printf("%c", temp->data.name[j]);
    }
    printf("\nStudent ID:");
    for (int k = 0; k <= 7; k++) {
        printf("%c", temp->data.no[k]);
    }
    printf("\nGrade:%d", temp->data.price);
    return OK;
}

Status Insert(List &l, int num, Student &e) {
    List temp = l;
    List nextone = new Node;
    for (int i = 1; i < num; i++) {
        if (temp->next == NULL) {
            printf("Invalid number.\n");
            return ERROR;
        }
        temp = temp->next;
    }
    for (int i = 0; i <= 7; i++) {
        nextone->data.no[i] = e.no[i];
    }
    for (int j = 0; j <= 19; j++) {
        nextone->data.name[j] = e.name[j];
    }
    nextone->data.price = e.price;
    nextone->next = temp->next;
    temp->next = nextone;
    return OK;
}

Status DeleteByNumber(List &l, int num) {
    List temp = l;
    List newnext;
    for (int i = 1; i < num; i++) {
        if (temp->next == NULL) {
            printf("Invalid number.\n");
            return ERROR;
        }
        temp = temp->next;
    }
    newnext = temp->next;
    newnext = temp->next;
    delete temp->next;
    temp->next = newnext;

    return OK;
}

int TotalStudent(List &l) {
    List temp = l;
    int num = 0;
    while (temp->next != NULL) {
        num++;
        temp = temp->next;
    }
    return num;
}

int main() {
    List l;
    int case_1_number, case_1_price;
    char case_1_no[8], case_1_name[20];
    Student case_1_student;
    char case_3_name[20];
    int case_4_locate_number;
    int case_5_number, case_5_price, case_5_local_number;
    char case_5_no[8], case_5_name[20];
    Student case_5_student;
    int case_6_local_number;
    Init(l);
    int pick = 1;
    while (pick) {
        cout << "This program could accomplish the following tasks:" << endl;
        cout << "1:input a declared number of Student data." << endl;
        cout << "2:show all students' data." << endl;
        cout << "3:find the student's data by name." << endl;
        cout << "4:search the data by locate number." << endl;
        cout << "5:insert a student's data into a declared location." << endl;
        cout << "6:delete a record by locate number." << endl;
        cout << "7:get the NUMBER of the students in the system." << endl;
        cout << "Please enter the serial number \nand number \"0\" means exit the system" << endl;
        cin >> pick;
        if (pick < 0 || pick > 7) {
            cout << "invalid input. please re-enter the serial number" << endl;
            break;
        }
        switch (pick) {
            case 0:
                exit(0);
            case 1:
                while (1) {
                    cout << "please enter the number" << endl;
                    cin >> case_1_number;
                    if (case_1_number <= 0)
                        cout << "invalid number. please re-enter the number" << endl;
                    if (case_1_number > 0)break;
                }
                for (int i = 0; i < case_1_number; i++) {
                    printf("No.%d\n", i);
                    printf("please enter the name\n");
                    cin >> case_1_name;
                    printf("please enter the student number\n");
                    cin >> case_1_no;
                    printf("please enter the student grade\n");
                    cin >> case_1_price;
                    for (int i = 0; i <= 7; i++) {
                        case_1_student.no[i] = case_1_no[i];
                    }
                    for (int i = 0; i <= 19; i++) {
                        case_1_student.name[i] = case_1_name[i];
                    }
                    case_1_student.price = case_1_price;
                    AddStudent(l, case_1_student);
                    printf("No.%d student data input successfully.\n");
                }
                break;
            case 2:
                ShowAllStudent(l);
                break;
            case 3:
                printf("please input the student name:\n");
                cin >> case_3_name;
                SearchByName(l, case_3_name);
                break;
            case 4:
                printf("please input the locate number:\n");
                cin >> case_4_locate_number;
                LocateByNumber(l, case_4_locate_number);
                break;
            case 5:
                printf("please input the local number:\n");
                cin >> case_5_local_number;
                printf("please enter the name\n");
                cin >> case_5_name;
                printf("please enter the student number\n");
                cin >> case_5_no;
                printf("please enter the student grade\n");
                cin >> case_5_price;
                for (int i = 0; i <= 7; i++) {
                    case_5_student.no[i] = case_5_no[i];
                }
                for (int i = 0; i <= 19; i++) {
                    case_5_student.name[i] = case_5_name[i];
                }
                case_5_student.price = case_5_price;
                Insert(l, case_5_local_number, case_5_student);
                printf("insert successfully.\n");
                break;
            case 6:
                printf("please input the local number:\n");
                cin >> case_6_local_number;
                DeleteByNumber(l, case_6_local_number);
                printf("delete successfully.\n");
                break;
            case 7:
                printf("The total number of students is %d\n", TotalStudent(l));
                break;


            default:
                printf("Color Eggs.\n");
        }
    }
    return 0;
}


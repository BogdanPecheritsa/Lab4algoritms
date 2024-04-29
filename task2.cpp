#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    void append(int data) {
        Node* newNode = new Node{ data, NULL, NULL };
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void remove(int data) {
        Node* temp = head;
        while (temp) {
            if (temp->data == data) {
                if (temp->prev) temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                if (temp == head) head = temp->next;
                if (temp == tail) tail = temp->prev;
                delete temp;
                break;
            }
            temp = temp->next;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, data;

    do {
        cout << "1. Додати\n2. Видалити\n3. Вивести\n4. Вийти\nВведіть свій вибір: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Введіть дані для додавання: ";
            cin >> data;
            dll.append(data);
            break;
        case 2:
            cout << "Введіть дані для видалення: ";
            cin >> data;
            dll.remove(data);
            break;
        case 3:
            dll.display();
            break;
        case 4:
            cout << "Вихід з програми." << endl;
            break;
        default:
            cout << "Неправильний вибір. Будь ласка, спробуйте ще раз." << endl;
        }
    } while (choice != 4);

    return 0;
}
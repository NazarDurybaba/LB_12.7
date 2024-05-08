#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

// Структура елемента списку
struct Node {
    int vertex; // Номер вершини графа
    int edgeLength; // Довжина ребра
    Node* next; // Вказівник на наступний елемент списку
};

// Функція для додавання елемента в кінець списку
void appendNode(Node*& head, int vertex, int edgeLength) {
    Node* newNode = new Node;
    newNode->vertex = vertex;
    newNode->edgeLength = edgeLength;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Функція для підрахунку кількості елементів у списку
int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Функція для пошуку елемента з заданим значенням та повернення його порядкового номера в списку
int findNodePosition(Node* head, int targetVertex) {
    int position = 0;
    Node* current = head;
    while (current != nullptr) {
        position++;
        if (current->vertex == targetVertex) {
            return position;
        }
        current = current->next;
    }
    // Якщо елемент не знайдено, повертаємо 0
    return 0;
}

// Функція для виведення списку на екран
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << "Вершина: " << current->vertex << ", Довжина ребра: " << current->edgeLength << endl;
        current = current->next;
    }
}

int main() {

    SetConsoleOutputCP(1251);

    // Відкриття файлу для зчитування
    ifstream inputFile("graph_data.txt");
    if (!inputFile) {
        cerr << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    // Читання даних з файлу та створення списку
    Node* head = nullptr;
    int vertex, edgeLength;
    while (inputFile >> vertex >> edgeLength) {
        appendNode(head, vertex, edgeLength);
    }

    // Закриття файлу
    inputFile.close();

    // Виведення списку на екран
    cout << "Список елементів графа:" << endl;
    printList(head);

    // Підрахунок кількості елементів у списку
    int nodeCount = countNodes(head);
    cout << "Кількість елементів у списку: " << nodeCount << endl;

    // Пошук елемента з заданим значенням та виведення його порядкового номера в списку
    int targetVertex;
    cout << "Введіть номер вершини для пошуку: ";
    cin >> targetVertex;
    int position = findNodePosition(head, targetVertex);
    if (position != 0) {
        cout << "Елемент з номером вершини " << targetVertex << " знаходиться на позиції " << position << " у списку." << endl;
    }
    else {
        cout << "Елемент з номером вершини " << targetVertex << " не знайдено у списку." << endl;
    }

    // Видалення списку для уникнення витоків пам'яті
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

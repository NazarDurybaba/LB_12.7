#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

// ��������� �������� ������
struct Node {
    int vertex; // ����� ������� �����
    int edgeLength; // ������� �����
    Node* next; // �������� �� ��������� ������� ������
};

// ������� ��� ��������� �������� � ����� ������
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

// ������� ��� ��������� ������� �������� � ������
int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// ������� ��� ������ �������� � ������� ��������� �� ���������� ���� ����������� ������ � ������
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
    // ���� ������� �� ��������, ��������� 0
    return 0;
}

// ������� ��� ��������� ������ �� �����
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << "�������: " << current->vertex << ", ������� �����: " << current->edgeLength << endl;
        current = current->next;
    }
}

int main() {

    SetConsoleOutputCP(1251);

    // ³������� ����� ��� ����������
    ifstream inputFile("graph_data.txt");
    if (!inputFile) {
        cerr << "������� �������� �����!" << endl;
        return 1;
    }

    // ������� ����� � ����� �� ��������� ������
    Node* head = nullptr;
    int vertex, edgeLength;
    while (inputFile >> vertex >> edgeLength) {
        appendNode(head, vertex, edgeLength);
    }

    // �������� �����
    inputFile.close();

    // ��������� ������ �� �����
    cout << "������ �������� �����:" << endl;
    printList(head);

    // ϳ�������� ������� �������� � ������
    int nodeCount = countNodes(head);
    cout << "ʳ������ �������� � ������: " << nodeCount << endl;

    // ����� �������� � ������� ��������� �� ��������� ���� ����������� ������ � ������
    int targetVertex;
    cout << "������ ����� ������� ��� ������: ";
    cin >> targetVertex;
    int position = findNodePosition(head, targetVertex);
    if (position != 0) {
        cout << "������� � ������� ������� " << targetVertex << " ����������� �� ������� " << position << " � ������." << endl;
    }
    else {
        cout << "������� � ������� ������� " << targetVertex << " �� �������� � ������." << endl;
    }

    // ��������� ������ ��� ��������� ������ ���'��
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

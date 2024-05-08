#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include "../LB_12.7.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestGraphConstruction)
		{
			// Створення тестового файлу з даними
			std::ofstream outputFile("test_graph_data.txt");
			outputFile << "1 10\n";
			outputFile << "2 20\n";
			outputFile << "3 30\n";
			outputFile << "4 40\n";
			outputFile << "5 50\n";
			outputFile.close();

			// Виклик функції побудови графа з файлу
			Node* head = nullptr;
			ifstream inputFile("test_graph_data.txt");
			if (inputFile) {
				int vertex, edgeLength;
				while (inputFile >> vertex >> edgeLength) {
					appendNode(head, vertex, edgeLength);
				}
				inputFile.close();
			}

			// Перевірка кількості елементів у списку
			Assert::AreEqual(5, countNodes(head));

			// Перевірка знаходження вершини у списку
			Assert::AreEqual(3, findNodePosition(head, 3));

			// Видалення списку для уникнення витоків пам'яті
			Node* current = head;
			while (current != nullptr) {
				Node* temp = current;
				current = current->next;
				delete temp;
			}
		}
	};
}
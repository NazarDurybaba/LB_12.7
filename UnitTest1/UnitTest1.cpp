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
			// ��������� ��������� ����� � ������
			std::ofstream outputFile("test_graph_data.txt");
			outputFile << "1 10\n";
			outputFile << "2 20\n";
			outputFile << "3 30\n";
			outputFile << "4 40\n";
			outputFile << "5 50\n";
			outputFile.close();

			// ������ ������� �������� ����� � �����
			Node* head = nullptr;
			ifstream inputFile("test_graph_data.txt");
			if (inputFile) {
				int vertex, edgeLength;
				while (inputFile >> vertex >> edgeLength) {
					appendNode(head, vertex, edgeLength);
				}
				inputFile.close();
			}

			// �������� ������� �������� � ������
			Assert::AreEqual(5, countNodes(head));

			// �������� ����������� ������� � ������
			Assert::AreEqual(3, findNodePosition(head, 3));

			// ��������� ������ ��� ��������� ������ ���'��
			Node* current = head;
			while (current != nullptr) {
				Node* temp = current;
				current = current->next;
				delete temp;
			}
		}
	};
}
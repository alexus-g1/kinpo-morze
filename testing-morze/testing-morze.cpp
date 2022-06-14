#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <algorithm>
#include "../kinpo-morze/functions.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

bool CompareVectors(const vector<string>& Checked, const vector<string>& Correct)
{
	bool Mark = true;
	if (Checked.size() != Correct.size()) {
		Logger::WriteMessage("Different length of vectors!");
		Mark = false;
	}

	for (int i = 0; i < Correct.size() && Mark; i++)
		if (Checked[i] != Correct[i]) {
			Logger::WriteMessage("Not equal!");
			Mark = false;
		}

	return Mark;
}

namespace testingmorze
{
	TEST_CLASS(testingmorze)
	{
	public:
		
		TEST_METHOD(OneDigitTest)
		{
			const string InputString = "...--";//3
			vector<string> InputVector;
			string BiuldString;
			decodeMorze(InputString, BiuldString, InputVector);


			const vector<string> WaitingResult = {
				"ЕЕЕТТ","ЕЕЕМ","ЕЕАТ","ЕЕВ","ЕИТТ",
				"ЕИМ","ЕЮ","ИЕТТ","ИЕМ","ИАТ","ИВ","СТТ","СМ","ЖТ","3"
			};

			Assert::IsTrue(CompareVectors(InputVector, WaitingResult));
		}

		TEST_METHOD(OneDoteTest)
		{
			const string InputString = ".";//E
			vector<string> InputVector;
			string BiuldString;
			decodeMorze(InputString, BiuldString, InputVector);

			vector<string> WaitingResult = { "Е" };
			Assert::IsTrue(CompareVectors(InputVector, WaitingResult));
		}

		TEST_METHOD(OneDashTest)
		{
			const string InputString = "-";//T
			vector<string> InputVector;
			string BiuldString;
			decodeMorze(InputString, BiuldString, InputVector);

			vector<string> WaitingResult = { "Т" };
			Assert::IsTrue(CompareVectors(InputVector, WaitingResult));
		}

		TEST_METHOD(OneLetterTest)
		{
			const string InputString = ".-";//A
			vector<string> InputVector;
			string BiuldString;
			decodeMorze(InputString, BiuldString, InputVector);

			vector<string> WaitingResult = { "ЕТ" ,"А" };
			Assert::IsTrue(CompareVectors(InputVector, WaitingResult));
		}

		TEST_METHOD(OneWordTest)
		{
			const string InputString = "---..-.---";//ЧАЙ
			vector<string> InputVector;
			string BiuldString;
			decodeMorze(InputString, BiuldString, InputVector);

			string MustBeString = "ЧАЙ";
			Assert::IsTrue(find(InputVector.begin(), InputVector.end(), MustBeString) != InputVector.end());
		}

		TEST_METHOD(OneNumberTest)
		{
			const string InputString = ".---------";//10
			vector<string> InputVector;
			string BiuldString;
			decodeMorze(InputString, BiuldString, InputVector);

			string MustBeString = "10";
			Assert::IsTrue(find(InputVector.begin(), InputVector.end(), MustBeString) != InputVector.end());
		}
	};
}

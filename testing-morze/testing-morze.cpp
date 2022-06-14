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
	};
}

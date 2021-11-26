#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-8.1.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char* s{"+-="};
			int b = CountSim("+-=", s);
			Assert::AreEqual(3, b);
		}
	};
}

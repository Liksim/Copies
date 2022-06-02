#include "pch.h"
#include "CppUnitTest.h"
#include "../Copies/CopiesHeader.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace nodTest
{
	TEST_CLASS(nodTest)
	{
	public:
		
		TEST_METHOD(typicalTest)
		{
			int largerNumber = 16, smallerNumber = 12;

			int actualNod = nod(largerNumber, smallerNumber);

			int expNod = 4;

			Assert::AreEqual(expNod, actualNod);
		}

		TEST_METHOD(largerIsMultipleOfSmaller)
		{
			int largerNumber = 6, smallerNumber = 3;

			int actualNod = nod(largerNumber, smallerNumber);

			int expNod = 3;

			Assert::AreEqual(expNod, actualNod);
		}

		TEST_METHOD(nodIsEqualToOne)
		{
			int largerNumber = 5, smallerNumber = 3;

			int actualNod = nod(largerNumber, smallerNumber);

			int expNod = 1;

			Assert::AreEqual(expNod, actualNod);
		}

		TEST_METHOD(numbersAreEqual)
		{
			int largerNumber = 6, smallerNumber = 6;

			int actualNod = nod(largerNumber, smallerNumber);

			int expNod = 6;

			Assert::AreEqual(expNod, actualNod);
		}

		TEST_METHOD(complexTest)
		{
			int largerNumber = 2147483646, smallerNumber = 835132529;

			int actualNod = nod(largerNumber, smallerNumber);

			int expNod = 119304647;

			Assert::AreEqual(expNod, actualNod);
		}
	};
}

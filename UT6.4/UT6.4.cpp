#include "pch.h"
#include "CppUnitTest.h"
#include "../PKR6.4/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT64
{
	TEST_CLASS(UT64)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* L = NULL;

			for (int i = 0; i < 2; i++)
			{
				insert(L, 1);
			}

			increm(L, 1);

			Assert::AreEqual(L->info, 2);
		}
	};
}
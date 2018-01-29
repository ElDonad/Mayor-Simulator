#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace Utilities
{
	template <typename T> bool isVectorContainingItem(const vector <T> &contain, const T &compare)
	{
		int truc = contain.size();
		for (int loop = 0; loop != contain.size(); loop++)
		{
			if (contain[loop] == compare)
				return true;
		}
		return false;
	}
}
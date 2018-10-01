#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x = 2;
	int n = 0;
	const char ones[4] = {'I', 'X', 'C', 'M'};
	const char fives[3] = {'V', 'L', 'D'};
	while(n < 500)
	{
		bool prime = true;
		for(int y = 2; y <= sqrt(x); y++)
		{
			if(x % y == 0)
			{
				prime = false;
				break;
			}
		}
		if(prime)
		{
			int digits[4] = {
				x % 10,
				(x % 100) / 10,
				(x % 1000) / 100,
				x / 1000
			};
			for(int i = 3; i >= 0; i--)
			{
				if(digits[i] < 4)
				{
					for(int j = 0; j < digits[i]; j++)
					{
						cout << ones[i];
					}
				}
				else if(digits[i] == 4)
				{
					cout << ones[i] << fives[i]; 
				}
				else if (digits[i] < 9)
				{
					cout << fives[i];
					for(int j = 5; j < digits[i]; j++)
					{
						cout << ones[i];
					}
				}
				else
				{
					cout << ones[i] << ones[i + 1];
				}
			}
			cout << '\n';
			n++;
		}
		x++;
	}
}


#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int tally(const string a[], int n, string target) //good to go
{
	int t = 0;
	if (n < 0 ) //don't worry about user putting in 2000
		return -1;
	for (int k = 0; k < n; k++)
		if (a[k] == target)
			t++;
	return t;
}

int findMatch(const string a[], int n, string target) //good to go
{
	if (n < 0)
		return -1;
	if (n == 0)
		return 0;
	for (int k = 0; k < n; k++)
	{
		if (a[k] == target)
			return k;
	}
	
	return -1;
}

bool findRun(const string a[], int n, string target, int& begin, int& end) //earliest, not longest
{
	if (n <= 0) // if we examine 0 things, there's no way target will equal anything.
		return false;
	for (int k = 0; k < n ; k++)
		if (a[k] == target)
		{
			begin = k;
			if (k == n - 1) //case when target found in last element of array
			{
				end = k;
				return true;
			}
			else
			{
				for (int j = k; j < n; j++)
				{
					if (a[j] == target)
						end = j; // if true, will start next iteration.
					else
					{
						//streak ends
							return true;
					}
				}
			}
		}	
	return false; //reaches here when first outer loop fails
}//good to go

int positionOfMin(const string a[], int n) //use less than or equal for string comp.
{
	if (n <= 0)
		return -1;
	for (int k = 0; k < n; k++) // want to do this for every character. 
	{
		for (int z = 0; z < n; z++)
		{
			if (k == z) //since we're referring to same array, only check if number is same. 
				continue;
			if (a[k] <= a[z])
			{
			}
			else 
				break;
			if (z == n - 1)
				return k;
		}
		
	}
	return -1;
} //good to go

int moveToEnd(string a[], int n, int pos)
{
	if (pos >= n) //for array size n, last position is n-1. 
		return -1; // an array size of 0 will have no elements.
	if (n < 0 || pos < 0)
		return -1;
	string aPos = a[pos];
	for (int k = pos; k != n-1; k++)//loop until just before reaching last element.
	{
		a[k] = a[k + 1];
	}
	a[n - 1] = aPos;
	return pos;
}//good to go

int moveToBeginning(string a[], int n, int pos)
{
	if (pos >= n) //for array size n, last position is n-1. 
		return -1; // an array size of 0 will have no elements.
	if (n < 0 || pos < 0)
		return -1;
	string bPos = a[pos];
	for (int k = pos; k != 0; k--)
	{
		a[k] = a[k - 1];
	}
	a[0] = bPos;
	return pos;
}

int findDifference(const string a1[], int n1, const string a2[], int n2)
{
	int countTotal = 0; 
	if (n1 < 0 || n2 < 0)
		return -1;
	if (n1 == 0 || n2 == 0)
		return 0;
	if (n1 < n2)
	{
		for (int k = 0; k != n1; k++)
		{
			if (a1[k] == a2[k])
				countTotal++;
			else
				return k;
			if (k == n1 - 1) //n1 has reached end and everything equals
				return n1;
		}
	}
	else
	{
		if (n1 == n2)
		{
			for (int k = 0; k != n1; k++)
			{
				if (a1[k] == a2[k])
					countTotal++;
				else 
					return k;
				if (k == n1 - 1)
					return n1;
			}
		}
		else //when n2<n1
		{
			for (int k = 0; k != n2; k++)
			{
				if (a1[k] == a2[k])
					countTotal++;
				else
					return k;
				if (k == n2 - 1) //assumes last element for n2 equals that for n1. 
					return n2;
			}
		}
	}
	return 0; //will probably never reach here, but added this since I get "not all control paths return value".
}

int eliminateDups(string a[], int n)
{
	if (n < 0)
		return -1;
	if (n == 0)
		return 0;
	int e = 0; //counter for number of unique elements
	for (int k = 0; k + 1< n; k++)
	{
		if (a[k] == a[k + 1])
		{
			int mult = 0; string elim = "";
			for (int j=k;(j+1)!=n;j++)
				if (a[k] == a[j + 1])
				{
					mult++;
					if (j + 1 == n - 1) //at this point, all consecutive elements are identical
						for (int g = k + 1; g != n; g++)
							a[g] = "";
				}
				else
				{
					elim = a[j + 1];
					e++;
					break;
				}
			for (int h = k ; h != k+mult; h++)
				a[h+1] = elim;
		}
		else
			e++;
	}
	
	return e+1; //when array has all unique elements. 
}//interestingly good to go by changing initial e from 1 to 0. come back to. 

bool subsequence(const string a1[], int n1, const string a2[], int n2)
{
	if (n1 < 0 || n2 < 0)
		return false;
	if (n2 > n1) //not possible for a sequence to be subsequence of smaller sequence
		return false;
	if (n2 == 0) //sequence with no elements is subsequence of any sequence. 
		return true;
	int c = 0;
	for (int k = 0; k != n2; k++)
	{
		for (int j = c; j != n1; j++)
		{
			if (a1[j] == a2[k])
			{
				c += j + 1;
				break;
			}
			if (j == n1 - 1)//at this point, subsequence element didn't equal any element in n1, so must be false. 
				return false;
		}
	}

	return true;
}//good to go

int makeMerger(const string a1[], int n1, const string a2[], int n2, string result[], int max)
{
	if (n1 + n2 > max)
		return -1;
	for (int k = 0; k < n1; k++) //checking if a1 is in nondecreasing order. 
	{
		for (int z = k; z < n1; z++)
		{
			if (k == z) 
				continue;
			if (a1[k] <= a1[z])
			{

			}
			else
				return -1;
		}
	}
	for (int k = 0; k < n2; k++) //checking if a2 is in nondecreasing order. 
	{
		for (int z = k; z < n2; z++)
		{
			if (k == z)
				continue;
			if (a2[k] <= a2[z])
			{

			}
			else
				return -1;
		}
	}
	int count1 = 0;
	int count2 = 0;
	for (int k = 0; k < n1; k++)//at this point, a1 and a2 should be in nondecreasing order
	{
		if (count1+count2 == n1 + n2)
			break;
		
		for (int j = 0+count2; j < n2; j++)
		{
			if (a1[k] < a2[j])
			{
				
					result[count1+count2] = a1[k];
					count1++;
					break;
				
			}
			else //already in nondec order
			{
				if (a1[k] > a2[j])
				{
					result[count2 + count1] = a2[j]; //must mean the element in a2 is smallest possible string
					count2++;
				}
				else //when equal
				{
					result[count2+count1] = a2[j];
					count2++;
				}
			}
		}
	}
	if (count1 == n1) //case when all elements in first array come before an element in array2. 
	{
		for (int o = 0; o != n2-count2; o++)
			result[count1 + count2+0] = a2[count2+o];
		count2 = n2;
		
	}
	if (count2 == n2) //vice versa for case above
	{
		for (int t = 0; t != n1-count1; t++)
			result[count1 + count2 + t] = a1[t+count1];
		count1 = n1;
		
	}
	return count1+count2;
}//good to go

int separate(string a[], int n, string separator) //not less means equal too.
{
	if (n < 0)
		return -1;
	int front = 0;
	int back = 0;
	string beg = ""; string end = "";
	for (int k = 0; k != n; k++) //loop to rearrange
	{
		
		if (a[k] < separator)
		{
			//front++;
			//beg = a[k];

		}
		else
		{
			end = a[k];
			for (int j = k + 1; j != n; j++)
			{
				if (a[j] < a[k])
				{
					a[k] = a[j];
					a[j] = end;
					end = a[k];
					//deleted break; 
				}
			}
		}
	}
	for (int m = 0; m != n; m++)
	{
		if (a[m] < separator)
			front++;
	}
		return front;
}//good to go

int main()
{
	const int m = 9;
	string a[m] = { "thor", "romanoff", "parker", "parker", "stark", "stark", "stark", "parker", "parker" };
	//cout << "Enter a list of words with a comma followed by each one: " << endl;
	//getline(cin, a);
	int n = 9;
	// cout << "Enter the number out of the total list you want to check: " << endl;
	//cin >> n; cin.ignore(10000, '\n');
	string target; 
	//cout << Enter word you seek: " << endl; getline(cin, target);
	int begin;
	int end;
	string people[5] = { "parker", "thor", "stark", "banner", "romanoff" };
	string h[7] = { "romanoff", "thor", "rogers", "banner", "", "parker", "rogers" };
	cout << findRun(a, n, "parker", begin, end) << endl;
	cout << begin << endl; cout << end << endl;
	cout << positionOfMin(people, 5) << endl;
	cout << moveToBeginning(people, 5, 2) << endl;
	string cast[5] = { "parker", "thor", "stark", "banner", "romanoff" };
	string roles[4] = { "parker", "thor", "tchalla", "rhodes" };
	string e[5] = { "parker", "parker", "parker", "thor", "thor" };
	cout << "findDifference" << endl;
	cout << findDifference(cast, 5, roles, 4) << endl;
	cout << findDifference(cast, 2, roles, 1) << endl;
	cout << "eliminateDups" << endl;
	cout << eliminateDups(a, 9) << endl;
	cout << eliminateDups(e, 5) << endl;
	cout << "subsequence" << endl;
	string big[10] = { "parker", "thor", "stark", "banner", "romanoff", "stark" };
	string little1[10] = { "thor", "banner", "romanoff" };string little2[10] = { "stark", "thor" }; string little3[10] = { "thor", "stark", "stark" }; string little4[10] = { "thor", "thor", "stark" };
	cout << subsequence(big, 6, little1, 3) << endl;
	cout << subsequence(big, 6, little2, 2) << endl;
	cout << subsequence(big, 6, little3, 3) << endl;
	cout << subsequence(big, 6, little4, 3) << endl;

	string x[5] = { "banner", "rhodes", "rogers", "stark", "tchalla" };
	string y[4] = { "parker", "rogers", "rogers", "thor" };
	string zed[20];
	cout << "makeMerger" << endl;
	cout << makeMerger(x, 5, y, 4, zed, 20) << endl;
	string x2[4] = { "rhodes", "rhodes", "tchalla", "thor" };
	string y2[4] = { "banner", "parker", "rhodes", "rogers" };
	string zed2[10];
	cout << makeMerger(x2, 4, y2, 4, zed2, 10) << endl; 
	cout << "separate" << endl;
	string f[6] = { "rhodes", "banner", "stark", "parker", "thor", "rogers" };
	string g[4] = { "romanoff", "rogers", "thor", "banner" };
	string gee[4] = { "romanoff", "thor", "banner", "parker" };
	cout << separate(f, 6, "romanoff") << endl;
	cout << separate(g, 4, "rogers") << endl;
	cout << separate(h, 7, "rogers") << endl; 
	cout << subsequence(h, 7, gee, 4) << endl;
}


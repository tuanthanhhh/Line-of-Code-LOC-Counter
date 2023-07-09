#include "LineOfCode.h"

int totalLinesOfCode = 0;
int main()
{
	string Link;

	// Check the Path. If the Path is Invalid, type again 

	cout << "===========================================================================\n" << endl;
	cout << "                    Line Of Code (LOC) Counter\n" << endl;
	cout << "===========================================================================\n" << endl;
	while (true)
	{
		cout << "Enter the path to the file or directory:    \n" << endl;
		getline(cin, Link);
		if (filesystem::exists(Link))
		{
			cout << "Valid Path" << endl;
			cout << "\n";
			break;
		}
		else
		{
			cout << "Invalid Path. Again" << endl;
			cout << "\n";
		}
	}
	cout << "===========================================================================\n" << endl;

	//Check path is directory or file
	if (std::filesystem::is_directory(Link))
	{
		listdir(Link);
	}
	else if (std::filesystem::is_regular_file(Link))
	{
		int lengthOfLinkFile = Link.length();
		if (Link[lengthOfLinkFile - 2] == 'p' && Link[lengthOfLinkFile - 1] == 'y')
			totalLineInPython(Link);
		else if (Link[lengthOfLinkFile - 4] == 'h' && Link[lengthOfLinkFile - 3] == 't' && Link[lengthOfLinkFile - 2] == 'm' && Link[lengthOfLinkFile - 1] == 'l')
			totalLineInHTML(Link);
		else
			totalLines(Link);
	}
	cout << "===========================================================================\n" << endl;
	cout << "Total lines of code: " << totalLinesOfCode << endl;
	getchar();
	return 0;
}
#include "LineOfCode.h"

int totalLinesOfCode = 0;
int main()
{
	string pathOfFiles;

	// Check the Path. If the Path is Invalid, type again 

	cout << "===========================================================================\n" << endl;
	cout << "                    Line Of Code (LOC) Counter\n" << endl;
	cout << "===========================================================================\n" << endl;
	while (true)
	{
		cout << "Enter the path to the file or directory:    \n" << endl;
		getline(cin, pathOfFiles);
		if (filesystem::exists(pathOfFiles))
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
	if (std::filesystem::is_directory(pathOfFiles))
	{
		listDir(pathOfFiles);
	}
	else if (std::filesystem::is_regular_file(pathOfFiles))
	{
		int lengthOfPathFile = pathOfFiles.length();
		if (pathOfFiles[lengthOfPathFile - 2] == 'p' && pathOfFiles[lengthOfPathFile - 1] == 'y')
			totalLineInPython(pathOfFiles);
		else if (pathOfFiles[lengthOfPathFile - 4] == 'h' && pathOfFiles[lengthOfPathFile - 3] == 't' && pathOfFiles[lengthOfPathFile - 2] == 'm' && pathOfFiles[lengthOfPathFile - 1] == 'l')
			totalLineInHTML(pathOfFiles);
		else
			totalLines(pathOfFiles);
	}
	cout << "===========================================================================\n" << endl;
	cout << "Total lines of code: " << totalLinesOfCode << endl;
	getchar();
	return 0;
}
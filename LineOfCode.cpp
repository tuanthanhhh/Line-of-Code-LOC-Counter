#include "LineOfCode.h"


extern int totalLinesOfCode;

void totalLines(string pathOfFile)
{
	int SumOfLines = 0;
	int checkCommentLine = 0;
	vector<string> lines;
	string line;
	int count = 0;
	ifstream outfile;
	outfile.open(pathOfFile, ios::in);
	while (getline(outfile, line))
	{
		lines.push_back(line);
		int lengthOfLine = line.length();
		if (checkCommentLine == 0)
		{
			if (line == "")
			{
				count++;
			}

			for (int i = 0; i < lengthOfLine - 1; i++)
			{
				if (line[i] == '/' && line[i + 1] == '/')
				{
					count++;
				}
				else
				{
					for (int i = 0; i < lengthOfLine - 1; i++)
					{
						if (line[i] == '/' && line[i + 1] == '*')
						{
							count++;
							checkCommentLine = 1;
							break;
						}
						if (checkCommentLine == 1)
							break;
					}
				}
			}

		}
		if (checkCommentLine == 1)
		{
			if (line[lengthOfLine - 2] == '*' && line[lengthOfLine - 1] == '/')
				checkCommentLine = 0;
			else
				count++;
		}
	}

	for (const auto& i : lines)
	{
		SumOfLines++;
	}
	outfile.close();
	totalLinesOfCode = totalLinesOfCode + SumOfLines - count;;
}

// check LOC for .Py(python file)
void totalLineInPython(string pathOfFile)
{
	int SumOfLines = 0;
	vector<string> lines;
	string line;
	int count = 0;
	ifstream outfile;
	outfile.open(pathOfFile, ios::in);
	while (getline(outfile, line))
	{
		lines.push_back(line);
		int lengthOfLine = line.length();
		if (line == "")
		{
			count++;
		}
		for (int i = 0; i < lengthOfLine - 1; i++)
		{
			if (line[i] == '#')
			{
				count++;
				break;
			}
		}
	}

	for (const auto& i : lines)
	{
		SumOfLines++;
	}
	outfile.close();
	totalLinesOfCode = totalLinesOfCode + SumOfLines - count;
}

//Check LOC for .HTML(HTML file)
void totalLineInHTML(string pathOfFile)
{
	int SumOfLines = 0;
	int checkCommentLine = 0;
	vector<string> lines;
	string line;
	int count = 0;
	ifstream outfile;
	outfile.open(pathOfFile, ios::in);
	while (getline(outfile, line))
	{
		lines.push_back(line);
		int lengthOfLine = line.length();
		if (checkCommentLine == 0)
		{
			if (line == "")
			{
				count++;
			}
			else
			{
				for (int i = 0; i < lengthOfLine - 1; i++)
				{
					if (line[i] == '<' && line[i + 1] == '!' && line[i + 2] == '-' && line[i + 3] == '-')
					{
						count++;
						checkCommentLine = 1;
					}
					if (checkCommentLine == 1)
						break;
				}
			}
		}
		if (checkCommentLine == 1)
		{
			if (line[lengthOfLine - 3] == '-' && line[lengthOfLine - 2] == '-' && line[lengthOfLine - 1] == '>')
				checkCommentLine = 0;
			else
				count++;
		}
	}

	for (const auto& i : lines)
	{
		SumOfLines++;
	}
	outfile.close();
	totalLinesOfCode = totalLinesOfCode + SumOfLines - count;
}

void listDir(string folderPath)
{
	int numberOfFiles = 0;
	for (const auto& entry : filesystem::directory_iterator(folderPath)) {
		if (entry.is_regular_file()) {
			numberOfFiles++;
			cout << entry.path() << endl;
			string typeFile = entry.path().string();
			int lengthOfLink = typeFile.length();
			if (typeFile[lengthOfLink - 2] == 'p' && typeFile[lengthOfLink - 1] == 'y')
				totalLineInPython(typeFile);
			else if (typeFile[lengthOfLink - 4] == 'h' && typeFile[lengthOfLink - 3] == 't' && typeFile[lengthOfLink - 2] == 'm' && typeFile[lengthOfLink - 1] == 'l')
				totalLineInHTML(typeFile);
			else
				totalLines(typeFile);
		}
	}
	cout << "Number of file in directory: " << numberOfFiles << endl;
}
#include "LineOfCode.h"


extern int totalLinesOfCode;

void totalLines(string a)
{
	int Sum = 0;
	int check = 0;
	vector<string> lines;
	string line;
	int count = 0;
	ifstream outfile;
	outfile.open(a, ios::in);
	while (getline(outfile, line))
	{
		lines.push_back(line);
		int n = line.length();
		if (check == 0)
		{
			if (line == "")
			{
				count++;
			}

			for (int i = 0; i < n - 1; i++)
			{
				if (line[i] == '/' && line[i + 1] == '/')
				{
					count++;
				}
				else
				{
					for (int i = 0; i < n - 1; i++)
					{
						if (line[i] == '/' && line[i + 1] == '*')
						{
							count++;
							check = 1;
							break;
						}
						if (check == 1)
							break;
					}
				}
			}

		}
		if (check == 1)
		{
			if (line[n - 2] == '*' && line[n - 1] == '/')
				check = 0;
			else
				count++;
		}
	}

	for (const auto& i : lines)
	{
		Sum++;
	}
	outfile.close();
	totalLinesOfCode = totalLinesOfCode + Sum - count;;
}

// check LOC for .Py(python file)
void totalLineInPython(string a)
{
	int Sum = 0;
	vector<string> lines;
	string line;
	int count = 0;
	ifstream outfile;
	outfile.open(a, ios::in);
	while (getline(outfile, line))
	{
		lines.push_back(line);
		int n = line.length();
		if (line == "")
		{
			count++;
		}
		for (int i = 0; i < n - 1; i++)
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
		Sum++;
	}
	outfile.close();
	totalLinesOfCode = totalLinesOfCode + Sum - count;
}

//Check LOC for .HTML(HTML file)
void totalLineInHTML(string a)
{
	int Sum = 0;
	int check = 0;
	vector<string> lines;
	string line;
	int count = 0;
	ifstream outfile;
	outfile.open(a, ios::in);
	while (getline(outfile, line))
	{
		lines.push_back(line);
		int n = line.length();
		if (check == 0)
		{
			if (line == "")
			{
				count++;
			}
			else
			{
				for (int i = 0; i < n - 1; i++)
				{
					if (line[i] == '<' && line[i + 1] == '!' && line[i + 2] == '-' && line[i + 3] == '-')
					{
						count++;
						check = 1;
					}
					if (check == 1)
						break;
				}
			}
		}
		if (check == 1)
		{
			if (line[n - 3] == '-' && line[n - 2] == '-' && line[n - 1] == '>')
				check = 0;
			else
				count++;
		}
	}

	for (const auto& i : lines)
	{
		Sum++;
	}
	outfile.close();
	totalLinesOfCode = totalLinesOfCode + Sum - count;
}

void listdir(string a)
{
	int k = 0;
	string folderPath = a;
	for (const auto& entry : filesystem::directory_iterator(folderPath)) {
		if (entry.is_regular_file()) {
			k++;
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
	cout << "Number of file in directory: " << k << endl;
}
#include "pch.h"
#include "Interview.h"
#include <fstream>
#include <iostream>

using dsUmap = std::unordered_map<std::string, std::string>;
dsUmap Interview::dialogue = Interview::fillUmap("questions.txt", "answers.txt");

dsUmap Interview::fillUmap(const std::string & fn, const std::string & sFn) {
	std::ifstream _qFile(fn);
	std::ifstream _aFile (sFn);
	if (!_qFile || !_aFile) {
		std::cerr << "Couldn't open file!\n";
		exit(0);
	}
	std::string lineToReadFrom_qFile;
	std::string lineToReadFrom_aFile;
	dsUmap tempUmap;
	while (!_qFile.eof() && !_aFile.eof()) {
		getline(_qFile, lineToReadFrom_qFile);
		getline(_aFile, lineToReadFrom_aFile);
		tempUmap.insert(std::make_pair(lineToReadFrom_qFile, lineToReadFrom_aFile));
	}
	return tempUmap;
}
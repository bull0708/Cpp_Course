#pragma once
#include <string>
#include "Entry.h"

class EntryFile : public Entry {
public:
	EntryFile(std::string, std::string);
	~EntryFile(void);
	int getSize();
	bool isFolder();
	void print();
	void removeEntry();

private:
	std::string mContent;
};

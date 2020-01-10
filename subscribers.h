#pragma once
#include "subscriber.h"
#include <string>
#include <fstream>
#include <time.h>
#include <string>



class ConsolePrint : public sub {
public:
	void Print(std::vector<std::shared_ptr<TFigure>>& v) override {
		for (unsigned int i = 0; i < v.size(); i++) {
			v[i]->Print(std::cout);
		}
	}
};


class FilePrint : public sub {
private:
	unsigned int count = 1;

public:
	void Print(std::vector<std::shared_ptr<TFigure>>& v) override {
		std::string filename = "";
		filename = "file_" + std::to_string(count) + ".txt";
		count++;
		std::ofstream file(filename);
		for (unsigned int i = 0; i < v.size(); i++) {
			v[i]->Print(file);
		}
	}

};
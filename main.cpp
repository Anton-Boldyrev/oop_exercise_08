#include "stack.h"
#include "allocator.h"
#include "rec.h"
#include <algorithm>
#include <map>
#include <string>


int main() {
	containers::TStack<TRectangle<int>, my_allocator<TRectangle<int>, 500>> s;
	std::string cmd;
	int index;
	std::cout << "ps - to push figure to stack\n"
			  << "i  - to insert figure to stack\n"
			  << "p  - to pop figure from Stack\n"
			  << "e  - to delete figure from Stack\n"
			  << "t  - to show first figure\n"
			  << "f  - to print figures\n"
			  << "m  - to show work allocator with map\n"
			  << "ex - to finish execution of program\n";
	while (true) {
		std::cin >> cmd;
		if (cmd == "ps") {
			std::cout << "enter coordinates\n";
			TRectangle<int> fig;
			try {
				TRectangle<int> tmp(std::cin);
				fig = tmp;
			} catch(std::exception& err) {
				std::cout << err.what() << std::endl;
				continue;
			}
			s.push(fig);
		} else if (cmd == "i") {
			std::cout << "enter index\n";
			std::cin >> index;
			auto p = s.begin();
			try {
				s.advance(p, index);
			} catch (std::exception& err) {
				std::cout << err.what() << std::endl;
				continue;
			}
			std::cout << "enter coordinates\n";
			TRectangle<int> fig;
			try {
				TRectangle<int> tmp(std::cin);
				fig = tmp;
			} catch(std::exception& err) {
				std::cout << err.what() << std::endl;
				continue;
			}
			s.insert(p, fig);
		} else if (cmd == "p") {
			try {
				s.pop();
			} catch(std::exception& err) {
				std::cout << err.what() << std::endl;
				continue;
			}
		} else if (cmd == "e") {
			std::cout << "enter index\n";
			std::cin >> index;
			auto p = s.begin();
			try {
				s.advance(p, index);
			} catch (std::exception& err) {
				std::cout << err.what() << std::endl;
				continue;
			}
			try {
				s.erase(p);
			} catch (std::exception& err) {
				std::cout << err.what() << std::endl;
				continue;
			}
		
		} else if (cmd == "t") {
			try {
				s.top();
			} catch (std::exception& err) {
				std::cout << err.what() << std::endl;
				continue;
			}
			(s.top()).Print();
		} else if (cmd == "f") {
			std::for_each(s.begin(), s.end(), [] (TRectangle<int> tmp) {return tmp.Print();});
		} else if (cmd == "ex") {
			break;
		} else if (cmd == "m"){
			std::map<int, int, std::less<>, my_allocator<std::pair<const int, int>, 1000>> tree;
			for (int i = 0; i < 6; i++) {
				tree[i] = i * i;
			}
			std::for_each(tree.begin(), tree.end(), [](std::pair<int, int> X) {std::cout << X.first << " " << X.second << " ";});
			std::cout << std::endl;
		} else {
			std::cout << "Wrong comand\n";
			continue;
		}

	}
	
}


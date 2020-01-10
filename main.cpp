#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "factory.h"
#include "subscribers.h"
#include "rectangle.h"
#include "rhombus.h"
#include "trapezoid.h"


int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "./oop_exercise_08 N\n";
		return 0;
	}

	unsigned int BufSize = std::atoi(argv[1]);
	std::vector<std::shared_ptr<TFigure>> f;
	std::string cmd;
	Factory factory;
	bool done = false;
	std::condition_variable rd;
	std::condition_variable hd;
	std::mutex mutex;
	int in = 1;
	std::vector<std::shared_ptr<sub>> s;
	s.push_back(std::make_shared<ConsolePrint>());
	s.push_back(std::make_shared<FilePrint>());
	std::thread sub([&]() {
		std::unique_lock<std::mutex> sub_lock(mutex);
		while (!done) {
			rd.wait(sub_lock);
			if (done) {
				hd.notify_all();
				break;
			}
			for (unsigned int i = 0; i < s.size(); i ++) {
				s[i]->Print(f);

			}
			in++;
			f.resize(0);
			hd.notify_all();
		}
	});

	std::cout << "enter - to enter " << BufSize << " figures\n"
        		 "exit - to finish execution of program\n";
	while(cmd != "exit") {
        
        std::cin >> cmd;
        if (cmd != "exit") {
            std::unique_lock<std::mutex> main_lock(mutex);
            for (unsigned int i = 0; i < BufSize; i++) {
                f.push_back(factory.FigureCreate(std::cin));
                if (f.size() == BufSize) {
        			std::cout << "Buffer is full!\n";
        		}
            }
            rd.notify_all();
            hd.wait(main_lock);
        } 
    }
    done = true;
    rd.notify_all();
    sub.join();
    return 0;

}

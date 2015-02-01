#pragma once
#include <string>
#include <fstream>
#include <iostream>
#ifndef TEMPLATE_HPP_
#define TEMPLATE_HPP_

template <class T1> class ToFile {
	public:
		ToFile();
		std::string name[5];
		T1 score[5];
		void addElement(std::string n, T1 m);
		void write();
		void read();
		unsigned int returnSize();
		std::string returnName(unsigned int i);
		T1 returnScore(unsigned int i);
	private:
		unsigned int a;
		std::string tmp0;
};


#endif

#pragma once
#include "TermsBSTNode.h"
#include <fstream>
#include <cstring>

class TermsBST
{
private:
	TermsBSTNode* root;
	void	post_destructor(TermsBSTNode* node);
	void	post_delete(TermsBSTNode* p, TermsBSTNode* pp, std::string name, int &num);
	void	in_print(TermsBSTNode* node, std::ofstream &fout);

public:
	TermsBST();
	~TermsBST();

	TermsBSTNode* getRoot();

	void	insert(TermsBSTNode* node);
	void	print(std::ofstream &fout);
	bool	default_delete(std::string date);
	void	name_delete(std::string name, int &num);
};
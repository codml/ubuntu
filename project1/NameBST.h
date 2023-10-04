#pragma once
#include "NameBSTNode.h"
#include <fstream>

class NameBST
{
private:
	NameBSTNode* root;
	void	post_destructor(NameBSTNode* node);
	void	post_delete(NameBSTNode* p, NameBSTNode* pp, std::string date);
	void	in_print(NameBSTNode* node, std::ofstream &fout);

public:
	NameBST();
	~NameBST();

	NameBSTNode* 	getRoot();

	void			insert(NameBSTNode* node);
	NameBSTNode*	search(std::string name);
	void			print(std::ofstream &fout);
	bool			default_delete(std::string name);
	void			date_delete(std::string date);
};
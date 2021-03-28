#pragma once
#include "tinyxml\tinyxml.h"
#include "..\\MenuComponents\MenuComponents.h"
#include <iostream>

int dump_attribs_to_stdout(TiXmlElement* pElement);
void dump_to_stdout(TiXmlNode* pParent);
void dump_to_stdout(const char* pFilename);

using namespace std;

class TextSystem {
public:
	void Print(const string pFilename);
	
	void Init(const string pFilename);
	
	vector<MenuBlock>& GetMenues(){
		return menues;
	}

private:
	vector<MenuBlock> menues;
	TiXmlDocument xmlFile;

	void SetMenuFromFile(TiXmlNode* pParent);

	void SetMenuBlock(TiXmlElement* pElement);

	void SetButton(TiXmlElement* pElement);

	MenuBlock* FindMenuByName(string name) {
		for (auto& menu : menues)
			if (menu.GetName() == name)
				return &menu;
		return nullptr;
	}
};
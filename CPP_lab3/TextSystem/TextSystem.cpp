#include"TextSystem.h"
#include "tinyxml\tinyxml.h"
#include <iostream>


int dump_attribs_to_stdout(TiXmlElement* pElement) {
	if (!pElement) return 0;

	TiXmlAttribute* pAttrib = pElement->FirstAttribute();
	int i = 0;
	int ival;
	double dval;
	printf("\n");
	while (pAttrib) {
		printf("%s: value=[%s]", pAttrib->Name(), pAttrib->Value());
		printf("\n");
		i++;
		pAttrib = pAttrib->Next();
	}
	return i;
}

void dump_to_stdout(TiXmlNode* pParent) {
	if (!pParent) return;

	TiXmlNode* pChild;
	TiXmlText* pText;
	int t = pParent->Type();
	int num;

	switch (t) {
	case TiXmlNode::TINYXML_DOCUMENT:
		printf("Document");
		break;

	case TiXmlNode::TINYXML_ELEMENT:
		printf("Element [%s]", pParent->Value());
		num = dump_attribs_to_stdout(pParent->ToElement());
		break;

	case TiXmlNode::TINYXML_COMMENT:
		printf("Comment: [%s]", pParent->Value());
		break;

	case TiXmlNode::TINYXML_UNKNOWN:
		printf("Unknown");
		break;

	case TiXmlNode::TINYXML_TEXT:
		pText = pParent->ToText();
		printf("Text: [%s]", pText->Value());
		break;

	case TiXmlNode::TINYXML_DECLARATION:
		printf("Declaration");
		break;
	default:
		break;
	}
	printf("\n");
	for (pChild = pParent->FirstChild(); pChild != 0; pChild = pChild->NextSibling()) {
		dump_to_stdout(pChild);
	}
}

// load the named file and dump its structure to STDOUT
void dump_to_stdout(const char* pFilename)
{
	TiXmlDocument doc(pFilename);
	bool loadOkay = doc.LoadFile();
	if (loadOkay) {
		printf("\n%s:\n", pFilename);
		dump_to_stdout(&doc); 
	}
	else {
		printf("Failed to load file \"%s\"\n", pFilename);
	}
}


void TextSystem::Print(const string pFilename) {
	TiXmlDocument doc = TiXmlDocument(pFilename.c_str());
	bool loadOkay = doc.LoadFile();
	if (loadOkay) {
		dump_to_stdout(&doc);
	}
	else {
		cout << "Failed to load file " << pFilename << endl;
	}
}

void TextSystem::Init(const string pFilename) {
	xmlFile = TiXmlDocument(pFilename.c_str());
	bool loadOkay = xmlFile.LoadFile();
	if (loadOkay) {
		SetMenuFromFile(&xmlFile);
	}
	else {
		cout << "Failed to load file " << pFilename << endl;
	}
}

void TextSystem::SetMenuFromFile(TiXmlNode* pParent) {
	if (!&pParent) return;

	TiXmlNode* pChild;
	TiXmlText* pText;
	int type = pParent->Type();
	size_t attrCount;

	if (type == TiXmlNode::TINYXML_ELEMENT) {
		if ((string)pParent->Value() == "menu")
			SetMenuBlock(pParent->ToElement());
		else if ((string)pParent->Value() == "button")
			SetButton(pParent->ToElement());
	}

	for (pChild = pParent->FirstChild(); pChild != 0; pChild = pChild->NextSibling()) {
		SetMenuFromFile(pChild);
	}
}

void TextSystem::SetMenuBlock(TiXmlElement* pElement) {
	if (!pElement) return;
	MenuBlock menuBlock;

	string name = "";
	classXY coord;
	classXY size;

	TiXmlAttribute* pAttrib = pElement->FirstAttribute();

	while (pAttrib) {
		if ((string)pAttrib->Name() == "name") {
			name = pAttrib->Value();
		}
		else if ((string)pAttrib->Name() == "xCoord") {
			coord.x = stof(pAttrib->Value());
		}
		else if ((string)pAttrib->Name() == "yCoord") {
			coord.y = stof(pAttrib->Value());
		}
		else if ((string)pAttrib->Name() == "xSize") {
			size.x = stof(pAttrib->Value());
		}
		else if ((string)pAttrib->Name() == "ySize") {
			size.y = stof(pAttrib->Value());
		}
		pAttrib = pAttrib->Next();
	}

	menuBlock.SetName(name);
	menuBlock.SetCoord(coord);
	menuBlock.SetSize(size);
	menues.push_back(menuBlock);
}

void TextSystem::SetButton(TiXmlElement* pElement) {
	if (!pElement) return;
	string name = "";
	classXY coord;
	classXY size;
	string menuName = "";
	string submenuName = "";

	TiXmlAttribute* pAttrib = pElement->FirstAttribute();

	while (pAttrib) {
		if ((string)pAttrib->Name() == "name") {
			name = pAttrib->Value();
		}
		else if ((string)pAttrib->Name() == "xCoord") {
			coord.x = stof(pAttrib->Value());
		}
		else if ((string)pAttrib->Name() == "yCoord") {
			coord.y = stof(pAttrib->Value());
		}
		else if ((string)pAttrib->Name() == "xSize") {
			size.x = stof(pAttrib->Value());
		}
		else if ((string)pAttrib->Name() == "ySize") {
			size.y = stof(pAttrib->Value());
		}
		else if ((string)pAttrib->Name() == "menuName") {
			menuName = pAttrib->Value();
		}
		else if ((string)pAttrib->Name() == "submenuName") {
			submenuName = pAttrib->Value();
		}
		pAttrib = pAttrib->Next();
	}

	MenuBlock* menu = FindMenuByName(menuName);
	MenuBlock* submenu = FindMenuByName(submenuName);
	MyButton button(name, coord, size, submenu);
	if (menu != nullptr)
		menu->AddBut(button);
}
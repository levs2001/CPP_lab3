#include "Singleton.h"

SingletonMenu* SingletonMenu::pSingletonMenu_s = nullptr;

SingletonMenu* SingletonMenu::GetInstance() {
	if (pSingletonMenu_s == nullptr) {
		pSingletonMenu_s = new SingletonMenu();
	}
	return pSingletonMenu_s;
}
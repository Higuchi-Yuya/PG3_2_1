#include <stdio.h>
#include <list>
#include <iostream>

int main() {
	std::list<const char*> Yamanote={ "Tokyo","Kanda","Akihabara","Okachimachi","Ueno",
									  "Uguisudani","Nippori","Tabata","Komagome",
							          "Sugamo","Otsuka","Ikebukuro","Mejiro" ,"Takadanobaba",
							          "Shin-Okubo","Shinjuku","Yoyogi","Harajuku","Shibuya",
							          "Ebisu","Meguro","Gotanda","Osaki","Shinagawa",
									  "Tamachi","Hamamatsucho","Shimbashi","Yurakucho"};
	// 出力
	for (std::list<const char*>::iterator itr = Yamanote.begin(); itr != Yamanote.end(); ++itr) {
		std::cout << *itr << std::endl;
	}
	//西日暮里を挿入
	for (std::list<const char*>::iterator itr = Yamanote.begin(); itr != Yamanote.end(); ++itr) {
		if (*itr == "Tabata") {
			itr = Yamanote.insert(itr, "Nishi-Nippori");
			++itr;
		}
	}
	// 出力
	for (std::list<const char*>::iterator itr = Yamanote.begin(); itr != Yamanote.end(); ++itr) {
		std::cout << *itr << std::endl;
	}

	// 高輪ゲートウェイを挿入
	for (std::list<const char*>::iterator itr = Yamanote.begin(); itr != Yamanote.end(); ++itr) {
		if (*itr == "Tamachi") {
			itr = Yamanote.insert(itr, "Takanawa Gateway");
			++itr;
		}
	}
	// 出力
	for (std::list<const char*>::iterator itr = Yamanote.begin(); itr != Yamanote.end(); ++itr) {
		std::cout << *itr << std::endl;
	}
	return 0;

}
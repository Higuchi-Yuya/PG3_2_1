#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// <summary>
/// 担当者の情報
/// </summary>
class PersonInCharge
{
public:
	enum ClassNum
	{
		LE2A,
		LE2B,
	};

	// 表示
	int GetPicID() { return this->picID; }
	// picIDの表示
	void DrawPicID();
	// 名前の表示
	void DrawContent();
	// クラスの表示
	void DrawClss();

	// 担当者の情報の全体を表示
	void DrawPicAllInfo();

	// セッター
	void SetPicID(int picID) { this->picID = picID; }
	void SetContent(const char* content) { strcpy_s(this->content, 16, content); }
	void SetClassNum(int classNum) { this->classNumber = classNum; }
private:
	int picID = 0;
	char content[16];
	int classNumber = 0;
	ClassNum classNum = ClassNum::LE2A;
};


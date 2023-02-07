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
	// 

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


#include "PersonInCharge.h"

void PersonInCharge::DrawPicID()
{
	printf("picID:%d ", picID);
}

void PersonInCharge::DrawContent()
{
	printf("Name:%s\n", content);
}

void PersonInCharge::DrawClss()
{
	switch (classNumber)
	{
	case 0:
		classNum = ClassNum::LE2A;
		break;
	case 1:
		classNum = ClassNum::LE2B;
		break;
	default:
		break;
	}
	switch (classNum)
	{
	case PersonInCharge::LE2A:
		printf("Class:LE2A ");
		break;
	case PersonInCharge::LE2B:
		printf("Class:LE2B ");
		break;
	default:
		break;
	}
	
}

void PersonInCharge::DrawPicAllInfo()
{
	DrawPicID();
	DrawClss();
	DrawContent();
}

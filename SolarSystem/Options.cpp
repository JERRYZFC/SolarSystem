#include "stdafx.h"
#include "Options.h"

#include "SolarSystem.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Options::Options()
	: gammaCorrection(false), showSkyBox(true), drawShadows(true), drawTextures(true),
	translationSpeed(100), rotationSpeed(100), scrollSpeed(100), showBillboard(false)
{
}


Options::~Options()
{
}


bool Options::Load()
{
	int res = static_cast<int>(theApp.GetProfileInt(L"options", L"gamma", 0));
	gammaCorrection = (res != 0 ? true : false);

	res = static_cast<int>(theApp.GetProfileInt(L"options", L"skyBox", 1));
	showSkyBox = (res != 0 ? true : false);

	res = static_cast<int>(theApp.GetProfileInt(L"options", L"shadows", 1));
	drawShadows = (res != 0 ? true : false);

	res = static_cast<int>(theApp.GetProfileInt(L"options", L"textures", 1));
	drawTextures = (res != 0 ? true : false);

	translationSpeed = theApp.GetProfileInt(L"options", L"translationSpeed", 100);
	rotationSpeed = theApp.GetProfileInt(L"options", L"rotationSpeed", 100);
	scrollSpeed = theApp.GetProfileInt(L"options", L"scrollSpeed", 100);

	res = static_cast<int>(theApp.GetProfileInt(L"options", L"showBillboard", 0));
	showBillboard = (res != 0 ? true : false);


	return true;
}


bool Options::Save()
{
	theApp.WriteProfileInt(L"options", L"gamma", gammaCorrection ? 1 : 0);
	theApp.WriteProfileInt(L"options", L"skyBox", showSkyBox ? 1 : 0);
	theApp.WriteProfileInt(L"options", L"shadows", drawShadows ? 1 : 0);
	theApp.WriteProfileInt(L"options", L"textures", drawTextures ? 1 : 0);

	theApp.WriteProfileInt(L"options", L"translationSpeed", (int)translationSpeed);
	theApp.WriteProfileInt(L"options", L"rotationSpeed", (int)rotationSpeed);
	theApp.WriteProfileInt(L"options", L"scrollSpeed", (int)scrollSpeed);

	theApp.WriteProfileInt(L"options", L"showBillboard", showBillboard ? 1 : 0);

	return false;
}

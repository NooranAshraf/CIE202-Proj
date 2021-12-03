#include "Fuse.h"
#include "../UI/UI.h"
Fuse::Fuse(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{}

void Fuse::Draw(UI* pUI)
{
	//Call output class and pass battery drawing info to it.
	pUI->DrawResistor(*m_pGfxInfo); //update to draw battery

}

void Fuse::Operate()
{

}

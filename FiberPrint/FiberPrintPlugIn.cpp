#include "FiberPrintPlugIn.h"


FiberPrintPlugIn::FiberPrintPlugIn()
{
}


FiberPrintPlugIn::FiberPrintPlugIn(WireFrame *ptr_frame)
{
	ptr_frame_ = ptr_frame;
	ptr_graphcut_ = new ADMMCut(ptr_frame);
	ptr_seqanalyzer_ = new FFAnalyzer(ptr_graphcut_);
}


FiberPrintPlugIn::FiberPrintPlugIn(WireFrame *ptr_frame, 
	FiberPrintPARM *ptr_parm, char *path)
{
	ptr_frame_ = ptr_frame;
	ptr_graphcut_ = new ADMMCut(ptr_frame, ptr_parm, path);
	ptr_seqanalyzer_ = new FFAnalyzer(ptr_graphcut_, ptr_parm, path);
	ptr_procanalyzer_ = new ProcessAnalyzer(ptr_seqanalyzer_, path);
}


FiberPrintPlugIn::~FiberPrintPlugIn()
{
	delete ptr_graphcut_;
	ptr_graphcut_ = NULL;

	delete ptr_seqanalyzer_;
	ptr_seqanalyzer_ = NULL;
}


void FiberPrintPlugIn::Print()
{
	//ptr_graphcut_->MakeLayers();
	//cout << "Graph Cut completed." << endl;


	if (!ptr_seqanalyzer_->LayerPrint())
	{
		cout << "Model not printable!" << endl;
		getchar();

		return;
	}
	printf("FiberPrint done.\n");
	//ptr_procanalyzer_->ProcPrint();
	//ptr_seqanalyzer_->WritePathRender();

	//ptr_seqanalyzer_->BruteForcePrint();
}


void FiberPrintPlugIn::Debug()
{

}
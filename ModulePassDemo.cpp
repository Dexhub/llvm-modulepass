#define DEBUG_TYPE "times"

#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/InstIterator.h"
#include "llvm/Support/Compiler.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Constant.h"
#include "llvm/ADT/APInt.h"
#include "llvm/ADT/Twine.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/ADT/Statistic.h"


//FDFSDGFDGREGTRYRTYR
using namespace llvm;
   STATISTIC(PrintCounter, "Number of printf functions calls");
   STATISTIC(LoadCounter, "Number of Load instrunction");
   STATISTIC(StoreCounter, "Number of Store Instructions");
   STATISTIC(FunctionCounter, "Number of Function Calls Encountered ");
   STATISTIC(InstCounter, "Total number of Instructions Except the Function call");
   STATISTIC(OtherFunctionCounter,"Number of Function calls apart from Printf");
   STATISTIC(BasicBlockCounter, "Total number of Basic Blocks");
	
namespace {
    struct ModulePassDemo : public ModulePass { 
    static char ID; // Pass identification



ModulePassDemo() : ModulePass(ID) {}  
    	virtual bool runOnModule(Module &M) {

/*
llvm::GlobalVariable    *globalcounter = new llvm::GlobalVariable(llvm::IntegerType::get(llvm::getGlobalContext(), 8), false, llvm::GlobalVariable::InternalLinkage, llvm::ConstantInt::get(llvm::getGlobalContext(), llvm::APInt(8, 0, false)), "GlobalCounter");

*/


errs()<<"==========Start============\n\n\n";
errs()<<"\n=======================Inside Module======================\n";
 		for (Module::iterator FunctionIter = M.getFunctionList().begin(); FunctionIter != M.getFunctionList().end(); ) {
	Function *F = FunctionIter++; // F is a pointer to a Function instance
	FunctionCounter++;



errs() << "-----------------------Function Name :" << F->getName() << "-----------------------\n";
errs()<<"\n==  ==  ==  ==  ==Instructions Starts==  ==  ==  ==  ==\n\n";
errs()<<"  OPCODE  \t| Instruction\n";

		for (inst_iterator I = inst_begin(F), E = inst_end(F); I != E; ++I)
		{
		errs()<<"  "<< I->getOpcodeName()<< "\t| "<< *I <<" \n";
		InstCounter++;
		}		

errs()<<"\n==  ==  ==  ==  ==Instructions Ends==  ==  ==  ==  ==\n\n";
errs() << "-----------------------Function Ends Here---------------------\n\n";
errs() << "=======================================================================================\n";
								
errs()<<"\n=======================Module Ends======================\n";
	
	errs() <<"Success Till Here";

}

errs()<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

// Printing all the Load instructions in the program
errs()<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~LOAD INSTRUCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
errs()<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
//DSADFSGFDHGFJHYKHKGHDGDFGDFGDFGDFG

   for(Module::iterator F = M.begin(), E = M.end(); F!= E; ++F)
            {
		

                for(Function::iterator BB = F->begin(), E = F->end(); BB != E; ++BB)
                {
			
                    ModulePassDemo::runOnBasicBlock(BB);
			++BasicBlockCounter;
                }

	}
errs()<<"\n";
/*
errs()<<"\n-------------------------------------------------------------";
errs()<<"\nTotal Number of Printf Statements in the Program ="<<"   "<<counter;
errs()<<"\n-------------------------------------------------------------\n";
*/

	return false;
}



 virtual bool runOnBasicBlock(Function::iterator &BB)
        {
            for(BasicBlock::iterator BI = BB->begin(), BE = BB->end(); BI != BE; ++BI)           
            {


		if( CallInst * pCall = dyn_cast<CallInst>(BI)){
		
		Function * pFunction = pCall->getCalledFunction();
		std::string fname = pFunction->getName();
		
		errs()<<"\n Function Name:  "<<fname<<"\t|  Function Call number:  "<<++FunctionCounter;		
if(fname =="printf")
PrintCounter++;		
else
OtherFunctionCounter++;
		//counter
		}
		else if(isa<LoadInst>(BI)){
		LoadCounter++;
		}
		else if(isa<StoreInst>(BI)){
		StoreCounter++;	

		}
	}


            return true;
        }

	};
}

char ModulePassDemo::ID = 0;
static RegisterPass<ModulePassDemo> X("ModulePassDemo", "Simple Module Pass program", false, false);


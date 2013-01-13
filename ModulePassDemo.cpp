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
using namespace llvm;
    
namespace {
    struct ModulePassDemo : public ModulePass { 
    static char ID; // Pass identification
	ModulePassDemo() : ModulePass(ID) {}    
    	virtual bool runOnModule(Module &M) {
//============================Global Variable Declaration and Initialization========================


GlobalVariable* counter = new GlobalVariable(/*Module=*/M,(Type*) Type::getInt32Ty (getGlobalContext()),
/*isConstant=*/false,
/*Linkage=*/GlobalValue::ExternalLinkage,
/*Initializer=*/0,
/*Name=*/"Counter");

errs()<<*counter +1;





errs()<<"\n\t\t================Global Variable Pointer========================\n";
errs()<<"Global Variable Code \t\t|Variable ID \t\t|Variable Name\n";
errs()<<counter<<"\t\t\t|"<<counter->getValueID()<<"\t\t\t|"<<*counter<<"\n";
//errs()<<"\nValue"<<*counter.getInt();

/*for (Module::const_global_iterator GI = M->global_begin(), GE = M->global_end(); GI != GE; ++GI) {
  if (GI->hasName())
	errs() << GI->getName() << endl; // Print name
  	errs() << GI->getType()->getElementType() << endl; // Print Type
}
*/

errs()<<"\n\t\t===============================================================\n";

errs()<<"============Global Variable Successful";

//////////////======================================================================================


errs()<<"==========Start============\n\n\n";
errs()<<"\n=======================Inside Module======================\n";
 		for (Module::iterator FunctionIter = M.getFunctionList().begin(); 
			FunctionIter != M.getFunctionList().end(); ) {
// F is a pointer to a Function instance
			Function *F = FunctionIter++;
errs() << "-----------------------Function Name :" << F->getName() << "-----------------------\n";
	errs()<<"\n==  ==  ==  ==  ==Instructions Starts==  ==  ==  ==  ==\n\n";
		errs()<<"  OPCODE  \t| Instruction\n";
			for (inst_iterator I = inst_begin(F), E = inst_end(F); I != E; ++I)
				errs()<<"  "<< I->getOpcodeName()<< "\t| "<< *I <<" \n";
									}
				errs()<<"\n==  ==  ==  ==  ==Instructions Ends==  ==  ==  ==  ==\n\n";
errs() << "-----------------------Function Ends Here---------------------\n\n";

errs() << "=======================================================================================\n";
									
errs()<<"\n=======================Module Ends======================\n";
	//errs()<< "Total Number of functions:" <<M.getFunctionList.getSize();
	errs() <<"Success Till Here";
	return true;
		}
	};
}

char ModulePassDemo::ID = 0;
static RegisterPass<ModulePassDemo> X("ModulePassDemo", "Simple Module Pass program", false, false);

/**     LLVMContext &Context = M.getContext();
      const PointerType *UIntPtr = Type::getInt32PtrTy(Context);
      const Type *Void = Type::getVoidTy(Context);
      

    //  MopFn = M.getOrInsertFunction("mop", Void,                              UIntPtr, Type::getInt32Ty(Context),Type::getInt32Ty(Context),                               (Type*)0);
      //Function *tmp = cast<Function>(MopFn);
     // tmp->setCallingConv(CallingConv::C);
for (Module::iterator F = M.begin(), E = M.end(); F != E; ++F) {
        if (F->isDeclaration()) continue;
          for (Function::iterator BB = F->begin(), E = F->end(); BB != E; ++BB) {
            TsanOfflineInstrument::runOnBasicBlock(BB);
          }
      }**/
/**
	for (Function::iterator InstructionIter = F->getInstructionList().begin();
InstrunctionIter != F->getInstructionList().end(); ) 
{
		errs()<<"==========2a============";
	Instruction *I = InstructionIter++;
	errs() << I << ":" << I->getOpcode() << "\n";
		errs()<<"==========2b============";
}
**/
/*
Twine *sixty = new Twine(60);
GlobalVariable *counter = new GlobalVariable((Type*) Type::getInt32Ty (getGlobalContext()),4, true, GlobalValue::ExternalLinkage,0,*sixty,GlobalVariable::ThreadLocalMode::NotThreadLocal, AddressSpace = 0);
*/


/*


GlobalVariable::GlobalVariable	(	Type * 	Ty,
bool 	isConstant,
LinkageTypes 	Linkage,
Constant * 	Initializer = 0,
const Twine & 	Name = "",
ThreadLocalMode 	TLMode = NotThreadLocal,
unsigned 	AddressSpace = 0 
)	

**/

/**
Module* mod = new Module("test", getGlobalContext()); 
GlobalVariable val(*mod, (Type*) ArrayType::get(Type::getInt8Ty(getGlobalContext()), 4), true,GlobalValue::ExternalLinkage, cons, s);

GlobalVariable *Counters = new GlobalVariable(Type::getInt8Ty(getGlobalContext()), 4, true,GlobalValue::ExternalLinkage, cons, s); 
*Counters = 0;**/
//Module* mod = new Module("test", getGlobalContext()); 

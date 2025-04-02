include "llvm/Target/Target.td"
include "Use_arch_btwRegisterInfo.td"
include "Use_arch_btwInstrInfo.td"
include "Use_arch_btwCallingConv.td"

class Proc<string Name, list<SubtargetFeature> Features>
: Processor<Name, NoItineraries, Features>;
 
def : Proc<"generic", []>;

def Use_arch_btw : Target;
def Use_arch_btw : Target {
   let InstructionSet = Use_arch_btwInstrInfo;
 }
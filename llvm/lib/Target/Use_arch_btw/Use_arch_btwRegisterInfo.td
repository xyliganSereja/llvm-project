// Use_arch_btw Register file declaration
class Use_arch_btwReg<bits<16> Enc, string n> : Register<n>{
    let HWEncoding = Enc;
    let Namespace = "Use_arch_btw";
}

// Registers
foreach I = 0-15 in {
    def R#I : Use_arch_btwReg<I, "r"#I>;
}

// Classes
def GPR : RegisterClass<"Use_arch_btw", [i32], 32, (add
R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15)>;

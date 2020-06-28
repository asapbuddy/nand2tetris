# Assembler
--
HACK platform instruction support two instruction types: A- and C- instruction.

##### The ```A-instruction```:
used to set the A register to a 15-bit value and represents a BCD:
<p align="center">
<img align="left" width="600" height="150" src="https://raw.githubusercontent.com/asapbuddy/nand2tetris/master/Images/A-Instruction.PNG">
</p>

##### The ```C-instruction```:
is the programming workhorse of the Hack platform — the instruction
that gets almost everything done. The instruction code is a specification
that answers three questions: (a) what to compute(`comp` part), (b) where to store the computed
value(`dest` part), and (c) what to do next(`jump` part)? 
Along with the A-instruction, these specifications determine all the possible operations of the computer.

<p align="center">
<img align="left" width="600" height="150" src="https://raw.githubusercontent.com/asapbuddy/nand2tetris/master/Images/C-Instruction.PNG">
</p>

### Implementation
By design, our assembly dialect supports labels that can be used before definitions, that actually does point to place in code.
Because of this we need to implement `TwoPass`-Assembler. 
On the first pass we just look at assembly code and count instructions:
A- or C- instructions and if we see an Label instruction we added that symbol to Lookup table with current address of current instruction count.
```
    @i
    M=1
    @sum
    M=0
(LOOP)    // Label instruction.
    @i
    D=M
    @100
``` 

### Code
Assembler pass source code file to parser(iterator-like API) then fetch the commands.
There 3 command types which are generated from the Parser: Address(A-), Instruction(C-), Label(actually 4 for null NotCommand).
On first pass we acts like described above: just count instructions and resolve Labels.
On second pass we process A- and C- instruction and if we see an A- instruction we can ensure that is address or label because of first pass.

![Image](https://raw.githubusercontent.com/asapbuddy/nand2tetris/master/Images/TwoPassAssembler.png)
# The project :
Project from the 19 Coding School. The goal is to sort data with the help of two piles and given operations you can apply on it. It has to be done with the smallest number of operations.

# Push-swap :
The program receives from the standard input the numbers to sort. The algorithm is based on a Quick-Sort twisted in a way to respect the given rules. It puts on the standard output the operations to make to sort the pile.

USAGE => 

./push_swap \`ruby -e "puts (0..100).to_a.shuffle.join(' ')"\`

The ruby command gives shuffled data (here 100) as parameter to the program.

# Checker :
The program receives from the standard input the numbers to place on the pile A. Read the operations from the standard output and check if the pile is sorted after having done the operations. Display "OK" on the standard output if the pile is sorted or "KO" if it doesn't.

USAGE => 
* ARG=\`ruby -e "puts (1..500).to_a.shuffle.join(' ')"\`
* ./push_swap $ARG | ./checker $ARG

# The visualizer :


# The operations :
sa/sb - SWAP the first two data on top of the pile(A/B). 

pa/pb - PUSH the first data from the top of the pile(B/A) on top of the pile (A/B).

ra/rb: ROTATE the data on top of the pile (A/B). The data on top becomes the data on the bottom.

rra/rrb: REVERSE ROTATE the data from the bottom of the pile (A/B). The data from the bottom becomes the data on top.
